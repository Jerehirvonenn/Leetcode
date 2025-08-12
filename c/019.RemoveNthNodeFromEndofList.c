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

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	if (!head)
		return NULL;
	int				 len = 0;
	struct ListNode *tmp = head;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	if (len < n || n == 0)
		return head;
	tmp = head;
	if (n == len)
	{
		head = head->next;
		free(tmp);
		return head;
	}
	for (int i = 0; i < len - n - 1; i++)
		tmp = tmp->next;
	struct ListNode *delete = tmp->next;
	tmp->next = tmp->next->next;
	free(delete);
	return head;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	struct ListNode *head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);

	printf("Original List: ");
	printList(head);

	int n = atoi(av[1]);
	head = removeNthFromEnd(head, n);

	printf("Modified List after removing %dth node from the end: ", n);
	printList(head);

	while (head != NULL)
	{
		struct ListNode *temp = head;
		head = head->next;
		free(temp);
	}
}
