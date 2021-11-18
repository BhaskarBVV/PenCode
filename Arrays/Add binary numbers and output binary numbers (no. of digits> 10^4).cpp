// IMPLEMENTED WITH HELP OF LOOK AHEAD CARRY ADDER
// Input: a = "11", b = "1"
// Output: "100"
// Input: a = "1010", b = "1011"
// Output: "10101"

 string addBinary(string a, string b)
{
    int carry = 0, sum = 0, i, j, x, y;
    string s = "";
    i = a.size() - 1;
    j = b.size() - 1;
    while (i >= 0 && j >= 0)
    {
        sum = ((a[i] - '0') ^ (b[j] - '0')) ^ (carry);
        s = (char)(sum + '0') + s;
        x = (a[i] - '0') ^ (b[j] - '0');
        x = x && carry;
        y = (a[i] - '0') && (b[j] - '0');
        carry = x || y;
        i -= 1;
        j -= 1;
    }
    while (i >= 0)
    {
        sum = (a[i] - '0') ^ (carry);
        s = (char)(sum + '0') + s;
        carry = carry && (a[i] - '0');
        i -= 1;
    }
    while (j >= 0)
    {
        sum = (b[j] - '0') ^ (carry);
        s = (char)(sum + '0') + s;
        carry = carry && (b[j] - '0');
        j -= 1;
    }
    if (carry == 1)
        s = (char)(carry + '0') + s;
    return s;
}
