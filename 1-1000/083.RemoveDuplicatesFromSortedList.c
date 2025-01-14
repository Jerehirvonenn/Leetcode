#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
	int				 val;
	struct ListNode *next;
};

struct ListNode *createNode(int val)
{
	struct ListNode *newNode =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

struct ListNode *insertNode(struct ListNode *head, int val)
{
	struct ListNode *newNode = createNode(val);
	if (!head)
		return newNode;
	struct ListNode *temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = newNode;
	return head;
}

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	struct ListNode *tmp = head;
	while (head && head->next)
	{
		if (head->val == head->next->val)
			head->next = head->next->next;
		else
			head = head->next;
	}
	return tmp;
}

void printList(struct ListNode *head)
{
	struct ListNode *temp = head;
	while (temp)
	{
		printf("%d -> ", temp->val);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Usage: ./a.out num1 num2 num3 ...\n");
		return 1;
	}
	struct ListNode *head = NULL;
	for (int i = 1; i < ac; i++)
	{
		int num = atoi(av[i]);
		head = insertNode(head, num);
	}
	printf("Original list: ");
	printList(head);
	head = deleteDuplicates(head);
	printf("List after removing duplicates: ");
	printList(head);

	struct ListNode *temp;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
