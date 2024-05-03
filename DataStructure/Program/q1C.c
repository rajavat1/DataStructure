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

void push(struct Stack *stack, char item)
{
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack)
{
    return stack->items[stack->top--];
}

int is_operator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

int is_alphanumeric(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

char peek(struct Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->items[stack->top];
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

int evaluate_postfix(char *postfix)
{
    struct Stack stack;
    initialize(&stack);

    int len = strlen(postfix);

    for (int i = 0; i < len; i++)
    {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9')
        {
            push(&stack, ch - '0'); // Convert character to integer
        }
        else if (is_operator(ch))
        {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            int result;

            switch (ch)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '%':
                result = operand1 % operand2;
                break;
            case '^':
                result = 1;
                for (int j = 0; j < operand2; j++)
                {
                    result *= operand1;
                }
                break;
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

void process_infix(char *infix, int option)
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

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    if (option == 2)
    {
        int len = strlen(postfix);

        for (int i = 0; i < len; i++)
        {
            if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z'))
            {
                int value;
                printf("Enter value for %c: ", postfix[i]);
                scanf("%d", &value);
                for (int j = 0; j < len; j++)
                {
                    if (postfix[j] == postfix[i])
                        postfix[j] = value + '0';
                }
            }
        }

        int result = evaluate_postfix(postfix);
        printf("Result of Evaluation: %d\n", result);
    }

    free(postfix);
}

int main()
{
    char iE[MAX_SIZE];
    printf("Enter Infix Expression: ");
    scanf("%s", iE);

    int option;
    printf("Choose an option:\n");
    printf("1. Convert to Postfix\n");
    printf("2. Convert to Postfix and Evaluate\n");
    scanf("%d", &option);

    process_infix(iE, option);

    return 0;
}
