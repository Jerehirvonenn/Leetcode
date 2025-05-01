#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

class Solution {
private:
	bool canSolveNTasks(const vector<int>& tasks, const vector<int>& workers,
			int pills, const int strength, const int n)
	{
        vector<int> available(workers.end() - n, workers.end());

        for (int i = n - 1; i >= 0; --i)
		{
            int task = tasks[i];
            if (available.back() >= task) {
                available.pop_back();
            }
            else if (pills) {
                auto it = lower_bound(available.begin(), available.end(), task - strength);
                if (it == available.end()) {
                    return false;
                }
                available.erase(it);
                pills--;
            }
            else {
                return false;
            }
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength)
	{
        sort(workers.begin(), workers.end());
        sort(tasks.begin(), tasks.end());

        int left = 0;
        int right = min(workers.size(), tasks.size());
        int result = 0;
        while (left <= right)
		{
            int middle = left + (right - left) / 2;
            if (canSolveNTasks(tasks, workers, pills, strength, middle)) {
                result = middle;
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return result;
    }
};

void runTest(vector<int> tasks, vector<int> workers, int pills, int strength)
{
    Solution solution;
    auto start = high_resolution_clock::now();

    int result = solution.maxTaskAssign(tasks, workers, pills, strength);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Max tasks assigned: " << result << "\n";
    cout << "Time taken: " << duration.count() << " ms\n";
}

void runRandomLargeTest(int numTasks, int numWorkers, int pills, int strength)
{
    vector<int> tasks(numTasks);
    vector<int> workers(numWorkers);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> taskDist(3, 7);
    uniform_int_distribution<int> workerDist(0, 6);

    for (int &t : tasks)
		t = taskDist(rng);
    for (int &w : workers)
		w = workerDist(rng);

    cout << "\nRunning random large test: " 
         << numTasks << " tasks, " << numWorkers << " workers\n";

    runTest(tasks, workers, pills, strength);
}

int main(void) {
    // small test
    runTest({3, 2, 1}, {0, 3, 3}, 1, 1);

    // medium test
    runTest({5, 4, 3, 2, 1}, {1, 1, 2, 3, 4, 5}, 2, 2);

	// big random tests
	runRandomLargeTest(15000, 12345, 300, 1);
	runRandomLargeTest(90000, 100000, 300, 1);
}
