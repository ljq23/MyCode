#ifndef BH860_H_INCLUDED
#define BH860_H_INCLUDED

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a=0,b=0,c=0;
        for(int i=0;i<bills.size(); ++i){
//            cout << i+1 << ":" << a << "-" << b << "-" << c <<endl;
            if(bills[i]==5){
                ++ a;
            }else if(bills[i]==10){
                if(a>0){
                    -- a;
                    ++ b;
                    continue;
                }
                return false;
            }else{
                if(a>0&&b>0||a>3){
                    ++c;
                    if(b==0) a -=3;
                    else --a,--b;
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};

#endif // BH860_H_INCLUDED
