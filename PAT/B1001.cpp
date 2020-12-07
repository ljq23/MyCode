#include<cstdio>

int main(){
    int count,n;
    while(scanf("%d",&n)!=EOF){
        count = 0;
        while(n!=1){
            if(n%2){
                n = (3*n+1)/2;
            }else{
                n = n/2;
            }
             count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
