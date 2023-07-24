#include "fruit.hpp"
#include "garden.hpp"
#include "branch.hpp"
#include "tree.hpp"
FRUIT_CLASS::~FRUIT_CLASS(){
    this->next = NULL;
    this->prev = NULL;
    this->pluckFruit();
    if(whichBranch != NULL) {
        whichBranch->decFruit(1);
        if (whichBranch->getTreePointer() != NULL) {
            whichBranch->getTreePointer()->decFruit(1);
            if (whichBranch->getTreePointer()->getGardenPointer() != NULL) {
                whichBranch->getTreePointer()->getGardenPointer()->decFruit(1);
            }
        }
    }
    this->whichBranch = NULL;
}
void FRUIT_CLASS::setPlace(unsigned int arg){
    this->growthPlace = arg;
}
void FRUIT_CLASS::addWeight(unsigned int arg){
    this->weight += arg;
}
FRUIT_CLASS::FRUIT_CLASS(BRANCH_CLASS* parentBranch){
    this->whichBranch = parentBranch;
    this->next = NULL;
    this->prev = NULL;
    this->weight = 0;
    this->growthPlace = parentBranch->getLength();
    if(parentBranch != NULL) {
        parentBranch->addFruit(1);
        if (parentBranch->getTreePointer() != NULL) {
            parentBranch->getTreePointer()->addFruits(1);
            if (parentBranch->getTreePointer()->getGardenPointer() != NULL) {
                parentBranch->getTreePointer()->getGardenPointer()->addFruit(1);
            }
        }
    }
}
FRUIT_CLASS::FRUIT_CLASS(){
    this->weight = 0;
    this->next = NULL;
    this->prev = NULL;
    this->growthPlace = 0;
    this->whichBranch = NULL;
}
unsigned int FRUIT_CLASS::getLength(void){
    return this->growthPlace;
}

unsigned int FRUIT_CLASS::getWeight(void){
    return this->weight;
}

void FRUIT_CLASS::growthFruit(void){
    this->weight++;
    if(this->whichBranch != NULL) {
        this->whichBranch->addWeight(1);
            if(this->whichBranch->getTreePointer() != NULL){
                this->whichBranch->getTreePointer()->addWeight(1);
                    if(this->whichBranch->getTreePointer()->getGardenPointer() != NULL){
                        this->whichBranch->getTreePointer()->getGardenPointer()->addWeight(1);
                    }
            }
    }
}
void FRUIT_CLASS::fadeFruit(void){
    if(this->weight > 0)
        this->weight--;
    if(this->whichBranch != NULL) {
        this->whichBranch->decWeight(1);
        if(this->whichBranch->getTreePointer() != NULL){
            this->whichBranch->getTreePointer()->decWeight(1);
            if(this->whichBranch->getTreePointer()->getGardenPointer() != NULL){
                this->whichBranch->getTreePointer()->getGardenPointer()->decWeight(1);
            }
        }
    }
}
void FRUIT_CLASS::pluckFruit(void){
    if(this->whichBranch != NULL) {
        this->whichBranch->decWeight(this->weight);
        if(this->whichBranch->getTreePointer() != NULL){
            this->whichBranch->getTreePointer()->decWeight(this->weight);
            if(this->whichBranch->getTreePointer()->getGardenPointer() != NULL){
                this->whichBranch->getTreePointer()->getGardenPointer()->decWeight(this->weight);
            }
        }
    }
    this->weight = 0;

}
BRANCH_CLASS* FRUIT_CLASS::getBranchPointer(void){
    return this->whichBranch;
}
FRUIT_CLASS * FRUIT_CLASS::getNext(void){
    return this->next;
}
FRUIT_CLASS* FRUIT_CLASS::getPrev(void){
    return this->prev;
}
void FRUIT_CLASS::setNext(FRUIT_CLASS* fruitNext){
    this->next = fruitNext;
}
void FRUIT_CLASS::setPrev(FRUIT_CLASS* fruitPrev){
    this->prev = fruitPrev;
}
