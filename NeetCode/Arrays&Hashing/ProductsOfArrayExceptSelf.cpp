#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> result(size, 1);

        for (int i = 1; i < size; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int total = nums[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            result[i] *= total;
            total *= nums[i];
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {1, 2, 4, 6};

    cout << "Input: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    vector<int> output = sol.productExceptSelf(nums);

    cout << "Output: ";
    for (int n : output) cout << n << " ";
    cout << endl;
}
