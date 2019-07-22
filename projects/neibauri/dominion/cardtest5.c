/*
 * cardtest5.c
 */

/*
 * Include the following lines in your makefile:
 *
 * CFLAGS= -Wall -fpic -coverage -lm -std=c99
 *
 * cardTest: cardtest5.c dominion.o rngs.o
 *	 gcc -o cardtest5 -g  cardtest5.c dominion.o rngs.o $(CFLAGS)
 */

//Original code provided in CS362 Module 3 from testUpdateCoins.c
// modified for HW3
// Author Isaac Neibaur 
// 7/14/2019

//#include "dominion.h"
//#include "dominion_helpers.h"
//#include <string.h>
//#include <stdio.h>
//#include <assert.h>
//#include "rngs.h"
//
//// set NOISY_TEST to 0 to remove printfs from output
//#define NOISY_TEST 1
//
//int main() {
//    int i;
//    int seed = 1000;
//    int numPlayer = 2;
//    int maxBonus = 10;
//    int p, r, handCount;
//    int bonus;
//    int k[10] = {adventurer, council_room, feast, gardens, mine
//               , remodel, smithy, village, baron, great_hall};
//    struct gameState G;
//    int maxHandCount = 5;
//    // arrays of all coppers, silvers, and golds
//    int coppers[MAX_HAND];
//    int silvers[MAX_HAND];
//    int golds[MAX_HAND];
//    for (i = 0; i < MAX_HAND; i++)
//    {
//        coppers[i] = copper;
//        silvers[i] = silver;
//        golds[i] = gold;
//    }
//
//    printf ("TESTING drawCard():\n");
//    for (p = 0; p < numPlayer; p++)
//    {
//        for (handCount = 1; handCount <= maxHandCount; handCount++)
//        {
//            for (bonus = 0; bonus <= maxBonus; bonus++)
//            {
//#if (NOISY_TEST == 1)
//                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
//#endif
//                memset(&G, 23, sizeof(struct gameState));   // clear the game state
//                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
//                G.handCount[p] = handCount;                 // set the number of cards on hand
//                memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
//                updateCoins(p, &G, bonus);
//#if (NOISY_TEST == 1)
//                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
//#endif
//                assert(G.coins == handCount * 1 + bonus); // check if the number of coins is correct
//
//                memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silver
//                updateCoins(p, &G, bonus);
//#if (NOISY_TEST == 1)
//                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
//#endif
//                assert(G.coins == handCount * 2 + bonus); // check if the number of coins is correct
//
//                memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
//                updateCoins(p, &G, bonus);
//#if (NOISY_TEST == 1)
//                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
//#endif
//                assert(G.coins == handCount * 3 + bonus); // check if the number of coins is correct
//            }
//        }
//    }
//
//    printf("All tests passed!\n");
//
//    return 0;
//}

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkDrawCard(int p, struct gameState *post) {
  int r;
    
  r = drawCard (p, post);

  assert (r == 0);
}

int main () {

  int i, n, r, p, deckCount, discardCount, handCount;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing drawCard.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    checkDrawCard(p, &G);
  }

  printf ("ALL TESTS OK\n");

  exit(0);

  printf ("SIMPLE FIXED TESTS.\n");
  for (p = 0; p < 2; p++) {
    for (deckCount = 0; deckCount < 5; deckCount++) {
      for (discardCount = 0; discardCount < 5; discardCount++) {
	for (handCount = 0; handCount < 5; handCount++) {
	  memset(&G, 23, sizeof(struct gameState)); 
	  r = initializeGame(2, k, 1, &G);
	  G.deckCount[p] = deckCount;
	  memset(G.deck[p], 0, sizeof(int) * deckCount);
	  G.discardCount[p] = discardCount;
	  memset(G.discard[p], 0, sizeof(int) * discardCount);
	  G.handCount[p] = handCount;
	  memset(G.hand[p], 0, sizeof(int) * handCount);
	  checkDrawCard(p, &G);
	}
      }
    }
  }

  return 0;
}
