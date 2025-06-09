#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int check = 1;
        int planted = 0;
        for (const int current : flowerbed)
        {
            if (current == 1)
                check = 0;
            else
			{
                check++;
                if (check == 3) {
                    planted++;
                    check = 1;
                }
            }
        }
        if (check >= 2)
            planted++;
        return planted >= n;
    }
};

int main(int ac, char **av)
{
    if (ac < 3) {
        cout << "Usage: " << av[0] << " flowerbed... n\n";
        return 1;
    }

    vector<int> flowerbed;
    for (int i = 1; i < ac - 1; ++i) {
        flowerbed.push_back(atoi(av[i]));
    }
    int n = atoi(av[ac - 1]);

    bool result = Solution::canPlaceFlowers(flowerbed, n);
    cout << (result ? "Yes, you can plant the flowers." : "No, you can't plant that many.") << endl;
}
