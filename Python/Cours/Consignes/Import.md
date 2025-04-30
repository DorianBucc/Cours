[*Retour*](https://github.com/DorianBucc/Cours/tree/main/Python/Cours/README.MD)

---

## Explication sur les imports

Commencé par installer un import : ```pip install requests```

```
import requests

response = requests.get('https://api.projetu.fr/jap/cours')
print(response.status_code)  # Code HTTP (ex: 200)
print(response.text)         # Contenu brut de la réponse
print(response.json())       # Si c'est du JSON
```

Pour import un fichier localement

Fichier python : Fonction.py
```
def Associe(mot1, mot2):
  return mot1 + mot2
```

Fichier main.py
```
from Fonction import Associe

print( Associe("Hello","World") ) 
```
</br>

---
