#ifndef OFFER-31_H_INCLUDED
#define OFFER-31_H_INCLUDED

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int s1=pushed.size(),s2=popped.size();
        if(s1!=s2) return false;
        int b1,b2;
        for(int i=0; i<s1; ++i){
            if(pushed[i]==popped[0]){
                b1 = b2 = i;
                break;
            }
        }
        --b1,++b2;
        for(int i=1; i<s2; ++i){
            if(b1>=0&&popped[i]==pushed[b1]){
                -- b1;
            }else
            if(b2<s2&&popped[i]==pushed[b2]){
                ++ b2;
            }else{
                return false;
            }
        }
        return true;
    }
};

#endif // OFFER-31_H_INCLUDED
