#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX_COMMAND_TOKEN_LENGTH 25
#define MAX_KEY_LENGTH 500
typedef enum { NONE = 0,
        UP = 1, DOWN = 2, LEFT = 4, RIGHT = 8
    }
Direction; 
typedef struct {
    int x, y; 
}
Vertex; 

typedef struct {
    int numberOfVertices; 
    Direction shiftDirection; 
    Vertex* vertexList;
}
Polygon;