#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"
GARDEN_CLASS::GARDEN_CLASS(){
    this->head = new TREE_CLASS();
    this->fruitTotal = 0;
    this->branchTotal = 0;
    this->treesTotal = 0;
    this->weightTotal = 0;
    this->gapCount = 0;
    this->last = NULL;
}
GARDEN_CLASS::~GARDEN_CLASS(){
    TREE_CLASS* tmp;
    while(head->getNext() != NULL){
        tmp = head->getNext();
        head->setNext(head->getNext()->getNext());
        delete tmp;
    }
    delete head;
}
unsigned int GARDEN_CLASS::getTreesTotal(void){
    return this->treesTotal;
}
unsigned int GARDEN_CLASS::getBranchesTotal(void){
    return this->branchTotal;
}
unsigned int GARDEN_CLASS::getFruitsTotal(void){
    return this->fruitTotal;
}
unsigned int GARDEN_CLASS::getWeightsTotal(void){
    return this->weightTotal;
}
void GARDEN_CLASS::addBranches(unsigned int arg){
    this->branchTotal += arg;
}
void GARDEN_CLASS::addFruit(unsigned int arg){
    this->fruitTotal += arg;
}
void GARDEN_CLASS::addWeight(unsigned int arg){
    this->weightTotal += arg;
}
void GARDEN_CLASS::addTrees(unsigned int arg){
    this->treesTotal += arg;
}
void GARDEN_CLASS::decBranch(unsigned int arg){
    if(this->branchTotal > 0)
    this->branchTotal -= arg;
}
void GARDEN_CLASS::decFruit(unsigned int arg){
    if(this->fruitTotal > 0)
    this->fruitTotal -= arg;
}
void GARDEN_CLASS::decWeight(unsigned int arg){
    if(this->weightTotal > 0)
    this->weightTotal -= arg;
}
void GARDEN_CLASS::decTree(unsigned int arg){
    if(this->treesTotal > 0)
    this->treesTotal -= arg;
}
void GARDEN_CLASS::plantTree(void){
    if(this->head->getNext() == NULL){
        this->head->setNext(new TREE_CLASS(this, 0));
        this->last = this->head->getNext();
    }
    else{
        if(gapCount > 0){
            TREE_CLASS* tmp = this->head->getNext();
            if(tmp->getNext() == NULL) {
                if (tmp->getNumber() > 0) {
                    tmp->setPrev(new TREE_CLASS(this, 0));
                    tmp->getPrev()->setNext(tmp);
                    this->head->setNext(tmp->getPrev());
                    gapCount--;
                }
                else if(tmp->getNumber() == 0){
                    tmp->setNext(new TREE_CLASS(this, 1));
                    tmp->getNext()->setPrev(tmp);
                }
            }
            else if(tmp->getNext() != NULL && tmp->getNumber() > 0){
                tmp->setPrev(new TREE_CLASS(this, 0));
                tmp->getPrev()->setNext(tmp);
                this->head->setNext(tmp->getPrev());
                gapCount--;
            }
            else {
                while (tmp->getNext() != NULL) {
                    if(tmp->getNext()->getNumber() - tmp->getNumber() > 1){
                        TREE_CLASS* newTree = new TREE_CLASS(this, tmp->getNumber() + 1);
                        newTree->setNext(tmp->getNext());
                        newTree->setPrev(tmp->getPrev());
                        tmp->getNext()->setPrev(newTree);
                        tmp->setNext(newTree);
                        gapCount--;
                        break;
                    }
                    tmp = tmp->getNext();
                }
            }
            tmp = NULL;
        }
        else{
            this->last->setNext(new TREE_CLASS(this ,this->last->getNumber() + 1));
            this->last->getNext()->setPrev(this->last);
            this->last = this->last->getNext();
        }
    }
}
void GARDEN_CLASS::extractTree(unsigned int arg){
    if(arg <= this->last->getNumber()) {
        if(this->treesTotal == 1){
            delete this->head->getNext();
            this->head->setNext(NULL);
            return;
        }
        else if(this->last->getNumber() == arg){
            this->last = this->last->getPrev();
            delete this->last->getNext();
            this->last->setNext(NULL);
            return;
        }
        else if(this->head->getNext()->getNumber() == arg){
            this->head->setNext(head->getNext()->getNext());
            delete head->getNext()->getPrev();
            this->head->getNext()->setPrev(NULL);
            this->gapCount++;
            return;
        }
        else {
            TREE_CLASS* tmp = this->head->getNext();
            while(tmp != NULL) {
                if(tmp->getNumber() == arg) {
                    tmp->getNext()->setPrev(tmp->getPrev());
                    tmp->getPrev()->setNext(tmp->getNext());
                    delete tmp;
                    this->gapCount++;
                    return;
                }
                tmp = tmp->getNext();
            }
        }
    }
}
    /*if(arg <= this->last->getNumber()) {
        if (head->getNext()->getNumber() == arg) {
            if (head->getNext()->getNext() == NULL) {
                delete head->getNext();
                head->setNext(NULL);
                this->last = NULL;
            } else {
                head->setNext(head->getNext()->getNext());
                delete head->getNext()->getPrev();
                head->getNext()->setPrev(NULL);
                    this->last = head->getNext();
                gapCount++;
            }
        } else if (this->last->getNumber() == arg) {
            this->last->getPrev()->setNext(NULL);
            delete this->last;
        } else {
            TREE_CLASS *tmp = this->last;
            while (tmp != NULL) {
                if (tmp->getNumber() == arg) {
                    if (tmp->getNext() == NULL) {
                        tmp->getPrev()->setNext(NULL);
                        this->last = tmp->getPrev();
                        delete tmp;
                        break;
                    } else {
                        tmp->getNext()->setPrev(tmp->getPrev());
                        tmp->getPrev()->setNext(tmp->getNext());
                        delete tmp;
                        break;
                    }
                }
                tmp = tmp->getPrev();
            }
            gapCount++;
        }
    }
     */
void GARDEN_CLASS::fadeGarden(void){
    TREE_CLASS* tmp = this->head->getNext();
    while(tmp != NULL){
        tmp->fadeTree();
        tmp = tmp->getNext();
    }
}
void GARDEN_CLASS::growthGarden(void){
    TREE_CLASS* tmp = this->head->getNext();
    while(tmp != NULL){
        tmp->growthTree();
        tmp = tmp->getNext();
    }
}
void GARDEN_CLASS::harvestGarden(unsigned int arg){
    TREE_CLASS* tmp = this->head->getNext();
    while(tmp != NULL){
        tmp->harvestTree(arg);
        tmp = tmp->getNext();
    }
}
TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int arg){
    if(this->head != NULL) {
        TREE_CLASS *tmp = this->head->getNext();
        while (tmp != NULL) {
            if (tmp->getNumber() == arg)
                break;
            tmp = tmp->getNext();
        }
        return tmp;
    }
    return NULL;
}
void GARDEN_CLASS::cloneTree(unsigned int arg){
    if(this->head != NULL) {
        TREE_CLASS *tmp = getTreePointer(arg);
        TREE_CLASS *aux = tmp;
        if (aux != NULL) {
            tmp = this->head->getNext();
            if (tmp->getNext() == NULL) {
                if (tmp->getNumber() > 0) {
                    this->head->getNext()->setPrev(new TREE_CLASS(*aux));
                    this->head->getNext()->getPrev()->setGarden(this);
                    this->head->getNext()->getPrev()->setNext(head->getNext());
                    this->head->getNext()->getPrev()->setIdentifier(0);
                    this->head->setNext(this->head->getNext()->getPrev());
                    gapCount--;
                } else {
                    this->head->getNext()->setNext(new TREE_CLASS(*aux));
                    this->head->getNext()->getNext()->setGarden(this);
                    this->head->getNext()->getNext()->setPrev(this->head->getNext());
                    this->head->getNext()->getNext()->setIdentifier(this->head->getNext()->getNumber() + 1);
                }
            }
            else if(this->head->getNext()->getNumber() > 0){
                this->head->getNext()->setPrev(new TREE_CLASS(*aux));
                this->head->getNext()->getPrev()->setNext(this->head->getNext());
                this->head->setNext(this->head->getNext()->getPrev());
                this->head->getNext()->setIdentifier(0);
                this->head->setPrev(NULL);
                gapCount--;
            }
            else {
                while (tmp->getNext() != NULL) {
                    if (tmp->getNext()->getNumber() - tmp->getNumber() > 1) {
                        TREE_CLASS *newTree = new TREE_CLASS(*aux);
                        newTree->setNext(tmp->getNext());
                        newTree->setPrev(tmp);
                        newTree->setIdentifier(tmp->getNumber() + 1);
                        tmp->getNext()->setPrev(newTree);
                        tmp->setNext(newTree);
                        newTree->setGarden(this);
                        gapCount--;
                        break;
                    } else
                        tmp = tmp->getNext();
                }
                if (tmp->getNext() == NULL) {
                    TREE_CLASS *newTree = new TREE_CLASS(*aux);
                    newTree->setNext(NULL);
                    newTree->setPrev(tmp);
                    tmp->setNext(newTree);
                    newTree->setIdentifier(tmp->getNumber() + 1);
                    newTree->setGarden(this);
                    this->last = newTree;
                }
            }
            this->addBranches(aux->getBranchesTotal());
            this->addFruit(aux->getFruitsTotal());
            this->addTrees(1);
            this->addWeight(aux->getWeightsTotal());
        }
    }
}
