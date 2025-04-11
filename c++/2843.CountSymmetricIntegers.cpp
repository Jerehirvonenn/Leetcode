#include <iostream>
#include <string>

using namespace std;

class Solution
{
	public:
    static int countSymmetricIntegers(int low, int high)
    {
        int result = 0;
        while (low <= high)
        {
            string num = to_string(low);
            if (num.length() % 2 != 0) {
                low++;
                continue;
            }
            int left = 0;
            int leftSum = 0;
            int right = num.length() - 1;
            int rightSum = 0;
            while (left < right) {
                leftSum += num[left++] - '0';
                rightSum += num[right--] - '0';
            }
            if (leftSum == rightSum) {
                result++;
            }
            low++;
        }
        return result;
    }
};

int main(int ac, char **av)
{
    if (ac != 3) {
        cerr << "Usage: " << av[0] << " <low> <high>" << endl;
        return 1;
    }
    int low = stoi(av[1]);
    int high = stoi(av[2]);

    int result = Solution::countSymmetricIntegers(low, high);
    cout << "Count of symmetric integers between " << low << " and " << high << ": " << result << endl;
}
