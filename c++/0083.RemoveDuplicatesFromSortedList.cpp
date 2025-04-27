#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    static ListNode* deleteDuplicates(ListNode* head)
	{
		if (!head || !head->next) {
			return head;
		}
		ListNode *dummy = new ListNode(101);
		ListNode *real = dummy;

		while (head)
		{
			if (head->val == real->val) {
				ListNode *tmp = head->next;
				delete head;
				head = tmp;
			}
			else {
				real->next = head;
				real = real->next;
				head = head->next;
			}
		}
		real->next = nullptr;
		real = dummy->next;
		delete dummy;
		return real;
    }
};

void	printList(ListNode *head)
{
	while (head)
	{
		std::cout << head->val;
		std::cout << " -> ";
		head = head->next;
	}
	std::cout << "NULL\n";
}

void	freeList(ListNode *head)
{
	ListNode *tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	ac--;
	av++;

	ListNode *head = nullptr;
	try
	{
		head = new ListNode(atoi(av[0]));
		ListNode *tmp = head;
		for (int i = 1; i < ac; i++) {
			tmp->next = new ListNode(atoi(av[i]));
			tmp = tmp->next;
		}
		std::cout << "Original List: ";
		printList(head);

		head = Solution::deleteDuplicates(head);
		std::cout << "List atfer   : ";
		printList(head);

		freeList(head);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
