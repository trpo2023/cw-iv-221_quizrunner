#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include "quiz.h"
// Функция для создания вопросов и ответов
void create_questions(question_t *questions)
{
    questions[0].question = "Какой тип данных используется для хранения целочисленных значений?";
    questions[0].answer = "int";
    questions[1].question = "Какой тип данных используется для хранения вещественных чисел?";
    questions[1].answer = "float";
    questions[2].question = "Каков результат выражения 2 + 3 * 4;";
    questions[2].answer = "14";
    questions[3].question = "Какая функция используется для вывода текста на экран?";
    questions[3].answer = "printf";
    questions[4].question = "Какой оператор используется для сравнения двух значений?";
    questions[4].answer = "==";
    questions[5].question = "Как называется цикл, который выполняется до тех пор, пока не выполнится определенное условие?";
    questions[5].answer = "while";
    questions[6].question = "Каким символом обозначается комментарий в языке Си?";
    questions[6].answer = "//";
    questions[7].question = "Какой тип данных может хранить только два значения: true и false?";
    questions[7].answer = "bool";
    questions[8].question = "Как называется оператор, который используется для считывания данных с консоли?";
    questions[8].answer = "scanf";
    
}

// Функция для перемешивания вопросов
void shuffle_questions(question_t *questions)
{
    int i, j;
    question_t temp;

    srand(time(NULL)); // Инициализируем генератор случайных чисел

    // Перемешиваем вопросы
    for (i = 0; i < NUM_QUESTIONS; i++)
    {
        j = rand() % NUM_QUESTIONS;
        temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}
bool check_answer(char* answer1, char* answer2){
    if (strcmp(answer1, answer2) == 0)
        {
           return true;
        }
        else
        {
           return  false;
            
        }
}
// Функция для проведения теста
void run_test(question_t *questions)
{
    int i;
    char answer[256];
    int score = 0;
    

    printf("Добро пожаловать на тест по языку Си!\n");
    printf("Ответьте правильно на %d вопросов, чтобы выиграть!\n", NUM_QUESTIONS);

    // Задаем вопросы и получаем ответы
    for (i = 0; i < NUM_QUESTIONS; i++)
    {
        printf("\nВопрос %d: %s\n", i + 1, questions[i].question);
        printf("Ответ: ");
        scanf("%s", answer);
        if(check_answer(answer,questions[i].answer)){
            printf("правильно!\n");
            score++;
        }else{
            printf("неправильно!\n");
        }
        
    }

    // Проверяем результаты теста и выводим сообщение об успехе или неудаче
    if (score == NUM_QUESTIONS)
    {
        printf("\nПоздравляем, вы выиграли!\n");
    }
    else
    {
        printf("\nК сожалению, вы не прошли тест. Ваш итоговый балл: %d/%d\n", score, NUM_QUESTIONS);
    }
}