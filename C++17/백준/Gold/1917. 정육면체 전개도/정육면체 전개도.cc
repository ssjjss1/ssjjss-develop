#include <iostream>
using namespace std;
char d[12][12];
string s[12][4] = {{"1000", "1111", "1000"}, {"1000", "1111", "0100"},
                   {"1000", "1111", "0010"}, {"1000", "1111", "0001"},
                   {"0100", "1111", "0100"}, {"0100", "1111", "0010"},
                   {"1000", "1110", "0011"}, {"0100", "1110", "0011"},
                   {"0010", "1110", "0011"}, {"1100", "0110", "0011"},
                   {"11100", "00111"}};
int g(int r) { return (r == 10) ? 2 : 3; }
bool g1(int x, int y, int r) {
    int h = g(r);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < s[r][i].size(); j++) {
            if (d[x + i][y + j] != s[r][i][j]) return false;
        }
    }
    return true;
}
bool g2(int x, int y, int r) {
    int h = g(r);
    int w = s[r][0].size();
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (d[x + i][y + j] != s[r][h - 1 - j][i]) return false;
        }
    }
    return true;
}
bool g3(int x, int y, int r) {
    int h = g(r);
    int w = s[r][0].size();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < s[r][i].size(); j++) {
            if (d[x + i][y + j] != s[r][h - 1 - i][w - 1 - j]) return false;
        }
    }
    return true;
}
bool g4(int x, int y, int r) {
    int h = g(r);
    int w = s[r][0].size();
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (d[x + i][y + j] != s[r][j][w - 1 - i]) return false;
        }
    }
    return true;
}
bool g_1(int x, int y, int r) {
    int h = g(r);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < s[r][i].size(); j++) {
            if (d[x + i][y + j] != s[r][i][s[r][i].size() - 1 - j]) return false;
        }
    }
    return true;
}
bool g_2(int x, int y, int r) {
    int h = g(r);
    int w = s[r][0].size();
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (d[x + i][y + j] != s[r][h - 1 - j][w - 1 - i]) return false;
        }
    }
    return true;
}
bool g_3(int x, int y, int r) {
    int h = g(r);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < s[r][i].size(); j++) {
            if (d[x + i][y + j] != s[r][h - 1 - i][j]) return false;
        }
    }
    return true;
}
bool g_4(int x, int y, int r) {
    int h = g(r);
    int w = s[r][0].size();
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (d[x + i][y + j] != s[r][j][i]) return false;
        }
    }
    return true;
}
bool f() {
    for (int r = 0; r < 11; r++) {
        for (int i = 0; i <= 6 ; i++) {
            for (int j = 0; j <= 6 ; j++) {
                if (g1(i, j, r)) return true;
                if (g2(i, j, r)) return true;
                if (g3(i, j, r)) return true;
                if (g4(i, j, r)) return true;
                if (g_1(i, j, r)) return true;
                if (g_2(i, j, r)) return true;
                if (g_3(i, j, r)) return true;
                if (g_4(i, j, r)) return true;
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int t = 1; t <= 3; t++) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                cin >> d[i][j];
            }
        }
        if (f()) cout << "yes\n";
        else cout << "no\n";
    }
}