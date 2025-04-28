# Exercice
Exercice de base pour tous language.

Consigne sous forme d'algorithme.

</br>

Pour voir mes projets aller sur mon répertoire [*Project*](https://github.com/DorianBucc/Project)


</br>

---

## Exercice 1

- Travail sur les boucles, le tableau simple et affichage console.

#### Consigne

```
    fonction main:
        tab[]         // taille 3x3
        pour i < 3 faire
            afficher("-------------")
            pour y < 3 faire
                afficher("| " + tab[i,y] + " ")
            fin pour
            afficher("|")
        fin pour
        afficher("-------------")
```

#### Résultat

```
    -------------
    | 0 | 0 | 0 |
    -------------
    | 0 | 1 | 0 |
    -------------
    | 0 | 0 | 0 |
    -------------
```

</br>

---

## Exercice 2

- Travail sur les references (pointeur), l'utilisation des strings et fonction.
    
#### Consigne

```
    fonction modification(var):
        var <- var + " le monde"

    fonction main:
        var <- "Bonjour"
        modification(var)
        afficher(var)
```

#### Résultat

```
    Bonjour le monde
```

</br>

---

## Exercice 3

- Travail sur les objets, une interface et un tableau plus complexe. (langage pas fait pour : C, rust)

#### Consigne

```
    interface Vitesse:
        abstraite string Vmax()

    abstraite class Vehicule:
        string name
        string vitesse

    class voiture hérite Vehicule implémente Vitesse:
        voiture(name):
            vitesse = " 130 km/h"
    
    class moto hérite Vehicule implémente Vitesse:
        voiture(name):
            vitesse = " 200 km/h"
    
    class camion hérite Vehicule implémente Vitesse:
        voiture(name):
            vitesse = " 80 km/h"
    
    fonction main :
        const tailleTab     // tailleTab = 3
        Tab[]
        tab(0) <- voiture("C2")
        tab(1) <- moto("R1")
        tab(2) <- camion("Man")
        
        pour i < tailleTab faire
            afficher(tab(i)->Vmax())
        fin pour
```

#### Résultat

```
    C3 130 km/h
    R1 200 km/h
    Man 80 km/h
```

</br>

---

## Exercice 4

- Travail sur les threads, recursive simple et une simple entrée console.

#### Consigne

```
    booléen fonction isPremierRec(var, diviseur)
        si diviseur >= var alors
            retourne vrai
        sinon si var mod diviseur = 0 alors
            retourne faux
        fin si
        retourne isPremierRec(var, diviseur+2)
    
    booléen fonction isPremier(var)
        si var mod 2 = 0 alors
            retourne faux
        retourne isPremierRec(var, 3)

    fonction_du_thread()
        ecrire "Entrée les nombres du tableau, pour terminer taper 0"
        entier tab[] // tableau d'entier
        pour i < tailletableau faire
            lire var
            si var = 0 alors
                quitter la boucle
            sinon
                tab[i] <- var;
            fin si
        fin pour
        pour y < i faire
            si isPremier(tab[y]) alors
                ecrire "C'est un nombre premier : " + tab[y]
            sinon
                ecrire "Ce n'est pas un nombre premier : " + tab[y]
            fin si
        fin pour
    
    fonction main()
        thread1 <- creationThread(fonction_du_thread())
        i <- 0
        faire
            i <- i + 1
            attendre(1s)
        tant que thread1 fonctionne
        fermer le thread1
        ecrire "Temps d'execution : " + i + " seconde"
        ecrire "Fin du programme"

```

#### Résultat

```
    Entrée les nombres du tableau, pour terminer taper 0
    17
    25
    16
    0
    C'est un nombre premier : 17
    Ce n'est pas un nombre premier : 25
    Ce n'est pas un nombre premier : 16
    Temps d'execution : 9 seconde
    Fin du programme
```

</br>

---

## Exercice 5

- Travail sur les dictionnaires/maps, objet heritage, attribut statique.

#### Consigne

```
```

#### Résultat

```
```

</br>

---

## Exercice 6
- Introduction.

#### Consigne

```
```

#### Résultat

```
```

---
"# Cours" 
