import java.util.Scanner;

public class input {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);  // objet pour lancer le scan de touche""
        System.out.println("Le message : " + scan.nextLine()); // ecrire le message qu'on va entré grace à scan.nextline()
        scan.close();       // objet Fermer
    }
}
