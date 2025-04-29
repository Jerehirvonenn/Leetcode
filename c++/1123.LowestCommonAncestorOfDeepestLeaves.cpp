#include <iostream>
#include <utility>

using namespace std;

/** TreeNode definition */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    pair<TreeNode*, int> dfs(TreeNode *node)
	{
        if (!node) {
            return {nullptr, 0};
        }
        auto [lowestLeft, depthLeft] = dfs(node->left);
        auto [lowestRight, depthRight] = dfs(node->right);
        if (depthLeft == depthRight) {
            return {node, depthLeft + 1};
        } else if (depthLeft > depthRight) {
            return {lowestLeft, depthLeft + 1};
        } else {
            return {lowestRight, depthRight + 1};
        }
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};

int main(void)
{
    //        1
    //       / \
    //      2   3
    //     /     \
    //    4       5
    //           / \
    //          6   7

    TreeNode* node7 = new TreeNode(7);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node5 = new TreeNode(5, node7, node6);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2, node4, nullptr);
    TreeNode* node3 = new TreeNode(3, nullptr, node5);
    TreeNode* root = new TreeNode(1, node2, node3);

    Solution sol;
    TreeNode* lca = sol.lcaDeepestLeaves(root);

    if (lca) {
        cout << "LCA of deepest leaves is: " << lca->val << endl;
    } else {
        cout << "Tree is empty." << endl;
    }

    delete node7;
    delete node6;
    delete node5;
    delete node4;
    delete node2;
    delete node3;
    delete root;
}
