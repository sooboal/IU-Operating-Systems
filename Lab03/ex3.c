#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Directory {
    char *name;
    struct Directory *parent;  
    struct File **files;     
    size_t nf;   
    struct Directory **directories; 
    size_t nd;
    char *path; 
};

struct File {
    int id;
    char *name;
    int size;
    char *data;
    struct Directory *dir;
};

char *duplicate_string(struct File *file, const char *s) {
    size_t n = strlen(s) + 1;
    free(file->data);
    char *result = (char *)malloc(n);
    memcpy(result, s, n);
    return result;
}

void overwrite_to_file(struct File *file, const char *str) {
    if (!file) return;
    file->data = duplicate_string(file, str);
}

char * merge_strings(struct File *file, const char *s1, const char *s2) {
    size_t n1 = strlen(s1);
    size_t n2 = strlen(s2);
    free(file->data);
    char *result = (char *)malloc(n1 + n2 + 1);
    memcpy(result, s1, n1);
    memcpy(result + n1, s2, n2);
    result[n1 + n2] = '\0';
    return result;
}

void append_to_file(struct File* file, const char* str) {
    if (!file) return;
    file->data = merge_strings(file, file->data, str);
}

void printp_file(struct File* file) {
    if (!file) return;
    printf("%s/%s\n", file->dir->path, file->name);
}

void add_file(struct File* file, struct Directory* dir) {
    if (!file || !dir) return;
    
    file->size = (file->data) ? (int)strlen(file->data) : 0;

    size_t new_size = (dir->nf + 1) * sizeof(struct File*);
    struct File** new_files = realloc(dir->files, new_size);

    dir->files = new_files;
    dir->files[dir->nf++] = file;
    dir->nf = dir->nf + 1;

    file->dir = dir;
}

int main(void) {
    struct Directory root = { .name = "/", .parent = NULL, .files = NULL, .nf = 0,
                              .directories = NULL, .nd = 0, .path = "" };
    struct Directory home = { .name = "home", .parent = &root, .files = NULL, .nf = 0,
                              .directories = NULL, .nd = 0, .path = "home" };
    struct Directory bin  = { .name = "bin",  .parent = &root, .files = NULL, .nf = 0,
                              .directories = NULL, .nd = 0, .path = "bin" };

    struct File bash  = { .id = 1, .name = "bash",    .size = 0, .data = NULL, .dir = NULL };
    struct File ex31  = { .id = 2, .name = "ex3_1.c", .size = 0, .data = NULL, .dir = NULL };
    struct File ex32  = { .id = 3, .name = "ex3_2.c", .size = 0, .data = NULL, .dir = NULL };

    add_file(&bash, &bin);
    add_file(&ex31, &home);
    add_file(&ex32, &home);

    overwrite_to_file(&bash, "Bourne Again Shell!!");
    bash.size = (int)strlen(bash.data);

    overwrite_to_file(&ex31, "int printf(const char * format, ...);");

    overwrite_to_file(&ex32, "//This is a comment in C language");
    ex32.size = (int)strlen(ex32.data);

    printp_file(&bash);
    printp_file(&ex31);
    printp_file(&ex32);

    return 0;
}
