
#include "solve.h"
#define SIZE 9




int main(int argc, char *argv[]) {
    printf("%i\n", argc);
    validateInput(argc, argv);

    puzzle thisPuzzle;
    char *filename = argv[1];
    loadFile(filename, &thisPuzzle);


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
        printf("%s", line);
        loadLineToPuzzle(line, output, row_count);
        row_count++;
   }
   fclose(file);
   return true;
}


void loadLineToPuzzle(char* line, puzzle* pz, int row) {

        for (int col = 0; col < SIZE; col++) {
            char c = line[col];
            pz->board[row][col] = c - '0'; 
        
    }
}

void validateInput(int argc, char *argv[]) {
    if (argc != 2) {
        EXIT_FAILURE;
    }
    
   
}

bool solvePuzzle(puzzle *pz){
// first check is line completion checks

for(int i = 0; i < SIZE; i++) {

    lineCompletionCheck(pz, i, HORIZONTAL);
    lineCompletionCheck(pz, i, VERTICAL);

}




}






bool lineCompletionCheck(puzzle *pz, int seq, direction dir){

    // first pass identifies

    int missing_count = 0;
    int line[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
       int tile = pz->board[dir == VERTICAL ? i : seq][dir == VERTICAL ? seq : i];
       line[i] = tile;
       if (tile == 0)
       {
           missing_count++;
       }
    }


    
}

