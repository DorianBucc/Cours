package CoR;

public class DicoEtrangerFrancaisCORDeviseToEuro extends DicoEtrangerFrancaisCOR {
    char symbole;
    double tauxChange;

    public DicoEtrangerFrancaisCORDeviseToEuro(DicoEtrangerFrancaisCOR suivant, char symbole, double tauxChange){
        super(suivant);
        this.symbole = symbole;
        this.tauxChange = tauxChange;
        
    }
    @Override
    protected String traduit2(String texte) 
    {
        try 
        {
        char c = texte.charAt(0);
        if(c != this.symbole) return null;
        String s = texte.substring(1);
        double v = Double.parseDouble(s);    
        double vEuro = v * tauxChange;
        return "€"+vEuro;
        }
        catch (NumberFormatException e) {
            return null;
        }
    }
}
