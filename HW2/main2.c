#include <stdio.h>

int main()
{
    char filename[] = "main2.c";
    char file_read[100]={0};
    FILE *fp, *txt;
    fp = fopen(filename, "r+");
    fseek(fp, 0, SEEK_SET);
    txt = fopen("main2.txt", "w+");

    while(fgets(file_read, 255, fp)!=NULL){
        fprintf(txt, "%s", file_read);
    }

    fclose(txt);
    fclose(fp);
}
