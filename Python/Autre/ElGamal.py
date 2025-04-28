import string
message = "CEST TOI JOJO ET PAS THIBAULT"
crypte = []
keya = 2093
keyb = 1934
g = 228476038
p = 87
## clé 67, 22,  
A = pow(g,keya,p)
B = pow(g,keyb,p)
print(A)
print(B)
print(pow(A,keyb,p))
print(pow(B,keya,p))
tab = []
for val in message:
    x = ord(val)
    tab.append(x)
tabcrypte = []
for val in tab:
    tabcrypte.append(val*pow(A,keyb,p)%p)
print(tabcrypte)
tabdecrypte = []
for val in tabcrypte:
    tabdecrypte.append(val*pow(B,-keya,p)%p)
print(tabdecrypte)
mes = ""
for val in tabdecrypte:
    x = chr(val)
    mes += x
print(mes)
