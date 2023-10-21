#include "quiz.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void to_lower(char* c, char* b)
{
    if (*c == -48 && (*b >= -125 && *b <= -97)) {
        *b = *b + ('а' - 'А');
    }

    if (*c == -48 && *b >= -96 && *b <= -81) {
        *c = *c + 1;
        *b = *b - ('а' - 'А');
    }
}

struct Question createQuestion(const char* text, const char* answer)
{
    struct Question question;
    strcpy(question.text, text);
    strcpy(question.answer, answer);
    return question;
}

int checkAnswer(const char* userAnswer, const char* correctAnswer)
{
    return strcmp(userAnswer, correctAnswer) == 0;
}

struct Question *shuffleQuestions(struct Question questions[], int numQuestions)
{
    srand(time(NULL));
    for (int i = numQuestions - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

int runQuiz(struct Question questions[], int numQuestions)
{
    int score = 0;

    printf("Добро пожаловать в викторину!\n");

    for (int i = 0; i < numQuestions; i++) {
        printf("\nВопрос %d: %s\n", i + 1, questions[i].text);

        char userAnswer[256];
        printf("Ваш ответ: ");
        scanf("%s", userAnswer);

        for (int y = 0; userAnswer[y] != '\0'; y = y + 2) {
            to_lower(&userAnswer[y], &userAnswer[y + 1]);
        }

        for (int y = 0; questions[i].answer[y] != '\0'; y = y + 2) {
            to_lower(&questions[i].answer[y], &questions[i].answer[y + 1]);
        }

        if (checkAnswer(userAnswer, questions[i].answer)) {
            printf("Правильно!\n");
            score++;
        } else {
            printf("Неправильно. Правильный ответ: '%s'\n",
                   questions[i].answer);
        }
    }

    printf("\nИгра окончена! Вы набрали %d из %d баллов.\n",
           score,
           numQuestions);
    return score;
}