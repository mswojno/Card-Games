//
//  Functions.c
//  Card Games
//
//  Created by MATTHEW S WOJNO on 10/14/14.
//  Copyright (c) 2014 Matthew Wojno. All rights reserved.
//

#include "Functions.h"
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include<time.h>

void shuffle(int deckIn[]){
    int random;
    srand(time(NULL));
    
    for(int i = 0; i<52; i++){
        random = rand() % 52 + 1;
        deckIn[i] = random;
        }
    
}