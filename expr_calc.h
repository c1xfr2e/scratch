
struct Stack
{
    int top;
    char data[30];
};

void Stack_Init(Stack *s)
{
    s->top = -1;
}

void Stack_Push(Stack *s, char c)
{
    s->data[++s->top] = c;
}

void Stack_Pop(Stack *s)
{
    s->top--;
}

char Stack_Top(Stack *s)
{
    return s->data[s->top];
}

int Stack_IsEmpty(Stack *s)
{
    return s->top == -1 ? 1 : 0;
}

int Priority(char operand)
{
    switch (operand)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

int IsDigit(int c)
{
    return c >= (int)'0' && c <= (int)'9';
}

void To_ReversePolishNotation(const char *expr, char *out)
{
    Stack s;
    Stack_Init(&s);
    int i = 0, j = 0;
    char tok;
    while ((tok = expr[i++]))
    {
        switch (tok)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            out[j++] = tok;
            break;

        case '+':
        case '-':
            while (!Stack_IsEmpty(&s))
            {
                char t = Stack_Top(&s);
                if (t == '(')
                    break;
                out[j++] = t;
                Stack_Pop(&s);
            }
            Stack_Push(&s, tok);
            break;

        case '*':
        case '/':
            if (Stack_IsEmpty(&s))
            {
                Stack_Push(&s, tok);
            }
            else
            {
                while (!Stack_IsEmpty(&s))
                {
                    char t = Stack_Top(&s);
                    if (t == '*' || t == '/')
                    {
                        out[j++] = t;
                        Stack_Pop(&s);
                    }
                    else
                    {
                        Stack_Push(&s, tok);
                        break;
                    }
                }
            }
            break;

        case '(':
            Stack_Push(&s, tok);
            break;

        case ')':
            while (!Stack_IsEmpty(&s))
            {
                char t = Stack_Top(&s);
                Stack_Pop(&s);
                if (t == '(')
                    break;
                else
                {
                    out[j++] = t;
                }
            }
            break;
        }
    }

    while (!Stack_IsEmpty(&s))
    {
        char t = Stack_Top(&s);
        Stack_Pop(&s);
        out[j++] = t;
    }

    out[j] = '\0';
}

int ToValue(char *rpn)
{
    int operand[30];
    int top = -1;
    char c;
    int i = 0;
    int val = 0;
    while ((c = rpn[i++]))
    {
        switch (c)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            operand[++top] = (int)(c - '0');
            break;

        case '+':
            val = operand[top - 1] + operand[top];
            operand[--top] = val;
            break;
        case '-':
            val = operand[top - 1] - operand[top];
            operand[--top] = val;
            break;
        case '*':
            val = operand[top - 1] * operand[top];
            operand[--top] = val;
            break;
        case '/':
            val = operand[top - 1] / operand[top];
            operand[--top] = val;
            break;
        }
    }

    return operand[0];
}