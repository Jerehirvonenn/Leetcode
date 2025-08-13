/*
 * Leetcode 82 - Remove Duplicates from Sorted List II (Medium)
 *
 * Problem:
 * Given the head of a sorted linked list, delete all nodes that have duplicates,
 * leaving only distinct numbers from the original list.
 *
 * Approach:
 * - Use a dummy node to handle edge cases.
 * - Traverse the list with two pointers:
 *   - `potential`: current node candidate to keep.
 *   - `check`: moves ahead to check duplicates.
 * - If duplicates found, skip all duplicates.
 * - If no duplicates, link `potential` to the result list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode dummy(0);
        ListNode* current = &dummy;
        ListNode* potential = head;
        ListNode* check;
        while (potential) {
            int same = 0;
            check = potential->next;
            while (check) {
                if (check->val != potential->val)
                    break;
                check = check->next;
                same++;
            }
            if (!same) {
                current->next = potential;
                current = current->next;
            }
            potential = check;
        }
        current->next = nullptr;
        return dummy.next;
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
    // 1->2->3->3->4->4->5
    ListNode* head = new ListNode(1,
                      new ListNode(2,
                      new ListNode(3,
                      new ListNode(3,
                      new ListNode(4,
                      new ListNode(4,
                      new ListNode(5)))))));

    Solution sol;
    cout << "Original list: ";
    printList(head);

    ListNode* newHead = sol.deleteDuplicates(head);
    cout << "After removing duplicates: ";
    printList(newHead);
}
