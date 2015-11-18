//
//  BlackJack.c
//  Card Games
//
//  Created by MATTHEW S WOJNO on 10/11/14.
//  Copyright (c) 2014 Matthew Wojno. All rights reserved.
//

#include "BlackJack.h"
#include "Functions.h"
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#include <math.h>


int deck[52];
int userDeck[10];
int compDeck[10];
int userTotal =0;
int compTotal =0;
int countUserDeck = 1;
int countDeck = 3;
int compScore = 0;
int userScore = 0;

        
void initialize(){
    shuffle(deck);
    
    
    //printf("\n\n Rules: Regular black jack rules apply. Object is to get 21. You will be playing against the computer (dealer).");
    
    userDeck[0] = deck[0];
    userDeck[1] = deck[1];
    compDeck[0] = deck[2];
    compDeck[1] = deck[3];
    
    printf("\n\nYour Hand is: ");
    
    for(int b = 0; b<2; b++){
        
        if( userDeck[b] >1 && userDeck[b] < 10){
            printf("\n%d of Diamonds", userDeck[b]);
            userTotal += userDeck[b];
        }
        if(userDeck[b] == 1){
            printf("\nAce of Diamonds");
            userTotal += 11;
        }
        if(userDeck[b] == 11){
            printf("\nJack of Diamonds");
            userTotal += 10;
        }
        if(userDeck[b] == 12){
            printf("\nQueen of Diamonds");
            userTotal += 10;
        }
        if(userDeck[b] == 13){
            printf("\nKing of Diamonds");
            userTotal += 10;
        }
        if(userDeck[b] >13 && userDeck[b] <24){
            if(userDeck[b] == 23){
                printf("\n9 of Hearts");
                userTotal += 9;
            }else{
            printf("\n%d of Hearts", (userDeck[b] - 14)+1);
            userTotal += userDeck[b] - 14+1;
            }
        }
        if(userDeck[b] == 14){
            printf("\nAce of Hearts");
            userTotal += 11;
        }
        if(userDeck[b] == 24){
            printf("\nJack of Hearts");
            userTotal += 10;
        }
        if(userDeck[b] == 25){
            printf("\nQueen of Hearts");
            userTotal += 10;
        }
        if(userDeck[b] == 26){
            printf("\nKing of Hearts");
            userTotal += 10;
        }
        if(userDeck[b] > 27 && userDeck[b] <37){
            if(userDeck[b] == 36){
                printf("\n9 of Clubs");
                userTotal+= 9;
            }else{
                printf("\n%d of Clubs", (userDeck[b]-27) +1);
                userTotal += userDeck[b]-27+1;
            }
        }
        if(userDeck[b] == 27){
            printf("\nAce of Clubs");
            userTotal += 11;
        }
        if(userDeck[b] == 37){
            printf("\nJack of Clubs");
            userTotal += 10;
        }
        if(userDeck[b] == 38){
            printf("\nQueen of Clubs");
            userTotal += 10;
        }
        if(userDeck[b] == 39){
            printf("\nKing of Clubs");
            userTotal += 10;
        }
        if(userDeck[b]>40 && userDeck[b]<50){
            if(userDeck[b] == 49){
                printf("\n9 of Spades");
                userTotal +=9;
            }else{
                printf("\n%d of Spades", (userDeck[b]-40) +1);
                userTotal += userDeck[b]-40+1;
            }

        }
        if(userDeck[b] == 40){
            printf("\nAce of Spades");
            userTotal += 11;
        }
        if(userDeck[b] == 50){
            printf("\nJack of Spades");
            userTotal += 10;
        }
        if(userDeck[b] == 51){
            printf("\nQueen of Spades");
            userTotal += 10;
        }
        if(userDeck[b] == 52){
            printf("\nKing of Spades");
            userTotal += 10;
        }
        
    
    }
    
    printf("\nYour total: %d", userTotal);
    
    
    for(int g = 0; g<2; g++){
        
        if( compDeck[g] >1 && compDeck[g] < 10){
           compTotal += compDeck[g];
        }
        if(compDeck[g] == 1){
            compTotal += 11;
        }
        if(compDeck[g] == 11){
           compTotal += 10;
        }
        if(compDeck[g] == 12){
            compTotal += 10;
        }
        if(compDeck[g] == 13){
            compTotal += 10;
        }
        if(compDeck[g] >13 && compDeck[g] <24){
            if(compDeck[g] == 23){
                compTotal += 9;
            }else{
            compTotal += compDeck[g]-14+1;
            }
        }
        if(compDeck[g] == 14){
            compTotal += 11;
        }
        if(compDeck[g] == 24){
            compTotal += 10;
        }
        if(compDeck[g] == 25){
            compTotal += 10;
        }
        if(compDeck[g] == 26){
            compTotal += 10;
        }
        if(compDeck[g] > 27 && compDeck[g] <37){
            if(compDeck[g] == 36){
                compTotal+= 9;
            }else{
            compTotal += compDeck[g]-27+1;
            }
        }
        if(compDeck[g] == 27){
            compTotal += 11;
        }
        if(compDeck[g] == 37){
            compTotal += 10;
        }
        if(compDeck[g] == 38){
            compTotal += 10;
        }
        if(compDeck[g] == 39){
            compTotal += 10;
        }
        if(compDeck[g]>40 && compDeck[g]<50){
            if(compDeck[g] == 49){
            compTotal +=9;
            }else{
            compTotal += compDeck[g]-40+1;
            }
        }
        if(compDeck[g] == 40){
            compTotal += 11;
        }
        if(compDeck[g] == 50){
            compTotal += 10;
        }
        if(compDeck[g] == 51){
            compTotal += 10;
        }
        if(compDeck[g] == 52){
            compTotal += 10;
        }
        
        
    }
    
}

void playBlackJack(){
    if(compTotal < 16){
        addCompCard();
    }
    
    char check;
    char nothing;
    char nothing1;
    char play;
    while(userTotal <=21){
       
    
    printf("\n\nWould you like to stay or hit:");
    printf("\n Hit- 'h'");
    nothing = getchar();
    printf("\n Stay- 's'");
    check = getchar();
    
    
    if(check == 'h'){
        
        addCard();
    }
    
    
        if(check == 's'){
            checkWhenNo();
            break;
    
        }
    
    }
    
    nothing1 = getchar();
    printf("\n\n If you would like to play again enter a 'y'. If not enter a 'n'");
    play = getchar();
    
    if(play == 'y'){
         userTotal =0;
         compTotal =0;
        playAgain();
    }
    
}



void addCard(){
    
    userDeck[countUserDeck] = deck[countDeck];
    
    
    
        
        if(  userDeck[countUserDeck] >1 &&  userDeck[countUserDeck] < 10){
            printf("\n%d of Diamonds",  userDeck[countUserDeck]);
            userTotal +=  userDeck[countUserDeck];
        }
        if( userDeck[countUserDeck] == 1){
            printf("\nAce of Diamonds");
            userTotal += 11;
        }
        if( userDeck[countUserDeck] == 11){
            printf("\nJack of Diamonds");
            userTotal += 10;
        }
        if( userDeck[countUserDeck] == 12){
            printf("\nQueen of Diamonds");
            userTotal += 10;
        }
        if( userDeck[countUserDeck] == 13){
            printf("\nKing of Diamonds");
            userTotal += 10;
        }
        if( userDeck[countUserDeck] >13 &&  userDeck[countUserDeck] <24){
            if( userDeck[countUserDeck] == 23){
                printf("\n9 of Hearts");
                userTotal += 9;
            }else{
                printf("\n%d of Hearts", ( userDeck[countUserDeck] - 14)+1);
                userTotal +=  userDeck[countUserDeck] - 14+1;
            }
        }
        if( userDeck[countUserDeck] == 14){
            printf("\nAce of Hearts");
            userTotal += 11;
        }
        if( userDeck[countUserDeck] == 24){
            printf("\nJack of Hearts");
            userTotal += 10;
        }
        if( userDeck[countUserDeck]== 25){
            printf("\nQueen of Hearts");
            userTotal += 10;
        }
        if( userDeck[countUserDeck] == 26){
            printf("\nKing of Hearts");
            userTotal += 10;
        }
        if( userDeck[countUserDeck] > 27 &&  userDeck[countUserDeck] <37){
            if( userDeck[countUserDeck] == 36){
                printf("\n9 of Clubs");
                userTotal+= 9;
            }else{
                printf("\n%d of Clubs", ( userDeck[countUserDeck]-27) +1);
                userTotal +=  userDeck[countUserDeck]-27+1;
            }
        }
        if( userDeck[countUserDeck] == 27){
            printf("\nAce of Clubs");
            userTotal += 11;
        }
        if( userDeck[countUserDeck] == 37){
            printf("\nJack of Clubs");
            userTotal += 10;
        }
        if( userDeck[countUserDeck] == 38){
            printf("\nQueen of Clubs");
            userTotal += 10;
        }
        if( userDeck[countUserDeck] == 39){
            printf("\nKing of Clubs");
            userTotal += 10;
        }
        if( userDeck[countUserDeck]>40 &&  userDeck[countUserDeck]<50){
            if( userDeck[countUserDeck] == 49){
                printf("\n9 of Spades");
                userTotal +=9;
            }else{
                printf("\n%d of Spades", ( userDeck[countUserDeck]-40) +1);
                userTotal +=  userDeck[countUserDeck]-40+1;
            }
            
        }
        if( userDeck[countUserDeck] == 40){
            printf("\nAce of Spades");
            userTotal += 11;
        }
        if( userDeck[countUserDeck] == 50){
            printf("\nJack of Spades");
            userTotal += 10;
        }
        if( userDeck[countUserDeck] == 51){
            printf("\nQueen of Spades");
            userTotal += 10;
        }
        if( userDeck[countUserDeck] == 52){
            printf("\nKing of Spades");
            userTotal += 10;
        }
        
        
    
    
    printf("\nYour new total is: %d", userTotal);
    
    
}



void addCompCard(){
    
    compDeck[2] =deck[45];
    
   if(compTotal !=21){
        
        if( compDeck[2] >1 && compDeck[2] < 10){
            compTotal += compDeck[2];
        }
        if(compDeck[2] == 1){
            compTotal += 11;
        }
        if(compDeck[2] == 11){
            compTotal += 10;
        }
        if(compDeck[2] == 12){
            compTotal += 10;
        }
        if(compDeck[2] == 13){
            compTotal += 10;
        }
        if(compDeck[2] >13 && compDeck[2] <24){
            if(compDeck[2] == 23){
                compTotal += 9;
            }else{
                compTotal += compDeck[2]-14+1;
            }
        }
        if(compDeck[2] == 14){
            compTotal += 11;
        }
        if(compDeck[2] == 24){
            compTotal += 10;
        }
        if(compDeck[2] == 25){
            compTotal += 10;
        }
        if(compDeck[2] == 26){
            compTotal += 10;
        }
        if(compDeck[2] > 27 && compDeck[2] <37){
            if(compDeck[2] == 36){
                compTotal+= 9;
            }else{
                compTotal += compDeck[2]-27+1;
            }
        }
        if(compDeck[2] == 27){
            compTotal += 11;
        }
        if(compDeck[2] == 37){
            compTotal += 10;
        }
        if(compDeck[2] == 38){
            compTotal += 10;
        }
        if(compDeck[2] == 39){
            compTotal += 10;
        }
        if(compDeck[2]>40 && compDeck[2]<50){
            if(compDeck[2] == 49){
                compTotal +=9;
            }else{
                compTotal += compDeck[2]-40+1;
            }
        }
        if(compDeck[2] == 40){
            compTotal += 11;
        }
        if(compDeck[2] == 50){
            compTotal += 10;
        }
        if(compDeck[2] == 51){
            compTotal += 10;
        }
        if(compDeck[2] == 52){
            compTotal += 10;
        }
        

    }
    
    
}

void checkWhenNo(){
    int userFar = 0;
    int compFar = 0;
    
    userFar = abs(userTotal -21);
    compFar = abs(compTotal - 21);
   
    if(userTotal < 21 && compTotal > 21){
        userScore++;
        printf("\nYou Won! Computer Total: %d", compTotal);
    }
    if(userTotal > 21){
        compScore++;
        printf("\nYou Lost! Computer Total: %d", compTotal);
    }
    
    if(userScore == 21){
        printf("\nYou have won with perfect 21!");
        userScore++;
    }
    if(compScore== 21){
        printf("\nYou have lost to a perfect 21 by the dealer!");
        compScore++;
    }
    if(userTotal <21 && compTotal <21){
        if(userFar < compFar){
            printf("\nYou won! Computer Total: %d", compTotal);
            userScore++;
        }
        if(compFar< userFar){
            printf("\nYou lost! Computer Total: %d", compTotal);
            compTotal++;
        }
    }
    
    printf("\nThe scores are: ");
    printf("\nComputer: %d", compScore);
    printf("\nUser: %d", userScore);
}

void playAgain(){
    initialize();
    playBlackJack();
}


