#ifndef OFFER-20_H_INCLUDED
#define OFFER-20_H_INCLUDED

class Solution {
public:
    int fun(string s){
        if(s.size()>0&&(s[0]=='+'||s[0]=='-'))
            s = s.substr(1);
        int size = s.size();
        int cur=0,pre=0;
        int flag = false;
        for(int i=0; i<size; ++i){
            if(s[i]=='.'){
                if(flag) return 0;
                flag = true;
                pre = cur;
                cur = 0;
            }else
            if(s[i]>='0'&&s[i]<='9'){
                ++ cur;
            }else{
                return 0;
            }
        }
        if(pre==0&&cur==0) return 0;
        if(flag) return 2;
        return 1;
    }
    bool isNumber(string s) {
        int size = s.size();
        int bi=0,end=size;
        while(bi<size&&s[bi]==' ') ++bi;
        while(end>0&&s[end-1]==' ') --end;
        s = s.substr(bi,end-bi);
        size = s.size();
        for(bi=0; bi<size; ++bi){
            if(s[bi]=='e'||s[bi]=='E'){
                return fun(s.substr(0,bi))&&(fun(s.substr(bi+1))==1);
            }
        }
        return fun(s);
    }
};

#endif // OFFER-20_H_INCLUDED
