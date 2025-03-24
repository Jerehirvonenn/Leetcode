#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int				 val;
	struct ListNode *next;
};

int listLen(struct ListNode *head)
{
	int len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return len;
}

bool isPalindrome(struct ListNode *head)
{
	if (!head || !head->next)
		return true;
	int len = listLen(head);
	int middle;
	middle = (len / 2);
	int *stack = malloc(sizeof(int) * middle);
	if (!stack)
		return false;

	int i = 0;
	int index = -1;
	while (i++ < middle)
	{
		stack[++index] = head->val;
		head = head->next;
	}
	if (len % 2 == 1)
		head = head->next;
	while (head)
	{
		if (head->val != stack[index--])
		{
			free(stack);
			return false;
		}
		head = head->next;
	}
	free(stack);
	return true;
}

struct ListNode *createList(int ac, char **av)
{
	struct ListNode *head = malloc(sizeof(struct ListNode));
	if (!head)
		return NULL;
	head->val = atoi(av[0]);
	head->next = NULL;

	struct ListNode *current = head;
	for (int i = 1; i < ac; i++)
	{
		struct ListNode *newNode = malloc(sizeof(struct ListNode));
		if (!newNode)
			return NULL; // Memory allocation check
		newNode->val = atoi(av[i]);
		newNode->next = NULL;
		current->next = newNode;
		current = newNode;
	}
	return head;
}

void printList(struct ListNode *head)
{
	while (head)
	{
		printf("%d -> ", head->val);
		head = head->next;
	}
	printf("NULL\n");
}

void freeList(struct ListNode *head)
{
	while (head)
	{
		struct ListNode *temp = head;
		head = head->next;
		free(temp);
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Usage: %s <Node1> <Node2>...<NodeN>\n", av[0]);
		return 1;
	}
	ac--;
	av++;

	struct ListNode *root = createList(ac, av);

	printf("Linked List: ");
    printList(root);

	if (isPalindrome(root))
		printf("List is Palindrome\n");
	else
		printf("List is not Palindrome\n");

    freeList(root);
}
