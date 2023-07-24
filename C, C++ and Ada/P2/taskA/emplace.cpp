#include "bitwise_operations.h"
void EmplaceWithEmptySet(char* bitString, int* set, int empty){
    if(*bitString == '\0')
    return;
else if(*bitString == ' '){
    
   EmplaceWithEmptySet(bitString+1, set, empty);
} 
else if(*bitString == '0' || *bitString == '1'){
    int bitID = 0;
    //kazda kombinacja poza 00000
    if(*bitString == '1')
        bitID |= (1 << 4); 
    if(*(bitString+1) == '1')
        bitID |= (1 << 3);
    if(*(bitString+2) == '1')
        bitID |= (1 << 2);
    if(*(bitString+3) == '1')
        bitID |= (1 << 1);
    if(*(bitString+4) == '1')
        bitID |= 1;
    //kombinacja 00000
    if(*bitString == '0' && *(bitString+1) == '0' && *(bitString+2) == '0' && *(bitString+3) == '0' && *(bitString+4) == '0')
        bitID = 0;
    *set |= (1 << bitID);
    EmplaceWithEmptySet(bitString+5, set, empty);
}
}
void Emplace(char* bitString, int* set) {
    *set = 0;
    int empty = 1;
    EmplaceWithEmptySet(bitString, set, empty);
}

