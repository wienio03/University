class BRANCH_CLASS;
class GARDEN_CLASS;
class TREE_CLASS{
private:
    unsigned int treeIdentifier;
    unsigned int treeHeight;
    unsigned int branchAmount;
    unsigned int fruitAmount;
    unsigned int weightTotal;
    GARDEN_CLASS* whichGarden;
    BRANCH_CLASS* head;
    BRANCH_CLASS* last;
    TREE_CLASS* next{};
    TREE_CLASS* prev{};
public:
    void displayAll();
    TREE_CLASS(GARDEN_CLASS* , unsigned int);
    TREE_CLASS(const TREE_CLASS&);
    TREE_CLASS();
    TREE_CLASS(unsigned int);
    void addBranches(unsigned int);
    void addFruits(unsigned int);
    void setIdentifier(unsigned int);
    void addHeight(unsigned int);
    void setGarden(GARDEN_CLASS*);
    void setNext(TREE_CLASS*);
    void setPrev(TREE_CLASS*);
    void addWeight(unsigned int);
    void decHeight(unsigned int);
    void decBranch(unsigned int);
    void decFruit(unsigned int);
    void decWeight(unsigned int);
    TREE_CLASS* getPrev();
    TREE_CLASS* getNext();
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    unsigned int getNumber();
    unsigned int getHeight();
    void growthTree();
    void fadeTree();
    void harvestTree(unsigned int);
    void cutTree(unsigned int);
    void cloneBranch(BRANCH_CLASS*);
    GARDEN_CLASS *getGardenPointer(void);
    BRANCH_CLASS *getBranchPointer(unsigned int);
    //void display(void);
    ~TREE_CLASS();
};
