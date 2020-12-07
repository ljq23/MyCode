#ifndef BH1680_H_INCLUDED
#define BH1680_H_INCLUDED

class Solution {
public:
    const int mod = 1e9+7;
    int concatenatedBinary(int n) {
        int size=1;
        int res = 0;
        vector<int> v = {1};
        for(int i=1; i<=n; ++i){
            res = ((res<<size)%mod+i)%mod;
            v[0] += 1;
            int bit = 0;
            for(int k=0; k<size; ++k){
               v[k] += bit;
               bit = v[k]/2;
               if(v[k]>1){
                 v[k] %= 2;
               }
            }
            if(bit){
                v.push_back(bit);
                ++ size;
            }
        }
        return res%mod;
    }
};


#endif // BH1680_H_INCLUDED
