#include<iostream>
#include<cstring>
#include<cstdio>
#include<iterator>
#include<stack>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<cstdlib>
#include<map>
using namespace std;
const int maxn = 10000;

struct node{
    int from,to;
    int cost;
    bool operator< (const node &b) const {
        return cost > b.cost;
//        由于优先队列是通过小于号判断的，所以需要重载小于号，将其改变方式，成为cost小优先
    }
    node(int ff,int tt,int cc){
        to = tt;
        from = ff;
        cost = cc;
    }
    node(){}
};
vector<node> v[maxn];
bool visited[maxn];

void prime(int from,long long &res){
    priority_queue<node> q;
    visited[from] = true;
    for(int i=0;i<v[from].size();i++){
        q.push(v[from][i]);
    }
    node tmp;
    while(!q.empty()){
        tmp = q.top();
        q.pop();
        if(!visited[tmp.to]){
            res += tmp.cost;
            for(int i=0;i<v[tmp.to].size();i++){
                q.push(v[tmp.to][i]);
            }
            visited[tmp.to] = true;
        }
    }
}
int main(){
    int n;
    long long res;
    while(scanf("%d",&n)!=EOF){
        v.clear();
        memset(visited,false,sizeof(visited));
        int to,from,cost;
        for(int i=0;i<n;i++){
//            无向图
            scanf("%d%d%d",&from,&to,&cost);
            v[from].push_back(node(from,to,cost));
            v[to].push_back(node(to,from,cost));
        }
        res = 0;
        prime(1,res);
        printf("%lld\n",res);
    }
    return 0;
}
