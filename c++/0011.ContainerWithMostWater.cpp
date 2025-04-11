#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
	public:
    int maxArea(vector<int>& height)
    {
        int left = 0;
        int right = height.size() - 1;
        int biggest = 0;
        while (left < right)
        {
            int current = min(height[left], height[right]) * (right - left);
            biggest = max(current, biggest);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return biggest;
    }
};

int main(int ac, char **av)
{
	if (ac < 3) {
        cout<< "Usage: " << av[0] << " num1 num2 num3 ..." << endl;
        return 1;
    }

    vector<int> height;
    for (int i = 1; i < ac; ++i)
		height.push_back(stoi(av[i]));

    Solution solve;
    int result = solve.maxArea(height);
    cout << "Max area: " << result << endl;
}
