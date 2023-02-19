#include <stdlib.h>
#include <stdio.h>

int lengthTR(char *str, int acc) {
    if (*str == '\0') {
        return acc; 
    }
    else {
        return lengthTR(str + 1, acc + 1);
    }
}

int main(){
    char input[20] = "hello";
    int len = lengthTR(input, 0);
    printf("%d", len);
}