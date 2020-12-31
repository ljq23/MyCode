#ifndef BH1557_H_INCLUDED
#define BH1557_H_INCLUDED

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> du = vector<int>(n,0);
        for(int i=0; i<edges.size(); ++i){
            ++ du[edges[i][1]];
        }
        vector<int> res;
        for(int i=0; i<du.size(); ++i){
            if(du[i]== 0)
                res.push_back(i);
        }
        return res;
    }
};

#endif // BH1557_H_INCLUDED
