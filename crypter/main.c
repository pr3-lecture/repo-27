#include <stdio.h>
#include "crypto.h"


int main(int argc, char const *argv[]) {

  int error = 0;

  switch(argc) {
	   case 2: //input from command line
        /** Read from stdin **/
        /** encrypt/decrypt message **/
        error =
        /** print output **/
        break;
	   case 3: //input from file
        /** open file **/
        /** read line **/
        /** encrypt/decrypt line **/
        error = 
        /** print line **/
        break;
	   default: // wrong parameters
        printf("Usage: KEY [file name]");
        break;
  }

  //check errors
  if (error == E_KEY_ILLEGAL_CHAR)
    fprintf(stderr, "Error: Key contains illegal characters\n");

  return 0;
}
