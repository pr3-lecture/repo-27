#include "crypto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 128
#define mu_assert(message, test) do { if (!(test)) return message; return 0; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)

KEY key;
// char output[BUFFER_SIZE];
int tests_run=0;


// static char* testKeyTooShortOnEncrypt() {
//     key.type=1;
//     key.chars = "";
//     char* input = "INPUT";
//     char* output = (char*) malloc(sizeof(char)*(strlen(input)));
//     mu_assert("testKeyTooShort failed", encrypt(key, input, output) == E_KEY_TOO_SHORT);
//     return NULL;
// }

// static char* testKeyTooShortOnDecrypt() {
//     key.type=1;
//     key.chars = "";
//     mu_assert("testKeyTooShort failed", decrypt(key, "INPUT", output) == E_KEY_TOO_SHORT);
//     return NULL;
// }
//
// static char* testKeyIllegalCharOnEncrypt() {
//     key.type = 1;
//     key.chars = "ABC1";
//     mu_assert("testKeyIllegalChar failed", encrypt(key, "INPUT", output) == E_KEY_ILLEGAL_CHAR);
//     return NULL;
// }
//
// static char* testKeyIllegalCharOnDecrypt() {
//     key.type = 1;
//     key.chars = "ABC1";
//     mu_assert("testKeyIllegalChar failed", decrypt(key, "INPUT", output) == E_KEY_ILLEGAL_CHAR);
//     return NULL;
// }

// static char* testMessageIllegalChar() {
//     key.type = 1;
//     key.chars = "LEGAL";
//     mu_assert("testMessageIllegalChar failed", encrypt(key, "ILLEGAL1", output) == E_MESSAGE_ILLEGAL_CHAR);
//     return NULL;
// }
//
// static char* testCypherIllegalChar() {
//     key.type = 1;
//     key.chars = "LEGAL";
//     mu_assert("testCypherIllegalChar failed", decrypt(key, "ILLEGAL1", output) == E_CYPHER_ILLEGAL_CHAR);
//     return NULL;
// }
//
// static char* testTperulesAsKeyEncrypt() {
//     key.type = 1;
//     key.chars = "TPERULES";
//     encrypt(key, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", output);
//     mu_assert("testTperulesAsKeyEncrypt failed", strcmp(output, "URFVPJB[]ZN^XBJCEBVF@ZRKMJ")==0);
//     return NULL;
// }

static char* allTests() {
    // mu_run_test(testKeyTooShortOnEncrypt);
    // mu_run_test(testKeyTooShortOnDecrypt);
    // mu_run_test(testKeyIllegalCharOnEncrypt);
    // mu_run_test(testKeyIllegalCharOnDecrypt);
    // mu_run_test(testMessageIllegalChar);
    // mu_run_test(testCypherIllegalChar);
    // mu_run_test(testTperulesAsKeyEncrypt);
    /** weitere Tests **/
    return 0;
}

int main() {
    char *result = allTests();

    if (result != 0) printf("%s\n", result);
    else             printf("ALL TESTS PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
