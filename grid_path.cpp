#include <bits/stdc++.h>
using namespace std;

bool grid[7][7] = {false};
int steps = 0;
int paths = 0;
int directions[49];
string path;

void fun(int i, int j) {
    if (i == 6 && j == 0 && steps == 48) {
        paths++;
        return;
    }

    if (grid[i][j] || ((j > 0 && j < 6 && !grid[i][j - 1] && !grid[i][j + 1]) && ((i == 0 && grid[i + 1][j]) || (i == 6 && grid[i - 1][j]))) ||
        ((i > 0 && i < 6 && !grid[i + 1][j] && !grid[i - 1][j]) && ((j == 0 && grid[i][j + 1]) || (j == 6 && grid[i][j - 1]))) ||
        ((i > 0 && i < 6 && j > 0 && j < 6 && grid[i - 1][j] && grid[i + 1][j] && !grid[i][j - 1] && !grid[i][j + 1])) ||
        ((i > 0 && i < 6 && j > 0 && j < 6 && !grid[i - 1][j] && !grid[i + 1][j] && grid[i][j - 1] && grid[i][j + 1]))) {
        return;
    }

    grid[i][j] = true;

    if (directions[steps] != -1) {
        switch (directions[steps]) {
            case 0: if (j > 0 && !grid[i][j - 1]) { steps++; fun(i, j - 1); steps--; } break;
            case 1: if (j < 6 && !grid[i][j + 1]) { steps++; fun(i, j + 1); steps--; } break;
            case 2: if (i > 0 && !grid[i - 1][j]) { steps++; fun(i - 1, j); steps--; } break;
            case 3: if (i < 6 && !grid[i + 1][j]) { steps++; fun(i + 1, j); steps--; } break;
        }
    } else {
        if (i < 6 && !grid[i + 1][j]) { steps++; fun(i + 1, j); steps--; }
        if (i > 0 && !grid[i - 1][j]) { steps++; fun(i - 1, j); steps--; }
        if (j > 0 && !grid[i][j - 1]) { steps++; fun(i, j - 1); steps--; }
        if (j < 6 && !grid[i][j + 1]) { steps++; fun(i, j + 1); steps--; }
    }

    grid[i][j] = false;
}

int main() {
    cin >> path;

    for (int i = 0; i < 48; i++) {
        switch (path[i]) {
            case '?': directions[i] = -1; break;
            case 'U': directions[i] = 2; break;
            case 'D': directions[i] = 3; break;
            case 'L': directions[i] = 0; break;
            case 'R': directions[i] = 1; break;
        }
    }

    fun(0, 0);
    cout << paths;
    return 0;
}
