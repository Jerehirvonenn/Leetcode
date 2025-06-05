/*
 * Leetcode 455 - Assign Cookies (Easy)
 *
 * Problem:
 * Each child has a greed factor g[i] (minimum size of cookie they need).
 * Each cookie has a size s[j].
 * You can assign at most one cookie per child.
 * A child i is content if s[j] >= g[i].
 * Maximize the number of content children.
 *
 * Approach:
 * - Sort both the greed and cookie arrays in descending order.
 * - Try to satisfy the greediest child with the biggest available cookie.
 * - If the cookie can satisfy the child, assign it and move to the next child and next cookie.
 * - Otherwise, move to the next child.
 *
 * Time Complexity: O(n log n + m log m) for sorting
 * Space Complexity: O(1) (in-place sorting)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool compare(const int a, const int b) {
        return a > b;
    }
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int cookieSize = s.size();
        if (cookieSize == 0) {
            return 0;
        }
        sort(g.begin(), g.end(), compare);
        sort(s.begin(), s.end(), compare);

        int current = 0;
        int result = 0;
        for (int i = 0; i < g.size(); i++) {
            if (g[i] <= s[current]) {
                result++;
                current++;
                if (current >= cookieSize) {
                    break;
                }
            }
        }
        return result;
    }
};

int main(void)
{
    int gSize, sSize;
    cout << "Enter number of children: ";
    cin >> gSize;
    vector<int> g(gSize);
    cout << "Enter greed factors: ";
    for (int i = 0; i < gSize; ++i) {
        cin >> g[i];
    }

    cout << "Enter number of cookies: ";
    cin >> sSize;
    vector<int> s(sSize);
    cout << "Enter cookie sizes: ";
    for (int i = 0; i < sSize; ++i) {
        cin >> s[i];
    }

    cout << "\nOriginal greed factors: ";
    for (int x : g) cout << x << " ";
    cout << "\nOriginal cookie sizes: ";
    for (int x : s) cout << x << " ";
    cout << "\n";

    Solution solution;
    int result = solution.findContentChildren(g, s);
    cout << "Number of content children: " << result << endl;
}
