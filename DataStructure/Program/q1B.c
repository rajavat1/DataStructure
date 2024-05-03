#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack
{
    char items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack)
{
    stack->top = -1;
}

int is_empty(struct Stack *stack)
{
    return stack->top == -1;
}

int is_full(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, char item)
{
    if (is_full(stack))
    {
        printf("Stack is full\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

char peek(struct Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}

int is_operator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

int precedence(char ch)
{
    if (ch == '^')
        return 1;
    if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 3;
    else
        return 0;
}

int is_alphanumeric(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

char *infix_to_postfix(char *infix)
{
    struct Stack stack;
    initialize(&stack);

    int len = strlen(infix);
    char *postfix = (char *)malloc((len + 1) * sizeof(char));
    int p_index = 0;

    for (int i = 0; i < len; i++)
    {
        char ch = infix[i];

        if (is_alphanumeric(ch))
        {
            postfix[p_index++] = ch;
        }
        else if (ch == '(')
        {
            push(&stack, ch);
        }
        else if (ch == ')')
        {
            while (!is_empty(&stack) && peek(&stack) != '(')
            {
                postfix[p_index++] = pop(&stack);
            }
            if (!is_empty(&stack) && peek(&stack) == '(')
            {
                pop(&stack);
            }
        }
        else if (is_operator(ch))
        {
            while (!is_empty(&stack) && precedence(ch) <= precedence(peek(&stack)))
            {
                postfix[p_index++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!is_empty(&stack))
    {
        postfix[p_index++] = pop(&stack);
    }

    postfix[p_index] = '\0';

    return postfix;
}

int main()
{
    char iE[MAX_SIZE];
    printf("Enter Infix Expression: ");
    scanf("%s", iE);
    char *pE = infix_to_postfix(iE);

    printf("Infix Expression: %s\n", iE);
    printf("Postfix Expression: %s\n", pE);

    free(pE);

    return 0;
}