#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 20

int main(void){
    int file_input;
    int file_output1;
    int file_output2;
    char buffer[BUFSIZ];

    if((file_input = open("test.txt", O_RDONLY)) < 0){
        perror("test.txt doesn't exist! Error :");
        return EXIT_FAILURE;
    }

    if((file_output1 = open("output1.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0){
        perror("output1.txt doesn't exist! Error :");
        close(file_input);
        return EXIT_FAILURE;
    }

    if((file_output2 = open("output2.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0){
        perror("output2.txt doesn't exist! Error :");
        close(file_output1);
        close(file_input);
        return EXIT_FAILURE;
    }

    int nombreInput, nombreOutput;
    while((nombreInput = read(file_input, buffer, sizeof(buffer))) > 0){
        if((nombreOutput = write(file_output1, buffer, nombreInput)) != nombreInput){
            perror("error writing to output1.txt! Error : ");
            close(file_output2);
            close(file_output1);
            close(file_input);
            return EXIT_FAILURE;
        }
    }

    lseek(file_output1, 0, SEEK_SET);

    while((nombreInput = read(file_output1, buffer, sizeof(buffer))) > 0){
        if((nombreOutput = write(file_output2, buffer, nombreInput)) != nombreInput){
            perror("error writing to output2.txt! Error : ");
            close(file_output2);
            close(file_output1);
            close(file_input);
            return EXIT_FAILURE;
        }
    }

    close(file_output2);
    close(file_output1);
    close(file_input);

    return EXIT_SUCCESS;

}