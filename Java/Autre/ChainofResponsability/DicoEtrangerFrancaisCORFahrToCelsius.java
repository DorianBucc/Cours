package CoR;

public class DicoEtrangerFrancaisCORFahrToCelsius extends DicoEtrangerFrancaisCOR {

    final static String FAHR = "°F";
    final static String CELSIUS = "°C";
    final static double a = 5.0/9;
    final static double b = -32;

    public DicoEtrangerFrancaisCORFahrToCelsius(DicoEtrangerFrancaisCOR suivant)
    {
        super(suivant);
    }
    @Override
    protected String traduit2(String texte) 
    {
        try 
        {
        if(!texte.endsWith(FAHR)) return null;
        String s = texte.substring(0,texte.length()-2);
        double v = Double.parseDouble(s);    
        double vCelsuis = (v + b) * a;
        return Double.toString(vCelsuis)+CELSIUS;
        }
        catch (NumberFormatException e) {
            return null;
        }
    }
}
