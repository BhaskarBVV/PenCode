// given list ko traverse krte jaa rhe hain
// and ek doosri list main (without extra space, same links ko break kreke bana rhe)
// starting se traverse krte hue, current element ko correct position pr place krte jaa rhe hain.

class Solution {
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *prev, *curnext, *temp, *newhead, *ntemp;
        temp = head;
        while (temp != NULL)
        {
            if (dummy->next == NULL)
            {
                head = temp->next;
                temp->next = NULL;
                dummy->next = temp;
            }
            else
            {
                prev = dummy;
                curnext = dummy->next;
                int flag = 0;
                while (curnext != NULL)
                {
                    if (curnext->val < temp->val)
                    {
                        curnext = curnext->next;
                        prev = prev->next;
                    }
                    else
                    {
                        flag = 1;
                      // flag : agar list ka end aagya, and cuurent elememt place hi ni hua list main, tab use list ke end main add krenge.
                        head = temp->next;
                        temp->next = curnext;
                        prev->next = temp;
                        break;
                    }
                }
                if (flag == 0)
                {
                    head = temp->next;
                    temp->next = NULL;
                    prev->next = temp;
                }
            }
            temp = head;
        }
        return dummy->next;
    }
};
