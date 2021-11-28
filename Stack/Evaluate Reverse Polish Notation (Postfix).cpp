class Solution {
public:
    int strToInt(string x)
    {
        stringstream temp(x);
        int num = 0;
        temp >> num;
        return num;
    }
    int evalRPN(vector<string>& tokens)
    {
        stack<int>st;
        int x;
        for(auto it: tokens)
        {
            
            if(it!="+"&& it!="-" && it!="*" && it!="/")
            {
                st.push(strToInt(it));
            }
            else
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(it=="+")
                    st.push(a+b);
                else if(it=="*")
                    st.push(a*b);
                else if(it=="-")
                    st.push(b-a);
                else if(it=="/")
                    st.push(b/a);
            }
        }
        return st.top();
    }
};
