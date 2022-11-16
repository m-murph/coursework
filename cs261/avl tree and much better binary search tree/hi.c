#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void delay(int milli_seconds){
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main(){
    srand(time(NULL));

    char* message = "hello world";
    int ml = 11;

    char* output[ml];
    for (int k = 0; k<ml; k++){
        output[k] = (rand() % 25) + 97;
    }
    
    for (int i = 0; i < ml; i++){
        char n = 'a';
        if (message[i] == 32){
            n = 32;
        }
        while(n <= message[i]){
            output[i] = n;
            for (int k = 0; k<ml; k++){
                printf("%c", output[k]);
            }
            printf("\n");
            n++;
            delay(85);
        }
    }
    return 0;
}