#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(sizeof(char)* 3*n +1); //한글은 2바이트!
    strcpy(answer, "");
    
    for(int i=0; i<n; i++){
        if(i%2==0){
            strcat(answer, "수");
        }
        else{
            strcat(answer, "박");
        }
    }
    
    return answer;
}
