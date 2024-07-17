/*
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
Output
Print one integer: the number of rooms.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e3 + 5;

vector<vector<char>> adj(N, vector<char>(N));
vector<vector<bool>> visited(N, vector<bool>(N));

void dfsMatrix(int i, int j, int n, int m) {
    visited[i][j] = true;
    if (i > 0 && adj[i-1][j] == '.' && !visited[i-1][j]) {
        dfsMatrix(i-1, j, n, m);
    }
    if (i < n-1 && adj[i+1][j] == '.' && !visited[i+1][j]) {
        dfsMatrix(i+1, j, n, m);
    }
    if (j > 0 && adj[i][j-1] == '.' && !visited[i][j-1]) {
        dfsMatrix(i, j-1, n, m);
    }
    if (j < m-1 && adj[i][j+1] == '.' && !visited[i][j+1]) {
        dfsMatrix(i, j+1, n, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> adj[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (adj[i][j] == '.' && !visited[i][j]) {
                dfsMatrix(i, j, n, m);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
