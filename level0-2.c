#include <stdio.h>
#include <string.h>

int main(){
    char keys[100] [20];
    char values [100] [20];
    FILE *file;
    file=fopen("data.txt","r");
    if (file == NULL){
        printf("I can't read the text.\n");
        return 1;
    }
    char line[100] ;
    int count=0;
    while (fgets(line, sizeof(line), file) != NULL){
        char *semicolon = strchr(line,':');
        if (semicolon ==NULL){
            continue;
        }
        *semicolon='\0';
        strcpy(keys[count],line);
        strcpy(values[count],semicolon+1);
        values[count][strcspn(values[count],"\n")]='\0';
        count++;
    }
    fclose(file);
    char input[100];
    while(1){
        printf("Please type in\n");
        fgets(input, sizeof(input),stdin);
        input[strcspn(input,"\n")]='\0';
        if(strcmp(input,"Quit")==0) {
                break;
        }
        int found=0;
        for(int number=0; number<count; number++){
        if(strcmp(input,keys[number])==0){
            printf("%s\n",values[number]);
            found=1;
            break;
        }
        }
    
        if(found==0){
                printf("Error\n");
            }
    }
    }
