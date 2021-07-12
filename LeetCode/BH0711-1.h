#ifndef BH0711-1_H_INCLUDED
#define BH0711-1_H_INCLUDED

class Cmp {
public:
    bool dfs(int g1,int g2,vector<vector<int>>&mp,vector<bool>&vis){
        if(g1==g2) return true;
        if(vis[g1]) return false;
        vis[g1] = true;
        for(int i=0; i<mp[g1].size(); ++i){
            if(dfs(mp[g1][i],g2,mp,vis))
                return true;
        }
        return false;
    }
    int cmp(int g1, int g2, vector<vector<int> > records, int n) {
        // write code here
        vector<vector<int>> mp(n+1,vector<int>());
        for(int i=0; i<n; ++i){
            mp[records[i][0]].push_back(records[i][1]);
        }
        vector<bool> vis(n+1,false);
        if(dfs(g1,g2,mp,vis)){
            return 1;
        }
        for(int i=0;i <=n; ++i) vis[i]=false;
        if(dfs(g2,g1,mp,vis)){
            return -1;
        }
        return 0;
    }
};


#endif // BH0711-1_H_INCLUDED
