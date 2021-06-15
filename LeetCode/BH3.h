#ifndef BH3_H_INCLUDED
#define BH3_H_INCLUDED

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0,size=s.size();
        if(size==0) return 0;
        vector<int> flag(26,0);
        int ans=0;
        while(right<size){
            int idx = s[right]-'a';
            while(flag[idx]==1){
                int tidx = s[left] - 'a';
                flag[tidx] = 0;
                ++ left;
            }
            flag[idx] = 1;
            ++ right;
            ans = max(ans,right-left);
        }
        return ans;
    }
};


#endif // BH3_H_INCLUDED
