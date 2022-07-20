// https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode
{
public:
    char val;
    map<char, TrieNode *> children;
    bool is_leaf;
    TrieNode(char val)
    {
        this->val = val;
        is_leaf = false;
    }
};







class Trie
{
public:
    
  
  
  TrieNode *root;
    Trie()
    {
        root = new TrieNode('/');
    }

  
  
  
  
    void insert_helper(TrieNode *root, string word)
    {
        if (root->children.find(word[0]) == root->children.end())
        {
            TrieNode *newNode = new TrieNode(word[0]);
            root->children[word[0]] = newNode;
            if (word.size() == 1)
            {
                newNode->is_leaf = true;
                return;
            }
            insert_helper(newNode, word.substr(1));
        }
        else
        {
            if (word.size() == 1)
            {
                root->children[word[0]]->is_leaf = true;
                return;
            }
            insert_helper(root->children[word[0]], word.substr(1));
        }
    }
    void insert(string word)
    {
        insert_helper(root, word);
    }

  
  
  
  
  
  
  
  
  
    bool search_helper(TrieNode *root, string word)
    {
        if (root->children.find(word[0]) == root->children.end())
            return false;
        if (word.size() == 1)
        {
            if (root->children[word[0]]->is_leaf == true)
                return true;
            return false;
        }
        return search_helper(root->children[word[0]], word.substr(1));
    }
    bool search(string word)
    {
        return search_helper(root, word);
    }

  
  
  
  
  
  
  
  
    bool startWith_helper(TrieNode *root, string word)
    {
        if (root->children.find(word[0]) == root->children.end())
            return false;
        if (word.size() == 1)
            return true;
        return startWith_helper(root->children[word[0]], word.substr(1));
    }
    bool startsWith(string prefix)
    {
        return startWith_helper(root, prefix);
    }
};
