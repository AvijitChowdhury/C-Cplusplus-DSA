/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n*/
class Solution {
public:
   
     
    bool visited[50][50]={false};
    void dfsMatrix(vector<vector<int>>&graph,int i,int j,int color1){
        int n = graph.size();
        int m = graph[0].size();
        visited[i][j] = true;
        int color= graph[i][j];
        //graph[i][j]=color1;
        if(i>0 && graph[i-1][j]==color&&!visited[i-1][j]){
            
            dfsMatrix(graph,i-1,j,color1);
            //graph[i-1][j] = color1;       
        }
        if(i<n-1 && graph[i+1][j]==color&&!visited[i+1][j]){
            
            dfsMatrix(graph,i+1,j,color1); 
           // graph[i+1][j] = color1;      
        }
        if(j>0 && graph[i][j-1]==color&&!visited[i][j-1]){
            
            dfsMatrix(graph,i,j-1,color1); 
           // graph[i][j-1] = color1;      
        }
        if(j<m-1 && graph[i][j+1]==color&&!visited[i][j+1]){
            
            dfsMatrix(graph,i,j+1,color1);
            //graph[i][j+1] = color1;       
        }
       graph[i][j] = color1;


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int color1=image[sr][sc];
        dfsMatrix(image,sr,sc,color);
        return image;
    }
};