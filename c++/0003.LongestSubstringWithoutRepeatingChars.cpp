#include <iostream>

int pos[2] = {0};

class Solution
{
	public:
		int lengthOfLongestSubstring(std::string s)
	    {
			int left = 0;
	        int right = 0;
			int length = s.length();
        	int maxLen = 0;
        	int amount[255] = {0};
        	while (right < length)
        	{
            	amount[s[right]]++;
                while (amount[s[right]] > 1)
                {
					amount[s[left]]--;
                    left++;
                }
            	int size = right - left + 1;
            	if (size > maxLen) {
					pos[0] = left;
					pos[1] = right;
                	maxLen = size;
            	}
            	right++;
        	}
        	return maxLen;           
    	}
};

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Usage: ./a.out <String>\n";
		return 1;
	}

	std::string input = av[1];
	Solution solve;
	int result = solve.lengthOfLongestSubstring(input);
	std::cout << "Longest substring with no repetition is " << result << std::endl;
	std::cout << input.substr(0, pos[0]);
	std::cout << "\033[1;4;32m" << input.substr(pos[0], result) << "\033[0m";
	std::cout << input.substr(pos[1] + 1) << std::endl;
}
