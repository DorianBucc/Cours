
;-----------------------------------------------------------------------
; 	ecrire un message a l'ecran
;-----------------------------------------------------------------------
			TITLE			DISPLAY - programme prototype
;-----------------------------------------------------------------------
			ASSUME CS:CSEG, DS:CSEG, ES:CSEG
CSEG		SEGMENT  'Code'

			ORG 100H
MAIN:		
; ---------------------------Affichage INT 21-40
			MOV BX, 0001H			
			MOV AH, 40H	
			LEA DX, MESSAGE
			MOV CX, _MESSAGE
			INT 21H
  

;--------------------------Lecture clavier INT 21-3FH
			MOV AH, 3FH
			LEA DX, RETOUR
			MOV CX, 6
			INT 21H
;----------------Retour chariot/ligne
			MOV AH, 2
			MOV DL, 0DH
			INT 21H
			MOV DL, 0AH
			INT 21H
			
;-------------------------Affichage INT 21-09
			MOV AH, 09H
			LEA DX, RETOUR			
			INT 21H
;---------------------Fin de programme INT 21-4C
			MOV AH, 4CH
			INT 21H


;**************zone de variables
RETOUR 		DB 80 dup ("$")
MESSAGE		DB "Veuiller saisir une chaine de caracteres", 0DH, 0AH
_MESSAGE	EQU $-MESSAGE

CSEG		ENDS
			END MAIN
;-------------------------------------------------------FIN DE PROGRAMME
