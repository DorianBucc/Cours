#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
    char nFile[] = "Test2.txt";
    // int fi = creat(nFile,O_CREAT|O_RDONLY|O_WRONLY); 

    int fd = open(argv[1],O_RDONLY);
    if(fd == -1){
        perror("Open ");
        return(errno);
    }
    int fd2 = open("Test2.txt",O_CREAT|O_WRONLY);
    if(fd2 == -1){
        perror("Now Open ");
        return(errno);
    }

    char temp[15];
    int read_size=read(fd, temp, 10); //lire 10 caractères de test1.txt
    int write_size=write(fd2, temp, 10);// écrire ces 10 caractères dans test2.txt
    close(fd2); // fermer le fichier test2.txt
    rename(nFile, "test3.txt"); // renommer le fichier test2.txt en test3.txt
    unlink(argv[1]); // supprimer le fichier test1.txt
    close(fd); // fermer le fichier test2.txt
    return 0;

}