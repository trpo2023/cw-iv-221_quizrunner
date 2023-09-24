#include <stdio.h>
#include "lib/quiz.h"

int main()
{
    struct Question questions[5];

    questions[0] = createQuestion("Какая столица Франции?", "Париж");
    questions[1] = createQuestion("Сколько планет в солнечной системе?", "8");
    questions[2] = createQuestion("Какой год начала Второй мировой войны?", "1939");
    questions[3] = createQuestion("Какой химический элемент имеет символ 'H'?", "Водород");
    questions[4] = createQuestion("Какой самый высокий горный пик в мире?", "Эверест");

    shuffleQuestions(questions, 5);

    int finalScore = runQuiz(questions, 5);

    printf("Ваш итоговый балл: %d\n", finalScore);

    return 0;
}