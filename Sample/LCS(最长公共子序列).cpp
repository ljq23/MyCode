#include<iostream>
#include<cstring>
#include<cstdio>
#include<iterator>
#include<stack>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<cstdlib>
#include<map>
using namespace std;
const int maxn = 1000+5;

int flag[maxn][maxn];

int main(){
    string str1 = "abcabbbc";
    string str2 = "abbc";
    memset(flag,0,sizeof(flag));
    for(int i=1;i<=str1.size();i++){
        for(int j=1;j<=str2.size();j++){
            if(str1[i-1]==str2[j-1]){
                flag[i][j] = flag[i-1][j-1]+1;
            }else{
                flag[i][j] = max(flag[i-1][j],flag[i][j-1]);
            }
        }
    }
    printf("%d\n",flag[str1.size()][str2.size()]);
    return 0;
}
