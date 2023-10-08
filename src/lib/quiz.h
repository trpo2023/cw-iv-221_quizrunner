#ifndef QUIZ_H
#define QUIZ_H

struct Question {
    char text[256];
    char answer[256];
};


struct Question createQuestion(const char* text, const char* answer);
int checkAnswer(const char* userAnswer, const char* correctAnswer);
void shuffleQuestions(struct Question questions[], int numQuestions);
int runQuiz(struct Question questions[], int numQuestions);

#endif // QUIZ_H
