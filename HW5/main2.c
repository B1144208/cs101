#include <stdio.h>

int main()
{
    double PI = 4.0f, a = 1.0f;
    int i = 1;
    while(a>=0.000001){
        i+=2;
        a = (float)4/i;

        if(i/2%2==1)
            PI -= a;
        else
            PI += a;
    }

    printf("%.5f", PI);
}
