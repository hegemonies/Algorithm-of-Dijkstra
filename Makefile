bin/main: build/main.o build/dijkstra.o build/heap.o build/graph.o
	gcc -Wall -Werror -I src build/main.o build/dijkstra.o build/heap.o build/graph.o -o bin/main

build/main.o: src/main.c src/dijkstra.c src/graph.c src/heap.c
	gcc -Wall -Werror -I src -c src/main.c -o build/main.o

build/dijkstra.o: src/dijkstra.c src/graph.c src/heap.c
	gcc -Wall -Werror -I src -c src/dijkstra.c -o build/dijkstra.o

build/heap.o: src/heap.c
	gcc -Wall -Werror -I src -c src/heap.c -o build/heap.o

build/graph.o: src/graph.c
	gcc -Wall -Werror -I src -c src/graph.c -o build/graph.o

.PHONY: clean

clean:
	rm bin/* build/*