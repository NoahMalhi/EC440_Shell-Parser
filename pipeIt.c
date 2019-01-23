#include "pipeIt.h"

int pipeIt(char ** commands, char * specChars){

//fd[1] read, fd2[2] write
int fd[2];
pid_t Pidster;

 char ** holdCommands1 = malloc(MAX_TOKENS);
 char ** holdCommands2 = malloc(MAX_TOKENS);
int strLen = sizeof(commands);
 int i = 0, finish = 0,  j = 0, k = 0, foo = 0;

 printf("I GOT THIS");
//splits up commands into two seperate arrays for the pipe
 while (i < strLen) {
  
   //increments after every command, ex) command ___ command ____
   if(!finish) {
     if(j%2 != 0) {
       foo++;
     }

     if(specChars[foo] == '|') {
       holdCommands1[i] = NULL;
       finish = 1;
     } else {
       holdCommands1[i] = commands[i];
     }
   }else {
     holdCommands2[k] = commands[i];
     k++;
   }
   i++;
 }
 holdCommands2[i] = NULL;

int length = sizeof(holdCommands1);
 for (i = 0; i < length; i++) {
   printf("%s /n", holdCommands1[i]); 
	}


pipe(fd);
Pidster = fork();

 if (Pidster == 0) {
   dup2(fd[0], 0);
   close(fd[1]);
   execvp(holdCommands1[0], holdCommands1);

 } else if (Pidster < 0) {
   perror("Pipe failure");
   exit(1);
 } else {
   dup2(fd[1], 1);
   close(fd[0]);
   execvp(holdCommands2[0], holdCommands2);
 }
 
}
