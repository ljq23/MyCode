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
int num[N][N] = {0};

int main(){
    #ifdef INPUT
//        freopen("input","r",stdin);
//        freopen("output","w",stdout);
    #endif // INPUT
    ios::sync_with_stdio(false);
    cin.fill(NULL);

    int n,m;
    cin >> n >> m;

    int left=0,right=m;
    int up=0,down=n;
    int idx=1;

    while(idx<=n*m){
        for(int k=left; k<right; ++k){
            num[up][k] = idx;
            ++ idx;
        }
        for(int k=up+1; k<down; ++k){
            num[k][right-1] = idx;
            ++ idx;
        }
        if(idx>n*m) break;
        for(int k=right-2; k>=left; --k){
            num[down-1][k] = idx;
            ++ idx;
        }
        for(int k=down-2; k>up; --k){
            num[k][left] = idx;
            ++ idx;
        }
        ++left,++up,--right,--down;
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}
