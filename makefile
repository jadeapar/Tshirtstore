tshirt_store2: readline.o tshirt.o tshirt_store2.o
	gcc -o tshirt_store2 readline.o tshirt.o tshirt_store2.o
tshirt_store2.o: tshirt_store2.c
	gcc -c tshirt_store2.c
readline.o: readline.c readline.h
	gcc -c readline.c
tshirt.o: tshirt.c tshirt.h
	gcc -c tshirt.c
clean:
	rm tshirt_store3 readline.o tshirt.o tshirt_store3.o

