#pragma once

// + - * / ( )
char priority_cmp(char a, char b)
{
    if (a == '+' || a == '-')
    {
        if (b == '+' || b == '-' || b == ')')
            return '>';
        else if (b == '*' || b == '/' || b == '(')
            return '<';
    }
    else if (a == '*' || a == '/')
    {
        if (b == '+' || b == '-' || b == '*' || b == '/' || b == ')')
            return '>';
        else if (b == '(')
            return '<';
    }
    else if (a == '(')
    {
        if (b == ')')
            return '=';
        else 
            return '<';
    }

    return ' ';
}

bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

bool is_operator(char c)
{
    return (c == '+' || c == '-' || c =='*' || c == '/' || c == '(' || c == ')');
}

int calc(char op, int v1, int v2)
{
    switch (op)
    {
    case '+':
        return v1 + v2;
    case '-':
        return v1 - v2;
    case '*':
        return v1 * v2;
    case '/':
        return v1 / v2;
    }
    return 0;
}

int evaluate(const char* expr)
{
    char s_op[10];
    int s_val[10];
    int top_op = -1;
    int top_val = -1;
    int i_expr = 0;

    while (expr[i_expr] != '\0')
    {
        char t = expr[i_expr];
        if (is_digit(t))
        {
            s_val[++top_val] = t - '0';
            ++i_expr;
        }
        else if (is_operator(t))
        {
            char p_cmp = (top_op == -1)? '<' : priority_cmp(s_op[top_op], t);
            if (p_cmp == '<')
            {
                s_op[++top_op] = t;
                ++i_expr;
            }
            else if (p_cmp == '=')
            {
                --top_op;
                ++i_expr;
            }
            else if (p_cmp == '>')
            {
                int r = calc(s_op[top_op], s_val[top_val - 1], s_val[top_val]);
                --top_op;
                --top_val;
                s_val[top_val] = r;
            }
        }
    }

    while (top_op != -1)
    {
        int r = calc(s_op[top_op], s_val[top_val - 1], s_val[top_val]);
        --top_op;
        --top_val;
        s_val[top_val] = r;
    }

    return s_val[top_val];
}