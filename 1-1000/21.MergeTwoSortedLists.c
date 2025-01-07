#include <stdio.h>
#include <stdlib.h>

struct	ListNode
{
    int			val;
    struct ListNode*	next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1,struct ListNode *list2)
{
    struct ListNode    tmp;
    struct ListNode    *tail = &tmp;

    tmp.next = NULL;
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = (list1 != NULL) ? list1 : list2;
    return tmp.next;
}

struct ListNode* createNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head)
{
    while (head)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void)
{
    struct ListNode* l1 = createNode(1);
    l1->next = createNode(2);
    l1->next->next = createNode(4);

    struct ListNode* l2 = createNode(1);
    l2->next = createNode(3);
    l2->next->next = createNode(4);

    struct ListNode* mergedList = mergeTwoLists(l1, l2);

    printList(mergedList);
}
