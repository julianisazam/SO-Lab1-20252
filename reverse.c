#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readLine();

int main(int argc, char *argv[]){

    //readFile();
    readLine();

    return 0;
    

}

/*void readFile(){

    FILE * fileContent;
    fileContent = fopen("entrada.txt", "r");

    return fileContent;

    //fclose (fileContent);
}*/

void readLine(){
    FILE * fileContent;
    fileContent = fopen("entrada.txt", "r");
    char line[256];
    if (fileContent!= NULL){

        while (fgets(line, sizeof(line), fileContent)){
            printf("%s", line);
        }
        fclose(fileContent);
    }
    else {
        fprintf(stderr, "unable to open file !\n");
    }   

}