class Solution {
private:
    void    createString(vector<string> &result, string current, char last, int n) {
        if (current.size() == n) {
            result.push_back(current);
            return ;
        }
        if (last == '1') {
            createString(result, current + "1", '1', n);
            createString(result, current + "0", '0', n);
        } else {
            createString(result, current + '1', '1', n);
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        createString(result, "", '1', n);
        return result;
    }
};