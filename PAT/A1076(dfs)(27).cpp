#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1000+5;

int N,L;
vector<int> fan[maxn];
int ans;
int lev[maxn];
bool visited[maxn];

void dfs(int index,int level){
    if(level == L)
        return ;
    int size = fan[index].size();
    for(int i=0; i<size; ++i){
        int flag = fan[index][i];
        if(!visited[flag]&&level<L){
            ++ ans;
            visited[flag] = true;
        }
        if(lev[flag]>L) return ;
        lev[flag] = level;
        dfs(flag,level+1);
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
            memset(lev,0,sizeof(lev));
            visited[userId-1] = true;
            dfs(userId-1,0);
            printf("%d\n", ans);
        }
    }

    return 0;
}
