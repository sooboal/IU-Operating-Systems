#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int int_var = INT_MAX;
    unsigned short uns_short_var = USHRT_MAX;
    long sign_long_int_var = LONG_MAX;
    float float_var = FLT_MAX;
    double double_var = DBL_MAX;

    printf("integer: %d, %ld\n", int_var, sizeof(int));
    printf("unsigned short integer: %u, %ld\n", uns_short_var, sizeof(unsigned short));
    printf("signed long int: %ld, %ld\n", sign_long_int_var, sizeof(long));
    printf("float: %f, %ld\n", float_var, sizeof(float));
    printf("double: %f, %ld\n", double_var, sizeof(double));

    return 0;
}
