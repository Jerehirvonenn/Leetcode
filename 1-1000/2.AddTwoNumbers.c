#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *createNode(int value)
{
	struct ListNode *newNode = malloc(sizeof(struct ListNode));
	newNode->val = value;
	newNode->next = NULL;
	return newNode;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode dummy;
	struct ListNode *newNode = &dummy;

	dummy.next = NULL;
	int carry = 0;
	while (l1 != NULL || l2 != NULL || carry != 0)
	{
		int sum = carry;
		if (l1 != NULL)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		carry = sum / 10;
		newNode->next = createNode(sum % 10);
		newNode = newNode->next;
	}
	return dummy.next;
}

void printList(struct ListNode *head)
{
	while (head != NULL)
	{
		printf("%d", head->val);
		if (head->next != NULL)
			printf(" -> ");
		head = head->next;
	}
	printf("\n");
}

void freeList(struct ListNode *head)
{
	struct ListNode *temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main()
{
	struct ListNode *l1 = createNode(2);
	l1->next = createNode(4);
	l1->next->next = createNode(7);
	l1->next->next->next = createNode(9);
	l1->next->next->next->next = createNode(9);
	printf("List1: ");
	printList(l1);

	struct ListNode *l2 = createNode(5);
	l2->next = createNode(6);
	l2->next->next = createNode(4);
	printf("List2: ");
	printList(l2);

	struct ListNode *result = addTwoNumbers(l1, l2);

	printf("Sum  : ");
	printList(result);

	freeList(l1);
	freeList(l2);
	freeList(result);
}
