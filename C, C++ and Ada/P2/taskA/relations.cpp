#include "bitwise_operations.h"
bool LessThen(int firstSet, int secondSet){
//firstset < secondSet
    int cardinalityFirst = Cardinality(firstSet);
    int cardinalitySecond = Cardinality(secondSet);
    if(cardinalityFirst < cardinalitySecond)
        return true;
    else if(cardinalityFirst == cardinalitySecond){
        if(firstSet < secondSet)
            return true;
        else
            return false;
    }
    else 
        return false;
    return false;
}
bool LessEqual(int firstSet, int secondSet){
//firstset <= secondset
    int cardinalityFirst = Cardinality(firstSet);
    int cardinalitySecond = Cardinality(secondSet);
    if(cardinalityFirst < cardinalitySecond)
        return true;
    else if(cardinalityFirst == cardinalitySecond){
        if(firstSet <= secondSet)
            return true;
        else
            return false;
    }
    else 
        return false;
    return false;
}
bool GreatEqual(int firstSet, int secondSet){
//firstset >= secondset
    int cardinalityFirst = Cardinality(firstSet);
    int cardinalitySecond = Cardinality(secondSet);
    if(cardinalityFirst > cardinalitySecond)
        return true;
    else if(cardinalityFirst == cardinalitySecond){
        if(firstSet >= secondSet)
            return true;
        else 
            return false;
    }
    else
        return false;
    return false;
}
bool GreatThen(int firstSet, int secondSet){
//firstset > secondset
   int cardinalityFirst = Cardinality(firstSet);
    int cardinalitySecond = Cardinality(secondSet);
    if(cardinalityFirst > cardinalitySecond)
        return true;
    else if(cardinalityFirst == cardinalitySecond){
        if(firstSet > secondSet)
            return true;
        else 
            return false;
    }
    else
        return false;
    return false;
}
