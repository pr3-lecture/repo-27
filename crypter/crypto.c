#include "crypto.h"
#include <string.h>
#include <stdio.h>

#define ENCRYPT_MODE 0
#define DECRYPT_MODE 1
#define TEXT_SIZE 128




int encrypt(KEY key, const char* input, char* output){
  return crypt(key, input, output, ENCRYPT_MODE);
}

int decrypt(KEY key, const char* cypherText, char* output){
  return crypt(key, cypherText, output, DECRYPT_MODE);
}

/* encrypts/decrypts message into output and returns error */
int crypt(KEY key, const char* message, char* output, int mode){
      int error;
      if((error = checkErrors(key.chars, message, mode))){
          return error;
      }
      if(mode == ENCRYPT_MODE){
        printf("ENCRYPT MODE\n");
      }
      if(mode == DECRYPT_MODE){
        printf("DECRYPT MODE\n");
      }
      return 0;
}

int checkErrors(KEY key, char* input, int mode){

  /** Check if key too short **/
  if(!strlen(key.chars)){
      fprintf(stderr, "Error: Key length not sufficient\n");
      return E_KEY_TOO_SHORT;
  }

  // /** Check if key contains illegal characters **/
  // for(int j=0;j<TEXT_SIZE;j++){
  //     if(!strchr(KEY_CHARACTERS, key.chars+j++)){
  //         fprintf(stderr, "Error: Key contains illegal characters\n");
  //         return E_KEY_ILLEGAL_CHAR;
  //     }
  // }


//    /** Check if message contains illegal characters **/
//    while(*input){
//      if(!strchr(MESSAGE_CHARACTERS, *input++)){
//        fprintf(stderr, "Error: Message contains illegal characters\n");
//        return E_MESSAGE_ILLEGAL_CHAR;
//      }
//    }
//  }else{
//    /** Check if cypher contains illegal characters **/
//    while(*input){
//      if(!strchr(CYPHER_CHARACTERS, *input++)){
//        fprintf(stderr, "Error: Cypher contains illegal characters\n");
//        return E_CYPHER_ILLEGAL_CHAR;
//      }
//    }
//  }

  return 0;
}
