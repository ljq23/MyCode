#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 2000+5;

int n,k;
bool visited[maxn];
int Tall[maxn];
int father[maxn];
map<string,int> sti,ans;
map<int,string> its;

int mfind(int index){
    if(father[index] != index)
        return mfind(father[index]);
    return index;
}
void join(int b1,int b2){
    int f1 = mfind(b1);
    int f2 = mfind(b2);
    if(f1 != f2)
        father[f2] = f1;
}
void fun(int boss){
    int maxV = boss;
    int number = 0,total = 0;
    for(int i=0; i<n; ++i){
        if(father[i] == boss){
            if(Tall[maxV] < Tall[i])
                maxV = i;
            ++ number;
            total += Tall[i];
        }
    }
    if(number>2 && total>k*2)
        ans[its[maxV]] = number;
}
void init(){
    for(int i=0; i<maxn; ++i)
        father[i] = i;
}
int main(){
    #ifdef INPUT
        freopen("input","r",stdin);
//        freopen("output","w",stdout);
    #endif // INPUT
    int time;
    string name1,name2;
    int b1,b2;
    while(scanf("%d%d",&n,&k)!=EOF){
        sti.clear(),its.clear(),ans.clear();
        memset(visited,false,sizeof(visited));
        memset(Tall,0,sizeof(Tall));
        init();
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
            join(b1,b2);
            Tall[b1] += time;
            Tall[b2] += time;
        }
        vector<int> boss;
        for(int i=0; i<n; ++i){
            if(father[i] == i)
                boss.push_back(i);
        }
        for(int i=0; i<boss.size(); ++i){
            fun(boss[i]);
        }
        printf("%d\n",ans.size());
        for(map<string,int>::iterator it = ans.begin();
                    it != ans.end(); ++ it){
                cout << it->first <<" "<< it->second <<"\n";
                    }
    }

    return 0;
}
