package CoR;

public abstract class DicoEtrangerFrancaisCOR implements DicoEtrangerFrancais {
    DicoEtrangerFrancaisCOR suivant;
    
    public DicoEtrangerFrancaisCOR(DicoEtrangerFrancaisCOR suivant)
    {
    super();
    this.suivant = suivant;
    }

    @Override
    public String traduit(String t) {
        String s = this.traduit1(t);
        if(s == null) return t;
        return s;
    }

    private String traduit1(String texte){
        String s = this.traduit2(texte);
        if(s != null) return s;
        else 
            if( this.suivant != null) return this.suivant.traduit1(texte);
            else 
                return null;
    }

    abstract protected String traduit2(String texte);


}
