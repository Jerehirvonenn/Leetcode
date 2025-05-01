#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int i = m - 1;
		int j = n - 1;
		int k = nums1.size() - 1;

		while (i >= 0 || j >= 0)
		{
			if (i >= 0 && j >= 0) {
				if (nums1[i] > nums2[j])
					nums1[k--] = nums1[i--];
				else
					nums1[k--] = nums2[j--];
			}
			else if (i >= 0)
					nums1[k--] = nums1[i--];
			else
					nums1[k--] = nums2[j--];
		}
    }
};

void	captureData(char *str, vector<int> &nums1, vector<int> &nums2)
{
	stringstream	ss(str);
	string			token;

	bool	isSecond = false;
	while (ss >> token)
	{
		if (token == "|")
			isSecond = true;
		else if (!isSecond)
			nums1.push_back(stoi(token));
		else
			nums2.push_back(stoi(token));
	}
}

void	printVector(vector<int> &nums, string msg)
{
	cout << msg;
	for (const int &num : nums) {
		cout << num << " -> ";
	}
	cout << "NULL" << endl;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	try
	{
		vector<int> nums1;
		vector<int> nums2;
		captureData(av[1], nums1, nums2);
		int nums1Size = nums1.size();
		int nums2Size = nums2.size();
		nums1.resize(nums1Size + nums2Size);
		printVector(nums1, "Vector 1: ");
		printVector(nums2, "Vector 2: ");

		Solution::merge(nums1, nums1Size, nums2, nums2Size);

		printVector(nums1, "Vector 1: ");
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}
