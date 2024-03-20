/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * left ;
        ListNode * right;
        ListNode * prev;
        ListNode * temp = list1;
        int count=0;
        
        while(temp != NULL)
        {
            if(count == a-1)
            {
                left = temp;
            }
            if(count == b)
            {
                prev = temp;
                right = temp->next;
                break;
            }
            temp = temp->next;
            count++;
        }
        
        left->next = list2;
        temp = list1;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = right;
        prev->next = NULL;
        return list1;
    }
};