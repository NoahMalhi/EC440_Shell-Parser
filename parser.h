#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 512
#define MAX_TOKEN_SIZE 32
#define MAX_TOKENS 15
#define DELIMS "\t\n\<>| "

char ** parser(char* line);
char * specialChar(char * line);
                         
