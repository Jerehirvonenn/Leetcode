#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int				 val;
	struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
	if (!head)
		return NULL;
	if (k == 0)
		return head;

	struct ListNode *tail = head;
	int				 len = 1;
	while (tail->next)
	{
		tail = tail->next;
		len++;
	}

	if (len == 1 || k % len == 0)
		return head;

	tail->next = head;
	int toMove = k % len;
	toMove = len - toMove;
	while (toMove)
	{
		tail = head;
		head = head->next;
		toMove--;
	}
	tail->next = NULL;
	return head;
}

// create linked list of size N
struct ListNode *createList(int n)
{
	if (n <= 0)
		return NULL;
	struct ListNode *head = malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = NULL;

	struct ListNode *current = head;
	for (int i = 2; i <= n; i++)
	{
		current->next = malloc(sizeof(struct ListNode));
		current = current->next;
		current->val = i;
		current->next = NULL;
	}
	return head;
}

void printList(struct ListNode *head)
{
	struct ListNode *current = head;
	while (current)
	{
		printf("%d -> ", current->val);
		current = current->next;
	}
	printf("NULL\n");
}

void freeList(struct ListNode *head)
{
	struct ListNode *temp;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: %s <ListSize> <Rotations>\n", argv[0]);
		return 1;
	}

	// init list and size based on command line args
	int k = atoi(argv[2]);
	int listSize = atoi(argv[1]);

	// Create and print the original list
	struct ListNode *head = createList(listSize);
	printf("Original list:\n");
	printList(head);

	// Rotate the list and print the result
	head = rotateRight(head, k);
	printf("Rotated list by %d steps:\n", k);
	printList(head);

	// free memory
	freeList(head);
}
