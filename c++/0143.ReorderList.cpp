/*
 * Leetcode 143 - Reorder List (Medium)
 *
 * Problem:
 * Given the head of a singly linked list, reorder it as:
 * L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
 *
 * Constraints:
 * - You may not modify the values in the list's nodes.
 * - Only nodes themselves may be changed.
 *
 * Approach:
 * - Count the number of nodes.
 * - Use a queue to store the first half nodes.
 * - Use a stack to store the second half nodes.
 * - Interleave nodes from the queue and stack.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <queue>
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }
        int n = 0;
        ListNode* tmp = head;
        while (tmp) {
            n++;
            tmp = tmp->next;
        }

        queue<ListNode*> front;
        stack<ListNode*> back;
        int cur = 0;
        tmp = head;
        while (tmp) {
            if (cur++ < n / 2) {
                front.push(tmp);
            }
            else {
                back.push(tmp);
            }
            tmp = tmp->next;
        }

        ListNode* current = head;
        front.pop();
        while (!back.empty()) {
            current->next = back.top();
            back.pop();
            current = current->next;
            if (!front.empty()) {
                current->next = front.front();
                front.pop();
                current = current->next;
            }
        }
        current->next = nullptr;
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
    ListNode* head = new ListNode(1,
                      new ListNode(2,
                      new ListNode(3,
                      new ListNode(4,
                      new ListNode(5)))));

    Solution sol;
    cout << "Original list: ";
    printList(head);

    sol.reorderList(head);
    cout << "Reordered list: ";
    printList(head);
}
