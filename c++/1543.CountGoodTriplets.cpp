#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

class Solution
{
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c)
    {
        int size = arr.size();
        int result = 0;

        for (int i = 0; i < size - 2; i++)
        {
            for (int j = i + 1; j < size - 1; j++)
            {
                if (abs(arr[i] - arr[j]) > a)
                    continue;
                for (int k = j + 1; k < size; k++)
                {
                    if (abs(arr[j] - arr[k]) > b || abs(arr[i] - arr[k]) > c)
                        continue;
                    result++;
                }
            }
        }
        return result;  
    }
};

int main(void)
{
    Solution sol;

    cout << "Running test cases...\n";

    vector<int> arr1 = {3, 0, 1, 1, 9, 7};
    assert(sol.countGoodTriplets(arr1, 7, 2, 3) == 4);

    vector<int> arr2 = {1, 1, 2, 2, 3};
    assert(sol.countGoodTriplets(arr2, 0, 0, 1) == 0);

    vector<int> arr3 = {1, 2, 3, 4};
    assert(sol.countGoodTriplets(arr3, 3, 3, 3) == 4);

    cout << "All tests passed!" << endl;
}
