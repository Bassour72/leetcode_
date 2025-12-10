#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

  struct ListNode  //
  {
      int val;
      ListNode *next;
     
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution 
{
    ListNode* addnode(int number)
    {
        ListNode* new_node;
        new_node = new ListNode;
        new_node->val = number;
        new_node->next = NULL;
        return new_node;
    }
    void addfornt( ListNode** oldlist, ListNode* new_list)
    {
        if (!*oldlist)
        {
            *oldlist = new_list;
        }
        else
        {
            new_list->next = *oldlist;
            *oldlist = new_list;
        }
    }
public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* temp = NULL;
        int number = 0;
        int sum = 0;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int number = carry; // start with carry from previous step
            if (l1) 
            {
                number += l1->val; 
                l1 = l1->next; 
            }
            if (l2) 
            { 
                number += l2->val; 
                 l2 = l2->next; 
            }
            carry = number / 10;
            addfornt(&temp, addnode(number % 10));
        }

        return (temp);
    }
};

