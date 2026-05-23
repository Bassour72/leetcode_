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
public:
    static bool isPalindrome(ListNode *head) 
    {
        ListNode* goSlow = head;
        ListNode* goFast = head;
        while(goFast && goFast->next)
        {
            goSlow = goSlow->next;
            goFast = goFast->next->next;
        }
        
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(goSlow)
        {
            next = goSlow->next;
            goSlow->next = prev;
            prev = goSlow;
            goSlow = next;
        }
        while(head && prev)
        {
            if (head->val != prev->val)
                return (false);
            prev = prev->next;
            head = head->next;
        }
        return (true);

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

   

    std ::cout << Solution::isPalindrome(l1) << "\n";

    // printList(reverse);
    // freeList(reverse);
    return 0;
}