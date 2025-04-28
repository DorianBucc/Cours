#include <iostream>
#include <string>
#include <vector>

// Interface class
class Vitesse {
public:
    virtual std::string Vmax() const = 0;
};

class Vehicule {
private:
    std::string _name;
protected:
    std::string vitesse;
    void setName(std::string v){
        this->_name = v;
    }
    std::string getName() const{
        return this->_name;
    }
};

class voiture : public Vitesse, protected Vehicule
{
public:
    voiture(std::string name){
        this->setName(name);
        this->vitesse = " 130 km/h";
    }
    std::string Vmax() const override{
        return this->getName() + vitesse;
    }
};

class moto : public Vitesse, protected Vehicule
{
public:
    moto(std::string name){
        this->setName(name);
        this->vitesse = " 200 km/h";
    }
    std::string Vmax() const override{
        return this->getName() + vitesse;
    }
};

class camion : public Vitesse, protected Vehicule
{
public:
    camion(std::string name){
        this->setName(name);
        this->vitesse = " 80 km/h";
    }
    std::string Vmax() const override{
        return this->getName() + vitesse;
    }
};

int main()
{
    const int tailleTab = 3;
    std::vector<Vitesse*> tab;
    tab.push_back(new voiture("C3"));
    tab.push_back(new moto("R1"));
    tab.push_back(new camion("Man"));
    
    for (int i = 0; i < tailleTab; i++)
    {
        std::cout << tab[i]->Vmax() << std::endl;
    }
    
    return 0;
}
