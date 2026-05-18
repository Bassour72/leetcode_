
#include <iostream>
#include <string>
#include <set>
#include <iterator>



 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
   static ListNode* reverseRecursive( ListNode *curr, ListNode *next, ListNode *prev)
    {
        if (!curr)
            return (prev);
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        return (reverseRecursive(curr, next, prev));
    }
public:
    static ListNode* reverseRecursive(ListNode* head) 
    {
        if (!head)
            return (head);
        ListNode *next = NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;
        return (reverseRecursive(curr,next,prev));
    }
    static ListNode* reverseList(ListNode* head) 
    {
        if (!head)
            return (head);
        ListNode *next = NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return (prev);
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
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);


    
    // ListNode* l2 = new ListNode(3);
    // l2->next = new ListNode(4);
    // l2->next->next = new ListNode(4);

    
    // ListNode* l3 = new ListNode(5);
    // l3->next = new ListNode(6);

   

    ListNode* reverse = Solution::reverseRecursive(l1);

    printList(reverse);
    freeList(reverse);
    return 0;
}