CFLAGS= -Wall -fpic -coverage -lm -std=c99

unittestresults: unittest1.c unittest2.c unittest4.c randomtestcard1.c randomtestcard2.c randomtestcard3.c dominion.c rngs.c

#Baron - Unit Test
	echo "unittest1results:" > unittest1results.out
	gcc -o unittest1 -g  unittest1.c dominion.c rngs.c $(CFLAGS)
	./unittest1 >> unittest1results.out
	gcov -f -b -c dominion.c >> unittest1results.out
    
#Minion - Unit Test
	echo "unittest2results:" >> unittest2results.out
	gcc -o unittest2 -g  unittest2.c dominion.c rngs.c $(CFLAGS)
	./unittest2 >> unittest2results.out
	gcov -f -b -c dominion.c >> unittest2results.out

#Tribute - Unit Test
	echo "unittest4results:" >> unittest4results.out
	gcc -o unittest4 -g  unittest4.c dominion.c rngs.c $(CFLAGS)
	./unittest4 >> unittest4results.out
	gcov -f -b -c dominion.c >> unittest4results.out

#Baron - Random Test
	echo "randomtestcard1_results:" > randomtest1results.out
	gcc -fprofile-arcs -ftest-coverage -o randomtestcard1 -g  randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard1 >> randomtest1results.out
	gcov -f -b -c dominion.c >> randomtest1results.out

#Minion - Random Test
	echo "randomtestcard2_results:" >> randomtest2results.out
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard2 >> randomtest2results.out
	gcov  -f -b -c dominion.c >> randomtest2results.out

#Tribute - Random Test
	echo "randomtestcard3_results:" >> randomtest3results.out
	gcc -o randomtestcard3 -g  randomtestcard3.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard3 >> randomtest3results.out
	gcov  -f -b -c dominion.c >> randomtest3results.out

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out