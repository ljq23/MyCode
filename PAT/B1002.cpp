#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;

string p[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};//零 是 ling
void fun(int num){
    stack<string> st;
    if(num==0){
        cout<<p[num]<<endl;
        return ;
    }
    while(num){
        int tmp = num%10;
        st.push(p[tmp]);
        num /= 10;
    }
    cout<<st.top();st.pop();
    while(!st.empty()){
        cout<<" "<<st.top();
        st.pop();
    }
    cout<<endl;
}
int main(){
    string str;
    while(cin>>str){
        long long sum = 0;
        for(int i=0;i<str.size();i++)
            sum += str[i] - '0';
        fun(sum);
    }
    return 0;
}
