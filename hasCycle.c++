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
// class Solution {
// public:
//     static bool hasCycle(ListNode *head) 
//     {
//         std::vector<int>::iterator  it;
//         std::set<ListNode *> vec;
//         while (head != NULL)
//         {
//             if(vec.find(head) != vec.end())
//                  return (true);
//             vec.insert(head);
//             head = head->next;
//         }
//         return (false);
//     }
// };
class Solution {
public:
    static bool hasCycle(ListNode *head) {
        ListNode* goSlow = head;
        ListNode* goFast = head;
        while(goFast && goFast->next)
        {
            goSlow = goSlow->next;
            goFast = goFast->next->next;
            if(goFast == goSlow) return true;
        }
        
        return false;

    }
};
int main(void)
{
    ListNode Node3(3);
    ListNode Node2(2);
    ListNode Node0(0);
    ListNode Node4n(-4);
    Node4n.next = NULL;
    // ListNode Node5(3);
    // ListNode Node6(3);
    ListNode *head;
    head = &Node3;
    head->next = &Node2;
    head->next->next = &Node0;
    head->next->next->next = &Node4n;
    // head->next->next->next->next = &Node2;
    std::cout << "\n\n" << Solution::hasCycle(head) << " \n";

//===========//
// ListNode Node1(-21);
// ListNode Node2(10);
// ListNode Node3(17);
// ListNode Node4(8);
// ListNode Node5(4);
// ListNode Node6(26);
// ListNode Node7(5);
// ListNode Node8(35);
// ListNode Node9(33);
// ListNode Node10(-7);
// ListNode Node11(-16);
// ListNode Node12(27);
// ListNode Node13(-12);
// ListNode Node14(6);
// ListNode Node15(29);
// ListNode Node16(-12);
// ListNode Node17(5);
// ListNode Node18(9);
// ListNode Node19(20);
// ListNode Node20(14);
// ListNode Node21(14);
// ListNode Node22(2);
// ListNode Node23(13);
// ListNode Node24(-24);
// ListNode Node25(21);
// ListNode Node26(23);
// ListNode Node27(-21);
// ListNode Node28(5);

// ListNode* head = &Node1;
// head->next = &Node2;
// Node2.next = &Node3;
// Node3.next = &Node4;
// Node4.next = &Node5;
// Node5.next = &Node6;
// Node6.next = &Node7;
// Node7.next = &Node8;
// Node8.next = &Node9;
// Node9.next = &Node10;
// Node10.next = &Node11;
// Node11.next = &Node12;
// Node12.next = &Node13;
// Node13.next = &Node14;
// Node14.next = &Node15;
// Node15.next = &Node16;
// Node16.next = &Node17;
// Node17.next = &Node18;
// Node18.next = &Node19;
// Node19.next = &Node20;
// Node20.next = &Node21;
// Node21.next = &Node22;
// Node22.next = &Node23;
// Node23.next = &Node24;
// Node24.next = &Node25;
// Node25.next = &Node26;
// Node26.next = &Node27;
// Node27.next = &Node28;
// Node28.next = NULL;
}