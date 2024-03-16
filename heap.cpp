#include "ds0.hpp"

// Max Int Heap
bool MaxIntHeap::compareNodes(int i, int j) {
    return(this->getVec()[i] < this->getVec()[j]);
}

MaxIntHeap::MaxIntHeap(std::vector<int> v0) {
    this->setVec(v0);
    this->initHeap();
}

// Min Int Heap
bool MinIntHeap::compareNodes(int i, int j) {
    return(this->getVec()[i] > this->getVec()[j]);
}

MinIntHeap::MinIntHeap(std::vector<int> v0) {
    this->setVec(v0);
    this->initHeap();
}