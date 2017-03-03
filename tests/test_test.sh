#!/bin/sh
test -e testFile.cpp
test -d testFile.cpp
test -f testFile.cpp
test testFile.cpp
[ -e testFile.cpp ]
[ -d testFile.cpp ]
[ -f testFile.cpp ]
[ testFile.cpp ]
test -e testDir
test -d testDir
test -f testDir
test testDir
[ -e testDir ]
[ -d testDir ]
[ -f testDir ]
[ testDir ]
[ testFile.cpp ] && echo a
test -e testFile.cpp && echo a