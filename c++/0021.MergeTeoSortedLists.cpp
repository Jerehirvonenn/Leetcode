#include <iostream>
#include <sstream>

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
		static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
		{
			ListNode *dummy = new ListNode(0);
			ListNode *current = dummy;
			while (list1 && list2)
			{
				if (list1->val < list2->val) {
					current->next = list1;
					list1 = list1->next;
				}
				else {
					current->next = list2;
					list2 = list2->next;
				}
				current = current->next;
			}
			if (list1) {
				current->next = list1;
			}
			else if (list2) {
				current->next = list2;
			}
			current = dummy->next;
			delete dummy;
			return current;
		}
};

void	createLists(ListNode *&l1, ListNode *&l2, char *input)
{
	std::stringstream	ss(input);
	std::string		token;
	ListNode		*current = l1;

	while (ss >> token)
	{
		if (token == "|") {
			current = l2;
			continue;
		}
		current->next = new ListNode(stoi(token));
		current = current->next; 
	}
}

void	freeList(ListNode *&head)
{
	ListNode *tmp = head;
	while (head)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
	head = nullptr;
}

void	printList(ListNode *head, std::string message)
{
	std::cout << message;
	while (head)
	{
		std::cout << head->val << " -> ";
		head = head->next;
	}
	std::cout << "NULL" << std::endl;
}

int		main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	ListNode *l1 = new ListNode(0);
	ListNode *l2 = new ListNode(0);
	createLists(l1, l2, av[1]);

	printList(l1->next, "List 1: ");
	printList(l2->next, "List 2: ");
	ListNode *result = Solution::mergeTwoLists(l1->next, l2->next);
	printList(result, "Merged: ");

	delete l1;
	delete l2;
	freeList(result);
}
