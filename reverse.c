#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFileAndInversePrint(char *path);
int countLines(FILE * fileContent);
FILE* openFile(char* path);
void readAndPrintConsole();
void readFileAndReturnOutputFile(char *path, char *outputPath);

int main(int argc, char *argv[]){

    if (argc==1){
        readAndPrintConsole();
    } else if (argc==2){
        readFileAndInversePrint(argv[1]);
    } else if (argc==3){
        readFileAndReturnOutputFile(argv[1], argv[2]);
    } else {
        fprintf(stderr, "Too many arguments !\n");
        exit(1);

       
    }

    
    return 0;
    

}

void readFileAndInversePrint(char *path){
    FILE * fileContent = openFile(path);
    if (fileContent!= NULL){

        int count = countLines(fileContent);
        rewind(fileContent);
        char **array = malloc(count * sizeof(char *));
        for (int i = count - 1; i >=0; i--){
            char * line;
            size_t len = 0;
            array[i] = malloc(sizeof(char));
            getline(&line, &len, fileContent);
            sprintf(array[i], "%s", line);
        }
         for (int i = 0; i < count; i++) {
        printf("%s", array[i]);
        }
       
       for (int i = 0; i < count; i++) {
        free(array[i]);
        }
       
       fclose(fileContent);
       free(array);
   }
   else {
       fprintf(stderr, "unable to open file !\n");
       exit(1);
   }
}

void readAndPrintConsole(){
    char * line;
    int amount;
    printf("Enter the amount of lines: ");
    scanf("%d", &amount);
    char **array = malloc(amount * sizeof(char *));
    for (int i = amount ; i >=0; i--){
        size_t len = 0;
        array[i] = malloc(sizeof(char*));
        getline(&line, &len, stdin);
        sprintf(array[i], "%s", line);
    }
    printf("Inversed Lines: \n");
     for (int i = 0; i < amount; i++) {
    printf("%s", array[i]);}
}

void readFileAndReturnOutputFile(char *path, char *outputPath){
    FILE * fileContent = openFile(path);
    if (fileContent!= NULL){

        int count = countLines(fileContent);
        rewind(fileContent);
        char **array = malloc(count * sizeof(char *));
        for (int i = count - 1; i >=0; i--){
            char * line;
            size_t len = 0;
            array[i] = malloc(sizeof(char));
            getline(&line, &len, fileContent);
            sprintf(array[i], "%s", line);
        }
        FILE * outputFile = fopen(outputPath, "w");
         for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%s", array[i]);
        }
       
       for (int i = 0; i < count; i++) {
        free(array[i]);
        }
       
       fclose(fileContent);
       fclose(outputFile);
       free(array);
    }
}

FILE* openFile(char* path){
    FILE * fileContent;
    fileContent = fopen(path, "r");
    
    return fileContent;
}

    
int countLines(FILE * fileContent){
    int count = 0;
    char c;

    for (c = getc(fileContent); c != EOF; c = getc(fileContent)){
        if (c == '\n'){
            count = count + 1;
        }
    }
    return count;

}