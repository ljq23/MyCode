#ifndef BH5749_H_INCLUDED
#define BH5749_H_INCLUDED

class Solution {
public:

    int getMinSwaps(string num, int k) {
        int ans = 0;
        string target = num;
        for(int i=0; i<k; ++i){
            next_permutation(target.begin(),target.end());
        }
        while(target.size()){
            int pos = num.rfind(target.back());
            ans += target.size()-1-pos;
            target.pop_back();
            num.erase(num.begin()+pos);
        }
        return ans;
    }
};

#endif // BH5749_H_INCLUDED
