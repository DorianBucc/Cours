#include <stdlib.h>
#include <stdio.h>
// #include <libgen.h>
#include <errno.h>
#include <string.h>
// #include <unistd.h>
#include <fcntl.h>

int main(void) {
    char buf[100];
    int n;
    
    int fd = open("fichier", O_CREAT | O_RDWR, 0600);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Déplacer le pointeur du fichier à la position 3 du fichier
    lseek(fd, 3, SEEK_SET);

    // Lire un caractère dans buf (buf reçoit p)
    n = read(fd, buf, 1);
    if (n == -1) {
        perror("Erreur lors de la lecture du fichier");
        close(fd);
        exit(EXIT_FAILURE);
    }
    write(STDOUT_FILENO, buf, n);

    // Positionner le pointeur deux caractères plus loin
    lseek(fd, 2, SEEK_CUR);

    // La valeur du pointeur est maintenant 3 + 2 = 5.

    // Lire un caractère dans buf (buf reçoit n)
    n = read(fd, buf, 1);
    if (n == -1) {
        perror("Erreur lors de la lecture du fichier");
        close(fd);
        exit(EXIT_FAILURE);
    }
    write(STDOUT_FILENO, "\n", 1);  // Ajouter un saut de ligne
    write(STDOUT_FILENO, buf, n);

    // Positionner le pointeur à la fin du fichier
    lseek(fd, 0, SEEK_END);

    // La valeur du pointeur est maintenant à la fin du fichier.

    // Lire un caractère dans buf (retournera 0 car nous sommes à la fin du fichier)
    n = read(fd, buf, 1);
    if (n == -1) {
        perror("Erreur lors de la lecture du fichier");
        close(fd);
        exit(EXIT_FAILURE);
    }
    write(STDOUT_FILENO, "\n", 1);  // Ajouter un saut de ligne
    write(STDOUT_FILENO, buf, n);

    close(fd);
    exit(EXIT_SUCCESS);
}

