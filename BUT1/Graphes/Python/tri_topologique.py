# les dictionnaires ou tables associatives en Python :
# un dictionnaire est un tableau associatif qui associe une valeur à une clé
# les clés peuvent être de n’importe quel type

# Le graphe est représentée par un dictionnaire où les clés sont des arcs
# et où les valeurs sont les poids des arcs
# clé = (x, y) --> valeur : poids de l'arc (x,y)

# les sommets peuvent être représentés par des entiers
# ou par des chaînes de caractères


# Remarque : les poids des arcs ne sont pas utilisés par le tri topologique, mais
# ils seront utilisés par l'algorithme de Bellman-Kalaba


# dictionnaire d'un premier graphe
g1 = {
	("a","b"): 1,
	("a","d"): 3,
	("b","c"): 3,
	("b","d"): 4,
	("d","e"): 1,
	("e","c"): 2,
	("e","f"): 1
}

# dictionnaire d'un second graphe
g2 = {
	(1,2): 9,
	(1,3): 8,
	(2,4): 7,
	(3,4): 7,
	(3,5): 8,
	(4,6): 3,
	(4,7): 9,
	(5,6): 5,
	(5,7): 6,
	(6,8): 1,
	(6,9): 4,
	(7,9): 1,
}

# choix du graphe
G = g1

# construction de l'ensemble des sommets représenté par une liste de sommets
# la liste est triée dans l'ordre croissant
S = sorted(list(set([x for (x,y) in G.keys()] + [y for (x,y) in G.keys()])))
S.sort()
print("liste des sommets :\n\t", S)
print("liste des arcs    :\n\t", list(G.keys()))

# construction des listes d'adjacence Succ et Pred
Succ = {s : [] for s in S}
Pred = {s : [] for s in S}
for (x,y) in G.keys():
	Succ[x].append(y)
	Pred[y].append(x)

# initialisation des marques (dictionnaire) et
# de l'ensemble des candidats C (liste gérée comme une file FIFO)
C = []
marque = {}
for s in S:
	marque[s] = len(Pred[s])
	if marque[s] == 0:
		C.append(s)

# construction de la liste des sommets rangés dans l'odre topologique
liste_topo = []
while len(C) > 0:
	print()
	print("les candidats :", " ".join(str(c) for c in C))
	s = C.pop(0)
	liste_topo.append(s)
	for x in Succ[s]:
		marque[x] = marque[x] - 1
		if marque[x] == 0:
			C.append(x)
	C.sort() # liste des candidats triés dans l'ordre croissant
	print("candidat choisit :", s)
	print("liste en cours de construction :", liste_topo)

print()
print("liste des sommets rangés dans l'ordre topologique :\n\t", liste_topo)
print()
