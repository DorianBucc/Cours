#!/bin/bash

max=$(find *img | wc -l)

for((i=1;i<$max;i++));
do
    cp $(find *img | head -n $i | tail -n 1) $(find *img | head -n $i | tail -n 1 | cut -d '.' -f1)_$(whoami).img

done
