#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

/**
 * Verify that the username returned by my_username()
 * matches the username stored in conf/username.txt.
 */
void test_validate_my_username(void)
{
    char *expected_username = my_username();
    char *actual_username = malloc_username_from_conf_file();

    TEST_ASSERT_NOT_NULL_MESSAGE(
        actual_username,
        "Could not read username from conf/username.txt"
    );

    TEST_ASSERT_EQUAL_STRING_MESSAGE(
        expected_username,
        actual_username,
        "Username from conf/username.txt does not match my_username()"
    );

    free(actual_username);
}
