//
//  tile.c
//  WorldGen
//
//  Created by LBQ on 5/20/14.
//  Copyright (c) 2014 Boqi Inc. All rights reserved.
//

#include <stdio.h>
#define WIDTH 200
#define HEIGHT 200
typedef struct {
    int id;
    char type[2]; //something like A1, A2, B, C blah
    int shape; //wtf a lot of binary numbers
}Tile;




int tile_SetTileId(char *set, int index, int shape){
    int result = 0;
    if (strcmp(set, "A1") == 0 )
    {
        result = 2048 + index * 48 + shape;
    }else if(strcmp(set, "A2")==0){
        result = 2816 + index * 48 + shape;
    }else if(strcmp(set, "A3")==0){
        result = 4352 + index * 48 + shape;
    }else if(strcmp(set, "A4")==0){
        result = 5888 + index * 48 + shape;
    }else if(strcmp(set, "A5")==0){
        result = 1536 + index;
    }else if(strcmp(set, "B")==0){
        return index;
    }else if(strcmp(set, "C")==0){
        return 256 + index;
    }else if(strcmp(set, "D")==0){
        return 512 + index;
    }else if(strcmp(set, "E")==0){
        return 768 + index;
    }
    return result;
}

Tile tile_TileIdToSet(id){
    
}