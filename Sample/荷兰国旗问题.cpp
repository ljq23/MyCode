/*
    荷兰问题
    时间：2019/1/6
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main(){
    int time;
    cin>>time;
    string str;
    while(time--){
        cin>>str;
        int l=0;
        int les=l-1,more=str.size();
        while(l<more){
            if(str[l]=='R'){
                swap(str[++les],str[l++]);
            }
            else if(str[l]=='B'){
                swap(str[--more],str[l]);
            }
            else if(str[l]=='W'){
                l++;
            }
            /*
              if(str[l]=='R'){
                swap(str[++les],str[l++]);
              }
              if(str[l]=='B'){
                swap(str[--more],str[l]);
              }
              if(str[l]=='W'){
                l++;
              }
              这种使用方式，会使已经完成归位的字母再次交换，导致错误，因此必须使用if-else
            */
        }
        cout<<str<<endl;
    }
    return 0;
}
