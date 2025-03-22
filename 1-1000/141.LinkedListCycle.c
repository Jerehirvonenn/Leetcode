#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int				 val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
	if (!head)
		return false;
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}

struct ListNode *createNode(int val)
{
	struct ListNode *newNode =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

void freeList(struct ListNode *head, int hasCycle)
{
	if (!hasCycle)
	{
		while (head)
		{
			struct ListNode *temp = head;
			head = head->next;
			free(temp);
		}
	}
}

int main()
{
	// List with a cycle
	struct ListNode node1 = {1, NULL};
	struct ListNode node2 = {2, NULL};
	struct ListNode node3 = {3, NULL};

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node2;

	printf("Test Case 1: %s\n",
		   hasCycle(&node1) ? "Cycle Detected" : "No Cycle");

	// List without a cycle
	struct ListNode node4 = {4, NULL};
	struct ListNode node5 = {5, NULL};
	struct ListNode node6 = {6, NULL};

	node4.next = &node5;
	node5.next = &node6;
	node6.next = NULL;

	printf("Test Case 2: %s\n",
		   hasCycle(&node4) ? "Cycle Detected" : "No Cycle");

	// Empty list
	struct ListNode *head3 = NULL;
	printf("Test Case 3: %s\n",
		   hasCycle(head3) ? "Cycle Detected" : "No Cycle");
}
