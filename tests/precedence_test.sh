#!/bin/sh
(echo a)
(ls)
(echo a && echo b)
(echo a && (echo b))
test -e testFile.cpp || (echo b)
(echo a && (echo b || (echo c)))
(echo a )
( echo a)
( echo a )
((((echo a))))
((((echo a && (echo b && echo c)))))