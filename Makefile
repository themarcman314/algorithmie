all: bin/liste run

bin/liste: src/liste.c | bin
	gcc src/liste.c -o bin/liste

bin:
	mkdir -p bin

run: bin/liste
	./bin/liste

clean:
	rm -rf bin/liste

