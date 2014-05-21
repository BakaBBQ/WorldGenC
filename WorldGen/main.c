//
//  main.c
//  WorldGen
//
//  Created by LBQ on 5/20/14.
//  Copyright (c) 2014 Boqi Inc. All rights reserved.
//

/*
 actually i am feeling really bad when writing C code
 I feel like i am doing a lot of things and codings but
 i feel like i am wasting time
 
 at least it is more efficient._.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 30
#define HEIGHT 30
#define TOTALSTEPS 2
static int die = 0;
static int live = 1;

int start_gen();
int print_state();
int step();
int cellStep();
int livingNeighborCnt();
static int map[WIDTH][HEIGHT] = {{0}};
static int cmap[WIDTH][HEIGHT] = {{0}};
int main(int argc, const char * argv[])
{
    //printf("test");
    start_gen();
    step();
    step();
    step();
    return 0;
}

int start_gen(){
    srand(time(NULL));
    int r;
    int i;
    int j;
    for (i = 0; i < WIDTH; i ++){
        for (j = 0; j < HEIGHT; j ++){
            r  = rand() % 4;
            if(r == 1){
                map[i][j] = live;
            }else{
                map[i][j] = die;
            }
            
        }
    }
    return 0;
}

int step(){
    print_state();
    memcpy(cmap, map, sizeof(map));
    int i;
    int j;
    for (i = 0; i < WIDTH; i ++){
        for (j = 0; j < HEIGHT; j ++){
            cellStep(i,j);
        }
    }
    return 0;
}
// cellStep, called to every cell on the map

int cellStep(int x, int y){
    int cell = map[x][y];
    int cnt = livingNeighborCnt(x,y);
    int result;
    if(cell == live){ //Living Cell
        // get the living neighbors
        /*
         Any live cell with fewer than two live neighbours dies, as if caused by under-population.
         Any live cell with two or three live neighbours lives on to the next generation.
         Any live cell with more than three live neighbours dies, as if by overcrowding.
         Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
         */
        
        
        if (cnt < 2){
            result = die;
        } else if (cnt >= 2 && cnt <= 3){
            result = live;
        } else{
            result = die; // cruel life
        }
    }else{ //Dead Cell
        if (cnt == 3){
            result = live;
        }
		else{
			result = die;
		}
    } // end of deciding the fate of the cell
    cmap[x][y] = result;
    
    memcpy(map, cmap, sizeof(map));
    return 0;
}

int livingNeighborCnt(int x, int y){
    int cnt = 0;
    int i;
    int j;
    for (i = -1; i <= 1; i++){
        for (j = -1; j <= 1; j ++){
            int tx = x + i;
            int ty = y + j;
            if (i == 0 && j == 0){
                //continue;
            } else if (tx < 0 && ty < 0){ // when the cell does not exist
                //continue;
            } else if(map[tx][ty] == live){ //When the cell exists and it is not itself
                cnt ++;
            }
        } // Iterating....
    }
    return cnt;
}


int print_state(){
    int i;
    int j;
    for (i = 0; i < WIDTH; i ++){
        for (j = 0; j < HEIGHT; j ++){
            printf("%d|",map[i][j]);
        }
        printf("\n");
    }
    printf("===================\n");
    
    
    return 0;
    
    
}

