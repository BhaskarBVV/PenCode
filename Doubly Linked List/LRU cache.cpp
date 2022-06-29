https://leetcode.com/problems/lru-cache/

class LRUCache
{
public:
    class ListNode
    {
    public:
        int val, key;
        ListNode *next, *prev;
        ListNode() {}
        ListNode(int key, int val) { this->key = key, this->val = val, prev = NULL, prev = NULL; }
    };
    ListNode *head = new ListNode(0, 0);
    ListNode *tail = new ListNode(0, 0);
    int cap;
    map<int, ListNode *> mp;
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        int val = -1;
        if (mp.find(key) != mp.end())
        {
            ListNode *temp = mp[key];
            val = temp->val;
            ListNode *pre_temp = temp->prev;
            pre_temp->next = temp->next;
            temp->next->prev = pre_temp;
            // temp->next = NULL;
            temp->next = head->next;
            head->next->prev = temp;
            head->next = temp;
            temp->prev = head;
        }

        return val;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            ListNode *temp = mp[key];
            temp->val = value;
            ListNode *pre_temp = temp->prev;
            pre_temp->next = temp->next;
            temp->next->prev = pre_temp;
            // temp->next = NULL;
            temp->next = head->next;
            head->next->prev = temp;
            head->next = temp;
            temp->prev = head;
        }
        else
        {
            if (mp.size() == cap)
            {
                ListNode *temp = tail->prev;
                ListNode *pre_temp = temp->prev;
                pre_temp->next = temp->next;
                temp->next->prev = pre_temp;
                mp.erase(temp->key);
            }
            ListNode *newNode = new ListNode(key, value);
            mp[key] = newNode;
            newNode->next = head->next;
            head->next->prev = newNode;
            head->next = newNode;
            newNode->prev = head;
        }
    }
};
