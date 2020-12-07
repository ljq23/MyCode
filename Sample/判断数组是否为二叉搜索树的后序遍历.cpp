#include<cstdio>
#include<vector>
using namespace std;

bool fun1(vector<int>& arry,int l,int r){
    if(l>=r) return true ;
    int index=-1;
    for(int i=0;i<r;i++){
        if(arry[i]>arry[r]){
            index = i;
            break ;
        }
    }
    for(int i=index;i<r;i++){
        if(arry[i]<arry[r]){
            return false;
        }
    }
    if(index==-1) return fun1(arry,l,r-1);
    return fun1(arry,l,index-1)&&fun1(arry,index,r-1); //2686707 表示对数据没有初始化
}
int main(){
    vector<int> arry;
    arry.resize(6);
    arry[0] = 1;
    arry[1] = 2;
    arry[2] = 3;
    arry[3] = 4;
    arry[4] = 5;
    arry[5] = 6;
if(fun1(arry,0,arry.size()-1)){
//    if(true){
        printf("YES\n");
    }else
        printf("NO\n");
    return 0;
}
