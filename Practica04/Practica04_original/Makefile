all: hash

hash: main-hash.o Nif.cc
	g++ $^ -o $@

%.o: %.cc
	g++ -c $< -o $@

clean:
	rm -f *.o mcd