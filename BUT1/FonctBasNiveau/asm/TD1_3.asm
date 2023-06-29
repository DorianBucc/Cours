;-----------------------------------------------------------------------
; 	ecrire un message a l'ecran
;-----------------------------------------------------------------------
			TITLE			DISPLAY - programme prototype
			.286
;----------------------------------------------------------STACK segment
SSEG 		SEGMENT		STACK
			DB			32 DUP("STACK---")
SSEG 		ENDS
;-----------------------------------------------------------DATA segment
DSEG 		SEGMENT
MESSAGE		DB		"Bonjour, voici un message !", 0DH, 0AH
L_MESSAGE	EQU		$-MESSAGE
DSEG 		ENDS
;-----------------------------------------------------------CODE segment
CSEG	SEGMENT		'CODE'
ASSUME	CS:CSEG, SS:SSEG, DS:DSEG
;-----------------------------------------------------------------------
;	procedure MAIN
MAIN	PROC FAR
; sauver l'adresse de retour
		PUSH DS
		PUSH 0
; registre
		MOV	AX, DSEG
		MOV DS, AX
; message
		MOV BX, 0001H
		LEA DX, MESSAGE
		MOV CX, L_MESSAGE
		MOV AH, 40H
		INT 21H
;retour
		RET
;fin de la procedure MAIN
		MAIN ENDP
;fin du code du segment
CSEG	ENDS
;fin du programme
		END MAIN
;-------------------------------------------------------FIN DE PROGRAMME
