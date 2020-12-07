/*
    冒泡排序，从小到大
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
void bubbleSort(vector<int> &arr){
    if(arr.empty()||arr.size()<1) return ;

    for(int i=arr.size()-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1])
                myswap(arr[j],arr[j+1]);
        }
    }
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
    vector<int> arry;
    getRandomArray(arry,20,200);
    myprint(arry);
    bubbleSort(arry);
    myprint(arry);
    return 0;
}
