#ifndef BH1678_H_INCLUDED
#define BH1678_H_INCLUDED

class Solution {
public:
    string interpret(string command) {
        if(command.size()==0) return "";
        string s = "";
        for(int i=0; i<command.size(); ++i){
            if(command[i]=='G'){
                s += "G";
            }else if(command[i]=='('){
                if(command[i+1]==')')
                    s += "o";
                else{
                    s += "al";
                }
            }
        }
        return s;
    }
};

#endif // 1678_H_INCLUDED
