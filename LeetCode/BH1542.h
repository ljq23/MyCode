#ifndef BH1542_H_INCLUDED
#define BH1542_H_INCLUDED

class Solution {
public:
    int longestAwesome(string s) {
        vector<int>prefix((1<<10)+5,100005);
        int now = 0;
        prefix[now] = -1;
        int res = 0;
        for(int i=0; i<s.size(); ++i){
            int p = (s[i]-'0');
            now ^= (1<<p);
            res = max(res,i-prefix[now]);
            for(int j=0; j<10; ++j){
                int nxt = now^(1<<j);
                res = max(res,i-prefix[nxt]);
            }
            prefix[now] = min(i,prefix[now]);
        }
        return res;
    }
};

#endif // BH1542_H_INCLUDED
