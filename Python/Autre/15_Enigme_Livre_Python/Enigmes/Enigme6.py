import time

global pin

def checkpin(essai):
    for i in range(len(pin)):
        time.sleep(1)
        if pin[i]!= essai[i]:
            return(False)
    return(True)

pin=input("Entrez un code PIN constitué de 6 chiffres entre 0 et 9 que l'ordinateur doit deviner : ")
