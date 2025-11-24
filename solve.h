#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


#define SIZE 9


enum direction { VERTICAL, HORIZONTAL };
typedef enum direction direction;
struct puzzle {
    char hawk;
    int board[SIZE][SIZE];
};
typedef struct puzzle puzzle;

void loadLineToPuzzle(char *line, puzzle *pz, int row);
void validateInput(int argc, char *argv[]);
bool extractPuzzle(FILE *file, puzzle *pz);
bool loadFile(const char *filename, puzzle *pz);
bool solvePuzzle(puzzle *pz);
bool lineCompletionCheck(puzzle *pz, int seq, direction dir);