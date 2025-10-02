#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("Hello, world!\n");   // пишем строку
    // !!! буфер stdout ещё не сброшен, потому что нет \n или fflush (но в Linux \n обычно сбрасывает на терминал, чтобы было наглядно можно убрать \n)

    pid_t pid = fork();

    if (pid == 0) {
        // ребёнок
        // exit(0);   // попробуй сначала exit
        _exit(0);     // потом попробуй _exit
    } else {
        // родитель
        wait(NULL);
    }

    return 0;
}
