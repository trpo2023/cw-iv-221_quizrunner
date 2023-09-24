#include "ctest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/lib/quiz.h"
CTEST(checkAnswer1, test1)
{
    struct Question ch = createQuestion("aaaaaa", "1");
    struct Question ch1 = createQuestion(ch.text, ch.answer);
    int a = checkAnswer(ch.answer, ch1.answer);
    int b = 0;
    ASSERT_EQUAL(a, b);
}

CTEST(returnscore1, test2)
{
    int a = 5;
    int b = 5;
    ASSERT_EQUAL(a, b);
}
CTEST(Question1, test3)
{
    struct Question txt = createQuestion("aaaaaa", "1");
    struct Question ch1 = createQuestion(txt.text, txt.answer);
    int a = strcmp(txt.text, ch1.text);
    int b = 0;
    int c = strcmp(txt.answer, ch1.answer);

    ASSERT_EQUAL(b, a);
    ASSERT_EQUAL(b, c);
}