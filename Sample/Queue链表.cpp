#include <iostream>
using namespace std;

struct node{
    int val;
    struct node* next;
    node(){}
    node(int x){
        val = x;
        next = nullptr;
    }
};

struct queue{
    struct node *front=nullptr,*back=nullptr,*rear;

    queue(){
        rear = new node();
        front = rear;
        back = rear;
    }
    bool isEmpty(){
        return front == back;
    }

    void inQueue(int val){
        node *newn = new node(val);
        rear->next = newn;
        rear = newn;
        back = rear;
    }

    int outQueue(){
        if(isEmpty()) return -1;
        node *ans = front->next;
        node *before = front;
        front = front->next;
        delete before;
        return ans->val;
    }
};

int main(){
    queue q = queue();
    q.inQueue(1);
    q.inQueue(2);
    printf("%d\n",q.outQueue());
    printf("%d\n",q.outQueue());
    printf("%d\n",q.outQueue());

    return 0;
}
