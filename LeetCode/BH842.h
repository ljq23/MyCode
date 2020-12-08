#ifndef BH842_H_INCLUDED
#define BH842_H_INCLUDED

class Solution {
public:
    int getNumber(string s,int left,int right){
        int val = 0;
        if(s[left]=='0') return INT_MIN;
        for(int i=left; i<right; ++i)
        {
            val = val*10 + (s[i]-'0');
        }
        return val;
    }
    int isOK(vector<int>& ans){
        if(ans[0]+ans[1] == ans[2])
            return 0;
        else if(ans[0]+ans[1] > ans[2])
            return 1;
        else
            return -1;
    }
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        int size = S.size();
        if(size < 3) return ans;
        for(int left=1; left<size; ++left){
            for(int right =size-1;right>left; --right){
                int leftval = getNumber(S,0,left);
                int midval = getNumber(S,left,right);
                int rightval = getNumber(S,right,size);
                ans.push_back(leftval);
                ans.push_back(midval);
                ans.push_back(rightval);
                int flag = isOK(ans);
                if(flag==0)
                    return ans;
                ans.clear();
            }
        }
        return ans;
    }
};

#endif // BH842_H_INCLUDED
