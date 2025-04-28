#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Creer un repertoire avec tous les droit
    mkdir("MonRepertoire", 0777);

    // creer deux liens pour les deux fichiers
    char file1_path[] = "MonRepertoire/Fichier1.txt";
    char file2_path[] = "MonRepertoire/Fichier2.txt";

    // Creer c'est deux fichiers avec tous les droit
    creat(file1_path, 0777);
    creat(file2_path, 0777);

    return 0;
}