#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
private:
    const int MOD = 1e9 + 7;

    long long expo(long long base, long long power)
	{
        long long result = 1;
        base %= MOD;

        while (power > 0) {
            if (power % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            power /= 2;
        }
        return result;
    }

public:
    int countGoodNumbers(long long n)
	{
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenWays = expo(5, even);
        long long oddWays = expo(4, odd);

        return (evenWays * oddWays) % MOD;
    }
};

int main(void)
{
    Solution sol;

    cout << "Running unit tests\n";

    assert(sol.countGoodNumbers(1) == 5);  // one digit, 0,2,4,6,8
    assert(sol.countGoodNumbers(2) == 20); // 5*4
    long long result = sol.countGoodNumbers(50); //5^25 * 4^25
    cout << "Result for n = 50: " << result << endl;
    result = sol.countGoodNumbers(1e18); // testing efficiency with big
    cout << "Result for n = 1e18: " << result << endl;
}
