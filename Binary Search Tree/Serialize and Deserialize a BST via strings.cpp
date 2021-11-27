//Every value in string obtained from serialization will be differntiated by "#" sign.

// we can serialize the BST into inorder (sorted order) also, but in inorder we don't know which value to consider as root node
// bcz for every value in sorted array (obtained from inorder traversal) can from a different BST, 
// but we have to select only that value as root which is the original root in given tree,
// For that in string we can append the root of original tree
// like "$root_val$inorder_traversal"
// like ex-> "$3$1#2#3#4#5#6#7#8#9#10#", here you cannot form the BST(deSerialize from string) from sorted array by taking mid as root,
// instead you have the root value enclosed in $_$, which we can easily extract.

//To simplify we can also serialize tree in preOrder, here we are sure the first value is root.
//or use postOrder, and root will be last value here.

class Codec
{
public:
    string intToStr(int num)
    {
        ostringstream str1;
        str1 << num;
        return str1.str();
    }
    int strToInt(string x)
    {
        stringstream temp(x);
        int num = 0;
        temp >> num;
        return num;
    }
    TreeNode *BST_from_PreOrder(vector<int> &pre, int s, int e)
    {
        if (s > e)
            return NULL;
        TreeNode *root = new TreeNode(pre[s]);
        int i;
        for (i = s + 1; i <= e; i++)
            if (pre[i] > pre[s])
                break;
        root->left = BST_from_PreOrder(pre, s + 1, i - 1);
        root->right = BST_from_PreOrder(pre, i, e);
        return root;
    }
    void preOrder(TreeNode *root, string &s)
    {
        if (root == NULL)
            return;
        s += intToStr(root->val);
        s += '#';
        preOrder(root->left, s);
        preOrder(root->right, s);
    }
    string serialize(TreeNode *root)
    {
        string s = "";
        preOrder(root, s);
        // cout << s << endl;
        return s;
    }

    TreeNode *deserialize(string data)
    {
        vector<int> v;
        string x = "";
        for (auto it : data)
        {
            if (it == '#')
            {
                v.push_back(strToInt(x));
                x = "";
            }
            else
                x += it;
        }
        for (auto it : v)
            cout << it << " ";
        return BST_from_PreOrder(v, 0, v.size() - 1);
    }
};
