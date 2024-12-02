all: bin/liste run

bin/liste: src/arbre.c | bin
	gcc src/arbre.c -o bin/arbre

bin:
	mkdir -p bin

run: bin/arbre
	./bin/arbre

clean:
	rm -rf bin/arbre

