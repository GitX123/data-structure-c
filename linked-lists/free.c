#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    float *fp;
    fp = (float *) malloc(sizeof(float));
    if(!fp) {
        printf("Memory allocation failed.");
        return 1;
    }

    *fp = 3.14159;
    printf("PI = %f, address: %p\n", *fp, fp);

    free(fp);
    return 0;
}