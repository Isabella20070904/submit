#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    while(1){
    printf("please type in\n");
    fgets (input, sizeof(input), stdin);
    input[strcspn(input, "\n")]='\0';
    if (strcmp(input, "Dian")==0){
    printf("2002\n");
    }
    else if (strcmp(input, "Quit")==0){
    break;
    }
    else {printf("Error\n");}
}
}
