#include <stdio.h>

int main()
{
    char filename[] = "main3.c";
    char file_read[100]={0};
    char main_func[] = "int main()";
    FILE *fp, *txt;
    fp = fopen(filename, "r+");
    fseek(fp, 0, SEEK_SET);
    txt = fopen("main3.txt", "w+");

    int test=1;
    for(int row=1, i=0; fgets(file_read, 255, fp)!=NULL; row++, i=0){

        if(test){
            while(main_func[i]){
                if(main_func[i]==file_read[i]) test = 0;
                else {test = 1; break;}
                i++;
            }if(test==0) printf("%02d %s", row, file_read);
        }
        fprintf(txt, "%s", file_read);
    }

    fclose(txt);
    fclose(fp);
}
