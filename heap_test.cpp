#include <iostream>
#include "ds0.hpp"
#include "general.tpp"

int main(int argc, char** argv) {
    // MaxIntHeap test
    std::vector<int> v0 = {2, 5, 1, 3, 9, 8, 7, 4, 6};

    MaxIntHeap max_ih = MaxIntHeap(v0);
    max_ih.insVal(-5);
    max_ih.insVal(-1);

    std::cout << "max_ih heap vector = "; printVec(max_ih.getVec());

    v0.assign({});
    while(max_ih.getVec().size() > 0) {
        std::cout << "root = " << max_ih.getRoot() << std::endl;

        int temp = max_ih.popVal(0);
        v0.insert(v0.begin(), temp);
    }

    std::cout << "heap sort using max_ih = "; printVec(v0);
    std::cout << std::endl;

    // MinIntHeap test
    std::vector<int> v1 = {2, 5, 1, 3, 9, 8, 7, 4, 6};

    MinIntHeap min_ih = MinIntHeap(v1);

    std::cout << "min_ih heap vector = "; printVec(min_ih.getVec());

    v1.assign({});
    while(min_ih.getVec().size() > 0) {
        std::cout << "root = " << min_ih.getRoot() << std::endl;

        int temp = min_ih.popVal(0);
        v1.push_back(temp);
    }

    std::cout << "heap sort using min_ih = "; printVec(v1);
    std::cout << std::endl;

    return(0);
}