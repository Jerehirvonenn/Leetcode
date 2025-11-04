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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *ptr = head;

        while (head && head->next) {
            ListNode *tmp = head->next;
            int newVal = gcd(head->val, tmp->val);
            head->next = new ListNode(newVal);
            head->next->next = tmp;
            head = tmp;
        }
        return ptr;
    }
};