//        1                   1
//      /   \               /   \
//     2     3             3     2
//    / \   /               \   /  \
//   4   5  6                6  4   5
//      / \                        / \
//     7   8                      8   7
// ans: yes 
// link: https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1#


bool isIsomorphic(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) ||
           (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left))
}
