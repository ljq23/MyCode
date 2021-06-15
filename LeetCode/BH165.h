#ifndef BH165_H_INCLUDED
#define BH165_H_INCLUDED

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        int tmp = 0;
        for(int i=0; i<version1.size(); ++i){
            if(version1[i]=='.'){
                v1.push_back(tmp);
                tmp = 0;
            }else{
                tmp = tmp*10 + version1[i]-'0';
            }
        }
        v1.push_back(tmp);
        tmp = 0;
        for(int i=0; i<version2.size(); ++i){
            if(version2[i]=='.'){
                v2.push_back(tmp);
                tmp = 0;
            }else{
                tmp = tmp*10 + version2[i]-'0';
            }
        }
        v2.push_back(tmp);
        int mv1=v1.size(),mv2=v2.size();
        int n1=0,n2=0;
        while(n1<mv1&&n2<mv2){
            if(v1[n1]<v2[n2]){
                return -1;
            }else if(v1[n1]>v2[n2]){
                return 1;
            }
            ++n1,++n2;
        }
        tmp = 0;
        while(n1<mv1) tmp += v1[n1++];
        if(tmp) return 1;
        while(n2<mv2) tmp += v2[n2++];
        if(tmp) return -1;
        return 0;
    }
};

#endif // BH165_H_INCLUDED
