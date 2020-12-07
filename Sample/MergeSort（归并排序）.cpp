/*
    归并选择排序，从小到大
    时间：2019/1/4
*/
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
using namespace std;

void Merge(vector<int>& arry,int l,int mid,int r){
    vector<int> help ;
    int p1 = l, p2 = mid+1 ;
    while(p1<=mid&&p2<=r)
        help.push_back(arry[p1]<arry[p2]?arry[p1++]:arry[p2++]) ;//从小到大排序
    while(p1<=mid) help.push_back(arry[p1++]);
    while(p2<=r) help.push_back(arry[p2++]);
    for(int i=0;i<help.size();i++)
        arry[l+i] = help[i];
}
void MergeSort(vector<int> &arry,int l,int r){
    if(l==r) return ;
    int mid = l + ((r-l)>>1) ;
    /*
        error: int mid = l + (r-l)>>1 ;
        '+' 优先级比 '>>' 高
    */
    MergeSort(arry,l,mid);
    MergeSort(arry,mid+1,r);
    Merge(arry,l,mid,r);
}
void MergeSort(vector<int> &arry){
    if(arry.empty()||arry.size()<2) return ;
    MergeSort(arry,0,arry.size()-1);
}
void myprint(vector<int> &arry){
    printf("%d",arry[0]);
    for(int i=1;i<arry.size();i++)
        printf(",%d",arry[i]);
    printf("\n");
}
void getRandomArray(vector<int> &arry,int size,int MaxValue){
    srand((unsigned)time(NULL));
    for(int i=0;i<size;i++)
        arry.push_back(rand()%(MaxValue+1));
}
int main()
{
    vector<int> arry;
    getRandomArray(arry,15,200);
    myprint(arry);
    MergeSort(arry);
    myprint(arry);
    return 0;
}
