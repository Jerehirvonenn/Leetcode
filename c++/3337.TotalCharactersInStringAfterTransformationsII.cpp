#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

class Solution {
private:
    static const int MOD = 1e9 + 7;
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        long long freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }
        while (t--) {
            long long delta[26] = {0};
            for (int i = 0; i < 26; ++i)
            {
                long long count = freq[i];
                if (count == 0 || nums[i] == 0)
                    continue;
                int start = (i + 1) % 26;
                int end = (i + nums[i] + 1) % 26;
                delta[start] = (delta[start] + count) % MOD;
                delta[end] = (delta[end] - count + MOD) % MOD;
                if (start > end) {
                    delta[0] = (delta[0] + count) % MOD;
                }
            }
            long long curr = 0;
            for (int i = 0; i < 26; ++i) {
                curr = (curr + delta[i]) % MOD;
                freq[i] = curr;
            }
        }
        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + freq[i]) % MOD;
        }
        return static_cast<int>(result);
    }
};

int main(void)
{
    string s = "abc";
    int t = 3;
    vector<int> nums(26, 1);
    nums[0] = 5;
	nums[1] = 3;
	nums[2] = 1;

    Solution sol;
    int result = sol.lengthAfterTransformations(s, t, nums);
    cout << "Final length after " << t << " transformations: " << result << endl;
}
