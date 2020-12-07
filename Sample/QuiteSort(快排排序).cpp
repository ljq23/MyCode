/*
    快速选择排序，从小到大
    时间：2019/1/5
*/
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
using namespace std;

int getRandomNumber(){
    srand(time(NULL));
    return rand();
}
void myswap(vector<int>& arry,int i,int j){
    int temp = arry[i] ;
    arry[i] = arry[j];
    arry[j] = temp ;
}
vector<int> myparition(vector<int>& arry,int l,int r){
    int le = l-1 , more = r;
    while(l<more){
        if(arry[l]<arry[r]){
            myswap(arry,++le,l++);
        }else if(arry[l]>arry[r]){
            myswap(arry,--more,l);
        }else{
            l++;
        }
    }
    myswap(arry,more,r);
    vector<int> temp;
    temp.push_back(le+1);temp.push_back(more);
    return temp;
}
void QuiteSort(vector<int>& arry,int l,int r){
    if(l<r){
        myswap(arry,l+(getRandomNumber()%(r-l+1)),r);
        vector<int> p = myparition(arry,l,r);
        QuiteSort(arry,l,p[0]-1);
        QuiteSort(arry,p[1]+1,r);
    }
}
void QuiteSort(vector<int>& arry){
    if(arry.empty()||arry.size()<2) return ;
    QuiteSort(arry,0,arry.size()-1);
}
void myprint(vector<int> &arry){
    printf("%d",arry[0]);
    int size = arry.size();
    for(int i=1;i<size;i++)
        printf(",%d",arry[i]);
    printf("\n");
}
void getRandomArray(vector<int> &arry,int size,int MaxValue){
    srand(time(NULL));
    for(int i=0;i<size;i++)
        arry.push_back(rand()%(MaxValue+1));
}
int main()
{
    vector<int> arry;
    getRandomArray(arry,15,200);
    myprint(arry);
    QuiteSort(arry); //调用排序算法
    myprint(arry);
    return 0;
}

/*
//
//   时间:2019/1/7
//
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;

int getRandomNumber(){
    srand(time(NULL));
    return rand();
}
void myswap(vector<int>& arry,int i,int j){
    int temp = arry[i];
    arry[i] = arry[j];
    arry[j] = temp;
}
vector<int> mypartition(vector<int>& arry,int l,int r){
    int les = l-1, more = r ;
    while(l<more){
        if(arry[l]<arry[r])
            myswap(arry,++les,l++);
        else if(arry[l]>arry[r])
            myswap(arry,--more,l);
        else
            l++;
    }
    myswap(arry,more,r); //忘记最后一次的交换
    vector<int> temp;
    temp.push_back(les+1);
    temp.push_back(more);
    return temp;
}
void QuiteSort(vector<int>& arry,int l,int r){
    if(l<r){   //写成 while(l<r)
        myswap(arry,l+(getRandomNumber()%(r-l+1)),r); //中间参数忘加 l
        vector<int> p = mypartition(arry,l,r);
        QuiteSort(arry,l,p[0]-1);
        QuiteSort(arry,p[1]+1,r);
    }
}
void QuiteSort(vector<int>& arry){
    if(arry.empty()||arry.size()<2) return ;
    QuiteSort(arry,0,arry.size()-1);
}
void getRandomArray(vector<int>& arry,int size,int MaxValue){
    srand(time(NULL));
    for(int i=0;i<size;i++)
        arry.push_back(rand()%(MaxValue+1));
}
void myprint(vector<int>& arry){
    int size = arry.size()-1;
    printf("%d",arry[0]);
    for(int i=1;i<size;i++)
        printf(",%d",arry[i]);
    printf("\n");
}
int main(){
    vector<int> arry;
    getRandomArray(arry,20,200);
    myprint(arry);
    QuiteSort(arry);
    myprint(arry);
    return 0;
}
*/
