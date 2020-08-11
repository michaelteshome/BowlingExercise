#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenize_input(char *input, int length);
int charToInt(char val);

int main(int argc, char **argv){


    int n = strlen((const char*)"5/-5/-5/-5/-5/-5/-5/-5/-5/-5/-5");
    int size = n;


    char *input = malloc(size * sizeof(char));

    if (input == NULL){
        printf("error allocating memory for this pointer");
        exit(0);
    }

    strcpy(input, "5/-5/-5/-5/-5/-5/-5/-5/-5/-5/-5");

    tokenize_input(input, size);

    free(input);

    return 0;
}


void tokenize_input(char * input, int length){
    const char *sequence = "-";
    int sum = 0;
    int strike = 0;

    char *token = malloc(length * sizeof(char));

    token = strtok(input, sequence);

    while(token != NULL){
        printf("%s\n", token);

        //Check if all bowling input pin is of length 1: ex- X-X-X-X-X-X-X :

        if(strlen(token) == 1){

            if(token[0] == 'X'){
                sum += 20;
                strike = 1;
                token = strtok(NULL, sequence);
                if(token == NULL){
                    sum += 10;
                    break;
                }
                else if(strlen(token) == 1){
                    sum += 10;
                }
                else if(strlen(token) == 2){
                    int b = charToInt(token[0]);
                    int c = charToInt(token[1]);
                    sum += b + c;
                }
                
            }
        }
        //Check if the bowling input pin is of length 2: ex- 5/-5/-5/-5/-5/ :
        else if(strlen(token) == 2){    

            //If the first or second input is a strike "X", check for the next two pins and calculate the sum:
            if(token[0] == 'X' || token[1] == 'X'){
                strike = 1;
                sum += charToInt(token[0]) + charToInt(token[1]);
                token = strtok(NULL, sequence);

                if(token == NULL){
                    break;
                }
                else{
                    sum += token[0];
                }
                
            }

            //Calculate sum of two throws if neither are a strike "X" or spare "\" :
            else{
                int a = charToInt((char)token[0]);
                int b = charToInt((char)token[1]);
                int c = a + b;
                sum += c;   
            }
            
        }

        //If there are no more tokens to parse, end the loop:
        else if(token == NULL){
            printf("\n null\n");
            break;
        }

        
        token = (strike == 0) ? strtok(NULL, sequence) : token;
        strike = (strike == 1) ? 0 : 0;
    }

    //Print the total sum:
    printf("Sum: %d\n", sum);
    
}


int charToInt(char val){
    if(val == '0'){
        return 0;
    }
    else if(val == '1'){
        return 1;
    }
    else if(val == '2'){
        return 2;
    }
    else if(val == '3'){
        return 3;
    }
    else if(val == '4'){
        return 4;
    }
    else if(val == '5'){
        return 5;
    }
    else if(val == '6'){
        return 6;
    }
    else if(val == '7'){
        return 7;
    }
    else if(val == '8'){
        return 8;
    }
    else if(val == '9'){
        return 9;
    }
    else if((int)val == 47){
        return 10;
    }
    else if(val == 'X'){
        return 10;
    }
    
}
