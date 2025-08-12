#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
	int				 val;
	struct ListNode *next;
};

struct ListNode* createNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void	free_list(struct ListNode *head, struct ListNode *stop)
{
	struct ListNode *tmp;
	while (head && head != stop)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int list_size(struct ListNode *root)
{
	int size = 0;
	while (root)
	{
		size++;
		root = root->next;
	}
	return size;
}

struct ListNode *getIntersectionNode(struct ListNode *headA,
									 struct ListNode *headB)
{
	if (!headA || !headB)
	{
		return NULL;
	}
	int lenA = list_size(headA);
	int lenB = list_size(headB);
	while (lenA > lenB)
	{
		headA = headA->next;
		lenA--;
	}
	while (lenA < lenB)
	{
		headB = headB->next;
		lenB--;
	}
	while (headA && headB)
	{
		if (headA == headB)
			return headA;
		headA = headA->next;
		headB = headB->next;
	}
	return NULL;
}

void printList(struct ListNode* head)
{
    struct ListNode* temp = head;
    while (temp)
    {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void)
{
	//start of a
	struct ListNode* listA = createNode(4);
	listA->next  = createNode(1);

	//start of b
	struct ListNode* listB = createNode(5);
	listB->next  = createNode(6);
	listB->next->next  = createNode(1);

	//intersection node
	struct ListNode* intersection = createNode(8);
	listA->next->next = intersection;
	listB->next->next->next  = intersection;

	//tail
	intersection->next = createNode(4);
	intersection->next->next = createNode(5);

	printList(listA);
	printList(listB);
	struct ListNode *result = getIntersectionNode(listA, listB);
	if (result)
		printf("Intersection found on Node with val of %d\n", result->val);
	else
		printf("Intersection not found\n");
	free_list(listA, NULL);
	free_list(listB, result);
}
