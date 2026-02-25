#include <iostream>
#include <vector>


//  Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1) 
            return l2;
        if (!l2) 
            return l1;

        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1)
            tail->next = l1;
        else
            tail->next = l2;

        return dummy.next;
    }
public:
    static ListNode* mergeKLists(std::vector<ListNode*>& lists) 
    {
        ListNode* result = NULL;
        for (int i = 0; i < (int)lists.size(); i++) 
        {
            result = mergeTwoLists(result, lists[i]);
        }
        return (result);
    }
};


void printList(ListNode* head) 
{
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
void freeList(ListNode* head)
{
    while (head)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(2);
    l1->next->next->next = new ListNode(3);


    
    ListNode* l2 = new ListNode(3);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(4);

    
    ListNode* l3 = new ListNode(5);
    l3->next = new ListNode(6);

    // C++98 way
    std::vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    ListNode* merged = Solution::mergeKLists(lists);

    printList(merged);
    freeList(merged);
    return 0;
}
// ✅ Output
// 1 1 2 3 4 4 5 6

// If you want next level (faster version using heap / priority_queue), tell me and I’ll show you 🔥