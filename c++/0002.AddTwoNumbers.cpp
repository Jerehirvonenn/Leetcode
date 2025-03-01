#include <iostream>
#include <sstream>
#include <regex>

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
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
		{
			ListNode *head = new ListNode();
			ListNode *tail = head;

    	    int carry = 0;
    	    int value = 0;
			while (l1 || l2 || carry)
			{
				if (l1 && l2) {
					value = l1->val + l2->val + carry;
					l1 = l1->next;
					l2 = l2->next;
				} else if (l1) {
                	value = l1->val + carry;
                	l1 = l1->next;
				} else if (l2) {
                	value = l2->val + carry;
               	    l2 = l2->next;
				} else {
					value = carry;
				}
            	tail->next = new ListNode(value % 10);
           	 	carry = value / 10;

           		 tail = tail->next;
			}
			return head->next;
		}
};

void	addNode(ListNode *&head, std::string token)
{
	int value = stoi(token);
	if (!head) {
		head = new ListNode(value);
        return;
	}
	ListNode *tmp = head;
	while (tmp->next) {
		tmp = tmp->next;
	}
	tmp->next = new ListNode(value);
}

void	printList(ListNode *head)
{
	while (head) {
		std::cout << head->val << " -> ";
		head = head->next;
	}
	std::cout << "NULL\n";
}

void	freeList(ListNode *head)
{
	while (head)
	{
		ListNode *tmp = head;
		head = head->next;
		delete tmp;;
	}
}

bool	checkFormat(std::string input)
{
	std::regex pattern(R"(^\s*(\d\s+){1,}\|(\s+\d){1,}\s*$)");
	return std::regex_match(input, pattern);
}

int main(int ac, char **av)
{
	if (ac != 2 || !checkFormat(std::string(av[1])))
	{
		std::cout << "Usage: " << av[0] << " <num1> <num2>... | <num1> <num2>...\n"
			<< "Program expectes one string and 0 <= num <= 9\n";
		return 1;
	}

	ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;
	std::stringstream	ss(av[1]);
	std::string			token;
	bool				isSecond = false;
	try
	{
		while (ss >> token)
		{
			if (token == "|") {
				isSecond = true;
				continue;
			}
			if (!isSecond) {
				addNode(l1, token);
			} else {
				addNode(l2, token);
			}
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		freeList(l1);
		freeList(l2);
		return 2;
	}
	std::cout << "List1:  ";
	printList(l1);
	std::cout << "List2:  ";
	printList(l2);

	Solution solve;
	ListNode *result = solve.addTwoNumbers(l1, l2);
	std::cout << "Result: ";
	printList(result);

	freeList(l1);
	freeList(l2);
	freeList(result);
}
