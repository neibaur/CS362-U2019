CFLAGS= -Wall -fpic -coverage -lm -std=c99

unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c unittest5.c dominion.c rngs.c

	echo "unittest1results:" > unittestresults.out
	gcc -o unittest1 -g  unittest1.c dominion.c rngs.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
    
	echo "unittest2results:" >> unittestresults.out
	gcc -o unittest2 -g  unittest2.c dominion.c rngs.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
    
	echo "unittest3results:" >> unittestresults.out
	gcc -o unittest3 -g  unittest3.c dominion.c rngs.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
    
	echo "unittest4results:" >> unittestresults.out
	gcc -o unittest4 -g  unittest4.c dominion.c rngs.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
    
	echo "unittest5results:" >> unittestresults.out
	gcc -o unittest5 -g  unittest5.c dominion.c rngs.c $(CFLAGS)
	./unittest5 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest1results:" >> unittestresults.out
	gcc -o cardtest1 -g  cardtest1.c dominion.c rngs.c $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
    
	echo "cardtest2results:" >> unittestresults.out
	gcc -o cardtest2 -g  cardtest2.c dominion.c rngs.c $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
    
	echo "cardtest3results:" >> unittestresults.out
	gcc -o cardtest3 -g  cardtest3.c dominion.c rngs.c $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
    
	echo "cardtest4results:" >> unittestresults.out
	gcc -o cardtest4 -g  cardtest4.c dominion.c rngs.c $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
    
	echo "cardtest5results:" >> unittestresults.out
	gcc -o cardtest5 -g  cardtest5.c dominion.c rngs.c $(CFLAGS)
	./cardtest5 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

#	echo "testOutput:" >> unittestresults.out
#	gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.c rngs.c $(CFLAGS)
#	./testUpdateCoins >> unittestresults.out
#	gcov dominion.c >> unittestresults.out

#testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
#     gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)

#cardTestMinion: unittest2.c dominion.o rngs.o
#	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
    
#cardTestAmbassador: unittest3.c dominion.o rngs.o
#	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
    
#cardTestTribute: unittest4.c dominion.o rngs.o
#	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
    
#cardTestMine: unittest5.c dominion.o rngs.o
#	gcc -o unittest5 -g  unittest5.c dominion.o rngs.o $(CFLAGS)
    
#cardtest4: cardtest4.c dominion.o rngs.o
#	gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)    






    






#cardTestBaron: unittest1.c dominion.o rngs.o
#	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
    
#cardTestMinion: unittest2.c dominion.o rngs.o
#	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
    
#cardTestAmbassador: unittest3.c dominion.o rngs.o
#	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
    
#cardTestTribute: unittest4.c dominion.o rngs.o
#	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
    
#cardTestMine: unittest5.c dominion.o rngs.o
#	gcc -o unittest5 -g  unittest5.c dominion.o rngs.o $(CFLAGS)
    
#cardtest4: cardtest4.c dominion.o rngs.o
#	gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)


    




    






rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
