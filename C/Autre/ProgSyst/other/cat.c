#include <stdio.h>
#include <stdlib.h>
// #include <libgen.h>
#include <errno.h>
#include <string.h>
// #include <unistd.h>  // Nouvelle inclusion pour les opérations d'E/S
#include <fcntl.h>   // Nouvelle inclusion pour les opérations de fichiers

int main(void) {
    char buffer[100];
    int n;

    int fd = open("filename.txt", O_RDONLY);
    if (fd == -1)
        exit(1);

    n = read(fd, buffer, 100);
    while (n > 0) {
        write(STDOUT_FILENO, buffer, n);
        n = read(fd, buffer, 100);
    }

    close(fd);  // Fermer le fichier après utilisation
    exit(0);
}

