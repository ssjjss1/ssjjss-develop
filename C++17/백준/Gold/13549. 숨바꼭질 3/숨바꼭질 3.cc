#include <iostream>
#include <queue>
using namespace std;
const int inf = 1e9 + 4;
int n, m;
int visited[200004];
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  fill(visited, visited + 200004, inf);
  deque<pair<int, int>> q;
  q.push_back({n, 0});
  visited[n] = 0;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop_front();
    if (2 * x <= 200000 && visited[2 * x] > y) {
      q.push_front({2 * x, y});
      visited[2 * x] = y;
    }
    if (x >= 1 && visited[x - 1] > y + 1) {
      q.push_back({x - 1, y + 1});
      visited[x - 1] = y + 1;
    }
    if (x <= 200000 && visited[x + 1] > y + 1) {
      q.push_back({x + 1, y + 1});
      visited[x + 1] = y + 1;
    }
  }
  cout << visited[m];
}