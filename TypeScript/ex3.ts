interface Vitesse {
    Vmax():string;
};

abstract class Vehicule{
    private _name:string;
    protected vitesse:string;

    protected set name(v : string) {
        this._name = v;
    }
    
    protected get name() : string {
        return this._name;
    }

    constructor(name : string){
        this.name = name;
    }

}

class voiture extends Vehicule implements Vitesse
{  
    constructor(name : string){
        super(name);
        this.vitesse = " 130 km/h";
    }

    public Vmax() :string{
        return this.name + this.vitesse;
    }
    
};

class moto extends Vehicule implements Vitesse
{  
    constructor(name : string){
        super(name);
        this.vitesse = " 200 km/h";
    }

    public Vmax() :string{
        return this.name + this.vitesse;
    }
    
};

class camion extends Vehicule implements Vitesse
{  
    constructor(name : string){
        super(name);
        this.vitesse = " 80 km/h";
    }

    public Vmax() :string{
        return this.name + this.vitesse;
    }
    
};

function ex3() : void
{
    let tab : Array<Vitesse> = new Array<Vitesse>();
    tab.push(new voiture("C3"));
    tab.push(new moto("R1"));
    tab.push(new camion("Man"));
    
    for (let i = 0; i < 3; i++)
    {
        console.log(tab[i].Vmax());
    }
    
    return;
}
ex3();
