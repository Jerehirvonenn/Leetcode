/*
 * Leetcode 23 - Merge k Sorted Lists (Hard)
 *
 * Problem:
 * You are given an array of k linked-lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 *
 * Approach:
 * - Use a min-heap (priority_queue with custom comparison struct) to track the smallest current node
 * - Push the head of each non-empty list into the heap
 * - At each step, pop the smallest node from the heap and add it to the result list
 * - Push the next node from the popped list if it exists
 *
 * Time Complexity: O(N log k), where N is total number of nodes, and k is the number of lists
 * Space Complexity: O(k) for the heap
 */

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        for (auto ptr : lists) {
            if (ptr)
                minHeap.push(ptr);
        }

        ListNode dummy(0);
        ListNode* current = &dummy;
        while (!minHeap.empty())
        {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            current->next = smallest;
            current = smallest;

            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        return dummy.next;
    }
};

//builds linked list out of vector
ListNode* buildList(const vector<int>& nums)
{
    ListNode dummy(0);
    ListNode* curr = &dummy;
    for (int val : nums) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return dummy.next;
}

//prints linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(void)
{
    Solution sol;
    int k;
    cout << "Enter number of lists: ";
    cin >> k;
    cin.ignore();

    vector<ListNode*> lists(k);
    for (int i = 0; i < k; ++i) {
        string line;
        cout << "Enter sorted integers for list " << i + 1 << " (space-separated): ";
        getline(cin, line);
        stringstream ss(line);
        vector<int> values;
        int val;
        while (ss >> val) values.push_back(val);
        lists[i] = buildList(values);
    }

    ListNode* result = sol.mergeKLists(lists);
    cout << "Merged list: ";
    printList(result);
}
