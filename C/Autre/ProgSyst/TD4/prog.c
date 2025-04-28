#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 4096

int main() {

    int source_fd = open("texte.txt", O_RDONLY); // ouvre le fichier source
    if(source_fd == -1){
        perror("Error : Ouverture");
        return(errno);
    }
    // ouvre et creer le fichier destination avectous les droit
    int dest_fd = open("copie.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777); //, 0777
    if(dest_fd == -1){
        perror("Error : Ecriture ou creation");
        return(errno);
    }

    //creer un buffer
    char buffer[BUFFER_SIZE];
    int read_size = 0;
    read(source_fd, buffer, 10);

    read_size = read(source_fd, buffer, 10); //lire 10 caractères
    write(dest_fd, buffer, read_size); //ecrit 10 caractères
    
    read(source_fd, buffer, 10);

    read_size = read(source_fd, buffer, 5); //lire 5 caractères
    write(dest_fd, buffer, read_size); //ecrit 5 caractères

    // ferme les deux fichiers
    close(source_fd);
    close(dest_fd);

    return 0;
}