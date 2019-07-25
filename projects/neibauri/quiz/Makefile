CFLAGS= -Wall -fpic -coverage -lm -std=c99

Quiz: testme.c

	echo "testmeresults:" > unittestresults.out
	gcc -o testme -g  testme.c $(CFLAGS)
	./testme >> unittestresults.out
	gcov testme.c >> unittestresults.out
    
clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out