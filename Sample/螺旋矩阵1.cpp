#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <iterator>
#include <utility>
using namespace std;

const int N = 110;
int q[N][N] = {0};

int main(){
    #ifdef INPUT
//        freopen("input","r",stdin);
//        freopen("output","w",stdout);
    #endif // INPUT
    ios::sync_with_stdio(false);
    cin.fill(NULL);

    int n,m;
    cin >> n >> m;

    int dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
    int x=0,y=0,d=1;
    for(int i=1; i<=n*m; ++i){
        q[x][y] = i;
        int a=x+dx[d],b=y+dy[d];
        if(a<0||a>=n||b<0||b>=m||q[a][b]){
            d = (d+1)%4;
            a = x+dx[d], b = y+dy[d];
        }
        x = a, y = b;
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            printf("%d ",q[i][j]);
        }
        printf("\n");
    }
    return 0;
}
