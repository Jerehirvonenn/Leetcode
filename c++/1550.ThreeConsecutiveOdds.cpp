/*
 * Leetcode 1550 - Three Consecutive Odds (Easy)
 *
 * Problem:
 * Given an integer array arr, return true if there are three consecutive odd numbers in the array.
 * Otherwise, return false.
 *
 * Approach:
 * - Initialize a counter to track how many consecutive odd numbers we've seen.
 * - Loop through the array:
 *     - If the current number is odd, increment the counter.
 *     - If it's even, reset the counter to 0.
 *     - If the counter reaches 3 at any point, return true.
 * - If we finish the loop without finding three in a row, return false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr)
	{
        int res = 0;

        for (const int num : arr) {
            if (num % 2 == 1)
                res++;
            else
                res = 0;

            if (res == 3)
				return true;
        }
        return false;
    }
};

int main(int ac, char **av)
{
    if (ac < 2) {
        cout << "Usage: ./program_name num1 num2 num3 ..." << endl;
        return 1;
    }

    vector<int> arr;
    for (int i = 1; i < ac; ++i) {
        arr.push_back(stoi(av[i]));
    }

    Solution sol;
    bool result = sol.threeConsecutiveOdds(arr);
    cout << (result ? "true" : "false") << endl;
}
