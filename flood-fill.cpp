/*
https://leetcode.com/problems/flood-fill/solutions/5556491/eazy-solution/
*/
class Solution {
public:
    void dfs(vector<vector<int>>& image, int& startcolor,int sr, int sc, int& color){
        if(sr>=image.size() || sc>=image[0].size()||sr<0 || sc<0 || image[sr][sc]!=startcolor){
            return;
        }
        else{
            image[sr][sc]=color;
            dfs(image,startcolor,sr+1,sc,color);
            dfs(image,startcolor,sr,sc+1,color);
            dfs(image,startcolor,sr-1,sc,color);
            dfs(image,startcolor,sr,sc-1,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startcolor = image[sr][sc];
        if(startcolor==color){
            return image;
        }
        else{
            dfs(image,startcolor,sr,sc,color);
            return image;
        }
    }
};