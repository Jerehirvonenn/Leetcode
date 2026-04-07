class Robot {
private:
    int x;
    int y;
    int n;
    int m;
    int perimeter;
    int dir; //0 north,  1 east,  2 south,  3 west
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int stepsTillWall(int x, int y, int width, int height, int dir) {
        switch(dir) {
            case(0) : return (height - 1) - y;
            case(1) : return (width - 1) - x;
            case(2) : return y;
            case(3) : return x;
            default : cout << "dir impossible" << endl; return 0;
        }
    }
public:
    Robot(int width, int height) {
        x = 0;
        y = 0;
        n = height;
        m = width;
        perimeter = 2 * (n + m) - 4;
        dir = 1;
    }
    
    void step(int num) {
        num = num % perimeter;
        if (num == 0) {
            num = perimeter;
        }

        while (num) {
            int canTake = min(num, stepsTillWall(x, y, m, n, dir));
            int nx = x + (canTake * dx[dir]);
            int ny = y + (canTake * dy[dir]);

            x = nx;
            y = ny;
            num -= canTake;
            if (num) {
                dir = (dir + 3) % 4;
            }
        }
        return ;
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        switch(dir) {
            case(0) : return "North";
            case(1) : return "East";
            case(2) : return "South";
            case(3) : return "West";
            default : return "Unknown";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */