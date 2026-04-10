class Solution {
private:
    int     goodTuple(int i, int j, int k) {
        //cout << i << " " << j << " " << k << endl;
        return (abs(i - j) + abs(j - k) + abs(k - i));
    }

    void    recurse(vector<int>& nums, vector<int>& current, int idx, int &best) {
        //cout << idx << " size " << current.size() << endl;
        if (current.size() == 3) {
            int candidate = goodTuple(current[0], current[1], current[2]);
            //cout << "candidate found " << candidate << endl;
            best = min(best, candidate); 
            return ;
        }
        if (idx >= nums.size()) {
            return ;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (current.empty()) {
                current.push_back(i);
                recurse(nums, current, i + 1, best);
                current.pop_back();
            }
            else if (nums[i] == nums[current[0]]) {
                current.push_back(i);
                recurse(nums, current, i + 1, best);
                current.pop_back();
            }
        }
    }
public:
    int minimumDistance(vector<int>& nums) {
        int best = INT_MAX;
        vector<int> current;
        current.reserve(3);
        recurse(nums, current, 0, best);
        return best == INT_MAX ? -1 : best;
    }
};