#include "crypto.h"
#include <string.h>

#define ENCRYPT_MODE 0
#define DECRYPT_MODE 1
#define TEXT_SIZE 128




int encrypt(KEY key, const char* input, char* output){
//  int error;
//  if(error = checkErrors(key.chars, input, ENCRYPT_MODE)){
//    return error;
//  }
//  crypt(key, input, output, ENCRYPT_MODE);
  return 0;
}

int decrypt(KEY key, const char* cypherText, char* output){
  int error;
  if(error = checkErrors(key, cypherText, DECRYPT_MODE)){
    return error;
  }
  crypt(key, cypherText, output, DECRYPT_MODE);
  return 0;
}

int crypt(KEY key, const char* message, char* output, int mode){
      if(mode == ENCRYPT_MODE){

      }
      if(mode == DECRYPT_MODE){

      }
      return 0;
}

int checkErrors(KEY key, char* input, int mode){

  /** Check if key too short **/
  if(!strlen(key.chars)){
      return E_KEY_TOO_SHORT;
  }

  /** Check if key contains illegal characters **/
  for(int j=0;j<TEXT_SIZE;j++){
      if(!strchr(KEY_CHARACTERS, key.chars+j++)){
          return E_KEY_ILLEGAL_CHAR;
      }
  }


//    /** Check if message contains illegal characters **/
//    while(*input){
//      if(!strchr(MESSAGE_CHARACTERS, *input++)){
//        return E_MESSAGE_ILLEGAL_CHAR;
//      }
//    }
//  }else{
//    /** Check if cypher contains illegal characters **/
//    while(*input){
//      if(!strchr(CYPHER_CHARACTERS, *input++)){
//        return E_CYPHER_ILLEGAL_CHAR;
//      }
//    }
//  }

  return 0;
}
