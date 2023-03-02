#include <stdlib.h>
#include <stdio.h>

//dateaccessioned,biblionumber,barcode,author,title,Edition,publishercode,place,copyrightdate,isbn,itemcallnumber,itype,onloan,,


//INCOMLPETE

typedef struct libData{
    char dateaccesioned[20];
    int biblionumber;
    
}Data;

int main(){

    FILE* fp = fopen("BITS Library Database.csv", "r");
    fscanf(fp, "%*[^\n]\n");

    while(!feof(fp)){

    }
}