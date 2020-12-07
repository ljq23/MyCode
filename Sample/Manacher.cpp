#include <cstdio>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <iterator>
using namespace std;

void manacher(string& str)
{
    string s = "$";
    for(int i=0; i<str.size(); ++i)
        s += str[i], s += "#";
    vector<int> len(s.size()+1,0);
    int mx=0, ans=0, po=0;
    int index = -1;
    for(int i=1; i<=s.size(); ++i)
    {
        if(mx > i)
            len[i] = min(mx-i, len[2*po-1]);
        else
            len[i] = 1;
        while(s[i-len[i]] == s[i+len[i]])
            ++ len[i];
        if(len[i]+i > mx)
        {
            mx = len[i]+i;
            po = i;
        }
        if(ans < len[i])
        {
            ans = len[i];
            index = i;
        }
    }
    int pos = (index-len[index]+1)/2;
    for(int i=0; i<ans; ++i)
        printf("%c", str[i+pos]);
}
int main(){
    #ifdef INPUT
        freopen("input","r",stdin);
//        freopen("output","w",stdout);
    #endif // INPUT
//    ios::sync_with_stdio(false);
//    cin.fill(NULL);

    string str = "12345678987654321";
    manacher(str);
    return 0;
}
