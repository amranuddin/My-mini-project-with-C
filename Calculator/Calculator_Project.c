#include <stdio.h>

int main()
{
    int choice;
    float a, b, ans;

    while (1)
    {
        printf("\n \n===== CALCULATOR ===== \n");
        printf("1. Add \n");
        printf("2. Subtract \n");
        printf("3. Multiply \n");
        printf("4. Divide \n");
        printf("5. Exit \n");

        printf("\n Enter your choice: ");
        scanf("%d ", &choice);

        if (choice == 5)
        {
            printf("Calculator closed.\n");

            break;
        }

        printf("Enter first number: ");
        scanf("%f", &a);
        printf("Enter second number: ");

        
        scanf("%f", &b);

        if (choice == 1)
        {
            ans = a + b;
            printf("Answer = %.2f", ans);
        }
        else if (choice == 2)
        {
            ans = a - b;
            printf("Answer = %.2f", ans);
        }
        else if (choice == 3)
        {
            ans = a * b;
            printf("Answer = %.2f", ans);
        }
        else if (choice ==4)
        {
            if (b==0)
            {
                printf("Cannot divide by zero!");
            }
            else
            {
                ans = a/b;
                printf("Answer = %.2f",ans);
            }
        }
        else
        {
            printf(" Wrong choice! ");
        }
    }
}