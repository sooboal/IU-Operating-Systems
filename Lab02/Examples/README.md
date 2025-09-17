# Execution flow of C program

1. main.c --> main.i
```sh
gcc -E main.c -o main.i
```

2. main.i --> main.asm
```sh
gcc -S main.i -o main.asm
```

3. main.asm --> main.obj
```sh
as main.asm -o main.obj
```

main.c --> main.obj
```sh
gcc -c main.c -o main.obj
```

4. main.obj --> main.out
```sh
gcc main.obj -o main.out
```


