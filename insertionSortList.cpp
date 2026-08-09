#include <iostream>
#include <string>


struct ListNode 
{
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 /*
    Time complexity:
    -Best-case: O(N)
    -Average-case: O(N^2)
    -Worst-case: O(N^2)
 */
class Solution 
{
    void sortedInsert(ListNode **list, ListNode *node)
    {
        if (!node)
            return;
        if (!*list || node->val <= (*list)->val)
        {
            // if (*list)
             std::cout << (node)->val << " = after \n";
            node->next = *list;
            *list = node;
            return;
        }
        ListNode *cur = *list;
        while (cur->next && cur->next->val < node->val)
            cur = cur->next;

        node->next = cur->next;
        cur->next = node;
    }

public:
    ListNode* insertionSortList(ListNode* head) 
    {
        if (!head)
            return NULL;

        ListNode *sorted = NULL;
        while (head != NULL)
        {
            ListNode *nextNode = head->next;
            head->next = NULL;
            sortedInsert(&sorted, head);

            std::cout << sorted->val << " root \n";
            head = nextNode;
        }

        return sorted;
    }

};
void printArray(ListNode* arr)
{
    for (; arr != NULL; arr = arr->next)
        std::cout << arr->val << " ";
    std::cout << std::endl;
}
int main()
{


    ListNode *list =NULL;
    list = new ListNode(0); list->val = 3;
    list->next = new ListNode(0); list->next->val = 2;
    list->next->next = new ListNode(0); list->next->next->val = -1;
    list->next->next->next = new ListNode(0); list->next->next->next->val = 4;
    list->next->next->next->next = new ListNode(0); list->next->next->next->next->val = -2;
    Solution so;
     ListNode *t = so.insertionSortList(list);
    printArray(t);

    return 0;
}
