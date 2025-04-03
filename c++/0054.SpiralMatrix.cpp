#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
    static vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int         rowLen = matrix.size();
        int         colLen = matrix[0].size();
        int         size = rowLen * colLen;
        vector<int> result(size);

        int row = 0;
        int col = 0;
        int current = 0;
        int level = 0;
        while (current < size) {
            while (current < size && col < colLen - level) {
                result[current++] = matrix[row][col++];
            }
            col--;
            row++;
            while (current < size && row < rowLen - level) {
                result[current++] = matrix[row++][col];
            }
            row--;
            col--;
            while (current < size && col >= level) {
                result[current++] = matrix[row][col--];
            }
            col++;
            row--;
            while (current < size && row >= level + 1) {
                result[current++] = matrix[row--][col];
            }
            row++;
            col++;
            level++;
        }
        return result;
    }
};

int main(void)
{
	vector<vector<int>> nums = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
	try
	{
		vector<int> result = Solution::spiralOrder(nums);
		cout << "Spiral: ";
		for (const auto num : result) {
			cout << num << " "; 
		}
		cout << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}
