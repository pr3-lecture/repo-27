
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)


static char* test1() {
    mu_assert("Meldung", 1 == 1);
}

static char* testKeyTooShort() {
    key.chars = ""
    mu_assert("Key too short", encrypt(key, "INPUT", output) == E_KEY_TOO_SHORT);
}

static char* testKeyIllegalChar() {
    mu_assert("Meldung", 1 == 1);
}

static char* testMessageIllegalChar() {
    mu_assert("Meldung", 1 == 1);
}

static char* testCypherIllegalChar() {
    mu_assert("Meldung", 1 == 1);
}

static char* allTests() {
    mu_run_test(test1);
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
