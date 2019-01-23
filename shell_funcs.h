#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_SIZE 512
#define MAX_TOKEN_SIZE 32

char* read_line(void);
int execute_command(char** commands);
void piperExec(char **commands);
void chooseFunc(char* specChars, char** commands);
void isWait(int flag);
