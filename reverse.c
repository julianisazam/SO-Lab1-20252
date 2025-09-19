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
        if(argv[1] == argv[2]){
            fprintf(stderr, "Input and output file must be different !\n");
            exit(1);
        }   
        readFileAndReturnOutputFile(argv[1], argv[2]);
    } else {
        fprintf(stderr, "usage: reverse <input> <output> !\n");
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
        if(array == NULL){
            fprintf(stderr, "Malloc failed\n");
            exit(1);
        }
        for (int i = count-1; i >=0; i--){
            char * line;
            size_t len = 0;
            size_t longi;
            longi = getline(&line, &len, fileContent);
            if(line[longi-1] != '\n'){
                line[longi] = '\n';
                line[longi+1] = '\0';
                longi += 1;
            }
            array[i] = malloc(longi * sizeof(char));
            if(array[i] == NULL){
                fprintf(stderr, "Malloc failed\n");
                exit(1);
            }
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
       fprintf(stderr, "error: cannot open file 'input.txt'\n");
       exit(1);
   }
}

void readAndPrintConsole(void) {
    FILE *fileTemp = tmpfile();              
    if (fileTemp == NULL) {
        fprintf(stderr, "The temporal file couldn't be created\n");
        exit(1);
    }

    char *line = NULL;                         
    size_t len = 0;                            
    size_t longi;                             

    printf("Write the lines,  if u wanna exit press Ctrl+D:\n");

    while ((longi = getline(&line, &len, stdin)) != -1) {
        fputs(line, fileTemp);                 
        if (longi > 0 && line[longi - 1] != '\n') {
            fputc('\n', fileTemp);          
        }
    }
    free(line);
    line = NULL;
    len  = 0;

    rewind(fileTemp);
    int count = countLines(fileTemp);
    char **array = (char **)malloc((size_t)count * sizeof(char *));
    if(array == NULL){
            fprintf(stderr, "Malloc failed\n");
            exit(1);
        }
    

    rewind(fileTemp);
     if (fileTemp!= NULL){
    for (int i = count-1; i >=0; i--){
            char * line;
            size_t len = 0;
            size_t longi;
            longi = getline(&line, &len, fileTemp);
            if(line[longi-1] != '\n'){
                line[longi] = '\n';
                line[longi+1] = '\0';
                longi += 1;
            }
            array[i] = malloc(longi * sizeof(char));
            if(array[i] == NULL){
                fprintf(stderr, "Malloc failed\n");
                exit(1);
            }
            sprintf(array[i], "%s", line);
        }
        printf("\nInversed lines:\n");
        for (int i = 0; i < count; i++) {
        printf("%s", array[i]);
        }
       
       for (int i = 0; i < count; i++) {
        free(array[i]);
        }
       
       fclose(fileTemp);
       free(array);
     }
    else {
        fprintf(stderr, "unable to open file !\n");
        exit(1);
   }
} 

void readFileAndReturnOutputFile(char *path, char *outputPath){
    FILE * fileContent = openFile(path);
    if (fileContent!= NULL){

        int count = countLines(fileContent);
        rewind(fileContent);
        char **array = malloc(count * sizeof(char *));
        
        if(array == NULL){
            fprintf(stderr, "Malloc failed\n");
            exit(1);
        }
        for (int i = count - 1; i >=0; i--){
            char * line;
            size_t len = 0;
           array[i] = malloc(sizeof(char*));
            if(array[i] == NULL){
                fprintf(stderr, "Malloc failed\n");
                exit(1);
            }
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
    } else {
       fprintf(stderr, "error: cannot open file 'input.txt'\n");
       exit(1);}
}

FILE* openFile(char* path){
    FILE * fileContent;
    fileContent = fopen(path, "r");
    
    return fileContent;
}

int countLines(FILE * fileContent){
    int count = 0;
    char c;
    size_t read;
    size_t len = 0;
    char * line = NULL ;

    while((read = getline(&line, &len, fileContent)) != -1){
        count++; 
    }
    return count;

}