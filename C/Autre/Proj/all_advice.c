//---------------------------------------Librairie------------------------------------------------------//
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>

#define ALPHA_SIZE 26


//---------------------------------------Fonctions sans pointeur, ni adresse------------------------------------------------------//
void count_number(){//Pas de variable dans la fonction car on ne change aucune variable du int main(){}
    int max = 10;
    int i;
    for(i = 0; i < max; i++){
        printf("value of i+%d : %d\n", i, i);//%d car affichage d'un décimal
    }
}

void display_char(){
    int i;
    char start = 'a';
    for(i = 0; i < ALPHA_SIZE; i++){
        printf("%c", start + i);//Exemple : a + 0 = a; a + 1 = b; a + i = ième lettre de l'alphabet;
    }
    printf("\n");
}

void ask_name_n_display(){//Fonction demande nom et affiche. Ex : variable fixe.
    char name[10];
    printf("\nHey, what's your name ?");
    scanf("%s", name);//%s car affichage d'une string/chaine de caractères.
    printf("Hello %s, I am a Robot.\n\n", name);
}


//---------------------------------------Fonctions avec pointeur et adresse-----------------------------------------------------//
void ask_name(char* name){
    char* temporary_name;
    temporary_name = malloc(sizeof(char) * 20);
    printf("Hey, what's your name ?\n");
    scanf("%s", temporary_name);
    strcpy(name, temporary_name);
    printf("Hello %s, I'am a Robot.\n\n", name);
    free(temporary_name);
}

void ask_old(char* name, int* old){
    int* temporary_old = 0;
    temporary_old = malloc(sizeof(int) * 10);
    printf("Hey, how old are you ?\n");
    scanf("%d", temporary_old);
    *old = *temporary_old;
    switch (*old)
    {
    case 0:
        printf("Hello %s, now I know you've %d year old.\n\n", name, *old);
        break;
    case 1: 
        printf("Hello %s, now I know you've %d year old.\n\n", name, *old);
        break;
    default:
        printf("Hello %s, now I know you've %d yearS old.\n\n", name, *old);
        break;
    }
    free(temporary_old);
}

void ask_postal_code(char* name, int* old, int* postal_code){
    printf("Please enter your postal code : ");
    scanf("%d", postal_code);
    printf("\nYou're name is %s, you've %d and you're postal code is %d.\n\n", name, *old, *postal_code);
}


//---------------------------------------Les différents retour de fonctions------------------------------------------------------//

void return_nothing(){
    printf("Void function : \n");
    printf("This function return nothing.\n\n");
}

int addition(int* a, int* b){
    printf("Int function : \n");
    printf("This funtion return the addition of the first and second number enter in parameter.\n");
    return *a + *b;
}

char return_char(char caractere){
    printf("Char function : \n");
    printf("This funtion return a character.\n");
    return caractere;
}

bool greater_than(int* a, int* b){//Cette fonction retourne true/vrai dans cas ou "a" et supérieur à "b". Sinon elle retourne false/faux.
    printf("Boolean function : \n");
    if(*a < *b) return false;
    
    return true;
}


//---------------------------------------Tableau 2D------------------------------------------------------//

void ask_size(int* line, int* column){
    do{
        printf("please enter line size : ");
        scanf("%d", line);
        printf("\nplease enter column size : ");
        scanf("%d", column);

        if((*line < 1 || *column < 1) && (*line > 10 || *column > 10)) printf("invalid value. Mini size = 10 and Max size = 10");

    }while((*line < 1 || *column < 1) && (*line > 10 || *column > 10));
}

int** create_array(int* line, int*column){
    int** array = malloc(sizeof(int*) * (*line));
    for(int i = 0; i < (*line); i++){
        array[i] = malloc(sizeof(int) * (*column));
    }
    return array;
}

void init_array(int** array, int* line, int* column){
    for(int i = 0; i < (*line); i++){
        for(int y = 0; y < (*column); y++){
            array[i][y] = 0;
        }
    }
}

void display_array(int** array, int* line, int* column){
    for(int i = 0; i < (*line); i++){
        for(int y = 0; y < (*column); y++){
            printf("%d", array[i][y]);
        }
        printf("\n");
    }
}

void free_array(int** array, int* line){
    for(int i = 0; i < (*line); i++){
        free(array[i]);
    }
}

void array_prog(int*** array, int* line, int* column){
    ask_size(line, column);
    *array = create_array(line, column);
    init_array(*array, line, column);
    display_array(*array, line, column);
    free_array(*array, line);
}


//---------------------------------------Structure de données------------------------------------------------------//

typedef struct rectangle
{
    int lenght;
    int witdh;
}R;

void create_rectangle(R* r){
    r->lenght = 10;
    r->witdh = 20;
    printf("Rectangle | lenght = %d & width = %d\n", r->lenght, r->witdh);
}

typedef struct triangle
{
    R rectangle;
    int height;
}T;

void create_triangle(T* t){
    t->rectangle.lenght = 20;
    t->rectangle.witdh = 25;
    t->height = 30;
    printf("Triangle  | lenght = %d & width = %d & height = %d\n", t->rectangle.lenght, t->rectangle.witdh, t->height);
}


//---------------------------------------Manipulation chaines de caractère------------------------------------------------------//

char* concat_2_strings(const char* first, const char* second){
    char* temp;
    temp = malloc(strlen(first) + strlen(second) + 1);
    puts("please enter the first string : "); scanf("%s", first);
    puts("\nplease enter the second string : "); scanf("%s", second);
    strncpy(temp, first, strlen(first) + 1);
    strncat(temp, second, strlen(second) + 1);

    return temp;
}

char* concat_2_numbers(const unsigned int* first, const unsigned int* second){
    char* temp;
    char* convert1, *convert2;
    convert1 = malloc(sizeof(char) * 10);
    convert2 = malloc(sizeof(char) * 10);
    temp = malloc(sizeof(char) * 1 + 1);
    puts("\nplease enter the first number : "); scanf("%d", first);
    puts("please enter the second number : "); scanf("%d", second);
    sprintf(convert1, "%d", *first);
    sprintf(convert2, "%d", *second);
    strncpy(temp, convert1, strlen(convert1) + 1);
    strncat(temp, convert2, strlen(convert2) + 1);

    free(convert1);
    free(convert2);
    return temp;
}


//---------------------------------------Fonction récursives------------------------------------------------------//

int sum_integer(unsigned int integer){
    if(integer == 1){
        return 1;
    }else{
        return integer + sum_integer(integer - 1);
    }
}

void all_possibilities(char start, char end, int lenght){ //Non fonctionnel
    for(int i = 0; i <= 26; i++){
        printf("%c", "a" + i);
    }
}


//---------------------------------------Manipulation de fichier------------------------------------------------------//

void read_file(char* file_name){
    FILE *readfile;
    readfile = fopen(file_name, "r");

    if(readfile == NULL) puts("[-]empty file\n");
    
    puts("file contents : ");
    char character = fgetc(readfile);
    while(character != EOF){
        putchar(character);
        character = fgetc(readfile);
    }
    printf("\n");

    fclose(readfile);
}

void write_file(char* file_name){
    char character;
    FILE *writefile;
    writefile = fopen(file_name, "w");

    if(writefile == NULL) puts("error open file.");

    puts("please enter text to write : \n");
    while((character = getchar()) != EOF){
        fputc(character, writefile);
    }
    printf("\n");

    fclose(writefile);
}

void write_file_aside(char* file_name){
    char character;
    FILE *writefile;
    writefile = fopen(file_name, "a");

    if(writefile == NULL) puts("error open file.");

    puts("please enter text to write : \n");
    while((character = getchar()) != EOF){
        fputc(character, writefile);
    }
    printf("\n");

    fclose(writefile);
}

//---------------------------------------Partie executable------------------------------------------------------//
int main(void){ //Ou int main(void){}
    printf("\nfunction count number allow you to display the number from 0 to max value.\n\n");
    count_number();
    printf("--------------------------------------------------------------\n\n");
    printf("\nfunction display char allow you to display all characters of the alphabet.\n\n");
    display_char();
    printf("--------------------------------------------------------------\n\n");
    printf("\nfuntion ask and display name.\n\n");
    ask_name_n_display();

    printf("--------------------------------------------------------------\n\n");
    printf("\nThis part of the program teach you how variable are stock in memory.\n\n");

    int one = 1;
    char first = 'a';
    double uno = 8;

    printf("value of one = %d\nadr = %p\nadr+1 = %p\n\n", one, &one, &one+1);//Décalage de 4 entre les deux adresse car int = 4 bytes/octets.
    printf("value of first = %c\nadr = %p\nadr+1 = %p\n\n", first, &first, &first+1);//Décalage de 1 car char = 1 byte/octect.
    printf("value of a = %lf\nadr = %p\nadr+1 = %p\n\n", uno, &uno, &uno+1);//Décalage de 8 car double = 8 bytes/octets.
    //Petite aparte pour aller voir ce qui trouve à l'adresse d'à coté.
    printf("value for address one + 1 = %d\n\n", *((int*)(&one+1)));

    printf("--------------------------------------------------------------\n\n");
    printf("Pointeur and address part\n\n");
    //int* test = valeur se trouvant à l'adresse pointé.
    //test = valeur adresse pointé.
    //&test = adresse de test.
    //L'utilisation de pointeur permet de conserver la valeur de ce qui se trouve dans la variable
    //Dans cette exemple, je vais utiliser le nom rentrer dans name pour l'utiliser dans plusieurs fonctions.
    char* name;
    name = malloc(sizeof(char) * 20);
    ask_name(name);

    int old;
    ask_old(name, &old);

    int postal_code;
    ask_postal_code(name, &old, &postal_code);

    printf("--------------------------------------------------------------\n\n");
    printf("Let's move on the differents return of functions.\n\n");
    //Fonctions qui retournent void(rien), int(un entier), char(un caractère), bool(retoune vrai/faux) -> #include <stdbool.h>
    return_nothing();

    int a = 10, b = 20;
    int result = addition(&a, &b);//La variable result récupère le résultat de l'addtion a+b. On place le resultat d'un return dans une variable.
    printf("a + b = %d\n\n", result);

    char caractere = 'g';
    char result1 = return_char(caractere);
    printf("The enter character is : %c\n\n", result1);

    //Fonction boolean
    if(greater_than(&a, &b)){//Vu que la fonction retourne vrai si a est supérieur à b. Cela revient à dire : if(a > b){a est supérieur}else{b est supérieur};
        printf("'a' is greater than 'b | a = %d and b = %d'\n\n", a, b);                                                              //if(vrai){a est supp}else if(faux){b est supp}
    }else{
        printf("'b' is greater than 'a' | a = %d and b = %d\n\n", a, b);
    }

    free(name);

    printf("--------------------------------------------------------------\n\n");
    printf("Let's continue with the creation of a 2D array.\n\n");
    int** array = NULL;
    int line, column;
    array_prog(&array, &line, &column);

    printf("--------------------------------------------------------------\n\n");
    printf("Let's jump with the data structurs\n\n");
    R r;
    create_rectangle(&r);

    T t;
    create_triangle(&t);

    printf("--------------------------------------------------------------\n\n");
    printf("Now I will explain how concatenation work\n\n");

    char* char1, *char2;
    char* resultat;
    char1 = malloc(sizeof(char) * 10);
    char2 = malloc(sizeof(char) * 10);
    resultat = malloc(sizeof(char) * 10);
    resultat = concat_2_strings(char1, char2);
    printf("%s", resultat);

    unsigned int numb1, numb2;
    resultat = concat_2_numbers(&numb1, &numb2);
    printf("%s", resultat);

    printf("\n--------------------------------------------------------------\n\n");
    printf("Let's move on the differents recursives functions.\n\n");

    unsigned int integer;
    int sum;
    puts("enter a positive integer to calcul the sum until it : "); scanf("%d", &integer);
    sum = sum_integer(integer);
    printf("\nThe sum of integers from 1 to %d = %d\n\n", integer, sum);

    char start, end;
    int lenght;
    puts("\nplease enter the start character : "); start = getchar(); while(getchar() != '\n'){}
    puts("\nplease enter the last character : "); end = getchar(); while(getchar() != '\n'){}
    puts("\nplease enter the brute force lenght : "); scanf("%d", &lenght);
    all_possibilities(start, end, lenght);

    printf("--------------------------------------------------------------\n\n");
    printf("Now I will introduce how file works\n\n");

    char* readfilename;
    readfilename = malloc(sizeof(char) * 100);
    puts("enter the file name for read it : ");
    scanf("%s", readfilename);
    read_file(readfilename);

    char* writefilename;
    writefilename = malloc(sizeof(char) * 100);
    puts("enter the file name to write it : ");
    scanf("%s", writefilename);
    write_file(writefilename);

    char* writeasidefilename;
    writeasidefilename = malloc(sizeof(char) * 100);
    puts("enter the file name to write it : ");
    scanf("%s", writeasidefilename);
    write_file(writeasidefilename);
}