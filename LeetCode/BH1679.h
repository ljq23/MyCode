#ifndef BH1679_H_INCLUDED
#define BH1679_H_INCLUDED

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        unordered_map<int,int> key;
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>k) continue;
            if(key[k-nums[i]]>0){
                ++ ans;
                -- key[k-nums[i]];
                continue;
            }
            ++ key[nums[i]];
        }
        return ans;
    }
};

#endif // BH1679_H_INCLUDED
