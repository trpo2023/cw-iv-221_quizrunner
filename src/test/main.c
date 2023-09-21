#include "quiz.h"
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    question_t questions[NUM_QUESTIONS];
    setlocale(LC_ALL, "Rus");

    create_questions(questions);
    shuffle_questions(questions);
    run_test(questions);

    return 0;
}