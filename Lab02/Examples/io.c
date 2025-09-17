#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

static void strip_nl(char *s){ s[strcspn(s, "\n")] = '\0'; }

int main(void){
    char buf[128];

    printf("Enter user name: ");
    if(!fgets(buf, sizeof buf, stdin)) return 1;
    strip_nl(buf);
    printf("User: %s\n", buf);

    const char s1[] = "OpSys";
    const char s2[] = {'O','p','S','y','s','\0'};
    printf("Strings: %s | %s\n", s1, s2);

    printf("Enter a float: ");
    double x = 0.0;
    for(;;){
        if(!fgets(buf, sizeof buf, stdin)) return 1;
        char *end = NULL;
        errno = 0;
        x = strtod(buf, &end);
        if(end != buf && errno == 0) break;
        printf("Try again: ");
    }
    printf("Float out: %.6f\n", x);

    printf("Enter a hexadecimal integer (e.g., 0x2A or 2A): ");
    long hx = 0;
    for(;;){
        if(!fgets(buf, sizeof buf, stdin)) return 1;
        char *p = buf;
        if(p[0]=='0' && (p[1]=='x' || p[1]=='X')) p += 2;
        char *end = NULL;
        errno = 0;
        hx = strtol(p, &end, 16);
        if(end != p && errno == 0) break;
        printf("Try again: ");
    }
    printf("Hex as decimal: %ld\n", hx);
    printf("Hex formatted: 0x%lX\n", hx);

    printf("Enter a word (scanf): ");
    char word[32];
    if(scanf("%31s", word) == 1){
        printf("Scanned word: %s\n", word);
        int c; while((c = getchar()) != '\n' && c != EOF){}
    }

    const char strnum[] = "2022";
    long n = strtol(strnum, NULL, 10);
    printf("String->int: %ld\n", n);

    char out[32];
    snprintf(out, sizeof out, "%ld", n);
    printf("Int->string: %s\n", out);

    return 0;
}

