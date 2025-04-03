all: mcd

mcd: mcd_main.o
	g++ $^ -o $@

%.o: %.cc
	g++ -c $< -o $@

clean:
	rm -f *.o mcd