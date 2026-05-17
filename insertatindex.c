#include <stdio.h>

int* insertat(int *a , int index , int value , int n){
    if(index < 0 || index > n){
        puts("wrong index");
    }
    int m = n + 1;
    int *b =(int*)malloc(m * sizeof(int));
    for(int i = 0;i < m;i++){
        if(i == index){
            b[i] = value;
        }else if(i < index){
            b[i] = a[i];
        }else{
            b[i] = a[i - 1];
        }
    }
    return b;
}

void main() {
    int a[] = {10 , 20 , 30 , 40};
    int *p = insertat(a , 1 , 50 , 4);
    for(int i = 0;i < 5;i++){
        printf("%d " , p[i]);
    }

}

