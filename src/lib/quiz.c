#include "quiz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void shuffleQuestions(struct Question questions[], int numQuestions)
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

        if (checkAnswer(userAnswer, questions[i].answer)) {
            printf("Правильно!\n");
            score++;
        } else {
            printf("Неправильно. Правильный ответ: %s\n", questions[i].answer);
        }
    }

    printf("\nИгра окончена! Вы набрали %d из %d баллов.\n",
           score,
           numQuestions);
    return score;
}