#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int));

    int i, j;
    int value;
    int count = 0;
    
    for (i = 0; i < numbers_len; i++) {
        for (j = (i + 1); j < numbers_len; j++) {
            value = numbers[i] + numbers[j];

            //값이 배열에 있는지 없는지 확인.
            bool isIn = false;
            for (int k = 0; k < count; k++) {
                if (value == answer[k]) {
                    isIn = true;
                    break;
                }
            }
            if (!isIn) {
                answer = (int*)realloc(answer, sizeof(int) * (1+count));
                answer[count] = value;
                //printf("%d\n", answer[count]);
                count++;
            }

        }
    }

    //정렬.
    int minInd = 0;
    for (i = 0; i < count; i++) {
        minInd = i;
        for (j = i + 1; j < count; j++) {
            if (answer[minInd] > answer[j]) {
                minInd = j;
            }
        }
        //printf("%d\n", answer[minInd]);
        int temp = answer[i];
        answer[i] = answer[minInd];
        answer[minInd] = temp;
    }

    return answer;
}
