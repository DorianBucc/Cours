;addition de deux nombres
;-----------------------------------------------------------------------
			ASSUME CS:CSEG, DS:CSEG, ES:CSEG
CSEG		SEGMENT
			ORG 100H
MAIN:		MOV AL, NOMBRE1
			MOV AH, 0
			ADD AL, NOMBRE2
			MOV RESULTAT, AL
			ADC AH, 0
			MOV RESULTAT+1, AH
			MOV AH, 4CH
			INT 21H
NOMBRE1		db 8dh
NOMBRE2 	db 0A2H
RESULTAT 	db 2 DUP (?)
CSEG 		ENDS
			END MAIN
;-----------------------------------------------------------------------
