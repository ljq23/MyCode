#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<iostream>
#include<map>
using namespace std;
const int maxn = 1000;

int gnext[maxn];
void fail(string& str){
//  i 表示 字符串相等的长度 ， j 表示 str 的位置
    int size = str.size();
    gnext[0] = -1;
    int i=-1,j=0;
    while(j<size-1){
        if(i==-1 || str[i]==str[j] ){
            gnext[++j] = ++i;
        }else{
            i = gnext[i];
        }
    }
}
int kmp(string& str1,string& str2,int pos)
{
    //检查字符串
    int i=pos,j=0;
    int size1 = str1.size(),size2 = str2.size();
    while(i<size1 && j <size2){
        if(j==-1 || str1[i]==str2[j]){
            i++;
            j++;
        }else{
            j = gnext[j];
        }
    }
    return j == size2 ? i-j:-1;
}
int main(){
    int n,size,pos;
    string str1,str2;
    bool flag;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            flag = false;
            cin>>str1>>str2;
            fail(str2);
            size = str1.size();
            for(int i=0;i<size;){
                pos = kmp(str1,str2,i);
                if(pos!=-1){
                    if(flag) printf(" ");
                    printf("%d",pos);
                    flag = true;
                }
                i++;
            }
            printf("\n");
        }
    }
    return 0;
}
