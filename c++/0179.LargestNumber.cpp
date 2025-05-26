/*
 * Leetcode 179 - Largest Number (Medium)
 *
 * Problem:
 * Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
 * Since the result may be very large, return it as a string rather than an integer.
 *
 * Approach:
 * - Convert all numbers to strings.
 * - Sort the strings using a custom comparator:
 *   - For two strings a and b, compare a + b vs b + a.
 *   - If a + b > b + a, a should come before b.
 * - If the largest element after sorting is "0", the answer is "0".
 * - Concatenate all strings to form the result.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        int size = nums.size();
        vector<string> input;
        input.reserve(size);
        
        for (const int num : nums) {
            input.push_back(to_string(num));
        }

        sort(input.begin(), input.end(), [](const string &a, const string &b) {
            return (a + b) > (b + a);
        });

        if (!input.empty() && input[0] == "0") {
            return "0";
        }

        string result;
        for (const string &str : input) {
            result += str;
        }
        return result;
    }
};

int main(void)
{
    vector<int> nums;
    int x;

    cout << "Enter numbers (non-negative integers), terminated by any non-integer input:\n";
    while (cin >> x) {
        nums.push_back(x);
    }

    Solution sol;
    string result = sol.largestNumber(nums);
    cout << "Largest Number: " << result << endl;
}
