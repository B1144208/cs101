#include <stdio.h>

int main()
{

    int count = 0;
    while(count<81){
        int i = count/9+1;
        int j = count%9+1;

        printf("%d*%d=%d\t", i, j, i*j);
        if(j%9==0) printf("\n");

        count++;
    }
}
