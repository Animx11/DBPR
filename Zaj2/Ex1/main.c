#include <stdio.h>
#include <string.h>

char lineFromFile[1024];
int lineNumber = 0;

int main(int argc, char **argv) {

    FILE *fileToOpen=fopen(argv[1],"r");

    while(fileToOpen && fgets(lineFromFile, sizeof(lineFromFile), fileToOpen)) {
        lineNumber++;
        if (strstr(lineFromFile, argv[2])) {
            printf("%s %d %s", "Wyraz znaleziono na lini:", lineNumber, "\n");
        };
    }

    return 0;

}
