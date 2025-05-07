/*
 * Leetcode 118 - Pascal's Triangle (Easy)
 *
 * Problem:
 * Given an integer numRows, return the first numRows of Pascal's triangle
 * In Pascal's triangle, each number is the sum of the two numbers directly above it,
 *
 *       1
 *      1 1
 *     1 2 1
 *    1 3 3 1
 *   1 4 6 4 1
 *
 * Approach:
 * - For each row, initialize a vector with size i + 1 (all elements set to 1)
 * - For rows greater than the first row, iterate through each element (except the first and last),
 *   and set the value to the sum of the two numbers directly above it from the previous row
 *       result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
 *
 * Time Complexity: O(numRows^2)
 * Space Complexity: O(numRows^2)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows)
	{
        vector<vector<int>> result; 
        result.reserve(numRows);     
        for (int i = 0; i < numRows; i++) {
            vector<int> tmp(i + 1, 1);  
            
            for (int j = 1; j < i; j++) {
                tmp[j] = result[i - 1][j - 1] + result[i - 1][j];  
            }
            result.push_back(tmp);  
        }
        return result;  
    }
};

int main(void)
{
    Solution solution;  
    int numRows;
    
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;
    
    vector<vector<int>> triangle = solution.generate(numRows); 
    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";  
        }
        cout << endl;  
    }
}
