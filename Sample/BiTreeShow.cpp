#include<cstdio>
#include<stack>
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct BiTreeNode{
    int value;
    struct BiTreeNode *lchild,*rchild;
}Node;

Node* create(){
    Node* p;
    int value;
    scanf("%d",&value);
    if(value==-1){
        p = NULL;
    }else {
        p = (Node*)malloc(sizeof(Node));
        p->value = value;
        p->lchild = create();
        p->rchild = create();
    }
    return p;
}
void preOrder(Node* root){
    if(root==NULL) return ;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        printf("%d",root->value);
        if(root->rchild) st.push(root->rchild);
        if(root->lchild) st.push(root->lchild);
    }
}
void inOrder(Node* root){
    if(root==NULL) return ;
    stack<Node*> st;
    while(!st.empty()||root){
        if(root){
            st.push(root);
            root = root->lchild;
        }else{
            root = st.top();st.pop();
            printf("%d",root->value);
            root = root->rchild;
        }
    }
}
void posOrder(Node* root){
    if(root==NULL) return ;
    stack<Node*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        root = s1.top();
        s1.pop();
        s2.push(root);
        if(root->lchild) s1.push(root->lchild);
        if(root->rchild) s1.push(root->rchild);
    }
    while(!s2.empty()){
        printf("%d",s2.top()->value);
        s2.pop();
    }
}

int main(){
    Node* T = create();
    preOrder(T); printf("\n");
    inOrder(T);  printf("\n");
    posOrder(T);
    return 0;
}
