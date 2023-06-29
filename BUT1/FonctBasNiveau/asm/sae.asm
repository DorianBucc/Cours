;-----------------------------------------------------------------------
; 	ecrire un message a l'ecran
;-----------------------------------------------------------------------
			TITLE			DISPLAY - programme prototype
			.286

.model small		
.stack 100h
;-----------------------------------------------------------DATA segment
DSEG 		SEGMENT
;**************zone de variables
    hour    db  ?   ; heure actuelle
    minute  db  ?   ; minute actuelle
    second  db  ?   ; seconde actuelle
    colon   db  ':' ; caractère de séparation pour l'affichage

DSEG 		ENDS
;-----------------------------------------------------------------------
			ASSUME CS:CSEG, DS:CSEG, ES:CSEG
CSEG		SEGMENT  'Code'
MAIN	PROC FAR
; registre
		MOV	AX, DSEG
		MOV DS, AX		
    ; boucle infinie pour afficher l'heure en continu
    mov ah, 2Ch     ; initialiser le compteur d'intervalles
    int 21h         ; appeler l'interruption 21h avec AH=2Ch
    mov ah, 0       ; préparer l'appel de l'interruption 1Ah
    int 1Ah         ; récupérer l'heure, les minutes et les secondes
    mov hour, ch    ; sauvegarder l'heure
    mov minute, cl  ; sauvegarder les minutes
    mov second, dh  ; sauvegarder les secondes
    
;-------------------------Affichage INT 21-09
		MOV AH, 09H
		LEA DX, second + "$"			
		INT 21H
			
;fin du programme
		END MAIN
;fin du code du segment
CSEG	ENDS

;-------------------------------------------------------FIN DE PROGRAMME
