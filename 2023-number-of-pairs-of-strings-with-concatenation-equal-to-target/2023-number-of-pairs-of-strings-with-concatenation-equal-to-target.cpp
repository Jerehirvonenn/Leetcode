class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        unordered_map<string, int> seen;
        for (const string &s : nums) {
            seen[s]++;
        }

        int result = 0;
        for (const string &s : nums) {
            if (target.rfind(s, 0))
                continue ;
            string suffix = target.substr(s.size());
            if (seen.count(suffix)) {
                result += seen[suffix];
                if (s == suffix)
                    result--;
            }
        }
        return result;
    }
};