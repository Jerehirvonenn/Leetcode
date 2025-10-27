class Solution {
private:
    int recurse(string &tiles, vector<bool> &used) {
        int result = 0;
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i] || (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1]))
                continue ;
            used[i] = true;
            result += 1 + recurse(tiles, used);
            used[i] = false;
        }
        return result;
    }
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> used(tiles.size());
        return recurse(tiles, used);
    }
};