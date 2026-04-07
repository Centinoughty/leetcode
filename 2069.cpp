#include <bits/stdc++.h>
using namespace std;

class Robot {
private:
    int w, h;
    int posX = 0, posY = 0;
    int dir = 1;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
    }
    
    void step(int num) {
        int p = 2 * (w + h) - 4;
        if (num % p == 0 && num > 0) num = p;
        else num %= p;

        while (num > 0) {
            vector<int> curr = getPos();
            int x = curr[0], y = curr[1];

            if (dir == 1) {
                int move = min(num, w - posX - 1);
                posX += move;
                num -= move;
                if (num > 0) dir = 2;
            }

            if (dir == 2) {
                int move = min(num, h - posY - 1);
                posY += move;
                num -= move;
                if (num > 0) dir = -1;
            }

            if (dir == -1) {
                int move = min(num, posX);
                posX -= move;
                num -= move;
                if (num > 0) dir = -2;
            }

            if (dir == -2) {
                int move = min(num, posY);
                posY -= move;
                num -= move;
                if (num > 0) dir = 1;
            }
        }
    }
    
    vector<int> getPos() {
        return {posX, posY};
    }
    
    string getDir() {
        if (dir == 1) return "East";
        if (dir == 2) return "North";
        if (dir == -1) return "West";
        return "South";
    }
};
