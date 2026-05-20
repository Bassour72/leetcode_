
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <vector>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
    static int listSize(ListNode* head)
    {
        if (!head)
            return (0);
        ListNode* temp = head;
        int len = 0;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return (len);
    }
public:
    static ListNode* middleNode(ListNode* head) 
    {
        if (!head)
            return (0);
        int len = listSize(head);
        int i = 0;
        ListNode* temp = head;
        while (temp != NULL && i < (len / 2))
        {
             temp = temp->next;
             i++;
        }
        return (temp);
    }
};