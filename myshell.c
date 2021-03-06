#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "shell_funcs.h"
#include "pipeIt.h"

int main(int argc, char *argv[]) {

  //line will hold input commands string and commands will hold the parsed commands
  //special chars will hold characters for redirect and piping
  char* line = NULL;
  char ** commands = NULL;
  char *specChars = NULL;
  int strLen, strLenIter = 0;
  int isExec = 1;

  while (!feof(stdin)) {
    //if second arg is -n it does not display "MY_SHELL ->"
          if(!argv[1]) {
            printf("MY_SHELL -> ");
            fflush(stdout);
          }else if(argv[2] == "-n"){
            fflush(stdout);
          }

	  
	           line = read_line();

          //checks if there was a user input

          if(line < 0) {
            exit(-1);
          } else {
            specChars = specialChar(line);
            commands = parser(line);
            strLen = strlen(specChars);

            for(;strLenIter < strLen; strLenIter++){

              if (specChars[strLenIter] = " ") {
                
              } else {
                isExec = 0;
                break;
              }
            }
            if (isExec == 1) {
              execute_command(commands);
            } else {
              chooseFunc(specChars, commands);
            }

            free(line);
            free(commands);
          }
        }

        return 0;
}

