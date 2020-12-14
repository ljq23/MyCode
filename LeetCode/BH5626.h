#ifndef BH5626_H_INCLUDED
#define BH5626_H_INCLUDED

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char c : n){
            ans = max(ans,c-'0');
        }
        return ans;
    }
};

#endif // BH5626_H_INCLUDED
