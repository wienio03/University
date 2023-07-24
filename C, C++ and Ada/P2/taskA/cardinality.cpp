#include "bitwise_operations.h"
bool Disjoint(int firstSet, int secondSet){
    if(!(firstSet & secondSet))
        return true;
    return false;
}
bool Conjunctive(int firstSet, int secondSet){
    if((firstSet & secondSet))
        return true;
    return false;
}
