#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int numberOfAlternatingGroups(vector<int>& colors, int k)
    {
		int size = colors.size();
		if (size < k) {
            return 0;
        }
        
        int result = 0;
        int i = 0;
        while (i < size)
        {
            int j = 0;
            int prev = -1;
            bool isValid = true;
            
            while (j < k)
            {
                int current = colors[(i + j) % size];
                if (current == prev) {
                    i += j - 1;
                    isValid = false;
                    break;
                }
                prev = current;
                j++;
            }
            if (isValid)
            {
                result++;
                while (i < size - 1 && colors[(i + j) % size] != prev) {
                    ++result;
                    prev = colors[(i + j) % size];
					i++;
                }
            }
            i++;
        }
        return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	ac--;
	av++;

	int len = 3;
	vector<int> input;
	for (int i = 0; i < ac; i++) {
		input.push_back(atoi(av[i]));
	}

	int result = Solution::numberOfAlternatingGroups(input, len);
	cout << result << endl;
}
