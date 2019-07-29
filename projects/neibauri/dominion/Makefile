CFLAGS= -Wall -fpic -coverage -lm -std=c99

randomtestresults: randomtestcard1.c randomtestcard2.c randomtestcard3.c dominion.c rngs.c

	echo "randomtestcard1_results:" > randomtestresults.out
	gcc -fprofile-arcs -ftest-coverage -o randomtestcard1 -g  randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard1 >> randomtestresults.out
	gcov -f -b -c dominion.c >> randomtestresults.out
    
	echo "randomtestcard2_results:" >> randomtestresults.out
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard2 >> randomtestresults.out
	gcov  -f -b -c dominion.c >> randomtestresults.out
    
	echo "randomtestcard3_results:" >> randomtestresults.out
	gcc -o randomtestcard3 -g  randomtestcard3.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard3 >> randomtestresults.out
	gcov  -f -b -c dominion.c >> randomtestresults.out

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out
