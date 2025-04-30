[*Retour*](https://github.com/DorianBucc/Cours/tree/main/Python/Cours/README.MD)

---

## Explication rapide sur les fonctions

Une fonction permet d'éviter de dupliquer du code, il permet aussi de facilité la modification du code ainsi que ça lisibilité.

#### Fonction Simple
```
def Test():		  # Ceci défini le nom de la fonction ainsi que c'est paramètre et son retour ( les paramètres et le retour sera expliquer plus loin)
	print("afficher") # Ici on défini le contenu et donc l'action de la fonction lorsqu'elle est appelée

        		  # Pour l'instant rien ne c'est passé

Test()			  # C'est ici que la fonction est appelé et donc déclenche 1 fois son contenu
```

#### Fonction avec des paramètres et un retour

Les paramètres permettent de transferer des valeurs aux fonctions qu'elles pouront réutiliser.

Le retour permet de retourner un resultat provenant de la fonction. Quand le retour est utilisé il arrête la fonction pour envoyer le resultat.

```
def TTC(a, b)
	resultat = (a + b) * 1.2
	return resultat
# Exemple d'utilisation
banane = 2
pomme = 1
prix = TTC(banane,pomme)
print(prix) 			# Affiche 3.6
```

</br>

---

## Exercice sur les fonctions

### Exercice 1 Utilisation simple d'une fonction

- Consigne Utilisé une seule fois print et ne pas utiliser de boucle 

#### Résultat à afficher dans le terminal : 

```
HelloWorld
HelloWorld
```

</br>

---

### Exercice 2 Utilisation des paramètres

- Consigne créer une fonction qui affiche l'enssemble des deux string avec un " _ " entre les deux

#### Format du code à utiliser (Schématisé avec de l'algoritme)

```
fonction nom_de_fonction(param1,param2):
	// le code à ajouter pour afficher le mot voulu

nom_de_fonction("Hello","World") 	// Appel de la fonction pour la déclencher
```

#### Résultat à afficher dans le terminal : 

```
Hello_World
```

</br>

---

### Exercice 3 Utilisation des paramètres avec le retour

- Consigne créer une fonction qui assemble deux string avec un " _ " entre les deux et qui retourne son résultat

❗Ne pas utiliser *print()* dans la fonction

#### Format du code à utiliser (Schématisé avec de l'algoritme)

```
fonction nom_de_fonction(param1,param2):
	// le code à ajouter
	retourner resultat

resultat = nom_de_fonction("Hello","World") 	// Appel de la fonction pour la déclencher
afficher(resultat)
```

#### Résultat à afficher dans le terminal : 

```
Hello_World
```

</br>

---

### Exercice 4

- Consigne qui modifie deux variables sans les retourner mais en les modifiants en dehors de la fonction

#### Format du code à utiliser (Schématisé avec de l'algoritme)

```
fonction nom_de_fonction(param1, param2):
	// le code à ajouter

a = 5
b = 7
resultat = nom_de_fonction(a, b)
afficher("La valeur de a : ", a)
afficher("La valeur de b : ", b)
```

#### Résultat à afficher dans le terminal :

```
La valeur de a : 6
La valeur de b : 9
```

</br>

---

### Exercice 5

- Avec le programme correct de l'exercice 4 faite en sorte que cette fois les valeurs ne soit pas modifiées hors de la fonction

#### Format du code à utiliser (Schématisé avec de l'algoritme)

```
fonction nom_de_fonction(param1, param2):
	// le code à ajouter
	afficher("La valeur de a dans la fonction : ", param1)
	afficher("La valeur de b dans la fonction : ", param2)

a = 5
b = 7
resultat = nom_de_fonction(a, b)
afficher("La valeur de a : ", a)
afficher("La valeur de b : ", b)
```

#### Résultat à afficher dans le terminal :

```
La valeur de a dans la fonction : 6
La valeur de b dans la fonction : 9
La valeur de a : 5
La valeur de b : 7
```

</br>

---