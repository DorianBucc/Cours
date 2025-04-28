#include <stdio.h>
#include <fcntl.h>
// #include <unistd.h>

int main() {
    // Utilisation de open
    int fd = open("example_open.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Erreur lors de l'ouverturlse avec open");
        return 1;
    }
    write(fd, "Hello, open!\n", 13);
    close(fd);

    // Utilisation de fopen
    FILE *file = fopen("example_fopen.txt", "w");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture avec fopen");
        return 1;
    }
    fprintf(file, "Hello, fopen!\n");
    fclose(file);

    return 0;
}

