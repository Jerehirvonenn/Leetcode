/*
 * Leetcode 2130 - Maximum Twin Sum of a Linked List (Medium)
 *
 * Problem:
 * In a linked list of size n (where n is even), the ith node (0-indexed) is the twin of the (n - 1 - i)th node.
 * The twin sum of a node is defined as the sum of the node's value and its twin's value.
 * 
 * Given the head of a linked list with even length, return the maximum twin sum of the linked list.
 *
 * Approach:
 * - Use the fast and slow pointer technique to find the middle of the linked list.
 * - Push the second half of the list onto a stack to reverse it.
 * - Traverse from the head and pop from the stack to compute twin sums.
 * - Track the maximum twin sum encountered.
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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        stack<ListNode*> stk;
        while (slow) {
            stk.push(slow);
            slow = slow->next;
        }

        int biggest = 0;
        while (!stk.empty()) {
            int sum = head->val + stk.top()->val;
            stk.pop();
            head = head->next;
            biggest = max(biggest, sum);
        }
        return biggest;
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

int main(void)
{
    Solution solution;
    int n;
    cout << "Enter the number of nodes (even number): ";
    cin >> n;

    vector<int> values(n);
    cout << "Enter the node values: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    ListNode* head = createLinkedList(values);
    int maxTwinSum = solution.pairSum(head);
    cout << "Maximum twin sum of the linked list: " << maxTwinSum << endl;
}
