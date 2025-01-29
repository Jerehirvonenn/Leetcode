#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int				 val;
	struct ListNode *next;
};

struct ListNode *createNode(int value)
{
	struct ListNode *newNode =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->val = value;
	newNode->next = NULL;
	return newNode;
}

struct ListNode *buildLinkedListFromArgs(int argc, char *argv[])
{
	if (argc < 2)
	{
		return NULL;
	}

	struct ListNode *head = createNode(atoi(argv[1]));
	struct ListNode *tmp = head;

	for (int i = 2; i < argc; i++)
	{
		tmp->next = createNode(atoi(argv[i]));
		tmp = tmp->next;
	}

	return head;
}

void printList(struct ListNode *head)
{
	struct ListNode *tmp = head;
	while (tmp != NULL)
	{
		printf("%d -> ", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

struct ListNode *swapPairs(struct ListNode *head)
{
	if (!head || !head->next)
		return head;

	struct ListNode *tmp = head;
	struct ListNode *prev = NULL;
	head = head->next;
	while (tmp && tmp->next)
	{
		struct ListNode *first = tmp;
		struct ListNode *second = tmp->next;
		if (prev)
			prev->next = second;
		first->next = second->next;
		second->next = first;
		prev = first;
		tmp = first->next;
	}
	return head;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Please provide numbers as command line arguments.\n");
		return 1;
	}

	struct ListNode *head = buildLinkedListFromArgs(argc, argv);
	printf("Original List: ");
	printList(head);

	head = swapPairs(head);

	printf("List after swapping pairs: ");
	printList(head);

	struct ListNode *tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
