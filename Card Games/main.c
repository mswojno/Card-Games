//
//  main.c
//  Card Games
//
//  Created by MATTHEW S WOJNO on 10/11/14.
//  Copyright (c) 2014 Matthew Wojno. All rights reserved.
//
#include "BlackJack.h"
#include "Poker.h"
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include<time.h>


int main(){
    
    char user;
    
    
    printf("\nTo Play: ");
    printf("\n Black Jack-");
    printf("enter 'b'");
    printf("\n Poker-");
    printf("enter 'p'");
    printf("\n Neither-");
    printf("enter 'n'");
    printf("\nWhich do you choose: ");
    user = getchar();
    
    
    if(user == 'b'){
        initialize();
        playBlackJack();
        main();
        
    }else if (user == 'p'){
        printDeck();
        playPoker();
        main();
    }else if(user == 'n'){
        main();
    }
    
}
