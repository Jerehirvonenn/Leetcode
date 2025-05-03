#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        int possible[2] = {tops[0], bottoms[0]};
        int result = INT_MAX;

        for (const int num : possible)
        {
            int currentTop = 0;
            int currentBot = 0;
            for (int i = 0; i < tops.size(); i++)
            {
                if (num == tops[i] && num == bottoms[i])
                    continue;
                else if (num == tops[i])
                    currentBot++;
                else if (num == bottoms[i])
                    currentTop++;
                else {
                    currentTop = -1;
                    currentBot = -1;
                    break;
                }
            }
            if (currentTop >= 0)
                result = min(result, currentTop);
            if (currentBot >= 0)
                result = min(result, currentBot);
        }
        return (result == INT_MAX ? -1 : result);
    }
};

int main(void)
{
	Solution solution;

    vector<vector<int>> testTops = {
        {2, 1, 2, 4, 2, 2},
        {3, 5, 1, 2, 3},
        {1, 2, 1, 1, 1, 2, 2, 2},
        {1, 2, 3, 4, 6},
        {1, 1, 1, 1, 1}
    };

    vector<vector<int>> testBottoms = {
        {5, 2, 6, 2, 3, 2},
        {3, 6, 3, 3, 4},
        {2, 1, 2, 2, 2, 1, 1, 1},
        {6, 5, 4, 3, 2},
        {1, 1, 1, 1, 1}
    };

    for (int i = 0; i < testTops.size(); i++) {
        int result = solution.minDominoRotations(testTops[i], testBottoms[i]);
        cout << "Test case " << i + 1 << ": ";
        cout << "Minimum rotations = " << result << endl;
    }
}
