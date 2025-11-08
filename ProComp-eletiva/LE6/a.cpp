#include <bits/stdc++.h>
using namespace std;

const int MAXN = 515;

int h, w;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

map<char, char> nxt = {
    {'s', 'n'},
    {'n', 'u'},
    {'u', 'k'},
    {'k', 'e'},
    {'e', 's'}
};

bool bfs() {
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;

    while (!q.empty()) {
        auto par = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = par.first + dx[dir];
            int ny = par.second + dy[dir];

            if (nx < 1 || nx > h || ny < 1 || ny > w) continue;
            if (visited[nx][ny]) continue;

            if (grid[nx][ny] == nxt[grid[par.first][par.second]]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return visited[h][w];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> grid[i][j]; 
        }
    }

    bool foii = bfs();

    if (foii) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
