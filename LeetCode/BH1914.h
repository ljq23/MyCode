#ifndef BH1914_H_INCLUDED
#define BH1914_H_INCLUDED

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid[0].size(),m=grid.size();
        int top=0,low=m-1,left=0,right=n-1;
        while(top<low&&left<right){
            int num=n+n+m+m-4;
            n-=2,m-=2;
            int cn = k % num;
            for(int tk=0; tk<cn; ++tk){
                int berf=grid[top][left];
                for(int i=left+1; i<=right; ++i){
                    grid[top][i-1] = grid[top][i];
                }
                for(int i=top+1; i<=low; ++i){
                    grid[i-1][right] = grid[i][right];
                }
                for(int i=right-1; i>=left; --i){
                    grid[low][i+1] = grid[low][i];
                }
                for(int i=low-1; i>top; --i){
                    grid[i+1][left] = grid[i][left];
                }
                grid[top+1][left] = berf;
            }
            ++top,--low,++left,--right;
        }
        return grid;
    }
};


#endif // BH1914_H_INCLUDED
