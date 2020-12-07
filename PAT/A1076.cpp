#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1000+5;

struct node{
    int index,step;
    node(){}
    node(int ii,int ss){
        index = ii;
        step = ss;
    }
};
int N,L;
vector<int> fan[maxn];
queue<node> q;
int ans;
bool visited[maxn];

void bfs(int index,int level){
    q.push(node(index,0));
    visited[index] = true;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        int flag,size = fan[top.index].size();
        for(int i=0; i<size; ++i){
            flag = fan[top.index][i];
            if(visited[flag]||top.step == level)
                continue ;
            ++ ans;
            visited[flag] = true;
            q.push(node(flag,top.step+1));
        }
    }
}
int main(){
    #ifdef INPUT
        freopen("input","r",stdin);
//        freopen("output","w",stdout);
    #endif // INPUT
    int number,tmp;
    int k,userId;
    while(scanf("%d%d",&N,&L)!=EOF){
        for(int i=0; i<N; ++i)
            fan[i].clear();
        for(int i=0; i<N; ++i){
            scanf("%d", &number);
            for(int j=0; j<number; ++j){
                scanf("%d", &tmp);
                fan[tmp-1].push_back(i);
            }
        }
        scanf("%d", &k);
        for(int i=0; i<k; ++i){
            scanf("%d", &userId);
            ans = 0;
            memset(visited,false,sizeof(visited));
            bfs(userId-1,L);
            printf("%d\n", ans);
        }
    }

    return 0;
}
