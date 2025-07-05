/*
 * Leetcode 876 - Middle of the Linked List (Easy)
 *
 * Problem:
 * Given the head of a singly linked list, return the middle node of the linked list.
 * If there are two middle nodes, return the second middle node.
 *
 * Approach:
 * - Use the fast and slow pointer technique:
 *   - Move 'slow' by one step and 'fast' by two steps in each iteration.
 *   - When 'fast' reaches the end of the list, 'slow' will be at the middle node.
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

ListNode* createLinkedList(const vector<int>& nums) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(void)
{
    Solution solution;
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    vector<int> values(n);
    cout << "Enter the node values: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    ListNode* head = createLinkedList(values);
    ListNode* middle = solution.middleNode(head);
    cout << "List starting from the middle:" << endl;
    printLinkedList(middle);
}
