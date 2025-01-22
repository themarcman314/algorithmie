all: bin/dungeon run

bin/dungeon: src/main.c | bin
	gcc src/main.c -o bin/dungeon

bin:
	mkdir -p bin

run: bin/dungeon
	./bin/dungeon

clean:
	rm -rf bin/dungeon

