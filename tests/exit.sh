#!/bin/sh
exit
echo a; exit
ls && exit
mkdir test; touch s; exit
touch a && echo b && exit #this should exit