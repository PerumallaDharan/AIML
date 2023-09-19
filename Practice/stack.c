// Creating stack using arrays in C

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the size of the stack\n");
    scanf("%d", &n);

    int stack[n], data, top = -1, choice;

    while (1)
    {
        printf("Enter your choice\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (top == n - 1)
            {
                printf("Stack overflow\n");
            }
            else
            {
                printf("Enter the data to be pushed\n");
                scanf("%d", &data);
                top++;
                stack[top] = data;
            }
            break;

        case 2:
            if (top == -1)
            {
                printf("Stack underflow\n");
            }
            else
            {
                printf("The popped element is %d\n", stack[top]);
                top--;
            }
            break;

        case 3:
            if (top == -1)
            {
                printf("Stack underflow\n");
            }
            else
            {
                printf("The stack is\n");
                for (int i = top; i >= 0; i--)
                {
                    printf("%d\n", stack[i]);
                }
            }
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}