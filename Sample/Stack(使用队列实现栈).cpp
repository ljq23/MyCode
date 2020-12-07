/*
    名称：使用两个队列实现栈
    时间：2019/1/7
*/
#include<cstdio>
#include<queue>
using namespace std;

struct stack{
    queue<int> q1,q2;
    void pop(){
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap();
    }
    void top(){
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        printf("%d",q1.front());
        q2.push(q1.front());
        q1.pop();
        swap();
    }
    void push(int i){
        q1.push(i);
    }
    void swap(){
        queue<int> temp=q1;
        q1 = q2;
        q2 = temp;
    }
};

int main(){
    stack st;
    st.push(1);st.push(2);st.push(3);st.push(4);st.push(5);st.push(6);
    st.top();st.pop();
    st.top();st.pop();
    st.top();st.pop();
    st.top();st.pop();
    st.top();st.pop();
    st.top();st.pop();
    return 0;
}
