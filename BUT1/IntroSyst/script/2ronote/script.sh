#!/bin/sh

echo "$(pwd)"
if [ -d bucchiotty$(date +%d%m%y) ] ; then
	echo "Le répertoire existe déjà"
else
	rep="bucchiotty$(date +%d%m%y)"
	mkdir $rep
	cd  $rep
	echo "Le répertoire a été créé"	
fi
cd bucchiotty$(date +%d%m%y)
if [ -e $(date +%d%m%y) ] ; then
 echo "Le fichier existe et c'est droit sont $(ls -og | grep -w $(date +%d%m%y))"
else
	touch $(date +%d%m%y)
fi









pwd
cd Image/SAE
cd base
cp access.log accesss.log
cd ..
