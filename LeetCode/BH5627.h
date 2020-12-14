#ifndef BH5627_H_INCLUDED
#define BH5627_H_INCLUDED

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int left=0,right=stones.size()-1;
        int alise=0,bob=0;
        int all=0,who=0;
        for(int i=0; i<=right; ++i) all += stones[i];
        while(left<right){
            if(stones[left]>stones[right]){
                if(who%2==0){
                    all -= stones[right];
                    -- right;
                    alise += all;
                }else{
                    if(left+1==right){
                        all -= stones[right];
                        -- right;
                        bob += all;
                    }else{
                        all -= stones[left];
                        ++ left;
                        bob += all;
                    }
                }
            }else{
                if(who%2==0){
                    all -= stones[left];
                    ++ left;
                    alise += all;
                }else{
                    if(left+1==right){
                        all -= stones[left];
                        ++ left;
                        bob += all;
                    }else{
                        all -= stones[right];
                        -- right;
                        bob += all;
                    }
                }
            }
            ++ who;
        }
        return alise-bob;
    }
};

#endif // BH5627_H_INCLUDED
