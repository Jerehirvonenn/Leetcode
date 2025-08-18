/*
 * Leetcode 206 - Reverse Linked List (Easy)
 *
 * Problem:
 * Given the head of a singly linked list, reverse the list and return the reversed list.
 *
 * Approach:
 * Use a stack to store nodes, then pop them to reverse the list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        stack<ListNode*> stk;
        while (head) {
            stk.push(head);
            head = head->next;
        }

        ListNode *newHead = stk.top();
        stk.pop();
        ListNode *tmp = newHead;
        while (!stk.empty()) {
            tmp->next = stk.top();
            stk.pop();
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        return newHead;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}

int main() {
    // 1->2->3->4->5->nullptr
    ListNode *head = new ListNode(1,
                     new ListNode(2,
                     new ListNode(3,
                     new ListNode(4,
                     new ListNode(5)))));
    
    Solution sol;
    cout << "Original list: ";
    printList(head);

    ListNode* reversed = sol.reverseList(head);
    cout << "Reversed list: ";
    printList(reversed);
}
