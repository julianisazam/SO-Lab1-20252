#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readLineAndInversePrint(char *path);
int countLines(FILE * fileContent);

int main(int argc, char *argv[]){

    readLineAndInversePrint(argv[1]);

    return 0;
    

}

void readLineAndInversePrint(char *path){
    FILE * fileContent;
    
    fileContent = fopen(path, "r");
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
   }
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