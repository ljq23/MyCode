#ifndef BH438_H_INCLUDED
#define BH438_H_INCLUDED

class Solution {
public:
    string smallestGoodBase(string n) {
        long long x = stol(n);
        for(int i=2; i<=60; ++i){
            long long k = pow(x,1.0/(1.0*i));
            long long tmp=1,sum=1;
            if(k==1) continue;
            for(int j=0; j<i; ++j){
                tmp *= k;
                sum += tmp;
            }
            if(sum==x) return to_string(k);
        }
        return to_string(x-1);
    }
};

#endif // BH438_H_INCLUDED
