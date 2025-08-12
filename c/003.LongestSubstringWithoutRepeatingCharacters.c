#include <stdio.h>
#include <string.h>

#define HASHMAP_SIZE 95 // For characters 32 (space) to 126 (~)

typedef struct
{
	int lastIndex;
} HashMap;

void initHashMap(HashMap *map)
{
	for (int i = 0; i < HASHMAP_SIZE; i++)
		map[i].lastIndex = -1;
}

int getIndex(char c) { return c - 32; }

int lengthOfLongestSubstring(char *s)
{
	HashMap map[HASHMAP_SIZE];
	initHashMap(map);

	int maxlen = 0;
	int len = 0;
	int left = 0;
	int right = 0;
	while (s[right])
	{
		int index = getIndex(s[right]);
		if (map[index].lastIndex >= left)
			left = map[index].lastIndex + 1;
		else
			len++;
		map[index].lastIndex = right;
		len = right - left + 1;
		if (len > maxlen)
			maxlen = len;
		right++;
	}
	if (len > maxlen)
		maxlen = len;
	return maxlen;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	printf("Longest substring without duplicates is %d\n",
		   lengthOfLongestSubstring(av[1]));
}
