#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>

void * func(void * p) {
    printf("Testing\n");
    return NULL;
}

int main(int argc, char*argv[]) {

    FILE * filePtr;
    filePtr = fopen(argv[1], "r");
    char  buffer[10000];
    int j = 0;
    int i = 0;
    char arr[200];

    pthread_t newthread;
    pthread_create(&newthread, NULL, func, NULL);

    while (!feof(filePtr)) {// iterating through file lines
        i = 0;
        fgets(buffer, 10000, filePtr);
        while (buffer[i] != '\0')  { //looping through buffer

                if (isdigit(buffer[i])) { //checking for number then filling array
                    arr[j] = buffer[i];
                    j++;
                }
                i++;
            }
        j = 0;
        puts(buffer); //printing buffer, take this out later
        while (arr[j] != '\0') { //printing array
            printf("%c\n", arr[j]);
            j++;
        }
        for (int i = 0; i < 200; i++) { //clearing array
            arr[i] = '\0';
        }
        j = 0;
        }










    fclose(filePtr);


    return 0;
}
