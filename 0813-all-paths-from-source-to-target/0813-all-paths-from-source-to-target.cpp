class Solution {
private:
    void    backtrack(vector<vector<int>> &result, vector<int> &path, vector<vector<int>> &graph, int current) {
        if (current == graph.size() - 1) {
            result.push_back(path);
            return ;
        }

        for (int i = 0; i < graph[current].size(); i++) {
            path.push_back(graph[current][i]);
            backtrack(result, path, graph, graph[current][i]);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        path.push_back(0);
        backtrack(result, path, graph, 0);
        return result; 
    }
};