#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_TOKENS 15

int pipeIt(char** commands, char* specChars);
void redirectIt(char ** commands, char * specChars);
