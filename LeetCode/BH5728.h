#ifndef BH5728_H_INCLUDED
#define BH5728_H_INCLUDED

class Solution {
public:
    const int maxn = 0x3f3f3f3f;
    int minSideJumps(vector<int>& obstacles) {
        int size = obstacles.size();
        vector<vector<int>> dp(3,vector<int>(size+1,maxn));
        dp[1][0] = 0;

        for(int i=0; i<size; ++i){
            int mi = maxn;
            for(int k=0; k<3; ++k) mi = min(mi,dp[k][i]);
            for(int k=0; k<3; ++k) if(obstacles[i]!=k+1) dp[k][i] = min(dp[k][i],mi+1);
            for(int k=0; k<3; ++k)
                if(obstacles[i+1]!=k+1)
                    dp[k][i+1] = dp[k][i];
        }

//        for(int i=0; i<3; ++i){
//            for(int j=0; j<size; ++j)
//                printf("%d ", dp[i][j]);
//            printf("\n");
//        }
        return min(dp[0][size-1],min(dp[1][size-1],dp[2][size-1]));
    }
};

#endif // BH5728_H_INCLUDED
