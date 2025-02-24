all: mcd

mcd: mcd_main.o mcd.o BigInteger.o BigUnsigned.o
	g++ $^ -o $@

%.o: %.cc
	g++ -c $< -o $@

clean:
	rm -f *.o mcd