#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypto.h"

#define ENCRYPT_MODE 0
#define DECRYPT_MODE 1
#define TEXT_SIZE 128

int main(int argc, char *argv[]) {
  int result = 0;
  char* input;
  char* output;


  switch(argc) {
	   case 2: //input from command line
        /** Read from stdin **/
        input = (char*) malloc(TEXT_SIZE);
        printf("Enter Message: ");
        fgets(input, TEXT_SIZE, stdin);
        printf("INPUT IS : %s\n", input);
        input[TEXT_SIZE-1] = '\0';
        /** encrypt/decrypt message **/
        output = (char*) malloc(sizeof(char) * (strlen(input) + 1));
        break;
	   case 3: //input from file
        /** open file **/
        /** read line **/
        /** encrypt/decrypt line **/
        //error =
        /** print line **/
        break;
	   default: // wrong parameters
        printf("Usage: KEY [file name]\n");
        return -1;
  }

  KEY key = {1, argv[1]};
  result = (0== strcmp(argv[0], "./encrypt")) ? encrypt(key, input, output) : decrypt(key, input, output); 
  /** print output **/
  printf("OUTPUT: %s\n", output);
  free(output);

  //check result for errors
  if (result == E_KEY_TOO_SHORT)
    fprintf(stderr, "Error: Key length not sufficient\n");

  if (result == E_KEY_ILLEGAL_CHAR)
    fprintf(stderr, "Error: Key contains illegal characters\n");

  if (result == E_MESSAGE_ILLEGAL_CHAR)
    fprintf(stderr, "Error: Message contains illegal characters\n");

  if (result == E_CYPHER_ILLEGAL_CHAR)
    fprintf(stderr, "Error: Cypher contains illegal characters\n");

  return result;
}
