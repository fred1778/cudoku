
#include "solve.h"
#define SIZE 9




int main(int argc, char *argv[]) {
    printf("%i\n", argc);
    validateInput(argc, argv);

    puzzle thisPuzzle;
    char *filename = argv[1];
    if(loadFile(filename, &thisPuzzle)){

        solvePuzzle(&thisPuzzle);
    }



    return 0;
}

bool loadFile(const char* fname, puzzle* str){
   if(fname == NULL || str == NULL){
      return false;
   }
   FILE* file_pointer = fopen(fname, "rt");
   if(file_pointer == NULL){
      return false;
   }   
   return extractPuzzle(file_pointer, str);
}


bool extractPuzzle(FILE* file, puzzle* output){
   char line[100];
   line[0] = '\0';
   int row_count = 0;
   // Unsigned long to match strlen() return for line_size_check()
   unsigned long row_length = 0; 
   while(fgets(line, 100, file) != NULL){
        loadLineToPuzzle(line, output, row_count);
 
        row_count++;
   }
   fclose(file);
   return true;
}


void loadLineToPuzzle(char* line, puzzle* pz, int row) {

        for (int i = 0; i < SIZE; i++) {
            char c = line[i];
            printf("%d\n", (row * SIZE) + i);

            pz->flatline[(row * SIZE) + i] = c - '0';
    }
}

void validateInput(int argc, char *argv[]) {
    if (argc != 2) {
        EXIT_FAILURE;
    }
    
   
}

bool solvePuzzle(puzzle *pz){

    DEBUG_arrPrint(pz->flatline, TOTAL);

    for (int cell = 0; cell < TOTALLEN; cell++)
    {
        if (pz->flatline[cell] == 0)
        {
            // Empty cell, begin checks from quick win to harder...
            lineCompletionCheck(pz, cell, VERTICAL);
        }
}

return true;
}

bool lineCompletionCheck(puzzle *pz, int seq, direction dir){

    // this is for 'colums'
    int localPosition = seq % SIZE;
    printf(">>>>> <%i/%i> %i\n", seq, SIZE, localPosition);
    int present[SIZE];
    cleanArray(present, SIZE);

    for (int i = localPosition; i < SIZE; i += SIZE)
    {
        printf("%i\n", pz->flatline[i]);
        if (pz->flatline[i] != 0)
        {
            present[i] = pz->flatline[i];
        }
    }
    DEBUG_arrPrint(present, LINE);
    return true;
}

void missingUpdate(int *missing, int cell){
    for (int i = 0; i < SIZE; i++){
        if(cell == missing[i]){
            missing[i] = 0;

        }

    }
}

// Generic function to print int arrays in different contexts (defined by lineMode)
void DEBUG_arrPrint(int *toprint, lineMode mode){

    int cap = mode == TOTAL ? TOTALLEN : SIZE;
    for (int i = 0; i < cap; i++){

       /*if(toprint[i] == 0 && (mode == NOZERO)){
            break;
        }*/
        printf("%i", toprint[i]);
    }
    printf("\n");
}
void cleanArray(int *arr, int size){

    for (int i = 0; i < size; i++){
        arr[i] = 0;
    }
}