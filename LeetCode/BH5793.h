#ifndef BH5793_H_INCLUDED
#define BH5793_H_INCLUDED

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size(),m=maze[0].size();
        int sx=entrance[0],sy=entrance[1];
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        q.push({sx,sy});
        vis[sx][sy]=1;
        int time = 0;
        while(q.size()){
            int size = q.size();
            for(int i=0; i<size; ++i){
                int tx = q.front().first;
                int ty = q.front().second;
                q.pop();
                if(time>0&&(tx==0||ty==0||tx==n-1||ty==m-1)) return time;
                for(int i=0; i<4; ++i){
                    int ttx=tx+dx[i];
                    int tty=ty+dy[i];
                    if(ttx<0||tty<0||ttx>=n||tty>=m||vis[ttx][tty]||maze[ttx][tty]=='+')
                        continue;
                    else{
                        vis[ttx][tty] = 1;
                        q.push({ttx,tty});
                    }
                }
            }
            ++time;
        }
        return -1;
    }
};

#endif // BH5793_H_INCLUDED
