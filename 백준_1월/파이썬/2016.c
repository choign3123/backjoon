#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(sizeof(char)*3);
    int dayArr[13] = {0, 31,29,31,30,31,30,31,31,30,31,30,31};
    char* week[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int totalDay = 0;
    
    for(int i=1; i<a; i++){
        totalDay += dayArr[i];
    }
    totalDay += b;
    
    strcpy(answer, week[totalDay%7]);
    // switch(totalDay % 7){
    //     case 1:
    //         answer = "FRI";
    //         break;
    //     case 2:
    //         answer = "SAT";
    //         break;
    //     case 3:
    //         answer = "SUN";
    //         break;
    //     case 4:
    //         answer = "MON";
    //         break;
    //     case 5:
    //         answer = "TUE";
    //         break;
    //     case 6:
    //         answer = "WED";
    //         break;
    //     case 0:
    //         answer = "THU";
    //         break;
    // }
    
    
    return answer;
}
