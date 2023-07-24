#include <stdio.h>
class TREE_CLASS;
class GARDEN_CLASS{
private:
    unsigned int treesTotal;
    unsigned int fruitTotal;
    unsigned int weightTotal;
    unsigned int branchTotal;
    unsigned int gapCount;
    TREE_CLASS* head;
    TREE_CLASS* last;
public:
    void displayAll();
    GARDEN_CLASS();
    unsigned int getTreesTotal(void);
    unsigned int getBranchesTotal(void);
    unsigned int getFruitsTotal(void);
    unsigned int getWeightsTotal(void);
    void addTrees(unsigned int);
    void addBranches(unsigned int);
    void addFruit(unsigned int);
    void addWeight(unsigned int);
    void decTree(unsigned int);
    void decFruit(unsigned int);
    void decWeight(unsigned int);
    void decBranch(unsigned int);
    void plantTree(void);
    void extractTree(unsigned int);
    void fadeGarden(void);
    void growthGarden(void);
    void harvestGarden(unsigned int);
    TREE_CLASS* getTreePointer(unsigned);
    void cloneTree(unsigned int);
    //void display(void);
    ~GARDEN_CLASS();
};
