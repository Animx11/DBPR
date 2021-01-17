#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

    FILE *fileToOpen=fopen(argv[1],"r");
    char lineFromFile[1024];
    int lineNumber = 0;

    while(fileToOpen && fgets(lineFromFile, sizeof(lineFromFile), fileToOpen)) {
        lineNumber++;
        if (strstr(lineFromFile, argv[2])) {
            printf("%s %d %s", "Wyraz znaleziono na lini:", lineNumber, "\n");
        };
    }
    fclose(fileToOpen);

    return 0;

}
