// https://leetcode.com/problems/longest-word-in-dictionary/

class Solution
{
public:
    class node
    {
    public:
        char val;
        set<node *> children;
        node(char ch)
        {
            val = ch;
        }
    };
    void traverse(node *root, string &ans, int &mx_size, string s, map<string, int> &mp)
    {
        s += root->val;
        if (mp[s] != 1)
        {
          // means, root->val ko add krne ke baad wala word, words vector main hai hi ni, 
          //(ek ke alphabet add krte hue word banana hai, and wo har word wordsVector main hona chaiye)
          //agar root->val ko add krne ke baad wala word ni hai words vector main, toh last added alphabet ko pop krkdo and check kro kya current string largest and
          // lex smaller hai ya ni.
            s.pop_back();
            if ((int)s.size() > mx_size)
            {
                mx_size = s.size();
                ans = s;
            }
            else if ((int)s.size() == mx_size)
            {
                if (s < ans)
                    ans = s;
            }
            return;
        }
        
      //ab root yahan leaf node hai, toh ab jo string bani hai use bhi check kro largest and lex small ke liye.
        if (root->children.size() == 0)
        {
            if ((int)s.size() > mx_size)
            {
                mx_size = s.size();
                ans = s;
            }
            else if ((int)s.size() == mx_size)
            {
                if (s < ans)
                    ans = s;
            }
        }
        for (auto it : root->children)
        {
            traverse(it, ans, mx_size, s, mp);
        }
    }
    string longestWord(vector<string> &words)
    {
        map<string, int> mp;
        for (auto it : words)
            mp[it] = 1;
        node *root = new node('.');
        node *temp;
        bool found;
        for (auto it : words)
        {
            temp = root;
            for (auto i : it)
            {
                found = false;
                for (auto child : temp->children)
                {
                    if (child->val == i)
                    {
                        found = true;
                        temp = child;
                        break;
                    }
                }
                if (found == false)
                {
                    node *new_child = new node(i);
                    temp->children.insert(new_child);
                    temp = new_child;
                }
            }
        }
        string ans;
        int mx = -1;
      // yahan se hi loop laga lo, taaki ('.') ye add na ho current strings main.
      // agar seedhe recursive call kroge toh current string main (.) add ho jayega, bcz of main root->val='.' hai
        for (auto it : root->children)
            traverse(it, ans, mx, "", mp);
        return ans;
    }
};
