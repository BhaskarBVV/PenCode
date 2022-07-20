// https://practice.geeksforgeeks.org/problems/trie-insert-and-search0651/1

#define ALPHABET_SIZE (26)
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
};

//      is_leaf
//      [][][][][].....26...[]
//      is type ke trie main node ki value uske index ke through identify kr rhe hain
//      and Root Node leaf ni hoga,
//      let key = "a", toh root ke children array main, 'a' ke liye ek naya Node bana denge.






void insert(struct TrieNode *root, string key)
{
    if (root->children[key[0] - 'a'] == NULL)
    {
        TrieNode *newNode = new TrieNode();
        root->children[key[0] - 'a'] = newNode;
        if (key.size() == 1)
        {
            newNode->isLeaf = true;
            return;
        }
        insert(root->children[key[0] - 'a'], key.substr(1));
    }
    else
    {
        if (key.size() == 1)
        {
            root->children[key[0] - 'a']->isLeaf = true;
            return;
        }
        insert(root->children[key[0] - 'a'], key.substr(1));
    }
}








bool search(struct TrieNode *root, string key)
{
    if (key.size() == 1)
    {
        if (root->children[key[0] - 'a'] == NULL)
            return false;
        if (root->children[key[0] - 'a']->isLeaf == true)
            return true;
        else
            return false;
    }
    if (root->children[key[0] - 'a'] == NULL)
        return false;
    else
        return search(root->children[key[0] - 'a'], key.substr(1));
}





