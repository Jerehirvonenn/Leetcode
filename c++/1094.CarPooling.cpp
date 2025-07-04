/*
 * Leetcode 1094 - Car Pooling (Medium)
 *
 * Problem:
 * You are given an integer `capacity` and an array `trips` where
 * trips[i] = [numPassengersi, fromi, toi] indicates a trip from `fromi`
 * to `toi` carrying `numPassengersi` passengers.
 *
 * The car drives only east (i.e., increasing distance), and must never
 * exceed its seating `capacity` at any moment.
 *
 * Return true if all trips can be completed without exceeding capacity.
 *
 * Approach:
 * - Use a difference array (`in_out`) to mark passenger change at each point.
 * - At `from`, increment passengers; at `to`, decrement.
 * - Then perform a prefix sum to simulate passenger count as the car moves.
 * - If at any point the number of passengers exceeds capacity, return false.
 *
 * Time Complexity: O(N + D), where N = number of trips, D ≤ 1000 (max distance)
 * Space Complexity: O(D) for tracking passenger deltas at each location
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();

        vector<int> in_out(1001, 0);
        int biggest = 0;
        for (const auto trip : trips) {
            biggest = max(biggest, trip[1]);
            in_out[trip[1]] += trip[0];
            in_out[trip[2]] -= trip[0];
        }

        int passengers = 0;
        for (int i = 0; i <= biggest; i++) {
            passengers += in_out[i];
            if (passengers > capacity)
                return false;
        }
        return true;
    }
};

int main() {
	int capacity, n;
	cout << "Max capacity: ";
	cin >> capacity;
	cout << "Number of elements: ";
	cin >> n;

	cout << "Provide " << n << " Elements (passengers, from, to): ";
	vector<vector<int>> trips(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		cin >> trips[i][0] >> trips[i][1] >> trips[i][2];
	}

	Solution sol;
	cout << (sol.carPooling(trips, capacity) ? "true" : "false") << endl;
}
