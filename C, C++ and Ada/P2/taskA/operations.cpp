#include "bitwise_operations.h"
void Union(int firstSet, int secondSet, int* resultSet){
    //OR operator
    *resultSet = firstSet | secondSet;
}
void Intersection(int firstSet, int secondSet, int* resultSet){
    *resultSet = firstSet & secondSet;
}
void Symmetric(int firstSet, int secondSet, int* resultSet){
    *resultSet = firstSet ^ secondSet;
}
void Difference(int firstSet, int secondSet, int* resultSet){
    *resultSet = firstSet & (~secondSet);
}
void Complement(int set, int* resultSet){
   *resultSet = ~set;
}
