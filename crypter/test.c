#include "crypto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 128
#define mu_assert(message, test) do { if (!(test)) return message; return 0; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)

KEY key;
char output[BUFFER_SIZE];
char* input;
int tests_run=0;


static char* testKeyTooShortOnEncrypt() {
    key.type=1;
    key.chars = "";
    mu_assert("testKeyTooShort failed", encrypt(key, "INPUT", output) == E_KEY_TOO_SHORT);
    return NULL;
}

static char* testKeyTooShortOnDecrypt() {
    key.type=1;
    key.chars = "";
    mu_assert("testKeyTooShort failed", decrypt(key, "INPUT", output) == E_KEY_TOO_SHORT);
    return NULL;
}

static char* testKeyIllegalCharOnEncrypt() {
    key.type = 1;
    key.chars = "ABC1";
    mu_assert("testKeyIllegalChar failed", encrypt(key, "INPUT", output) == E_KEY_ILLEGAL_CHAR);
    return NULL;
}

static char* testKeyIllegalCharOnDecrypt() {
    key.type = 1;
    key.chars = "ABC1";
    mu_assert("testKeyIllegalChar failed", decrypt(key, "INPUT", output) == E_KEY_ILLEGAL_CHAR);
    return NULL;
}

static char* testMessageIllegalChar() {
    key.type = 1;
    key.chars = "LEGAL";
    mu_assert("testMessageIllegalChar failed", encrypt(key, "ILLEGAL1", output) == E_MESSAGE_ILLEGAL_CHAR);
    return NULL;
}

static char* testCypherIllegalChar() {
    key.type = 1;
    key.chars = "LEGAL";
    mu_assert("testCypherIllegalChar failed", decrypt(key, "ILLEGAL1", output) == E_CYPHER_ILLEGAL_CHAR);
    return NULL;
}

static char* testTperulesAsKeyEncrypt() {
    key.type = 1;
    key.chars = "TPERULES";
    mu_assert("testTperulesAsKeyEncrypt failed (wrong return code)", encrypt(key, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", output) == 0);
    mu_assert("testTperulesAsKeyEncrypt failed (wrong output)", strcmp(output, "URFVPJB[]ZN^XBJCEBVF@ZRKMJ")==0);
    return NULL;
}

static char* testTperulesAsKeyDecrypt() {
    key.type = 1;
    key.chars = "TPERULES";
    mu_assert("testTperulesAsKeyDecrypt failed (wrong return code)", decrypt(key, "URFVPJB[]ZN^XBJCEBVF@ZRKMJ", output) == 0);
    mu_assert("testTperulesAsKeyEncrypt failed (wrong output)", strcmp(output, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")==0);
    return NULL;
}

static char* allTests() {
    mu_run_test(testKeyTooShortOnEncrypt);
    mu_run_test(testKeyTooShortOnDecrypt);
    mu_run_test(testKeyIllegalCharOnEncrypt);
    mu_run_test(testKeyIllegalCharOnDecrypt);
    mu_run_test(testMessageIllegalChar);
    mu_run_test(testCypherIllegalChar);
    mu_run_test(testTperulesAsKeyEncrypt);
    mu_run_test(testTperulesAsKeyDecrypt);
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
