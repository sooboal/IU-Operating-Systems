#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    /*
// 2 snippet
int main() {
    char * const p = malloc(6);
    memset(p, ’A’, 6);
    (*p)++;
    //p = NULL;
    printf("%c\n", *p++);
    free(p);
        
    return 0;
}
    */

    /* 3 snippet
int main () {
    double c = 1.5;
    const double * const p = &c;
    c+=0.5;
    //*p = c;
    //p = NULL;
    printf("%f\n", *p);
    return 0;
}
    */