/*
 * Leetcode 1710 - Maximum Units on a Truck (Easy)
 *
 * Problem:
 * You are given a 2D vector `boxTypes`, where each element is [numberOfBoxes, unitsPerBox].
 * You're also given an integer `truckSize` which is the max number of boxes the truck can carry.
 * 
 * Goal:
 * - Load the truck with boxes to maximize the total number of units.
 * - You can select any type of box and as many as you like,
 *   as long as the total number of boxes ≤ truckSize.
 *
 * Approach:
 * - Sort box types in descending order based on units per box.
 * - Greedily take as many as possible from the most valuable (unit-wise) box types.
 *
 * Time Complexity: O(n log n) due to sorting.
 * Space Complexity: O(1) extra (in-place sorting).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool biggestBox(const vector<int> &a, const vector<int> &b) {
        return a[1] > b[1];
    }

public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
	{
        sort(boxTypes.begin(), boxTypes.end(), biggestBox);

        int result = 0;
        for (auto &boxes : boxTypes)
		{
            int add = min(truckSize, boxes[0]);
            result += add * boxes[1];
            truckSize -= add;
            if (truckSize <= 0)
                break;
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    int n, truckSize;
    cout << "Enter number of box types: ";
    cin >> n;

    vector<vector<int>> boxTypes(n, vector<int>(2));
    cout << "Enter box types as [numberOfBoxes unitsPerBox] per line:\n";
    for (int i = 0; i < n; ++i) {
        cin >> boxTypes[i][0] >> boxTypes[i][1];
    }

    cout << "Enter truck size: ";
    cin >> truckSize;

    int result = sol.maximumUnits(boxTypes, truckSize);
    cout << "Maximum units that can be loaded: " << result << endl;
}
