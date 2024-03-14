#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int n;
    time_t curtime;
    int lotto_num[70]={0};

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩:");

    do{
        scanf("%d", &n);
    }while(n<1 || n>5);

    FILE *fp;
    if((fp = fopen("lotto.txt", "w+")) == NULL){
        printf("Can not open the file...\n");
        exit(1);
    }
    srand((unsigned)time(&curtime));

    char current_time[30]={0};
    strcpy(current_time, ctime(&curtime));
    current_time[strlen(current_time)-1] = '\0';

    if(fprintf(fp, "========lotto649=========\n=%s=\n", current_time)<0)
        printf("Write file error\n");
    fclose(fp);

    if((fp = fopen("lotto.txt", "a+")) == NULL){
        printf("Can not open the file...\n");
        exit(1);
    }

    int num=0, i;
    for(i=1; i<=n; i++){
        if(fprintf(fp, "[%d]:", i)<0)
            printf("Write file error\n");

        for(int j=0; j<7; j++){
            if(lotto_num[num=rand()%69+1]==1) {--j; continue;}
            else lotto_num[num] = 1;

            if(fprintf(fp, " %2d", num)<0)
                printf("Write file error\n");
        }
        memset(lotto_num, 0, 70*sizeof(int));
        fprintf(fp, "\n");
    }
    for( ; i<=5; i++){
        if(fprintf(fp, "[%d]:=====================\n", i)<0)
            printf("Write file error\n");
    }
    fclose(fp);

    printf("已為您購買的%d組樂透組和輸出至lotto.txt", n);
}
