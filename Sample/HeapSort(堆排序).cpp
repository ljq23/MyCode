/*
    堆排序问题,从小到大排序
    时间：2019/1/6
*/
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

void swap(vector<int>& arry,int i,int j){
    int temp = arry[i];
    arry[i] = arry[j];
    arry[j] = temp;
}
void heapInsert(vector<int>& arry,int index){
    while(arry[index]>arry[(index-1)/2]){ //细节注意
        swap(arry,index,(index-1)/2);
        index = (index-1)/2;
    }
}
void heapify(vector<int>& arry,int index,int heapsize){
    int left = index*2+1;
    while(left<heapsize){
        if(left+1<heapsize&&arry[left]<arry[left+1])
            left = left+1 ;
        if(arry[index] >= arry[left])  break ;
        swap(arry,index,left);
        index = left ;
        left = index*2+1;
    }
}
void heapSort(vector<int>& arry){//从小到大排序，建立大根堆；从大到小排序，建立小根堆
    if(arry.empty()||arry.size()<2) return ;
    int heapsize = arry.size();
    for(int i=1;i<heapsize;i++){
        heapInsert(arry,i);
    }//堆的初始化
    swap(arry,0,--heapsize);
    while(heapsize>0){
        heapify(arry,0,heapsize);
        swap(arry,0,--heapsize);
    }
}
void myprint(vector<int>& arry){
    int size = arry.size()-1;
    printf("%d",arry[0]);
    for(int i=1;i<size;i++)
        printf(",%d",arry[i]);
    printf("\n");
}
void getRandomArray(vector<int>& arry,int size,int MaxValue){
    srand(time(NULL));
    for(int i=0;i<size;i++)
        arry.push_back(rand()%(MaxValue+1));
}
void copyfun(vector<int>& arry,vector<int>& cp){
    int size = arry.size();
    for(int i=0;i<size;i++)
        cp.push_back(arry[i]);
}
bool isEqule(vector<int>& arry,vector<int>& cp){
    if((arry.empty()&&!cp.empty())||(!arry.empty()&&cp.empty()))
        return false ;
    if(arry.empty()&&cp.empty()) return true;
    if(arry.size()!=cp.size()) return false;
    int size = arry.size();
    for(int i=0;i<size;i++)
        if(arry[i]!=cp[i])
            return false ;
    return true ;
}
int main(){
    vector<int> arry,cp;
    int testTime = 500000;
    int maxSize = 100;
    int maxValue = 200;
    bool flag = true ;
    srand(time(NULL));
/*********对堆排序进行测试***********/
    while(testTime--){
        arry.clear();
        cp.clear();
        getRandomArray(arry,rand()%(maxSize+1),maxValue);
        copyfun(arry,cp);
        heapSort(arry);
        sort(cp.begin(),cp.end());
        flag = isEqule(arry,cp);
        if(!flag){
            myprint(cp);
            myprint(arry);
            break ;
        }
    }
    if(!flag){
        printf("No\n");
    }else
        printf("Yes\n");
/*************测试结束**************/
    return 0;
}
