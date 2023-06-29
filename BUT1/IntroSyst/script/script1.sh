#!/bin/bash

read -p "Veuiller saisir " rep
case $rep in "FR" | "Francais" | "Français") echo "Bonjour";;
"Belges" | "BL") echo "Bonejoure";;
"English" | "Anglais") echo "Good day";;
esac






#!/bin/bash
k=0
for((y=0;y<12;y++));
do
    i=$y
    if [ $y -lt 10 ] 
    then
        i=$k$y
    fi
    echo $i
done