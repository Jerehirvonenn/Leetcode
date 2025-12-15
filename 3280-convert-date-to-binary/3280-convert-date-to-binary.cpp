class Solution {
private:
    string strToBinary(int num) {
        if (num == 0)
            return "0";
        string result;

        while (num > 0) {
            int digit = num % 2;
            result += digit + '0';
            num /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
public:
    string convertDateToBinary(string date) {
        string result;

        result += strToBinary(stoi(date.substr(0, 4)));
        result += "-";
        result += strToBinary(stoi(date.substr(5, 2)));
        result += "-";
        result += strToBinary(stoi(date.substr(8, 2)));

        return result;
    }
};