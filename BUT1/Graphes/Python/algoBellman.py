import math

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
	(10,9): 5
}

# fonction qui retourne la liste des sommets de G
def sommets(G):
	S = set()
	for (x,y) in G.keys():
		S.add(x)
		S.add(y)
	S = list(S)
	S.sort() # non obligatoire
	
	return S
	
# fonction qui retourne les listes d'adjacence, Succ et Pred, de G
def adj(G, S):
	Succ = {s : [] for s in S}
	Pred = {s : [] for s in S}
	for (x,y) in G.keys():
		Succ[x].append(y)
		Pred[y].append(x)

	return Succ, Pred

# fonction qui détermine un ordre topologique et retourne une liste 
def tri_topo(S, Succ, Pred):
	C = []
	marque = {}
	for s in S:
		marque[s] = len(Pred[s])
		if marque[s] == 0:
			C.append(s)

	liste_topo = []
	while len(C) > 0:
		s = C.pop(0)
		liste_topo.append(s)
		for x in Succ[s]:
			marque[x] = marque[x] - 1
			if marque[x] == 0:
				C.append(x)
		C.sort() # non obligatoire

	return liste_topo
	
# algorithme de Bellman qui détermine
# une r-arborescence de chemins de poids minimum
def Bellman_Arbo_Min(r, G, Pred, topo):
	Arbo = {}
	Pi = {}
	for s in topo:
		if s == r:
			Pi[s]   = 0
			Arbo[s] = None
		else:
			Pi[s]   = math.inf # représente +infini en python
			Arbo[s] = s
			for x in Pred[s]:
				if Pi[s] > Pi[x] + G[(x,s)]:
					Pi[s]   = Pi[x] + G[(x,s)]
					Arbo[s] = x
	return Arbo, Pi

# A FAIRE : 
# algorithme de Bellman qui détermine une r-arborescence de chemins de poids maximum
# algorithme de Bellman qui détermine une r-anti-arborescence de chemins de poids minimum
# algorithme de Bellman qui détermine une r-anti-arborescence de chemins de poids maximum
# indication : si L est une liste alors L.reverse() inverse la liste L


g = g2
gS = sommets(g)
gSucc, gPred = adj(g, gS)
gtopo = tri_topo(gS, gSucc, gPred)

racine = 1
Arbo, Pi = Bellman_Arbo_Min(racine, g, gPred, gtopo)

print()
print("\t".join(["sommets    :"] + [str(s) for s in gtopo]))
print("\t".join(["potentiels :"] + [str(Pi.get(s)) for s in gtopo]))
print("\t".join(["peres      :"] + [str(Arbo.get(s)) for s in gtopo]))
print()