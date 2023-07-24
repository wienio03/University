#include <iostream>
bool Universe(int x){
    if (x<=4095 && x>=1) return true;
    else return false;
}
void Cardinality(int set[], int* cardinality) {
    *(cardinality)=0;
    while (set[*cardinality]!=(-1)) {
        (*cardinality)++;
    }
}
void bubbleSort(int set[]){
    int size;
    Cardinality(set,&size);
    int i,j;
    for (i = 0; i < size- 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (set[j] > set[j + 1]) {
                std::swap(set[j], set[j + 1]);
            }
        }
    }
}
bool Element(int x, int set[]){
    int n=0;
    int size;
    Cardinality(set, &size);
    while(n<size){
        if (x==set[n]) return true;
        n++;
    }
    return false;
}
void AddNoSort(int number, int set[]){
    int n;
    Cardinality(set,&n);
    if ((number>=1&&number<=4095)&&!Element(number,set)){
        set[n]=number;
        set[n+1]=(-1);
    }
}
void Add(int number, int set[]){
    int n;
    Cardinality(set,&n);
    if ((number>=1&&number<=4095)&&!Element(number,set)){
        set[n]=number;
        set[n+1]=(-1);
    }
    bubbleSort(set);
}
void Create(unsigned int usedElements, int sourceSet[], int set[]){
    *set=-1;
    int i;
    for (i=0; i<usedElements; i++){
        if(Universe(sourceSet[i]))Add(sourceSet[i],set);
    }
    bubbleSort(set);
}

bool Empty(int set[]){
    int size;
    Cardinality(set,&size);
    if(size==0) return true;
    if(size=!0) return false;
}
bool Nonempty(int set[]){
    int size;
    Cardinality(set,&size);
    if(size==0) return false;
    if(size!=0) return true;
}

void Union(int set1[],int set2[], int setResultant[]){
    int size1;
    int size2;
    *setResultant=-1;
    Cardinality(set2,&size2);
    Cardinality(set1,&size1);
    int i,k;
    for (i=0; i<size1; i++){
        AddNoSort(set1[i],setResultant);
    }
    for(k=0; k<size2; k++){
        if(!Element(set2[k],setResultant)) AddNoSort(set2[k], setResultant);
    }
    bubbleSort(setResultant);
}
void Intersection(int set1[],int set2[], int setIntersection[]){
    int size1;
    *setIntersection=-1;
    Cardinality(set1,&size1);
    int i;
    for(i=0; i<size1; i++){
        if(Element(set1[i],set2)) AddNoSort(set1[i],setIntersection);
    }
    bubbleSort(setIntersection);
}
void Difference(int set1[],int set2[], int setDifference[]){
    *setDifference=-1;
    int size1;
    Cardinality(set1, &size1);
    int i;
    for(i=0; i<size1;i++){
        if(!Element(set1[i],set2)) AddNoSort(set1[i],setDifference);
    }
    bubbleSort(setDifference);
}
void Complement(int set[], int setComplement[]){
    *setComplement=-1;
    int i;
    for(i=1; i<4096; i++){
        if(!Element(i,set)) AddNoSort(i,setComplement);
    }
}
void Symmetric(int set1[], int set2[], int setSymetric[]){
    *setSymetric=-1;
    int size1;
    int size2;
    Cardinality(set1,&size1);
    Cardinality(set2,&size2);
    int i;
    for(i=0; i<size2;i++){
        if(!Element(set2[i],set1)) AddNoSort(set2[i],setSymetric);

    }
    for(i=0; i<size1;i++){
        if(!Element(set1[i],set2)) AddNoSort(set1[i],setSymetric);

    }
    bubbleSort(setSymetric);
}
double Arithmetic (int set[]){
    int size;
    double aMean=0;
    int n = 0;
    Cardinality (set,&size);
    if (size==0) aMean=0;
    else {
        while(n<size){
            aMean+=set[n];
            n++;
        }
        aMean=(aMean/n);
    }
    return aMean;
}
double Harmonic (int set[]){
    int size;
    double hMean=0;
    double hDenominator=0;
    double hNumerator=0;
    int n = 0;
    Cardinality(set, &size);
    if (size==0) hMean=1;
    else {
        while (n<size){
            hDenominator+=(1.0/set[n]);
            n++;
        }
        hNumerator=size;
        hMean = hNumerator/hDenominator;
    }
    return hMean;
}
bool Equal(int set1[], int set2[]){
    int size1,size2;
    Cardinality(set1,&size1);
    Cardinality( set2, &size2);
    if(size1==size2) {
        for (int i = 0; i < size1; i++){
            if (!Element(set1[i],set2)) return false;
        }
        return true;
    }
    else return false;
}
bool Subset(int set1[], int set2[]){
    int size1,size2;
    Cardinality(set1,&size1);
    Cardinality(set2,&size2);
    int j, i,k=0;
    if(size1==0)return true;
    if(size1==size2) Equal(set1,set2);
    for(i=0;i<size1;i++){
            for(j=0;j<size2;j++){
                if(set1[i]==set2[j]) k++;
            }
        }
        if(k==size1) return true;
        else return false;
}
void MinMax(int set[], int* min, int& max){
    int size;
    int i = 0 , j = 0;
    Cardinality(set, &size);
    if(Nonempty(set)) {
        *min=set[0];
        max=set[0];
        while (i < size) {
            if (set[i] > max) max = set[i];
            i++;
        }
        while (j < size) {
            if (set[j] < *min) *min = set[j];
            j++;
        }
    }
}
void Properties(int set[], char sign[], double &arithmetic, double* harmonic, int &minimum, int* maximum, int &harvestpower) {
    while(*sign!=0){
    if(*sign=='a')arithmetic=Arithmetic(set);
    else if(*sign=='h')*harmonic=Harmonic(set);
    else if(*sign=='c')Cardinality(set,&harvestpower);
    else if(*sign=='m')MinMax(set,&minimum, *maximum);
       ++sign;
    }
}
