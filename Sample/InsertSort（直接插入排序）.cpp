/*
    直接插入排序，从小到大
     时间：2019/1/4
*/
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
using namespace std;

void myswap(int &a,int &b){
/**
    如果 a 与 b相等时，异或值为0
    a = a^b;
    b = a^b;
    a = a^b;
**/
   int temp = a ;
    a = b;
    b = temp ;
}
void InsertSort(vector<int> &arr){
    if(arr.empty()||arr.size()<2)
        return ;
    for(int i=1;i<arr.size();i++)
        for(int j=i-1;j>=0&&arr[j+1]<arr[j];j--)
            myswap(arr[j],arr[j+1]);
}
void myprint(vector<int> &arr){
    int size = arr.size()-1;
    for(int i=0;i<size;i++)
        printf("%d,",arr[i]);
    printf("%d\n",arr[arr.size()-1]);
}
void getRandomArray(vector<int> &arry,int size,int MaxValue){
    srand(time(NULL));
    for(int i=0;i<size;i++)
        arry.push_back(rand()%(MaxValue+1));
}
int main()
{
    int ArrySize = 20 ,MaxValue = 200;
    vector<int> arry;
    getRandomArray(arry,ArrySize,MaxValue);
    myprint(arry);
    InsertSort(arry); //调用排序函数
    myprint(arry);
    return 0;
}
