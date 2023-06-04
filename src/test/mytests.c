
#include "ctest.h"
#include "quiz.h"
#include <stdbool.h>
#include <stdio.h>

CTEST(suite1, test1)
{
    bool ch;
    bool ch1;
    bool exp = true;
    bool exp1 = false;
    ch = check_answer("aaaaaa", "aaaaaa");
    ch1 = check_answer("aaaaaa", "bbbbb");
    ASSERT_EQUAL(ch, exp);
    ASSERT_EQUAL(ch1, exp1);
}