#include "fruit.hpp"
#include "garden.hpp"
#include "branch.hpp"
#include "tree.hpp"
BRANCH_CLASS::BRANCH_CLASS(){
    this->branchLength = 0;
    this->last = NULL;
    this->weightTotal = 0;
    this->fruitTotal = 0;
    this->growthHeight = 0;
    this->next = NULL;
    this->prev = NULL;
    this->whichTree = NULL;
    this->head = NULL;
}
BRANCH_CLASS::BRANCH_CLASS(TREE_CLASS* parentTree, unsigned int height){
    this->fruitTotal = 0;
    this->weightTotal = 0;
    this->growthHeight = height;
    this->branchLength = 0;
    this->head = new FRUIT_CLASS();
    this->last = NULL;
    this->whichTree = parentTree;
    this->next = NULL;
    this->prev = NULL;
    if(whichTree != NULL){
        whichTree->addBranches(1);
        if(whichTree->getGardenPointer() != NULL){
            whichTree->getGardenPointer()->addBranches(1);
        }
    }
}
void BRANCH_CLASS::setHeight(unsigned int height){
    this->growthHeight = height;
}
BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS& clonedBranch){
    this->whichTree = NULL;
    if(clonedBranch.head != NULL) {
        this->head = new FRUIT_CLASS(this);
        if (clonedBranch.head->getNext() == NULL)
            this->last = NULL;
        else {
            FRUIT_CLASS *tmp = clonedBranch.head->getNext();
            this->head->setNext(new FRUIT_CLASS(this));
            this->head->getNext()->setPrev(NULL);
            FRUIT_CLASS *tmpThis = this->head->getNext();
            while (tmp != NULL) {
                tmpThis->addWeight(tmp->getWeight());
                tmpThis->setPlace(tmp->getLength());
                if (tmp->getNext() == NULL)
                    tmpThis->setNext(NULL);
                else {
                    tmpThis->setNext(new FRUIT_CLASS(this));
                    tmpThis->getNext()->setPrev(tmpThis);
                    tmpThis = tmpThis->getNext();
                }
                tmp = tmp->getNext();
            }
            this->last = tmpThis;
        }
    }
    else
        this->head = NULL;
    this->fruitTotal = clonedBranch.fruitTotal;
    this->weightTotal = clonedBranch.weightTotal;
    this->growthHeight = clonedBranch.growthHeight;
    this->branchLength = clonedBranch.branchLength;
    this->prev = NULL;
    this->next = NULL;
}

BRANCH_CLASS::~BRANCH_CLASS(){
    this->prev = NULL;
    this->next = NULL;
    this->last = NULL;
    if(this->whichTree != NULL) {
        this->whichTree->decBranch(1);
        if (this->whichTree->getGardenPointer() != NULL) {
            this->whichTree->getGardenPointer()->decBranch(1);
        }
    }
    FRUIT_CLASS* tmp;
    if(head != NULL) {
        while (head->getNext() != NULL) {
            tmp = head->getNext();
            head->setNext(head->getNext()->getNext());
            delete tmp;
        }
        delete head;
    }
    this->whichTree = NULL;
}
void BRANCH_CLASS::addFruit( unsigned int arg){
    this->fruitTotal += arg;
}
void BRANCH_CLASS::addHeight(unsigned int arg){
    this->growthHeight += arg;
}
void BRANCH_CLASS::addLength(unsigned int arg){
    this->branchLength += arg;
}
void BRANCH_CLASS::setTree(TREE_CLASS* arg){
    this->whichTree = arg;
}
void BRANCH_CLASS::addWeight(unsigned int arg){
    this->weightTotal += arg;
}
void BRANCH_CLASS::decFruit(unsigned int arg){
    if(this->fruitTotal > 0)
    this->fruitTotal -= arg;
}
void BRANCH_CLASS::decHeight(unsigned int arg){
    if(this->growthHeight > 0)
    this->growthHeight -= arg;
}
void BRANCH_CLASS::decLength(unsigned int arg){
    if(this->branchLength > 0)
    this->branchLength -= arg;
}
void BRANCH_CLASS::decWeight(unsigned int arg){
   if(this->weightTotal > 0)
    this->weightTotal -= arg;
}
void BRANCH_CLASS::setNext(BRANCH_CLASS* nextptr){
    this->next = nextptr;
}
void BRANCH_CLASS::setPrev(BRANCH_CLASS* prevptr){
    this->prev = prevptr;
}
BRANCH_CLASS* BRANCH_CLASS::getPrev(){
    return this->prev;
}
BRANCH_CLASS * BRANCH_CLASS::getNext(void){
    return this->next;
}
unsigned int BRANCH_CLASS::getFruitsTotal(void){
    return this->fruitTotal;
}
unsigned int BRANCH_CLASS::getWeightsTotal(void){
    return this->weightTotal;
}
unsigned int BRANCH_CLASS::getHeight(void){
    return this->growthHeight;
}
unsigned int BRANCH_CLASS::getLength(void){
    return this->branchLength;
}
void BRANCH_CLASS::growthBranch(void) {
    this->branchLength++;
    if(this->head == NULL){
        this->head = new FRUIT_CLASS();
    }
    FRUIT_CLASS *tmp = this->head->getNext();
    while (tmp != NULL) {
        tmp->growthFruit();
        tmp = tmp->getNext();
    }
    if (this->branchLength % 2 == 0) {
       if(this->head->getNext() == NULL){
           this->head->setNext(new FRUIT_CLASS(this));
           this->last = this->head->getNext();
       }
       else{
           this->last->setNext(new FRUIT_CLASS(this));
           this->last->getNext()->setPrev(this->last);
           this->last = this->last->getNext();
       }
    }
    tmp = NULL;
}
void BRANCH_CLASS::fadeBranch(void) {
    if(this->branchLength > 0)
        this->branchLength--;
    if(this->head != NULL) {
        FRUIT_CLASS *tmp = this->head->getNext();
        FRUIT_CLASS *aux;
        if (tmp != NULL) {
            while (tmp != NULL) {
                aux = tmp;
                tmp = tmp->getNext();
                if (aux->getLength() > this->branchLength) {
                    if (aux->getPrev() != NULL && aux->getNext() != NULL) {
                        aux->getNext()->setPrev(aux->getPrev());
                        aux->getPrev()->setNext(aux->getNext());
                    }
                    else if(aux->getPrev() != NULL && aux->getNext() == NULL){
                        this->last = this->last->getPrev();
                        this->last->setNext(NULL);
                    }
                    else if (aux->getPrev() == NULL && aux->getNext() == NULL)
                        this->head->setNext(NULL);
                    else if (aux->getPrev() == NULL && aux->getNext() != NULL) {
                        this->head->setNext(this->head->getNext()->getNext());
                        this->head->setPrev(NULL);
                    }
                    delete aux;
                }
                else
                    aux->fadeFruit();
            }
        }
        tmp = NULL;
        aux = NULL;
    }
}
void BRANCH_CLASS::harvestBranch(unsigned int arg){
    FRUIT_CLASS* tmp = this->head->getNext();
    while(tmp != NULL){
        if(tmp->getWeight() >= arg)
            tmp->pluckFruit();
        tmp = tmp->getNext();
    }
    tmp = NULL;
}
void BRANCH_CLASS::cutBranch(unsigned int arg){
    if(arg < this->branchLength){
        this->branchLength = arg;
        if(this->head != NULL) {
            FRUIT_CLASS *tmp = this->head->getNext();
            FRUIT_CLASS *aux;
            while (tmp != NULL) {
                aux = tmp;
                tmp = tmp->getNext();
                if (aux->getLength() > arg) {
                    if (aux->getPrev() != NULL && aux->getNext() != NULL) {
                        aux->getNext()->setPrev(aux->getPrev());
                        aux->getPrev()->setNext(aux->getNext());
                    }
                    else if(aux->getPrev() != NULL && aux->getNext() == NULL){
                        this->last = this->last->getPrev();
                        this->last->setNext(NULL);
                    }
                    else if (aux->getPrev() == NULL && aux->getNext() == NULL)
                        this->head->setNext(NULL);
                    else if (aux->getPrev() == NULL && aux->getNext() != NULL) {
                        this->head->setNext(this->head->getNext()->getNext());
                        this->head->getNext()->setPrev(NULL);
                    }
                    delete aux;
                }
            }
            tmp = NULL;
        }
    }
}
FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int arg){
    FRUIT_CLASS* tmp = this->head->getNext();
    while(tmp != NULL && tmp->getLength() != arg){
            tmp = tmp->getNext();
    }
    return tmp;
}
TREE_CLASS* BRANCH_CLASS::getTreePointer(void){
    return this->whichTree;
}
