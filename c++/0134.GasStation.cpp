#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
	public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
		int totalGas = 0;
        	int totalCost = 0;
        	int start = 0;
        	int reserve = 0;

		for (unsigned int i = 0; i < gas.size(); i++) {
			totalGas += gas[i];
            		totalCost += cost[i];
            		reserve += gas[i] - cost[i];
            		if (reserve < 0) {
                		start = i + 1;
                		reserve = 0;
			}
		}
		return totalGas >= totalCost ? start : -1;
	}
};

int main(int ac, char* av[])
{
	if (ac < 4) {
	    cerr << "Usage: " << av[0] << " num num ... | num num ..." << endl;
	    return 1;
	}

	vector<int> gas;
	vector<int> cost;

	bool parsingCost = false;
	for (int i = 1; i < ac; ++i) {
		string arg = av[i];
		if (arg == "|") {
			parsingCost = true;
	        	continue;
	    	}

	    	try {
	        	int num = stoi(arg);
	        	if (!parsingCost)
	            		gas.push_back(num);
	        	else
	            		cost.push_back(num);
		}
		catch (invalid_argument&) {
	        	cerr << "Invalid number: " << arg << endl;
	        	return 1;
		}
	}

	if (gas.size() != cost.size()) {
	    cerr << "Error: gas and cost lists must have the same number of elements." << endl;
	    return 1;
	}

	Solution sol;
	int result = sol.canCompleteCircuit(gas, cost);
	cout << "Starting index: " << result << endl;
}
