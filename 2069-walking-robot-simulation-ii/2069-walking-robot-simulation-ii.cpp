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
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                dir = (dir + 3) % 4;
                continue;
            }
            x = nx;
            y = ny;
            num--;
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