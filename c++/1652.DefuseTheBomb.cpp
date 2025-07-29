/*
1652. Defuse the Bomb
---------------------
You are given a circular array 'code' and an integer 'k'. You must decrypt it as follows:

- If k > 0: Replace each element with the sum of the next k elements (wrapping around circularly).
- If k < 0: Replace each element with the sum of the previous k elements (again, circularly).
- If k == 0: Replace each element with 0.

Approach:
- Use a helper function to safely access circular indices.
- Use a sliding window approach to maintain the sum of k elements as we shift across the array.
- Maintain performance by not recalculating the entire sum at each step.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int circIndex(int i, int n) {
        return (i % n + n) % n;
    }
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int size = code.size();
        vector<int> result(size, 0);
        if (k == 0) {
            return result;
        }

        int direction = k > 0 ? 1 : -1;
        int sum = 0;
        for (int i = 1; i <= abs(k); i++) {
            int index = circIndex(i * direction, size);
            sum += code[index];
        }
        for (int i = 0; i < size; i++) {
            result[i] = sum;
            if (k > 0) {
                sum -= code[circIndex(i + 1, size)];
                sum += code[circIndex(i + k + 1, size)];
            }
            else {
                sum -= code[circIndex(i + k, size)];
                sum += code[i];
            }
        }
        return result;
    }
};

int main(void)
{
    int n;
	int k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> code(n);
    cout << "Enter the elements of the circular array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> code[i];
    }
    cout << "Enter key k: ";
    cin >> k;

    Solution sol;
    vector<int> decrypted = sol.decrypt(code, k);

    cout << "Decrypted code: ";
    for (int num : decrypted) {
        cout << num << " ";
    }
    cout << endl;
}
