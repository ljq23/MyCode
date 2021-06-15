#ifndef OFFER-13_H_INCLUDED
#define OFFER-13_H_INCLUDED

class Solution {
public:
    int check(int i,int j){
        int ans = 0;
        while(i){
            ans += i%10;
            i /= 10;
        }
        while(j){
            ans += j%10;
            j /= 10;
        }
        return ans;
    }
    void dfs(vector<vector<bool>>&vis,int n,int m,int i,int j,int k,int &ans){
        if(i<0||i>=n||j<0||j>=m||vis[i][j]) return;
        if(check(i,j)<=k) ++ ans;
        else return;
        vis[i][j] = true;
        dfs(vis,n,m,i+1,j,k,ans);
        dfs(vis,n,m,i-1,j,k,ans);
        dfs(vis,n,m,i,j+1,k,ans);
        dfs(vis,n,m,i,j-1,k,ans);
    }
    int movingCount(int n, int m, int k) {
        int ans = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        dfs(vis,n,m,0,0,k,ans);
        return ans;
    }
};

#endif // OFFER-13_H_INCLUDED
