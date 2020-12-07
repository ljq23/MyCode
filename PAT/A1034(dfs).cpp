#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 2000+5;

struct node{
    int to;
    int cost;
    node(){}
    node(int tt,int cc){
        to = tt;
        cost = cc;
    }
};
int n,k;
bool visited[maxn];
int Tall[maxn];
map<string,int> sti;
map<int,string> its;
vector<node> v[maxn];
map<string,int> ans;

void dfs(int index){
    queue<node> q;
    q.push(node(index,0));
    int total = 0, boss = index, number = 0;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        int t = top.to;
        if(visited[t])
            continue ;
        visited[t] = true;
        total += Tall[t];
        ++ number;
        if(Tall[boss] < Tall[t])
            boss = t;
        for(int i=0;i<v[t].size();++i){
            if(visited[v[t][i].to])
                continue ;
            q.push(v[t][i]);
        }
    }
    if(number>2 && total>k*2){
        ans[its[boss]] = number;
    }
}
int main(){
    #ifdef INPUT
        freopen("input","r",stdin);
//        freopen("output","w",stdout);
    #endif // INPUT
    string name1,name2;
    int time;
    int b1,b2;
    while(scanf("%d%d",&n,&k)!=EOF){
        sti.clear(); its.clear();ans.clear();
        for(int i=0;i<n;++i) v[i].clear();
        memset(visited,false,sizeof(visited));
        memset(Tall,0,sizeof(Tall));
        for(int i=0; i<n; ++i){
            cin >> name1 >> name2 >> time;
            if(sti.find(name1)!=sti.end()){
                b1 = sti[name1];
            }else{
                b1 = sti.size();
                sti[name1] = b1;
                its[b1] = name1;
            }
            if(sti.find(name2)!=sti.end()){
                b2 = sti[name2];
            }else{
                b2 = sti.size();
                sti[name2] = b2;
                its[b2] = name2;
            }
            v[b1].push_back(node(b2,time));
            v[b2].push_back(node(b1,time));
            Tall[b1] += time;
            Tall[b2] += time;
        }

        for(int i=0; i<n; ++i){
            if(!visited[i]){
                dfs(i);
            }
        }
        printf("%d\n",ans.size());
        map<string,int>::iterator it = ans.begin();
        for( it; it != ans.end(); ++ it){
            cout << it->first << " " << it->second << "\n";
        }
    }

    return 0;
}
