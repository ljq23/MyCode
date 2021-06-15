#ifndef BH1805_H_INCLUDED
#define BH1805_H_INCLUDED

class Solution {
public:
    string help(string s){
        int bi = s.size()-1;
        for(int i=0; i<=s.size()-1; ++i){
            if(s[i]!='0'){
                bi = i;
                break;
            }
        }
        return s.substr(bi);
    }
    int numDifferentIntegers(string word) {
        set<string> ans;
        for(int i=0; i<word.size();){
            if(word[i]>='0'&&word[i]<='9'){
                string tp = "";
                while(i<word.size()&&word[i]>='0'&&word[i]<='9'){
                    tp += word[i];
                    ++ i;
                }
                ans.insert(help(tp));
            }else{
                ++ i;
            }
        }
        return ans.size();
    }
};

#endif // BH1805_H_INCLUDED
