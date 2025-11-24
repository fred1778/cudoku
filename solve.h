#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


#define SIZE 9
#define TOTALLEN SIZE * SIZE

enum lineMode
{
    NOZERO,
    LINE,
    TOTAL
};

typedef enum lineMode lineMode;

enum direction
{
    VERTICAL,
    HORIZONTAL
};
typedef enum direction direction;
struct puzzle {
    int flatline[TOTALLEN];
};
typedef struct puzzle puzzle;

void loadLineToPuzzle(char *line, puzzle *pz, int row);
void validateInput(int argc, char *argv[]);
bool extractPuzzle(FILE *file, puzzle *pz);
bool loadFile(const char *filename, puzzle *pz);
bool solvePuzzle(puzzle *pz);
bool lineCompletionCheck(puzzle *pz, int seq, direction dir);
bool identifyMissing(int *range);
void missingUpdate(int *missing, int cell);
void DEBUG_arrPrint(int *toprint, lineMode mode);
void cleanArray(int *arr, int size);