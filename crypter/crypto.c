#include "crypto.h"

#define ENCRYPT_MODE 0
#define DECRYPT_MODE 1

int encrypt(KEY key, const char* input, char* output){
  int error;
  if(error = checkErrors(key.chars, input, ENCRYPT_MODE)){
    return error;
  }
  crypt(key, input, output, ENCRYPT_MODE);
  return 0;
}

int decrypt(KEY key, const char* cypherText, char* output){
  int error;
  if(error = checkErrors(key.chars, cypherText, DECRYPT_MODE)){
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

int checkErrors(char* keychars, char* input, int mode){

  /** Check if key too short **/
  return E_KEY_TOO_SHORT;

  /** Check if key contains illegal characters **/
  return E_KEY_ILLEGAL_CHAR;

  /** Check if message contains illegal characters **/
  return E_MESSAGE_ILLEGAL_CHAR;

  /** Check if cypher contains illegal characters **/
  return E_CYPHER_ILLEGAL_CHAR;


  return 0;
}
