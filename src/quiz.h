#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
// Задайте количество вопросов
#define NUM_QUESTIONS 9

// Структура для хранения информации о вопросах и ответах
typedef struct
{
    char *question;
    char *answer;
} question_t;
void create_questions(question_t *questions);

bool check_answer(char* answer1, char* answer2);
// Функция для перемешивания вопросов
void shuffle_questions(question_t *questions);


// Функция для проведения теста
void run_test(question_t *questions);

