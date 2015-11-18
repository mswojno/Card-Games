//
//  Poker.c
//  Card Games
//
//  Created by MATTHEW S WOJNO on 10/11/14.
//  Copyright (c) 2014 Matthew Wojno. All rights reserved.
//

#include "Poker.h"
#include "Functions.h"
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#include <math.h>


int deck[52];
int userDeck[5];
int isStraight = 0;
int isFlush = 0;
int anything = 0;

void printDeck(){
       shuffle(deck);
    
    userDeck[0] = deck[0];
    userDeck[1] = deck[1];
    userDeck[2] = deck[2];
    userDeck[3] = deck[3];
    userDeck[4] = deck[4];
    
    
        printf("\n\nYour Hand is: ");
        
        for(int b = 0; b<5; b++){
            
            if( userDeck[b] >1 && userDeck[b] < 10){
                printf("\n%d of Diamonds", userDeck[b]);
                
            }
            if(userDeck[b] == 1){
                printf("\nAce of Diamonds");

            }
            if(userDeck[b] == 11){
                printf("\nJack of Diamonds");
                
            }
            if(userDeck[b] == 12){
                printf("\nQueen of Diamonds");
                            }
            if(userDeck[b] == 13){
                printf("\nKing of Diamonds");
                
            }
            if(userDeck[b] >14 && userDeck[b] <24){
                if(userDeck[b] == 23){
                    printf("\n9 of Hearts");
            }else{
                    printf("\n%d of Hearts", (userDeck[b] - 14)+1);
                
                }
            }
            if(userDeck[b] == 14){
                printf("\nAce of Hearts");
                
            }
            if(userDeck[b] == 24){
                printf("\nJack of Hearts");
                
            }
            if(userDeck[b] == 25){
                printf("\nQueen of Hearts");
                
            }
            if(userDeck[b] == 26){
                printf("\nKing of Hearts");
                
            }
            if(userDeck[b] > 27 && userDeck[b] <37){
                if(userDeck[b] == 36){
                    printf("\n9 of Clubs");
                    
                }else{
                    printf("\n%d of Clubs", (userDeck[b]-27) +1);
                                    }
            }
            if(userDeck[b] == 27){
                printf("\nAce of Clubs");
                            }
            if(userDeck[b] == 37){
                printf("\nJack of Clubs");
                
            }
            if(userDeck[b] == 38){
                printf("\nQueen of Clubs");
                
            }
            if(userDeck[b] == 39){
                printf("\nKing of Clubs");
                
            }
            if(userDeck[b]>40 && userDeck[b]<50){
                if(userDeck[b] == 49){
                    printf("\n9 of Spades");
                }else{
                    printf("\n%d of Spades", (userDeck[b]-40) +1);
                    
                }
                
            }
            if(userDeck[b] == 40){
                printf("\nAce of Spades");
            }
            if(userDeck[b] == 50){
                printf("\nJack of Spades");
                
            }
            if(userDeck[b] == 51){
                printf("\nQueen of Spades");
            }
            
            if(userDeck[b] == 52){
                printf("\nKing of Spades");
                
            }
            
        }
        }

void playPoker(){
    char play1;
    char response;
    
    checkOfKinds();
    checkFlush();
    checkStraight();
    checkStraightFlush();
    
    if(anything == 0){
        printf("\n\nI'm sorry your hand is a dud!");
    }
    
    play1 = getchar();
    printf("\n\n If you would like to play again enter a 'y'. If not enter a 'n'");
    response = getchar();
    
    if(response == 'y'){
         isStraight = 0;
         isFlush = 0;
        anything = 0;
        playAgainYo();
    }

    
    }


void checkOfKinds(){
    
    int countPairs = 0;
    int compareArray[4];
    
    
    
    
    for(int d = 0; d<5; d++){
        
        if( userDeck[d] >1 && userDeck[d] < 10){
            compareArray[d] =  userDeck[d];
        }
        if(userDeck[d] == 1){
            compareArray[d] =1;
            
        }
        if(userDeck[d] == 11){
            compareArray[d] =11;
            
        }
        if(userDeck[d] == 12){
            compareArray[d] =12;
            
        }
        if(userDeck[d] == 13){
            compareArray[d] = 13;
           
        }
        if(userDeck[d] >14 && userDeck[d] <24){
            if(userDeck[d] == 23){
                compareArray[d] = 9;
                
            }else{
                compareArray[d] = (userDeck[d] - 14)+1;
                
            }
        }
        if(userDeck[d] == 14){
            compareArray[d] = 1;
            
        }
        if(userDeck[d] == 24){
            compareArray[d] = 11;
            
        }
        if(userDeck[d] == 25){
            compareArray[d] = 12;
            
        }
        if(userDeck[d] == 26){
            compareArray[d] = 13;
            
        }
        if(userDeck[d] > 27 && userDeck[d] <37){
            if(userDeck[d] == 36){
                compareArray[d] =9;
                
            }else{
                compareArray[d] = (userDeck[d]-27) +1;
                
            }
        }
        if(userDeck[d] == 27){
            compareArray[d] = 1;
            
        }
        if(userDeck[d] == 37){
            compareArray[d] = 11;
            
            
        }
        if(userDeck[d] == 38){
            compareArray[d] = 12;
            }
        if(userDeck[d] == 39){
            compareArray[d] = 13;
            
        }
        if(userDeck[d]>40 && userDeck[d]<50){
            if(userDeck[d] == 49){
                compareArray[d] = 9;
                
            }else{
                compareArray[d] = (userDeck[d]-40) +1;
                
            }
            
        }
        if(userDeck[d] == 40){
            compareArray[d] = 1;
            
        }
        if(userDeck[d] == 50){
            compareArray[d] = 11;
            
        }
        if(userDeck[d] == 51){
            compareArray[d] = 12;
           
        }
        
        if(userDeck[d] == 52){
            compareArray[d] = 13;
        }
        
        }
    
    for(int q = 0; q<5; q++){
        for(int e = 0; e<5; e++){
            if(q==e){
                countPairs--;
            }
            if(compareArray[q] == compareArray[e]){
                countPairs++;
            }
        }
    }
    
    if(countPairs ==12){
        printf("\n\nYou have four of a kind!");
        anything++;
    }
    if(countPairs == 2){
        printf("\n\nYou have one pair!");
        anything++;
       
    }
    if(countPairs == 6){
        printf("\n\nYou have three of a kind!");
        anything++;
        
    }
    if(countPairs == 4){
        printf("\n\nYou have two pairs!");
        anything++;
    }
    if(countPairs == 8){
        printf("\n\nYou have a Full House!!!");
        anything++;
    }
    
}

void checkFlush(){
    int countHearts = 0;
    int countSpades = 0;
    int countClubs = 0;
    int countDiamonds = 0;
    
    for(int g = 0; g<5; g++){
        if(userDeck[g] > 0 && userDeck[g] <14){
            countDiamonds++;
        }
        if(userDeck[g] > 13 && userDeck[g] <27){
            countHearts++;
        }
        if(userDeck[g] >26 && userDeck[g] <40){
            countClubs++;
        }
        if(userDeck[g] >39 && userDeck[g] <53){
            countSpades++;
        }
    }
    
    if(countSpades == 5 || countClubs == 5 || countDiamonds==5|| countHearts == 5){
        printf("\n\nYou have a flush!");
        isFlush = 2;
        anything++;
    }
    
    
}

void checkStraight(){
    int checkArray[4];
    int hold = 0;
    int countStraight = 0;
    
    
    for(int d = 0; d<5; d++){
        
        if( userDeck[d] >1 && userDeck[d] < 10){
            checkArray[d] =  userDeck[d];
        }
        if(userDeck[d] == 1){
           checkArray[d] =1;
            
        }
        if(userDeck[d] == 11){
            checkArray[d] =11;
            
        }
        if(userDeck[d] == 12){
            checkArray[d] =12;
            
        }
        if(userDeck[d] == 13){
            checkArray[d] = 13;
            
        }
        if(userDeck[d] >14 && userDeck[d] <24){
            if(userDeck[d] == 23){
                checkArray[d] = 9;
                
            }else{
                checkArray[d] = (userDeck[d] - 14)+1;
                
            }
        }
        if(userDeck[d] == 14){
            checkArray[d] = 1;
            
        }
        if(userDeck[d] == 24){
            checkArray[d] = 11;
            
        }
        if(userDeck[d] == 25){
            checkArray[d] = 12;
            
        }
        if(userDeck[d] == 26){
            checkArray[d] = 13;
            
        }
        if(userDeck[d] > 27 && userDeck[d] <37){
            if(userDeck[d] == 36){
                checkArray[d] =9;
                
            }else{
                checkArray[d]= (userDeck[d]-27) +1;
                
            }
        }
        if(userDeck[d] == 27){
            checkArray[d] = 1;
            
        }
        if(userDeck[d] == 37){
            checkArray[d]= 11;
            
            
        }
        if(userDeck[d] == 38){
            checkArray[d] = 12;
        }
        if(userDeck[d] == 39){
            checkArray[d] = 13;
            
        }
        if(userDeck[d]>40 && userDeck[d]<50){
            if(userDeck[d] == 49){
                checkArray[d] = 9;
                
            }else{
               checkArray[d] = (userDeck[d]-40) +1;
                
            }
            
        }
        if(userDeck[d] == 40){
            checkArray[d] = 1;
            
        }
        if(userDeck[d] == 50){
            checkArray[d] = 11;
            
        }
        if(userDeck[d] == 51){
            checkArray[d] = 12;
            
        }
        
        if(userDeck[d] == 52){
            checkArray[d] = 13;
        }
        
        
    }
    
    for(int w = 0; w<5; w++){
        for(int z = 0; z<5; z++){
            hold = abs(checkArray[w] - checkArray[z]);
            if(hold ==1){
                countStraight++;
            }
        }
    }
    
    if(countStraight == 8){
        isStraight = 5;
        printf("\n\nYou have a Straight!");
        anything++;
    }
    
    
}


void checkStraightFlush(){
    if(isStraight == 5 && isFlush == 2){
        printf("\n\nTherefore you have a Straight Flush!");
        anything++;
    }
}

void playAgainYo(){
    printDeck();
    playPoker();
}










