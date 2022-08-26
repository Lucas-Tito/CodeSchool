#include<stdio.h>

int Fabio(int n, int m){
    int fabio=0;
    
    if(n<3 || m<3) return 1;
    else if(n%2==0 && m%2!=0) fabio = Fabio(n-1, m)+1;
    else if(n%2!=0 && m%2==0) fabio = Fabio(n-1, m-2)+2;
    else if(n%2==0 && m%2==0) fabio = Fabio(n-2, m-1)+3;
    else if(n%2!=0 && m%2!=0) fabio = Fabio(n, m-1)+4;
    
    return fabio;
}

int main(){
    
    int n, m;
    scanf("%d %d",&n, &m);
    
    printf("%d", Fabio(n, m));
    
    
    return 0;
}