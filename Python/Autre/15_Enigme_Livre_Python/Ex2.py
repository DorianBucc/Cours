tableau0 = ["S","E","N","D","M","O","R","Y"]
tableau1 = [1,0,0,0,0,0,0,0]
106805

t1 = "SEND"
t2 = "MORE"
t3 = "MONEY"

def translate(text, tableau0, tableau1) -> int:
    result = 0
    multiplicateur = 1
    text = reversed(text)
    for t in text :
        result += tableau1[tableau0.index(t)]*multiplicateur
        multiplicateur *= 10
    return result

def verif(tableau) -> bool :
    
    for y in range(0,10):
        count = 0
        for i in range(0,8):
            if tableau[i] == y :
                count += 1
        if count > 1 :
            return False
    return True

def brute(tableau,t1,t2,t3,tableauCaractere):
    while verif(tableau) == False :
        launch = True
        while translate(t1,tableauCaractere,tableau)+translate(t2,tableauCaractere,tableau) != translate(t3,tableauCaractere,tableau) or tableau[0] == 0 or tableau[4] == 0 or launch == True:
            launch = False
            tableau[0] += 1
            for i in range(0,8):
                if tableau[i] >= 10 :
                    tableau[i] = 0
                    tableau[i+1] += 1
            # print(tableau)
    print(translate(t1,tableauCaractere,tableau)+translate(t2,tableauCaractere,tableau))
    print(translate(t3,tableauCaractere,tableau))
    print(tableau)

brute(tableau1,t1,t2,t3,tableau0)
