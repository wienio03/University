#include "bitwise_operations.h"
bool Inclusion(int includedSet, int mainSet){
    if(( includedSet & mainSet )== includedSet)
        return true;
    return false;
}
bool Equality(int firstSet, int secondSet){
    int equality = (firstSet & secondSet);
    if((equality == firstSet) && (equality == secondSet))
        return true;
    return false;
}
