#include "ctest.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../src/lib/quiz.h"

// проверяем, что createQuestion возвращает структуру Question с идентичным
// текстом и ответом.
CTEST(createQuestion, identicalTextAndAnswer)
{
    struct Question expectedQuestion = createQuestion("aaaaaa", "1");

    struct Question actualQuestion
            = createQuestion(expectedQuestion.text, expectedQuestion.answer);

    int textComparison = strcmp(expectedQuestion.text, actualQuestion.text);
    int answerComparison
            = strcmp(expectedQuestion.answer, actualQuestion.answer);

    ASSERT_EQUAL(0, textComparison);
    ASSERT_EQUAL(0, answerComparison);
}

// проверяем, как createQuestion обрабатывает пустые строки.
CTEST(createQuestion, emptyTextAndAnswer)
{
    struct Question expectedQuestion = createQuestion("", "");

    struct Question actualQuestion
            = createQuestion(expectedQuestion.text, expectedQuestion.answer);

    int textComparison = strcmp(expectedQuestion.text, actualQuestion.text);
    int answerComparison
            = strcmp(expectedQuestion.answer, actualQuestion.answer);

    ASSERT_EQUAL(0, textComparison);
    ASSERT_EQUAL(0, answerComparison);
}

// Вспомогательная функция: подсчитывает, сколько элементов находится в
// одинаковом положении в перетасованном и исходном массивах
int countSamePosElements(
        struct Question originalQuestions[],
        struct Question shuffledQuestions[],
        int questionCount)
{
    int count = 0;
    for (int i = 0; i < questionCount; i++) {
        if (strcmp(originalQuestions[i].text, shuffledQuestions[i].text) == 0
            && strcmp(originalQuestions[i].answer, shuffledQuestions[i].answer)
                    == 0) {
            count++;
        }
    }
    return count;
}

CTEST(questionsHandling, shuffleQuestions)
{
    const char* filePath = "../src/app/questions.txt";
    struct Question* originalQuestions = readQuestionsFromFile(filePath);
    int questionCount = getQuestionCount(filePath);

    srand(time(NULL));
    struct Question* shuffledQuestions
            = shuffleQuestions(originalQuestions, questionCount);

    int samePosCount = countSamePosElements(
            originalQuestions, shuffledQuestions, questionCount);
    ASSERT_TRUE(samePosCount < questionCount);

    free(originalQuestions);
    free(shuffledQuestions);
}