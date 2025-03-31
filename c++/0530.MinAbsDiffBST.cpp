#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
	public:
    int getMinimumDifference(TreeNode* root)
	{
        if (!root)
			return -1;
        
        vector<int> nums;
        stack<TreeNode*> st;
        TreeNode *current = root;

        while (current || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();
            nums.push_back(current->val);

            current = current->right;
        }

        int lowest = INT_MAX;
        for (size_t i = 1; i < nums.size(); i++) {
            lowest = min(nums[i] - nums[i - 1], lowest);
        }

        return lowest;
    }
};

TreeNode* insert(TreeNode* root, int value)
{
    if (!root)
		return new TreeNode(value);
    if (value < root->val)
		root->left = insert(root->left, value);
    else
		root->right = insert(root->right, value);
    return root;
}

int main(void)
{
    TreeNode* root = nullptr;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);

    Solution sol;
    int result = sol.getMinimumDifference(root);
    cout << "Minimum Absolute Difference: " << result << endl;
}

