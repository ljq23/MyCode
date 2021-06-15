#ifndef BH5747_H_INCLUDED
#define BH5747_H_INCLUDED

class Solution {
public:
    bool dfs(string& s,int idx,long long pre,long long cnt){
        if(idx==s.size()){
            return cnt > 1;
        }
        long long cur = 0;
        for(int i=idx; i<s.size(); ++i){
            cur = cur*10 + s[i]-'0';
            if(cur>pre) return false;
            if(cnt==0||cur==pre-1){
                cout << pre<< " " << cur << endl;
                if(dfs(s,i+1,cur,cnt+1))
                    return true;
            }
        }
        return false;
    }
    bool splitString(string s) {
        return dfs(s,0,0,0);
    }
};

#endif // BH5747_H_INCLUDED
