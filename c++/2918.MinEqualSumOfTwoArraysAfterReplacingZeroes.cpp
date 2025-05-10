/*
 * Leetcode - 2918 Minimum Equal Sum of Two Arrays After Replacing Zeros (Medium)
 *
 * Problem:
 * You are given two arrays nums1 and nums2 consisting of positive integers.
 * You have to replace all the 0's in both arrays with strictly positive integers 
 * such that the sum of elements of both arrays becomes equal.
 * 
 * Return the minimum equal sum you can obtain, or -1 if it is impossible.
 *
 * Approach:
 * - For both arrays, calculate the sum assuming each 0 will be replaced by 1.
 * - Count the number of zeros in each array.
 * - If one array has a higher sum but the other has no zeros, return -1.
 * - Otherwise, the answer is the maximum of both  sums.
 *
 * Time Complexity: O(n + m), where n and m are the lengths of nums1 and nums2.
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2)
	{
        size_t zero1 = 0, zero2 = 0;
        long long sum1 = 0, sum2 = 0;

        for (const int num : nums1) {
            if (num == 0) {
                sum1 += 1;
                zero1++;
            } else {
                sum1 += num;
            }
        }

        for (const int num : nums2) {
            if (num == 0) {
                sum2 += 1;
                zero2++;
            } else {
                sum2 += num;
            }
        }

        if (sum1 > sum2 && zero2 == 0)
			return -1;
        if (sum2 > sum1 && zero1 == 0)
			return -1;
        return max(sum1, sum2);
    }
};

vector<int> parseInput(const string& input) {
    vector<int> nums;
    istringstream iss(input);
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }
    return nums;
}

int main(int ac, char **av)
{
    if (ac != 3) {
        cerr << "Usage: ./min_sum \"num1 num2 ...\" \"num1 num2 ...\"\n";
        return 1;
    }

    vector<int> nums1 = parseInput(av[1]);
    vector<int> nums2 = parseInput(av[2]);

    Solution sol;
    long long result = sol.minSum(nums1, nums2);
    cout << "Minimum equal sum: " << result << endl;
}
