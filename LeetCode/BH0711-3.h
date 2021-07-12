#ifndef BH0711-3_H_INCLUDED
#define BH0711-3_H_INCLUDED
class Cows {
public:
    int countSum(int n) {
        // write code here
        int mod = 1000000007;
        long f[3] = {0,0,1};
        for(int i=1; i<n; ++i){
            int tp = f[2];
            f[2] = (f[1]+f[2])%mod;
            f[1] = f[0];
            f[0] = tp;
        }
        long ans = (f[0]+f[1]+f[2])%mod;
        return ans;
    }
};
#endif // BH0711-3_H_INCLUDED
