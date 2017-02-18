all:
	mkdir -p ./bin
	g++ -Wall -Werror -ansi -pedantic ./src/main.cpp -o ./bin/rshell
rshell:
	g++ -Wall -Werror -ansi -pedantic ./src/main.cpp -o ./bin/rshell
