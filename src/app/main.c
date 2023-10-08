#include "lib/quiz.h"
#include <stdio.h>
#include <string.h>
#define MAX_LINE_LENGTH 1000

int main()
{

    struct Question questions[5];

    FILE *file = fopen("../src/app/questions.txt", "r");
    
    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        
        if((line[strlen(line) - 1]) == '\n'){
            line[strlen(line) - 1] = '\0';
        }
        if(lineNumber % 2 == 0){
            strcpy(questions[i].text, line);
            
        }
        else{
            strcpy(questions[i].answer, line);
            i++;
        }
        lineNumber++;

        

    }
    
    fclose(file);

    shuffleQuestions(questions, 5);

    int finalScore = runQuiz(questions, 5);

    printf("Ваш итоговый балл: %d\n", finalScore);

    return 0;
}