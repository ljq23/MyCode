#ifndef BH5750_H_INCLUDED
#define BH5750_H_INCLUDED

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> v(200,0);
        int ans = 0,year=1950;
        int size = logs.size();
        for(int i=0; i<size; ++i){
            for(int k=logs[i][0];k<logs[i][1]; ++k){
                ++ v[k-1950];
                if(v[k-1950]>ans){
                    year = k;
                    ans = v[k-1950];
                }
            }
        }
        for(int i=0; i<v.size(); ++i){
            if(ans==v[i]){
                year = 1950+i;
                return year;
            }
        }
        return year;
    }
};


#endif // BH5750_H_INCLUDED
