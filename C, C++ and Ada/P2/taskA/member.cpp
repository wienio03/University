#include "bitwise_operations.h"
bool Member(char* element, int set){    
if(*element == ' ')
    Member(element+1, set);
else if(*element == '\0')
    return false;
else if(*element == '0' || *element == '1'){
    int bitID = 0;
    if(*element == '1')
        bitID |= (1 << 4);
    if(*(element+1) == '1')
        bitID |= (1 << 3);
    if(*(element+2) == '1')
        bitID |= (1 << 2);
    if(*(element+3) == '1')
        bitID |= (1 << 1);
    if(*(element+4) == '1')
        bitID |= 1;
    if(*element == '0' && *(element+1) == '0' && *(element+2) == '0' && *(element+3) == '0' && *(element+4) =='0')
        bitID = 0;
    if(set & (1 << bitID))
        return true;
    else 
        return false;
}
}
