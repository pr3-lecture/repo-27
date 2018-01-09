#include "crypto.h"
#include <string.h>
#include <stdio.h>

#define ENCRYPT_MODE 0
#define DECRYPT_MODE 1


int encrypt(KEY key, const char* input, char* output){
  return crypt(key, input, output, ENCRYPT_MODE);
}

int decrypt(KEY key, const char* cypherText, char* output){
  return crypt(key, cypherText, output, DECRYPT_MODE);
}

/* encrypts/decrypts message into output and returns error */
int crypt(KEY key, const char* message, char* output, int mode){
      int error;
      if((error = checkErrors(key, message, mode))){
          return error;
      }
    for(int i=0;i<strlen(message);i++){
          output[i]= ((message[i]-'A'+ 1) ^ (key.chars[i%strlen(key.chars)]-'A'+1))+'A'-1;
    }
    return 0;
}

int checkErrors(KEY key, char* input, int mode){

  /** Check if key too short **/
  if(!strlen(key.chars)){
      return E_KEY_TOO_SHORT;
  }

  /** Check if key contains illegal characters **/
  for(int i=0;i<strlen(key.chars);i++){
      if(!strchr(KEY_CHARACTERS, key.chars[i])){
          return E_KEY_ILLEGAL_CHAR;
      }
  }

  if(mode==ENCRYPT_MODE){
    /** Check if message contains illegal characters **/
    for(int i=0;i<strlen(input);i++){
      if(!strchr(MESSAGE_CHARACTERS, input[i])){
        return E_MESSAGE_ILLEGAL_CHAR;
      }
    }
  }else{
   /** Check if cypher contains illegal characters **/
   for(int i=0;i<strlen(input);i++){
     if(!strchr(CYPHER_CHARACTERS, input[i])){
       return E_CYPHER_ILLEGAL_CHAR;
     }
   }
 }

  return 0;
}
