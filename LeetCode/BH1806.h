#ifndef BH1806_H_INCLUDED
#define BH1806_H_INCLUDED

class Solution {
public:
    bool ok(vector<int>& perm,int n){
        for(int i=0; i<n; ++i)
            if(i!=perm[i])
                return false;
        return true;
    }
    int reinitializePermutation(int n) {
        vector<int> perm;
        for(int i=0; i<n; ++i)
            perm.push_back(i);
        bool first = true;
        int ans = 0;
        while(first||!ok(perm,n)){
            first = false;
            vector<int> arr(n);
            for(int i=0; i<n; ++i){
                if(i%2==0){
                    arr[i] = perm[i/2];
                }else{
                    arr[i] = perm[n/2+(i-1)/2];
                }
            }
            perm = arr;
            ++ ans;
        }
        return ans;
    }
};

#endif // BH1806_H_INCLUDED
