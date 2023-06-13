#include <stdio.h>
#include <stdlib.h>

int main() {
    float *fp;
    fp = (float *) malloc(sizeof(float));
    if(!fp) {
        printf("malloc() failed");
        return 1;
    }
    printf("Address: %p", fp);
    return 0;
}