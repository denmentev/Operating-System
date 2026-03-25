COMP = gcc

# prog1: prog1.c
# 	$(COMP) -Wall -o prog1 prog1.c

# prog2: prog2.c
# 	$(COMP) -Wall -o prog2 prog2.c

# prog3: prog3.c
# 	$(COMP) -Wall -o prog3 prog3.c

# prog4a: prog4a.c prime.c
# 	$(COMP) -c prime.c -Wall
# 	$(COMP) -Wall -o prog4a prog4a.c prime.o -lm

prog6: prog6.c prime.c
	$(COMP) -c prime.c -Wall
	$(COMP) -Wall -o prog6 prog6.c prime.o

clean:
	rm -rf prog1
	rm -rf prog2
	rm -rf prog3
	rm -rf prime
	rm -rf prog4a
	rm -rf prime.o
	rm -rf prog5
	rm -rf prog6
