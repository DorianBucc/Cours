;-----------------------------------------------------------------------
; 	ecrire un message a l'ecran
;-----------------------------------------------------------------------
			TITLE			DISPLAY - programme prototype
;-----------------------------------------------------------------------
			ASSUME CS:CSEG, DS:CSEG, ES:CSEG
CSEG		SEGMENT

			ORG 100H
MAIN:		MOV BX, 0001H
			LEA DX, MESSAGE
			MOV CX, L_MESSAGE
			MOV AH, 40H
			INT 21H
			MOV AH, 4CH
			INT 21H
MESSAGE		DB "bonjour, voici un message !", 0DH, 0AH
L_MESSAGE	EQU $-MESSAGE

CSEG		ENDS
			END MAIN
;-------------------------------------------------------FIN DE PROGRAMME
			



