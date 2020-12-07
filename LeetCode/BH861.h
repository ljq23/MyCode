#ifndef BH861_H_INCLUDED
#define BH861_H_INCLUDED

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if(A.size() == 0)
            return 0;
        int a=A.size(), b=A[0].size();
        vector<int> v(A[0].size(),0);
        for(int i=0; i<a; ++i)
        {
           if(A[i][0]==1)
            {
                for(int j=0; j<b; ++j)
                    A[i][j]=1-A[i][j], v[j]+=A[i][j];
            }else{
                for(int j=0; j<b; ++j)
                    v[j]+=A[i][j];
            }
        }
        int res = 0;
        for(int i=0; i<b; ++i)
        {
            res += max(v[i],a-v[i])*(1<<(b-i-1));
        }
        return res;
    }
};

#endif // BH861_H_INCLUDED
