#ifndef BH207_H_INCLUDED
#define BH207_H_INCLUDED


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> du(numCourses,0);
        map<int,vector<int>> mp;
        for(int i=0; i<prerequisites.size(); ++i){
            vector<int> v = prerequisites[i];
            if(mp.find(v[0])==mp.end()){
                vector<int> vv = {v[1]};
                mp[v[0]] = vv;
            }else{
                mp[v[0]].push_back(v[1]);
            }
            ++ du[v[1]];
        }
        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(du[i]==0)
                q.push(i);
        }
        int ans = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ++ ans;
            vector<int> v = mp[top];
            for(int i=0; i<v.size(); ++i){
                -- du[v[i]];
                if(du[v[i]]==0) q.push(v[i]);
            }
        }
        return ans == numCourses;
    }
};

#endif // BH207_H_INCLUDED
