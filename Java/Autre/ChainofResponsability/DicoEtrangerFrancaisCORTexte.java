package CoR;

public class DicoEtrangerFrancaisCORTexte extends DicoEtrangerFrancaisCOR {
    String tableauStrings[][];

    DicoEtrangerFrancaisCORTexte(DicoEtrangerFrancaisCOR suivant,String[][] t){
        super(suivant);
        this.tableauStrings = t;
    }
    @Override
    protected String traduit2(String texte)
    {
        int i;
        for(i = 0; i < tableauStrings.length ; ++i)
            if(texte.equalsIgnoreCase(tableauStrings[i][0]))
                return tableauStrings[i][1];
        return null;
    }
}

