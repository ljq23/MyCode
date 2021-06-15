#ifndef BH79_H_INCLUDED
#define BH79_H_INCLUDED

class Solution {
public:
    bool dfs(vector<vector<bool>>&vis,vector<vector<char>>&board,int i,int j,string& word,int idx){
        if(idx>=word.size()){
            return true;
        }
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||vis[i][j]) return false;
        if(board[i][j]==word[idx]){
            vis[i][j] = true;
            if(dfs(vis,board,i,j+1,word,idx+1)||
                dfs(vis,board,i,j-1,word,idx+1)||
                dfs(vis,board,i+1,j,word,idx+1)||
                dfs(vis,board,i-1,j,word,idx+1)){
                    return true;
                }
            vis[i][j] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(dfs(vis,board,i,j,word,0))
                    return true;
            }
        }
        return false;
    }
};

#endif // BH79_H_INCLUDED
