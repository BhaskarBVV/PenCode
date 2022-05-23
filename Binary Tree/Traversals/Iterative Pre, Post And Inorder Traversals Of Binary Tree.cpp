void iterativePrePostInTraversal(Node *root)
{
    // pair of node and number of visits to the i-th node.
    //  if number of visits=0, then print in pre and move to left.
    //  if number of visits=1, then print in In and move to right.
    //  if number of visits=2, then print in post and pop the value at top;

    stack<pair<Node *, int>> st;
    vector<int> pre, post, in;

    st.push({root, 0});

    pair<Node *, int> temp;

    while (!st.empty())
    {
        temp = st.top();

        if (temp.second == 0)
        {
            st.top().second++;
            pre.push_back(temp.first->data);
            if (temp.first->left)
                st.push({temp.first->left, 0});
        }


        else if (temp.second == 1)
        {
            st.top().second++;
            in.push_back(temp.first->data);
            if (temp.first->right)
                st.push({temp.first->right, 0});
        }


        else
        {
            st.pop();
            post.push_back(temp.first->data);
        }
    }

    
    for (auto it : pre)
        cout << it << " ";
    cout << endl;
    for (auto it : in)
        cout << it << " ";
    cout << endl;
    for (auto it : post)
        cout << it << " ";
}
