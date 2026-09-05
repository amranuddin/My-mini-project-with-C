#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100

struct Book
{
    int id;
    char name[50];
    char author[50];
    float price;
    int available;
};



struct Book books[MAX_BOOKS];
int bookCount = 0;

void addBook()
{
    if (bookCount >= MAX_BOOKS)
    {
        printf("\n Library is full! \n");
        return;
    }

    printf("\n Enter Book ID: ");
    scanf("%d", &books[bookCount].id);

    getchar();

    printf("Enter Book Name: ");
    fgets(books[bookCount].name, 50, stdin);
    books[bookCount].name[strcspn(books[bookCount].name, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(books[bookCount].author, 50, stdin);
    books[bookCount].author[strcspn(books[bookCount].author, "\n")] = '\0';

    printf("Enter Book Price: ");
    scanf("%f", &books[bookCount].price);

    books[bookCount].available = 1;
    bookCount++;

    printf("\nBook added successfully!\n");
}

void displayBooks()
{
    int i;

    if (bookCount == 0)
    {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n========== ALL BOOKS ==========\n");

    for (i = 0; i < bookCount; i++)
    {
        printf("\nBook ID     : %d", books[i].id);
        printf("\nBook Name   : %s", books[i].name);
        printf("\nAuthor      : %s", books[i].author);
        printf("\nPrice       : %.2f", books[i].price);

        if (books[i].available == 1)
            printf("\nStatus      : Available\n");
        else
            printf("\nStatus      : Issued\n");
    }
}

void searchBook()
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            printf("\nBook Found!\n");
            printf("Book ID     : %d\n", books[i].id);
            printf("Book Name   : %s\n", books[i].name);
            printf("Author      : %s\n", books[i].author);
            printf("Price       : %.2f\n", books[i].price);

            if (books[i].available == 1)
                printf("Status      : Available\n");
            else
                printf("Status      : Issued\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nBook not found!\n");
}

void issueBook()
{
    int id;
    int i;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            if (books[i].available == 1)
            {
                books[i].available = 0;
                printf("\nBook issued successfully!\n");
            }
            else
            {
                printf("\nSorry, this book is already issued.\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}

void returnBook()
{
    int id;
    int i;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            if (books[i].available == 0)
            {
                books[i].available = 1;
                printf("\nBook returned successfully!\n");
            }
            else
            {
                printf("\nThis book was not issued.\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}

void deleteBook()
{
    int id;
    int i, j;

    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            for (j = i; j < bookCount - 1; j++)
            {
                books[j] = books[j + 1];
            }

            bookCount--;

            printf("\n Book deleted successfully! \n");
            return;
        }
    }

    printf("\n Book not found! \n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n ====================================");
        printf("\n       LIBRARY MANAGEMENT SYSTEM");
        printf("\n ====================================");

        printf("\n 1. Add Book");
        printf("\n 2. Display All Books");
        printf("\n 3. Search Book");
        printf("\n 4. Issue Book");
        printf("\n 5. Return Book");
        printf("\n 6. Delete Book");
        printf("\n 7. Exit");

        printf("\n \n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                deleteBook();
                break;

            case 7:
                printf("\n Thank you for using the Library Management System!\n");
                return 0;

            default:
                printf("\n Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
