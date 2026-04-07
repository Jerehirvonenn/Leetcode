class Solution {
private:
    long long makeKey(int x, int y) {
        return ((long long)x << 32) | (y & 0xffffffff);
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int best = 0;
        int direction = 0; //0 north, 1 east, 2 south, 3 west
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        pair<int,int> position;

        unordered_set<long long> obs;
        for (vector<int> obstacle : obstacles) {
            obs.insert(makeKey(obstacle[0], obstacle[1]));
        }

        for (int command : commands) {
            //cout << position.first << " " << position.second << endl;
            if (command == -2) {
                direction = (direction + 3) % 4;
                continue ;
            }
            else if (command == -1) {
                direction = (direction + 1) % 4;
                continue ;
            }
            
            for (int i = 1; i <= command; i++) {
                position.first += dx[direction];
                position.second += dy[direction];
                if (obs.count(makeKey(position.first, position.second))) {
                    position.first -= dx[direction];
                    position.second -= dy[direction];
                    break;
                }
            }
            best = max(best, ((position.first * position.first) + (position.second * position.second)));
        }
        return best;
    }
};