/*
    简单选择排序，从小到大
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
void SelectionSort(vector<int> &arry){
    if(arry.empty()||arry.size()<2)
        return ;
    for(int i=0;i<arry.size();i++)
    {
        int temp = i;
        for(int j=i+1;j<arry.size();j++)
            if(arry[j]<arry[temp])
                temp = j;
        myswap(arry[i],arry[temp]);
    }
}
void myprint(vector<int> &arry){
    int size = arry.size()-1;
    for(int i=0;i<size;i++)
        printf("%d,",arry[i]);
    printf("%d\n",arry[size]);
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
    SelectionSort(arry); //调用排序函数
    myprint(arry);
    return 0;
}
