#include <stdio.h>
#include <stdlib.h>

int const_tri(int * const p, int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;

    p[0] = 0;
    p[1] = 1;
    p[2] = 1;

    int temp;

    for (int i = 3; i <= n; i++) {
        temp = p[0] + p[1] + p[2];

        p[0] = p[1];
        p[1] = p[2];
        p[2] = temp;
    }

    return p[2];
}


int main() {
    const int x = 1;
    const int * q = &x;
    int * const p = (int*)malloc(3 * sizeof(int));

    p[0] = *q;
    p[1] = *q;
    p[2] = (*q)*2;
    printf("%d %d %d\n", p[0], p[1], p[2]);
    printf("%ld %ld %ld\n", &p[0], &p[1], &p[2]);

    int result = const_tri(p, 4);
    printf("%d\n", result);

    free(p);
    free(q);
    return 0;
}