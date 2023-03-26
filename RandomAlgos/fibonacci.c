#include <stdlib.h>
#include <stdio.h>

int rfib(int n);
int ifib(int n);

int main(){
    int out = rfib(5);
    printf("%d\n", out);

    out = ifib(7);
    printf("%d", out);
    
}

int rfib(int n){
    if (n == 1) return 1;
    if (n == 2) return 1;

    return rfib(n-1) + rfib(n-2);
}

int ifib(int n){

    int i1 = 1;
    int i2 = 1;
    
    for (int j = 3; j <= n; j++){
        if (j % 2 == 0)
            i1 = i1 + i2;
        else
            i2 = i2 + i1;
    }
    if (n%2 != 0)
        return i2;
    else
        return i1;
}

