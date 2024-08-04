#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int one_check(const vector<vector<int>>& board, int N, int M) {
    int dx[2] = {1, -1};
    int dy[2] = {1, -1};
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] == 0)
                continue;
            bool check_x = false;
            bool check_y = false;
            for (int i = 0; i < 2; i++) {
                int nx = x + dx[i];
                if (nx >= 0 && nx < M && board[y][nx] == 1)
                    check_x = true;
                int ny = y + dy[i];
                if (ny >= 0 && ny < N && board[ny][x] == 1)
                    check_y = true;
            }
            if (check_x && check_y) {
                cout << y + 1 << " " << x + 1 << endl;
                return 0;
            }
        }
    }
    return -1;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<int>> board(N, vector<int>(M));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    int seed = 0;
    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == 1)
                seed++;
        }
    }
    
    if (2 * K == seed) {
        cout << 0 << endl;
        return 0;
    }
    
    cout << 2 * K - seed << endl;
    
    if (K == 1) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (board[y][x] == 1) {
                    cout << y + 1 << " " << x + 1 << endl;
                    return 0;
                }
            }
        }
    }
    
    if (2 * K - 1 == seed) {
        if (one_check(board, N, M) != -1) {
            return 0;
        }
    }
    
    int start_x = 2001, start_y = 2001;
    int end_x = -1, end_y = -1;
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] == 1) {
                start_x = min(x, start_x);
                start_y = min(y, start_y);
                end_x = max(x, end_x);
                end_y = max(y, end_y);
            }
        }
    }
    
    if (start_x == end_x) {
        for (int i = 0; i < 2 * K - seed; i++) {
            cout << start_y + seed - K + i + 1 << " " << start_x + 1 << endl;
        }
        return 0;
    }
    
    if (start_y == end_y) {
        for (int i = 0; i < 2 * K - seed; i++) {
            cout << start_y + 1 << " " << start_x + seed - K + i + 1 << endl;
        }
    }
    
    return 0;
}
