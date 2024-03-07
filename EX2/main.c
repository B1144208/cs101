#include <stdio.h>

int main() {
    FILE* fp;
    int a[3] = {0, 1, 2};
    char b[] = "ABC";
    float c[3] = {1.1, 1.2, 1.3};

    fp = fopen("a.bin", "wb+");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }
    fwrite(a, sizeof(a), 1, fp);
    fwrite(b, sizeof(b), 1, fp);
    fwrite(c, sizeof(c), 1, fp);
    fclose(fp);

    int ra[3];
    char rb[4];
    float rc[3];

    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }
    fread(ra, sizeof(ra), 1, fp);
    fread(rb, sizeof(rb), 1, fp);
    fread(rc, sizeof(rc), 1, fp);
    fclose(fp);

    for (int i = 0; i < 3; i++) {
        printf("%d ", ra[i]);
    }
    printf("\n%s\n", rb);
    for (int i = 0; i < 3; i++) {
        printf("%.6f ", rc[i]);
    }
    printf("\n");

    return 0;
}
