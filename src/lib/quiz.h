#ifndef QUIZ_H
#define QUIZ_H

#define MAX_LINE_LENGTH 1000

struct Question {
    char text[256];
    char answer[256];
};

struct Question createQuestion(const char* text, const char* answer);
int checkAnswer(const char* userAnswer, const char* correctAnswer);
void shuffleQuestions(struct Question questions[], int numQuestions);
int runQuiz(struct Question questions[], int numQuestions);
int getQuestionCount(const char* filePath); // Объявление функции в .h файле
struct Question* readQuestionsFromFile(const char* filePath); // Объявление функции в .h файле

#endif // QUIZ_H
