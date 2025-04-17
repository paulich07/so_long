#!/bin/bash
for i in ./maps/invalid/**/*.ber; 
do
echo -e "\n\e[93m$i: \e[:0m";
valgrind --quiet ./so_long "$i";
done; 