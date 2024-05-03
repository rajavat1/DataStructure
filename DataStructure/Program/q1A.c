#include <stdio.h>

int top = -1, arr[5], item, ch;
void push()
{
    if (top >= 5)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        printf("Enter Element into stack: ");
        scanf("%d", &item);
        arr[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Popped Element: %d\n", arr[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    do
    {
        printf("\n 1. PUSH\t 2. POP\t 3. DISPLAY\t 4. EXIT ");
        printf("\n Enter Your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Wrong value!!!\n");
            break;
        }
    } while (ch != 4);

    return 0;
}
