/*
 * cardtest4.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "tribute"

// compares two integers and returns 1 if true.  testCounter is not used, included as a place to incement the counter only. 
int assertrue(int originalState, int newState, char testName[], int testCounter){
    if (originalState == newState)
    {
        printf("Test Pass: %s Count\n", testName);
        return 1;
    }
    else 
    {   
        printf("Test Fail: %s Count\n", testName);
        return 0;
    }
}

int main() {
    int passCounter = 0; // tallies test results
    int testCounter = 0;
    
    int testState = 0;  //used to pass values to functions and make code more readable
    int compareState = 0;

    int discarded = 1;  // state of normal hand
    int newCards = 0;   
    int xtraCoins = 0;
    int shuffledCards = 0;
    int numBuys = 0;
    int numActions = 0;

//    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
//    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = other player +2 discarded, current player +2 Actions --------------
	printf("TEST 1: choice1 = 1 = other player +2 discarded, current player +2 Actions\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(tribute, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    numActions = 2;
    
    testState = testG.handCount[thisPlayer];                                        //Failed
    compareState = G.handCount[thisPlayer] + newCards - discarded;  
	printf("hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[thisPlayer];
    compareState = G.deckCount[thisPlayer] - newCards + shuffledCards;  
	printf("\ndeck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);

    testState = testG.coins;                                                        //Passed but seems off
    compareState = G.coins + xtraCoins;  
	printf("\ncoins = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Coins", testCounter++);
    
    testState = testG.numBuys;                                                      //Failed
    compareState = G.numBuys + numBuys;     
    printf("\nbuys = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numBuys", testCounter++); 
    
    testState = testG.numActions;                                                      //Failed
    compareState = G.numActions + numActions;     
    printf("\nnumActions = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numActions", testCounter++); 
    
    printf("\nPass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1;
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
    discarded = 2; // tribute action on other player
    
    testState = testG.handCount[otherPlayer];                                        //Failed
    compareState = G.handCount[otherPlayer] + newCards - discarded; 
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 0; // setting for Other Player
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
	printf("Other Player: hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[otherPlayer];
    compareState = G.deckCount[otherPlayer] - newCards + shuffledCards;  
	printf("\nOther Player: deck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);
    
    printf("\nOther Player: Pass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1; 
    newCards = xtraCoins = shuffledCards = numBuys = 0;

	// ----------- TEST 2: choice1 = 1 = other player +2 discarded, current player +2 Treasure Card --------------
	printf("TEST 2: choice1 = 1 = other player +2 discarded, current player +2 Treasure Card\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(tribute, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    xtraCoins = 2; // test
    
    testState = testG.handCount[thisPlayer];                                        //Failed
    compareState = G.handCount[thisPlayer] + newCards - discarded;  
	printf("hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[thisPlayer];
    compareState = G.deckCount[thisPlayer] - newCards + shuffledCards;  
	printf("\ndeck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);

    testState = testG.coins;                                                        //Passed but seems off
    compareState = G.coins + xtraCoins;  
	printf("\ncoins = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Coins", testCounter++);
    
    testState = testG.numBuys;                                                      //Failed
    compareState = G.numBuys + numBuys;     
    printf("\nbuys = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numBuys", testCounter++); 
    
    testState = testG.numActions;                                                      //Failed
    compareState = G.numActions + numActions;     
    printf("\nnumActions = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numActions", testCounter++); 
    
    printf("\nPass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1;
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
    discarded = 2; // tribute action on other player
    
    testState = testG.handCount[otherPlayer];                                        //Failed
    compareState = G.handCount[otherPlayer] + newCards - discarded; 
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 0; // setting for Other Player
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
	printf("Other Player: hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[otherPlayer];
    compareState = G.deckCount[otherPlayer] - newCards + shuffledCards;  
	printf("\nOther Player: deck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);
    
    printf("\nOther Player: Pass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1; 
    newCards = xtraCoins = shuffledCards = numBuys = 0;

    	// ----------- TEST 3: choice1 = 1 = other player +2 discarded, current player +2 Cards --------------
	printf("TEST 3: choice1 = 1 = other player +2 discarded, current player +2 Cards\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(tribute, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    newCards = 2; // test
    
    testState = testG.handCount[thisPlayer];                                        //Failed
    compareState = G.handCount[thisPlayer] + newCards - discarded;  
	printf("hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[thisPlayer];
    compareState = G.deckCount[thisPlayer] - newCards + shuffledCards;  
	printf("\ndeck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);

    testState = testG.coins;                                                        //Passed but seems off
    compareState = G.coins + xtraCoins;  
	printf("\ncoins = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Coins", testCounter++);
    
    testState = testG.numBuys;                                                      //Failed
    compareState = G.numBuys + numBuys;     
    printf("\nbuys = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numBuys", testCounter++); 
    
    testState = testG.numActions;                                                      //Failed
    compareState = G.numActions + numActions;     
    printf("\nnumActions = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numActions", testCounter++); 
    
    printf("\nPass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1;
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
    discarded = 2; // tribute action on other player
    
    testState = testG.handCount[otherPlayer];                                        //Failed
    compareState = G.handCount[otherPlayer] + newCards - discarded; 
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 0; // setting for Other Player
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
	printf("Other Player: hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[otherPlayer];
    compareState = G.deckCount[otherPlayer] - newCards + shuffledCards;  
	printf("\nOther Player: deck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);
    
    printf("\nOther Player: Pass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1; 
    newCards = xtraCoins = shuffledCards = numBuys = 0;

    
	// ----------- TEST 4: choice1 = 1 = other player +2 discarded, current player +2 Actions and +2 Coins --------------
	printf("TEST 4: choice1 = 1 = other player +2 discarded, current player +2 Actions and + 2 Coins \n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(tribute, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    numActions = 2; // test
    xtraCoins = 2;
    
    testState = testG.handCount[thisPlayer];                                        //Failed
    compareState = G.handCount[thisPlayer] + newCards - discarded;  
	printf("hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[thisPlayer];
    compareState = G.deckCount[thisPlayer] - newCards + shuffledCards;  
	printf("\ndeck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);

    testState = testG.coins;                                                        //Passed but seems off
    compareState = G.coins + xtraCoins;  
	printf("\ncoins = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Coins", testCounter++);
    
    testState = testG.numBuys;                                                      //Failed
    compareState = G.numBuys + numBuys;     
    printf("\nbuys = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numBuys", testCounter++); 
    
    testState = testG.numActions;                                                      //Failed
    compareState = G.numActions + numActions;     
    printf("\nnumActions = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numActions", testCounter++); 
    
    printf("\nPass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1;
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
    discarded = 2; // tribute action on other player
    
    testState = testG.handCount[otherPlayer];                                        //Failed
    compareState = G.handCount[otherPlayer] + newCards - discarded; 
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 0; // setting for Other Player
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
	printf("Other Player: hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[otherPlayer];
    compareState = G.deckCount[otherPlayer] - newCards + shuffledCards;  
	printf("\nOther Player: deck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);
    
    printf("\nOther Player: Pass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1; 
    newCards = xtraCoins = shuffledCards = numBuys = 0;

    
	// ----------- TEST 5: choice1 = 1 = other player +2 discarded, current player +2 Actions + 2 Coins --------------
	printf("TEST 5: choice1 = 1 = other player +2 discarded, current player +2 Actions and + 2 Cards\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(tribute, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    numActions = 2; // test
    newCards = 2;
    
    testState = testG.handCount[thisPlayer];                                        //Failed
    compareState = G.handCount[thisPlayer] + newCards - discarded;  
	printf("hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[thisPlayer];
    compareState = G.deckCount[thisPlayer] - newCards + shuffledCards;  
	printf("\ndeck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);

    testState = testG.coins;                                                        //Passed but seems off
    compareState = G.coins + xtraCoins;  
	printf("\ncoins = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Coins", testCounter++);
    
    testState = testG.numBuys;                                                      //Failed
    compareState = G.numBuys + numBuys;     
    printf("\nbuys = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numBuys", testCounter++); 
    
    testState = testG.numActions;                                                      //Failed
    compareState = G.numActions + numActions;     
    printf("\nnumActions = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numActions", testCounter++); 
    
    printf("\nPass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1;
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
    discarded = 2; // tribute action on other player
    
    testState = testG.handCount[otherPlayer];                                        //Failed
    compareState = G.handCount[otherPlayer] + newCards - discarded; 
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 0; // setting for Other Player
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
	printf("Other Player: hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[otherPlayer];
    compareState = G.deckCount[otherPlayer] - newCards + shuffledCards;  
	printf("\nOther Player: deck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);
    
    printf("\nOther Player: Pass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1; 
    newCards = xtraCoins = shuffledCards = numBuys = 0;

    
	// ----------- TEST 6: choice1 = 1 = other player +2 discarded, current player +2 Coins and +2 Cards --------------
	printf("TEST 6: choice1 = 1 = other player +2 discarded, current player +2 Coins and +2 Cards\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(tribute, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    xtraCoins = 2; // test
    newCards = 2;
    
    testState = testG.handCount[thisPlayer];                                        //Failed
    compareState = G.handCount[thisPlayer] + newCards - discarded;  
	printf("hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[thisPlayer];
    compareState = G.deckCount[thisPlayer] - newCards + shuffledCards;  
	printf("\ndeck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);

    testState = testG.coins;                                                        //Passed but seems off
    compareState = G.coins + xtraCoins;  
	printf("\ncoins = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Coins", testCounter++);
    
    testState = testG.numBuys;                                                      //Failed
    compareState = G.numBuys + numBuys;     
    printf("\nbuys = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numBuys", testCounter++); 
    
    testState = testG.numActions;                                                      //Failed
    compareState = G.numActions + numActions;     
    printf("\nnumActions = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numActions", testCounter++); 
    
    printf("\nPass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1;
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
    discarded = 2; // tribute action on other player
    
    testState = testG.handCount[otherPlayer];                                        //Failed
    compareState = G.handCount[otherPlayer] + newCards - discarded; 
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 0; // setting for Other Player
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
	printf("Other Player: hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[otherPlayer];
    compareState = G.deckCount[otherPlayer] - newCards + shuffledCards;  
	printf("\nOther Player: deck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);
    
    printf("\nOther Player: Pass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1; 
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
    
	// ----------- TEST 1: choice1 = 1 = other player +2 discarded, current player +2 Actions --------------
	printf("TEST 1: choice1 = 1 = other player +2 discarded, current player +2 Actions\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(tribute, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    numActions = 2;
    
    testState = testG.handCount[thisPlayer];                                        //Failed
    compareState = G.handCount[thisPlayer] + newCards - discarded;  
	printf("hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[thisPlayer];
    compareState = G.deckCount[thisPlayer] - newCards + shuffledCards;  
	printf("\ndeck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);

    testState = testG.coins;                                                        //Passed but seems off
    compareState = G.coins + xtraCoins;  
	printf("\ncoins = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Coins", testCounter++);
    
    testState = testG.numBuys;                                                      //Failed
    compareState = G.numBuys + numBuys;     
    printf("\nbuys = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numBuys", testCounter++); 
    
    testState = testG.numActions;                                                      //Failed
    compareState = G.numActions + numActions;     
    printf("\nnumActions = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "numActions", testCounter++); 
    
    printf("\nPass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1;
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
    discarded = 2; // tribute action on other player
    
    testState = testG.handCount[otherPlayer];                                        //Failed
    compareState = G.handCount[otherPlayer] + newCards - discarded; 
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 0; // setting for Other Player
    newCards = xtraCoins = shuffledCards = numBuys = 0;
    
	printf("Other Player: hand count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Hand", testCounter++);    

    testState = testG.deckCount[otherPlayer];
    compareState = G.deckCount[otherPlayer] - newCards + shuffledCards;  
	printf("\nOther Player: deck count = %d, expected = %d\n", testState, compareState);
    passCounter = passCounter + assertrue(testState, compareState, "Deck", testCounter++);
    
    printf("\nOther Player: Pass Tests = %d, Total Tests = %d\n\n", passCounter, testCounter);
    
    // resetting for next test
    passCounter = testCounter = 0;
    discarded = 1; 
    newCards = xtraCoins = shuffledCards = numBuys = 0;

//	// ----------- TEST 3: choice1 = 3 = trash two cards --------------
//
//	printf("TEST 3: choice1 = 3 = trash two cards\n");
//	choice1 = 3;
//
//	// cycle through each eligible combination of 2 cards to trash
//	for (i=1; i<G.handCount[thisPlayer]; i++) {
//		for (j=i+1; j<G.handCount[thisPlayer]; j++) {
//
//			G.hand[thisPlayer][0] = tribute;
//			G.hand[thisPlayer][1] = copper;
//			G.hand[thisPlayer][2] = duchy;
//			G.hand[thisPlayer][3] = estate;
//			G.hand[thisPlayer][4] = feast;
//
//			// copy the game state to a test case
//			memcpy(&testG, &G, sizeof(struct gameState));
//
//			printf("starting cards: ");
//			for (m=0; m<testG.handCount[thisPlayer]; m++) {
//				printf("(%d)", testG.hand[thisPlayer][m]);
//			}
//			printf("; ");
//
//			choice2 = j;
//			choice3 = i;
//			remove1 = testG.hand[thisPlayer][i];
//			remove2 = testG.hand[thisPlayer][j];
//			cardEffect(tribute, choice1, choice2, choice3, &testG, handpos, &bonus);
//
//			printf("removed: (%d)(%d); ", remove1, remove2);
//			printf("ending cards: ");
//
//			// tests that the removed cards are no longer in the player's hand
//			for (m=0; m<testG.handCount[thisPlayer]; m++) {
//				printf("(%d)", testG.hand[thisPlayer][m]);
//				assert(testG.hand[thisPlayer][m] != remove1);
//				assert(testG.hand[thisPlayer][m] != remove2);
//			}
//			printf(", expected: ");
//			for (m=1; m<G.handCount[thisPlayer]; m++) {
//				if (G.hand[thisPlayer][m] != G.hand[thisPlayer][i] && G.hand[thisPlayer][m] != G.hand[thisPlayer][j]) {
//					printf("(%d)", G.hand[thisPlayer][m]);
//				}
//			}
//			printf("\n");
//
//			// tests for the appropriate number of remaining cards
//			newCards = 0;
//			xtraCoins = 0;
//			discarded = 3;
//			if (i==1 && j==2) {
//				printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
//				printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
//			}
//			assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
//			assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
//		}
//
//	}

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}

