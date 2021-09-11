bool isValid(string s)
{
    stack<char> stk;
    int f = 1, i;
    for (i = 0; i < s.size() && f == 1; i++)
    {
        if (stk.empty())
        {
            if ((s[i] == '{' || s[i] == '[' || s[i] == '('))
                stk.push(s[i]);
            else
                f = 0;
        }
        else if ((s[i] == '{' || s[i] == '[' || s[i] == '('))
            stk.push(s[i]);
        else if (s[i] == '}')
        {
            if (stk.top() == '{')
                stk.pop();
            else
                f = 0;
        }
        else if (s[i] == ']')
        {
            if (stk.top() == '[')
                stk.pop();
            else
                f = 0;
        }
        else if (s[i] == ')')
        {
            if (stk.top() == '(')
                stk.pop();
            else
                f = 0;
        }
    }
    if (f == 1 && stk.empty())
        return true;
    return false;
}
