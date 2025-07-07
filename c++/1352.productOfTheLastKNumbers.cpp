/*
 * Leetcode 1352 - Product of the Last K Numbers (Medium)
 *
 * Problem:
 * Design a class that supports two operations:
 * - `add(num)`: adds a number to the stream.
 * - `getProduct(k)`: returns the product of the last k numbers in the stream.
 *
 * If 0 appears in the stream, the product becomes 0 for any k covering it.
 *
 * Approach:
 * - Maintain a prefix product array, resetting on 0.
 * - On `getProduct(k)`, return prefix[n] / prefix[n - k], unless there was a reset.
 *
 * Time Complexity: O(1) for both operations
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ProductOfNumbers {
	private:
    vector<int> prefix;
    int size;
	public:
	ProductOfNumbers() {
        prefix.clear();
        prefix.push_back(1);
        size = 1;
    }
    
    void add(int num) {
        if (num)
            prefix.push_back(num * prefix[size++ - 1]);
        else {
            prefix.clear();
            prefix.push_back(1);
            size = 1;
        }
    }
    
    int getProduct(int k) {
        if (size <= k) {
            return 0;
        }
        else {
            return prefix[size - 1] / prefix[size - k - 1];
        }
    }
};

int main() {
    ProductOfNumbers pon;

    pon.add(3);
    pon.add(0);
    pon.add(2);
    pon.add(5);
    pon.add(4);

    cout << "getProduct(2): " << pon.getProduct(2) << endl; // 20
    cout << "getProduct(3): " << pon.getProduct(3) << endl; // 40
    cout << "getProduct(4): " << pon.getProduct(4) << endl; // 0
}
