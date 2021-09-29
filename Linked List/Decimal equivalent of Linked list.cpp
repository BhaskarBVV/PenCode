void rev(Node *head, vector<int> &v)
    {
        if (head == 0)
            return;
        else
            rev(head->next, v);
        v.push_back(head->data);
    }
long long unsigned int decimalValue(Node *head)
{
   vector<int> v;
        rev(head, v);
        unsigned int sum = 0, i = 1;
        for (auto it : v)
        {
            if (it == 1)
            {
                sum += i;
//               sum=sum%(1000000007); in case question demands answer modulo 10e9+7
            }
            i *= 2;
//           i=i%(1000000007);
        }
        return sum;
}
