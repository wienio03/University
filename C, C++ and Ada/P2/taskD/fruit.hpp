class BRANCH_CLASS;
class FRUIT_CLASS{
private:
    unsigned int weight;
    unsigned int growthPlace;
    BRANCH_CLASS* whichBranch;
    FRUIT_CLASS* next;
    FRUIT_CLASS* prev;
public:
    void addWeight(unsigned int);
    void setPlace(unsigned int);
    FRUIT_CLASS(BRANCH_CLASS*);
    FRUIT_CLASS();
    unsigned int getLength(void);
    unsigned int getWeight(void);
    FRUIT_CLASS* getNext(void);
    FRUIT_CLASS* getPrev(void);
    void setNext(FRUIT_CLASS* );
    void setPrev(FRUIT_CLASS* );
    void growthFruit(void);
    void fadeFruit(void);
    void pluckFruit(void);
    BRANCH_CLASS* getBranchPointer(void);
    //void display(void);
    ~FRUIT_CLASS();
};
