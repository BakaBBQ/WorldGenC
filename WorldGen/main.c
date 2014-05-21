//
//  main.c
//  WorldGen
//
//  Created by LBQ on 5/20/14.
//  Copyright (c) 2014 Boqi Inc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 30
#define HEIGHT 30
#define TOTALSTEPS 2

#define DIE = 0
#define LIVE = 1

int init_state();
int print_state();
static int map[WIDTH][HEIGHT] = {{0}};
static int cmap[WIDTH][HEIGHT] = {{0}};
int main(int argc, const char * argv[])
{
    init_state();
    print_state();
    return 0;
}

int init_state(){
    srand(time(NULL));
    int r;
    for (int i = 0; i < WIDTH; i ++){
        for (int j = 0; j < HEIGHT; j ++){
            r  = rand() % 4;
            if(r == 1){
                map[i][j] = 1;
            }else{
                map[i][j] = 0;
            }
            
        }
    }
    return 0;
}

int step(){
    memcpy(cmap, map, sizeof(map));
    for (int i = 0; i < WIDTH; i ++){
        for (int j = 0; j < HEIGHT; j ++){
            cellStep(i,j);
        }
    }
    return 0;
}
// cellStep, called to every cell on the map
int cellStep(int x, int y){
    int cell = map[x][y];
    if(cell == LIVE){ //Living Cell
        // get the living neighbors
        /*
         Any live cell with fewer than two live neighbours dies, as if caused by under-population.
         Any live cell with two or three live neighbours lives on to the next generation.
         Any live cell with more than three live neighbours dies, as if by overcrowding.
         Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
         */
        
        int cnt = livingNeighborCnt(x,y);
        int result;
        if (cnt < 2){
            result = DIE;
        } else if (cnt >= 2 && cnt <= 3){
            result = LIVE;
        } else{
            result = DIE; // cruel life
        }
    }else{ //Dead Cell
        
    }
    return 0;
}

int livingNeighborCnt(int x, int y){
    int cnt = 0;
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j ++){
            int tx = x + i;
            int ty = y + j;
            if (i == 0 && j == 0){
                continue;
            } else if (tx < 0 && ty < 0){ // when the cell does not exist
                continue;
            } else { //When the cell exists and it is not itself
                cnt ++;
            }
        } // Iterating....
    }
    return cnt;
}


int print_state(){
    for (int i = 0; i < WIDTH; i ++){
        for (int j = 0; j < HEIGHT; j ++){
            printf("%d",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}

