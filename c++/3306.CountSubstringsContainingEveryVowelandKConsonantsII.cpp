#include <iostream>

using namespace std;

class Solution {
private:
	static bool	checkVowels(unordered_map<char, int> &vowel)
	{
		return vowel['a'] >= 1 && vowel['e'] >= 1 && 
           vowel['i'] >= 1 && vowel['o'] >= 1 && vowel['u'] >= 1;
	}

	static int	howManyTrailingVocals(string word, int pos)
	{
		int result = 0;
		if (pos >= word.size())
			return 0;

		while (word[pos] == 'a' || word[pos] == 'e' || word[pos] == 'i' ||
			word[pos] == 'o' || word[pos] == 'u') {
			result++;
			pos++;
		}
		return result;
	}
public:
    static long long countOfSubstrings(string word, int k)
	{
		unordered_map<char, int>	vowel;
		long long					result = 0;
		unsigned int				size = word.size();
		int							consonant = 0;

		int left  = 0;
		for (unsigned int right = 0; right < size; right++)
		{
			if (word[right] == 'a' || word[right] == 'e' || word[right] == 'i' ||
				word[right] == 'o' || word[right] == 'u') {
				vowel[word[right]]++;
			}
			else {
				consonant++;
			}

			while (consonant > k)
			{
				if (word[left] == 'a' || word[left] == 'e' || word[left] == 'i' ||
				word[left] == 'o' || word[left] == 'u') {
					vowel[word[left]]--;
				}
				else {
					consonant--;
				}
				left++;
			}

			while (consonant == k && checkVowels(vowel)) {
				result += 1 + howManyTrailingVocals(word, right + 1);
				if (word[left] == 'a' || word[left] == 'e' || word[left] == 'i' ||
				word[left] == 'o' || word[left] == 'u') {
					vowel[word[left]]--;
				}
				else {
					consonant--;
				}
				left++;
			}
		}
		return result;
    }
};

int main(int ac, char **av) 
{
	if (ac < 3)
		return 1;

	string	input = av[1];
	int		k = atoi(av[2]);

	long long result = Solution::countOfSubstrings(input, k);
	cout << result << endl;
}
