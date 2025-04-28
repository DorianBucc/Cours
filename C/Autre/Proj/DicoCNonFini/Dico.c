#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void vidbuffer()
{
    while (getchar() != '\n'){}
}

void menu(){
        printf("\nLancer la recherche : 1\n");
        printf("Modifier le fichier du jeu de donnee : 2\n");
        printf("Modifier le nom du fichier des mot de passe : 3\n");
        printf("Fermer le Programme : 4\n");
}
// void pass(int t){
    /*
    aaaaaaaaaa\n
    AAAAAAAAAA
    AaAaAaAaAa
    aAaAaAaAaA
    */

// }
int lecturefichier(char* *tNom,char* tPseudo,int* tNombre, char* localise){
    FILE* fichier;
    char caractere;

    // Ouvrir le fichier en mode lecture
    fichier = fopen(localise, "r");

    // Vérifier si le fichier a été ouvert avec succès
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 0;
    }
    int mod = 1;
    int w = 1;
    int wtab = 1;
    int tabCompteur = 0;
    int tabLenght = 0;
    // Lire le contenu caractère par caractère
    while ((caractere = fgetc(fichier)) != EOF) {
        
        if(caractere == ":" && mod == 1){
            mod = 2;
            w = 0;

        }
        else if(mod == 2){
            switch (caractere)
            {
            case 'n':
                wtab = 1;
                break;
            case 'c':
                wtab = 2;
                break;
            }
        }

        if(w==1){
            
        }
        printf("%c", caractere);
    }
    while ((caractere = fgetc(fichier)) != EOF) {
        printf("%c", caractere);
    }

    // Fermer le fichier
    fclose(fichier);
    return 1;
}

// void ecrire(char* str,int av,int ap){
//     char* temp;
//     for (int i = av-1; i < ap-1; i++)
//     {
        
//     }
    
// }

// int findExe(char* str){
//     int i;
//     for ( i = 0; i < strlen(str); i++)
//     {
//         if(str[i] == '.'){
//             for (int y = i; y > 0; y--)
//             {
//                 if (str[y] == '\\')
//                 {
//                     /* code */
//                 }
                
//             }
            
//         }
//     }
    
    
    
//     return 0;

// }

void main(int argc, char *argv[])
{
    int complexe = 11;           //structuration des passwd
    int NombreComplexe = 100;    //nombre pouvant etre écrit en lettre
    int LongPrefixe = 5;         //longueur des acronyme de mot exemple visual avec 4 : vi, vis, visu
    int lang = 2;                //variable pour le choix des langue All=0 En=1 Fr=2
    int TabTaille = 0;
    char* LiNom[500];           //liste des noms //5000000
    int LiNombre[500];          //liste des nombre : 2 ou deux
    char LiPseudo[500];         //liste des pseudo : FYnD ne sera pas modifier (!= fynd) (nom != pseudo)
    char* fichierSortie = "../resultat/text.txt";

    char* hierachie = malloc(strlen(argv[0]) * sizeof(char));
    strcpy(hierachie,argv[0]);
    char *dernierSeparateur = strrchr(hierachie, '\\'); // Trouver la dernière occurrence du séparateur de chemin
    if (dernierSeparateur != NULL) *dernierSeparateur = '\0'; // Ajouter un caractère nul pour terminer la chaîne à cet emplacement
    else  printf("Chemin du répertoire du programme : . (répertoire courant)\n");
    strcat(hierachie,"\\");
    char* fichierConfig = strcat(hierachie,"data.txt"); //"C:/Users/bucch/Git/Programme/C/Console1/data.txt"   //C:/Users/bucch/Git/Programme/C/Console1
    
    lecturefichier(LiNom,LiPseudo,LiNombre,fichierConfig);
    
    int Start = 1;
    char Intro0[] = "\n********    ***     ******      ******\n***   ***    *     ****        ***  ***\n***   ***    *     ***         ***  ***\n***   ***    *     ****        ***  ***\n********    ***     ******      ******\n";            
    char Intro1[] = "\n=====    ====     ====    ====\n||  ||    ||     ||      ||  ||\n||   ||   ||    ||       ||  ||\n||  ||    ||     ||      ||  ||\n=====    ====     ====    ====\n";
    char Intro2[] = "\n########    ###     ######      ######\n###   ###    #     ####        ###  ###\n###   ###    #     ###         ###  ###\n###   ###    #     ####        ###  ###\n########    ###     ######      ######\n";
    char Intro3[] = "\n........    ...     ......      ......\n...   ...    .     ....        ...  ...\n...   ...    .     ...         ...  ...\n...   ...    .     ....        ...  ...\n........    ...     ......      ......\n";
    char Intro4[] = "\n++++++++    +++     ++++++      ++++++\n+++   +++    +     ++++        +++  +++\n+++   +++    +     +++         +++  +++\n+++   +++    +     ++++        +++  +++\n++++++++    +++     ++++++      ++++++\n";
    char Intro5[] = "\n@@@@@@@@    @@@     @@@@@@      @@@@@@\n@@@   @@@    @     @@@@        @@@  @@@\n@@@   @@@    @     @@@         @@@  @@@\n@@@   @@@    @     @@@@        @@@  @@@\n@@@@@@@@    @@@     @@@@@@      @@@@@@\n";       
    srand(time(NULL));
    int nA = rand() % 6;
    
    switch (nA)
    {
    case 0:
        printf(Intro0);
        break;
    case 1:
        printf(Intro1);
        break;    
    case 2:
        printf(Intro2);
        break;
    case 3:
        printf(Intro3);
        break;
    case 4:
        printf(Intro4);
        break;
    case 5:
        printf(Intro5);
        break;
    default:
        printf("\nErreur Chargement\n");
        break;
    }
    char get;
    while(Start == 1){
        menu();
        get = getchar();
        vidbuffer();
        if(get == '4'){
            Start = 0;
            printf("Exit\n");
            break;
        }
        else if(get == '1'){
            printf("Lancement test\n");
            printf("Terminer\n");
        }
        else if(get == '2'){
            printf("setdata\n");
            // pass.setFichierConfig(scan.readLine());
        }
        else if(get == '3'){
            printf("setsortie\n");
            // pass.setFichierSortie(scan.readLine());
        }
    }
    free(hierachie);
}