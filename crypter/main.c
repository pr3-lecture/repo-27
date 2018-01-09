#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypto.h"
#define TEXT_SIZE 128

int main(int argc, char *argv[]) {
  int result = 0;
  const char* input;
  char* output;

  //READ INPUT TEXT
  switch(argc) {
	   case 2:{
        //allocate memory for input and read from stdin
        char* stdInput = (char*) malloc(TEXT_SIZE);
        printf("Enter Message: ");
        fgets(stdInput, TEXT_SIZE, stdin);
        stdInput[strlen(stdInput)-1] = '\0';
        input = stdInput;
        break;}
        //END OF READ FROM CONSOLE
	   case 3:{
        printf("READ FROM FILE: ");
        //open file
        FILE* f;
        if ((f = fopen(argv[2], "r")) == NULL) {
          printf("FAILED TO OPEN FILE\n");
          exit(-1);
        }

        //allocate memory for input and read from file
        char* fileInput = (char*) malloc (TEXT_SIZE);
        if(fgets(fileInput, TEXT_SIZE, f) != NULL){
          printf("%s\n", fileInput);
        }

        if (fclose(f)) {
          printf("ERROR WHILE CLOSING FILE\n");
        }
        input = fileInput;
        break;}
        //END OF READ FROM FILE
	   default: // wrong parameters
        printf("Usage: KEY [file name]\n");
        return -1;
        //END OF WRONG PARAMETERS
  }//END OF GEsT INPUT
  output = (char*)malloc(strlen(input));
  KEY key = {1, argv[1]};
  result = (0== strcmp(argv[0], "./encrypt")) ? encrypt(key, input, output) : decrypt(key, input, output);
  /** print output **/
  printf("OUTPUT: ");
  for(int i; i<strlen(input); i++)printf("%c", output[i]);
  free((char*)input);
  free(output);

  if(result == E_KEY_TOO_SHORT){
    fprintf(stderr, "Error: Key length not sufficient\n");
  }

  if(result == E_KEY_ILLEGAL_CHAR){
     fprintf(stderr, "Error: Key contains illegal characters\n");
  }

  if(result == E_MESSAGE_ILLEGAL_CHAR){
    fprintf(stderr, "Error: Message contains illegal characters\n");
  }

  if(result == E_CYPHER_ILLEGAL_CHAR){
    fprintf(stderr, "Error: Cypher contains illegal characters\n");
  }
  return result;
}
