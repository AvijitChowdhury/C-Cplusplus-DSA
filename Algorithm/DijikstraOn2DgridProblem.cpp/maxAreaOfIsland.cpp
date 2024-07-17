/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.*/
class Solution {
public:
    bool visited[50][50]={false};
    int cnt=0;
    void dfsMatrix(vector<vector<int>>&graph,int i, int j){
        int n=graph.size();
        int m = graph[0].size();
        visited[i][j]= true;
        if(i>=0&&i<n&&j>=0&&j<m&&graph[i][j]==1){
            cnt++;
            if(i>0&&!visited[i-1][j]){
                dfsMatrix(graph,i-1,j);
            }
            if(i<n-1&&!visited[i+1][j]){
                dfsMatrix(graph,i+1,j);
            }
            if(j>0&&!visited[i][j-1]){
                dfsMatrix(graph,i,j-1);
            }
            if(j<m-1&&!visited[i][j+1]){
                dfsMatrix(graph,i,j+1);
            }
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!visited[i][j]){
                    int area = 0;
                    cnt=0;
                    dfsMatrix(grid,i,j);
                    area = cnt;
                    maxArea = max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};