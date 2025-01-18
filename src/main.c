#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "lang.h"
#define MAX 50
#define LEN 26

char * get_name(char *str);
int * get_args(char *str);
void execute(char **commands, int count);
void call_func(char **commands, int i, int *prev);

int * get_args(char *str){
    int i, j, len;
    int *args = malloc(sizeof(int)*2);

    i = 0;
    j = 0;
    len = 0;
    args[0] = INT_MAX;
    args[1] = INT_MAX;

    while (str[i] != '\n'){
        if (str[i++] == ' '){
            args[j] = 0;
            while (str[i] != ' ' && str[i] != '\n'){
                len++;
                i++;
            }
            i -= len;
            while (str[i] != ' ' && str[i] != '\n'){
                args[j] += (str[i++] - '0') * pow(10, --len);
            }
            j++;
        }
    }

    return args;
}

char * get_name(char *str){
    int i = 0;
    char *cropped = malloc(sizeof(char)*5);

    while (str[i] != ' ' && str[i] != '\n'){
        cropped[i] = str[i];
        i++;
    }  
    cropped[i] = '\0';

    return cropped;
}


void execute(char **commands, int count){
    int i;
    int prev; // value of previous operation
    
    i = 0;
    prev = 0;

    while (strcmp(commands[i], "exc\n") && i < MAX){
        call_func(commands, i, &prev);
        i++;
    }
}

void call_func(char **commands, int i, int *prev){
    int *args; // holds function's arguments
    char *f_name; // holds function's name
    int j;

    f_name = get_name(commands[i]);
    args = get_args(commands[i]);

    for (j=0;j<COUNT;j++){
        if (!strcmp(f_name, func_map[j].name)){
            if (args[1] == INT_MAX) args[1] = *prev; 
            *prev = func_map[j].func(args[0], args[1]);
            printf("\n%d ", *prev);
            break;
        }
        else if (!strcmp(f_name, "rp")){
            call_func(commands, args[0]-1, prev);
            break;
        }
        else if (!strcmp(f_name, "rpl")){
            call_func(commands, i-1, prev);
            break;
        }
    }

    free(f_name);
    free(args);
}

int main(int argc, char *argv[]){
    char **commands;
    int i, j;
    const char exc[] = "exc\n";

    commands = malloc(sizeof(char*)*MAX);
    
    for (i=0;i<MAX;i++){
        commands[i] = malloc(sizeof(char)*LEN);
        printf("\nPrint command: ");
        fgets(commands[i], LEN, stdin);
        if (!strcmp(commands[i], exc)){
            execute(commands, MAX);
            break;
        }
    }
    
    for (i=0;i<COUNT;i++){
        free(commands[i]);
    }
    free(commands);

    return 0;
}
