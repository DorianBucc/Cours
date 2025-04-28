#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main() {

    int source_fd = open("source.txt", O_RDONLY); // ouvre le fichier source
    // ouvre et creer le fichier destination avectous les droit
    int dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777); 

    //creer un buffer
    char buffer[BUFFER_SIZE];
    // varible te type nb octet
    ssize_t OctetsLus;

    while ((OctetsLus = read(source_fd, buffer, BUFFER_SIZE)) > 0) { // lit dans le fichier source
        write(dest_fd, buffer, OctetsLus); // ecrit dans le fichier destination
    }

    // ferme les deux fichiers
    close(source_fd);
    close(dest_fd);

    return 0;
}