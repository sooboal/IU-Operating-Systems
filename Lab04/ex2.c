#include <stdio.h> // input/output
#include <stdlib.h> // malloc, rand
#include <time.h> // time
#include <unistd.h> // fork, exit
#include <sys/types.h> // pid_t
#include <sys/wait.h> // wait
#define ll long long

double now_ms(void) { // Get current time
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000.0 + ts.tv_nsec / 1e6; // From seconds to ms, from nanoseconds to ms
}

int main() {
    int n;
    int M = 120;    

    scanf("%d", &n);

    if (n <= 0) {
        printf("Bad n\n");
        exit(1);
    }

    printf("Processes: %d, Elements: %d\n", n, M);

    int *u = malloc(sizeof(int)*M), *v = malloc(sizeof(int)*M);

    for (int i = 0; i < M; i++) {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }

    FILE *fw = fopen("temp.txt", "w");
    if (fw) fclose(fw);

    double t0 = now_ms(); // Take time of starting

    int a = M / n; // Elements per process
    int extra = M % n; // Extra elements for some processes

    for (int i = 0; i < n; i++) {
        int start, end;
        if (i < extra) {
            start = (i + 1) * a;
            end = start + a + 1;
        } else {
            start = i * a + extra;
            end = start + a;
        }
        pid_t pid = fork();
        if (pid < 0) {
            printf("Fork %d failed\n", i);
            exit(1);
        } else if (pid == 0) {
            ll part_sum = 0;

            for (int j = start; j < end; j++) {
                part_sum += u[j] * v[j];
            }

            FILE *fa = fopen("temp.txt", "a"); // append mode. Just adding line in the end.
            if (fa) {
                fprintf(fa, "%lld\n", part_sum); // Write result to file
                fclose(fa);
            }
            exit(0);
        }
    }

    for (int i = 0; i < n; i++) { 
        wait(NULL); // Parent need to know that his child is dead(because he doesn't want zombie apocalypse) but he doesn't care how. 
    }

    FILE *fr = fopen("temp.txt", "r");
    ll total = 0, x = 0;
    while (fr && fscanf(fr, "%lld", &x) == 1) total += x;
    if (fr) fclose(fr);
    
    double t1 = now_ms();

    ll check = 0;
    for (int i = 0; i < M; i++) check += u[i] * v[i];

    printf("Result: %lld\n", total);
    printf("Check: %lld\n", check);
    printf("Time: %.3f\n", t1 - t0);

    free(u); free(v);

    return 0;
}