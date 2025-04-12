#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> plusOne(vector<int>& digits)
    {
        int carry = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); it++)
		{
            if (*it + carry > 9) {
                *it = 0;
                carry = 1;
            }
            else {
                *it += carry;
                carry = 0;
				break;
            }
        }
        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	ac--;
	av++;
	try
	{
		int	target = 3;
		vector<int> nums;
		nums.reserve(ac);
		for (int i = 0; i < ac; i++) {
			int num = stoi(av[i]);
			if (num < 0 || num > 9) {
				throw runtime_error("Nums between 0 - 9");
			}
			nums.push_back(num);
		}
		Solution::plusOne(nums);
		cout << "Vector after: ";
		for (unsigned int i = 0; i < nums.size(); i++) {
			cout << nums[i];
		}
		cout << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}
