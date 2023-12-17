#include <stdio.h>

int main()
{
    int i = 12345;

    if(i>0){
        int thousand = i%10000/1000;
        int digit = i%10;

        i = i-thousand*1000 + thousand - digit + digit*1000;
    }
    printf("%d", i);
}
