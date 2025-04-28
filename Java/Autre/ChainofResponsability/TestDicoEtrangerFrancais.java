package CoR;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class TestDicoEtrangerFrancais {
    public static void main(String[] args) {
        DicoEtrangerFrancaisCOR dicoCOR = null;
        dicoCOR = new DicoEtrangerFrancaisCORDeviseToEuro(dicoCOR, '$', 0.91);
        dicoCOR = new DicoEtrangerFrancaisCORFahrToCelsius(dicoCOR);
        String t0[][] = 
                    {
                        {"Mind your own business","Occupez-vous de vos affaires"},
                        {"Nice to meet you","Enchanté de faire votre connaissance"},
                        {"How are you","Comment allez-vous"}
                    };
        String t1[][] = 
                    {
                        {"Una cerveza bien fria","Une bière bien fraiche"},
                        {"El coche de mis sueños","La voiture de mes rêves"},
                        {"Bizcocho","gâteau"}
                    };
        dicoCOR = new DicoEtrangerFrancaisCORTexte(dicoCOR, t1);
        dicoCOR = new DicoEtrangerFrancaisCORTexte(dicoCOR, t0);

        try {
        BufferedReader clavier = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Taper le texte à traduire");
        String texte = clavier.readLine();
        String result = dicoCOR.traduit(texte);
        System.out.println(result);
        } 
        catch (Exception e) {
        }
    }
}
