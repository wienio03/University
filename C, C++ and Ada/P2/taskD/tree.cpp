#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"
TREE_CLASS::TREE_CLASS(GARDEN_CLASS* parentGarden, unsigned int identifier){
    this->treeHeight = 0;
    this->branchAmount = 0;
    this->fruitAmount = 0;
    this->weightTotal = 0;
    this->treeIdentifier = identifier;
    this->whichGarden = parentGarden;
    this->next = NULL;
    this->prev = NULL;
    this->last = NULL;
    this->head = new BRANCH_CLASS();
    if(this->whichGarden != NULL)
        this->whichGarden->addTrees(1);
}
TREE_CLASS::TREE_CLASS(){
    this->treeHeight = 0;
    this->branchAmount = 0;
    this->weightTotal = 0;
    this->fruitAmount = 0;
    this->treeIdentifier = 0;
    this->head = NULL;
    this->whichGarden = NULL;
    this->next = NULL;
    this->prev = NULL;
    this->last = NULL;
}
TREE_CLASS::TREE_CLASS(unsigned int arg){
    this->treeHeight = 0;
    this->branchAmount = 0;
    this->weightTotal = 0;
    this->fruitAmount = 0;
    this->treeIdentifier = arg;
    this->head = NULL;
    this->whichGarden = NULL;
    this->next = NULL;
    this->prev = NULL;
    this->last = NULL;
}
TREE_CLASS::~TREE_CLASS(){
    this->next = NULL;
    this->prev = NULL;
    this->last = NULL;
    if(this->whichGarden != NULL)
        this->whichGarden->decTree(1);
    BRANCH_CLASS* tmp;
    if(head != NULL) {
        while (head->getNext() != NULL) {
            tmp = head->getNext();
            head->setNext(head->getNext()->getNext());
            delete tmp;
        }
        delete head;
    }
}
TREE_CLASS::TREE_CLASS(const TREE_CLASS& clonedTree){
    this->whichGarden = clonedTree.whichGarden;
    if(clonedTree.head != NULL) {
        this->head = new BRANCH_CLASS();
        if (clonedTree.head->getNext() == NULL) {
            this->head->setNext(NULL);
            this->head->setPrev(NULL);
            this->last = NULL;
        } else {
            BRANCH_CLASS *tmp = clonedTree.head->getNext();
            this->head->setNext(new BRANCH_CLASS(*tmp));
            this->head->getNext()->setPrev(NULL);
            BRANCH_CLASS *tmpThis = this->head->getNext();
            tmp = tmp->getNext();
            while (tmp != NULL) {
                tmpThis->setNext(new BRANCH_CLASS(*tmp));
                tmpThis->getNext()->setPrev(tmpThis);
                tmpThis = tmpThis->getNext();
                tmp = tmp->getNext();
            }
            this->last = tmpThis;
            this->last->setNext(NULL);
            tmp = this->head->getNext();
            while(tmp != NULL){
                tmp->setTree(this);
                tmp = tmp->getNext();
            }
        }
    }
    else
        this->head = NULL;
    this->treeHeight = clonedTree.treeHeight;
    this->branchAmount = clonedTree.branchAmount;
    this->fruitAmount = clonedTree.fruitAmount;
    this->weightTotal = clonedTree.weightTotal;
    this->treeIdentifier = clonedTree.treeIdentifier;
    this->next = NULL;
    this->prev = NULL;
}
unsigned int TREE_CLASS::getBranchesTotal(void){
    return this->branchAmount;
}
unsigned int TREE_CLASS::getFruitsTotal(void){
    return this->fruitAmount;
}
unsigned int TREE_CLASS::getWeightsTotal(void){
    return this->weightTotal;
};
unsigned int TREE_CLASS::getNumber(void){
    return this->treeIdentifier;
}
unsigned int TREE_CLASS::getHeight(void){
    return this->treeHeight;
}
void TREE_CLASS::growthTree(void){
    this->treeHeight++;
    if(this->head == NULL){
        this->head = new BRANCH_CLASS();
    }
    BRANCH_CLASS* tmp = head->getNext();
    while(tmp != NULL){
        tmp->growthBranch();
        tmp = tmp->getNext();
    }
    if(this->treeHeight % 3 == 0){
        if(head->getNext() == NULL){
            this->head->setNext(new BRANCH_CLASS(this, this->treeHeight));
            this->last = head->getNext();
        }
        else {
            this->last->setNext(new BRANCH_CLASS(this, this->treeHeight));
            this->last->getNext()->setPrev(this->last);
            this->last = this->last->getNext();
        }
    }
}
void TREE_CLASS::addWeight(unsigned int arg){
    this->weightTotal += arg;
}
void TREE_CLASS::fadeTree(void){
    if(this->treeHeight > 0)
        this->treeHeight--;
    BRANCH_CLASS* tmp = this->head->getNext();
    while(tmp != NULL){
        tmp->fadeBranch();
        tmp = tmp->getNext();
    }
    tmp = head->getNext();
    BRANCH_CLASS* aux;
    while(tmp != NULL){
        aux = tmp;
        tmp = tmp->getNext();
        if (aux->getHeight() > this->treeHeight) {
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

    }
}
void TREE_CLASS::harvestTree(unsigned int arg){
    BRANCH_CLASS* tmp = this->head->getNext();
    while(tmp != NULL){
        tmp->harvestBranch(arg);
        tmp = tmp->getNext();
    }
}
void TREE_CLASS::cutTree(unsigned int arg){
    if(arg < this->treeHeight) {
        this->treeHeight = arg;
        BRANCH_CLASS *tmp = this->head->getNext();
        BRANCH_CLASS *aux;
        while (tmp != NULL) {
            aux = tmp;
            tmp = tmp->getNext();
            if (aux->getHeight() > arg) {
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
    }
}
void TREE_CLASS::cloneBranch(BRANCH_CLASS* arg){
    BRANCH_CLASS* tmp = this->head->getNext();
    while(tmp != NULL){
        if(tmp->getLength() == 0){
            BRANCH_CLASS* replacement = new BRANCH_CLASS(*arg);
            replacement->setPrev(tmp->getPrev());
            replacement->setNext(tmp->getNext());
            replacement->setTree(this);
            replacement->setHeight(tmp->getHeight());
            this->branchAmount++;
            this->fruitAmount += replacement->getFruitsTotal();
            this->weightTotal += replacement->getWeightsTotal();
            if(this->getGardenPointer() != NULL) {
                //this->getGardenPointer()->addFruit(replacement->getFruitsTotal());
                //this->getGardenPointer()->addWeight(replacement->getWeightsTotal());
                this->getGardenPointer()->addBranches(1);
            }
            if(tmp->getPrev() != NULL)
                tmp->getPrev()->setNext(replacement);
            if(tmp->getNext() != NULL)
                tmp->getNext()->setPrev(replacement);
            if(head->getNext() == tmp){
                head->setNext(replacement);
            }
            delete tmp;
            break;
        }
        tmp = tmp->getNext();
    }
}
GARDEN_CLASS* TREE_CLASS::getGardenPointer(void){
    return this->whichGarden;
}
BRANCH_CLASS* TREE_CLASS::getBranchPointer(unsigned int arg){
    if(this->head != NULL) {
        BRANCH_CLASS *tmp = this->head->getNext();
        while (tmp != NULL) {
            if (tmp->getHeight() == arg)
                break;
            tmp = tmp->getNext();
        }
        return tmp;
    }
    return NULL;
}
void TREE_CLASS::setNext(TREE_CLASS* arg){
    this->next = arg;
}
void TREE_CLASS::setPrev(TREE_CLASS* arg){
    this->prev = arg;
}
void TREE_CLASS::decBranch(unsigned int arg){
    if(this->branchAmount > 0)
    this->branchAmount -= arg;
}
void TREE_CLASS::decFruit(unsigned int arg){
    if(this->fruitAmount > 0)
    this->fruitAmount -= arg;
}
void TREE_CLASS::decHeight(unsigned int arg){
    if(this->treeHeight > 0)
    this->treeHeight -= arg;
}
void TREE_CLASS::decWeight(unsigned int arg){
    if(this->weightTotal > 0)
    this->weightTotal -= arg;
}
void TREE_CLASS::addBranches(unsigned int arg){
    this->branchAmount += arg;
}
void TREE_CLASS::addHeight(unsigned int arg){
    this->treeHeight += arg;
}
void TREE_CLASS::addFruits(unsigned int arg){
    this->fruitAmount += arg;
}
void TREE_CLASS::setGarden(GARDEN_CLASS* arg){
    this->whichGarden = arg;
}
void TREE_CLASS::setIdentifier(unsigned int arg){
    this->treeIdentifier = arg;
}
TREE_CLASS* TREE_CLASS::getPrev(){
    return this->prev;
}
TREE_CLASS* TREE_CLASS::getNext() {
    return this->next;
}
