class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int check = 0;
        if (ruleKey == "type")
            check = 0;
        else if (ruleKey == "color")
            check = 1;
        else
            check = 2;

        int result = 0;
        for (const auto &item : items) {
            if (item[check] == ruleValue)
                result++;
        }
        return result;
    }
};