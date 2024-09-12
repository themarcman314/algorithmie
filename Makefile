all : src/liste.c
	gcc src/liste.c -o bin/liste
	bin/liste
