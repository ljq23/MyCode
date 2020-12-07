/*
    名称：使用两个栈实现队列
    时间：2019/1/7
*/
#include<cstdio>
#include<stack>
using namespace std;
struct queue{
    stack<int> data,po;
    void front(int i){
        data.push(i);
        printf("%d",i);
    }
    void rear(){
        shfit();
        if(po.empty()){
            printf("queue is empty\n");
            return ;
        }
        printf("%d",po.top());
        po.pop();
    }
    void shfit(){
        if(!po.empty()) return ;
        while(!data.empty()){
            po.push(data.top());
            data.pop();
        }
    }
};

int main(){
    queue q;
    q.front(2);q.front(3);q.front(4);q.front(1);q.front(5);q.front(6);
    printf("\n");
    q.rear(); q.rear(); q.rear(); q.rear(); q.rear(); q.rear();
    return 0;
}
