CFLAGS= -Wall -fpic -coverage -lm -std=c99

Quiz: testme.c

	echo "testmeresults:" > unittestresults.out
	gcc -o testme -g  testme.c $(CFLAGS)
	./testme >> unittestresults.out
	gcov testme.c >> unittestresults.out

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
