#include "shell_funcs.h"

char *read_line(void) {
  char *line = malloc(MAX_TOKEN_SIZE + 1);

  //reads from command line and stores string in char * line
  fgets(line, MAX_SIZE, stdin);
  if(line == NULL) {
    perror("Read Failed");
  } else {
    return line;
  }
}

int execute_command(char ** commands) {
  int* status;
  pid_t Pidster = fork();

  //if the parent it waits for child to finish
  //else if the child it execute the commands
  if(Pidster > 0){
        waitpid(Pidster, &status, 0);
        return;
  } else if(Pidster == 0) {
    if( execvp(commands[0],commands)<0) {
      exit(0);
    }
  } else{
    perror("Execute failure\n");
  }

}

//based on special char, pipe or redirect called
void chooseFunc(char * specChars, char ** commands) {
  int specIndex = 0;
  int specLen = strlen(specChars);
  char ** holdCommands = 15;

  //loops through the special characters
  while(specIndex != specLen){

    if(specChars[specIndex] == '|'){
      printf("LOL LOOK AT ME PIPE");
      //calls for pipe
      pipeIt(commands, specChars);
    } else {
      //call redirect
      break;
    }
    specIndex++;
     }

}

