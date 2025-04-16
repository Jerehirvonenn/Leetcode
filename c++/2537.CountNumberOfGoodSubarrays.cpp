#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
    static long long countGood(vector<int>& nums, int k)
    {
		long long result = 0;
        unordered_map<int, int> seen;

        int size = nums.size();
        int left = 0;
        int pairs = 0;
        for (int right = 0; right < size; right++)
        {
            int current = nums[right];
            if (++seen[current] > 1)
                pairs += seen[current] - 1;
            while (pairs >= k && left <= right)
            {
                current = nums[left];
                result += size - right;
                if (--seen[current] >= 1)
                    pairs -= seen[current];
                left++;
            }
        }
        return result;
    }
};

int main(int ac, char **av)
{
    if (ac < 3) {
        cerr << "Usage: " << av[0] << " <num1> <num2> ... <k>" << endl;
        return 1;
    }

    vector<int> nums;
    for (int i = 1; i < ac - 1; ++i)
        nums.push_back(atoi(av[i]));
    int k = atoi(av[ac - 1]);

    long long result = Solution::countGood(nums, k);
    cout << "Count of good subarrays: " << result << endl;
}
