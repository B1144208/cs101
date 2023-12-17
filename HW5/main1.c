#include <stdio.h>

int main()
{
    int x = 7;

    for(int i=1; i<=7; i++){
        printf("%*c", x-i+1, ' ');
        for(int j=1; j<=i; j++){
            printf("%d ", i);
        }printf("\n");
    }
}
