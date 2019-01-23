#include "parser.h"

char** parser(char *line){

  char *token = malloc(MAX_TOKEN_SIZE);
  char **tokens = malloc(MAX_TOKENS);
  int i = 0;

  token = strtok(line,  DELIMS);
  while(token!=NULL) {
    tokens[i] = token;
    token = strtok(NULL,DELIMS);
    i++;
  } 
  tokens[i] = NULL;
  return tokens;
 
}   

char* specialChar(char * line) {
  int j = 0, k = 0; 
  int lineSize = strlen(line);
  char *specChars = malloc(MAX_TOKENS);
  
  for (;j < lineSize; j++){
    if(line[j] == '<' || line[j] == '>' || line[j] == '|' ||  line[j] == ' ') {
      if(line[j] = ' '){
	specChars[k] = '-';
	k++;
      }else {
       specChars[k] = line[j];
       k++;
      }
      }
    }


  return specChars;
}

