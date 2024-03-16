#include <vector>

// === START Heap ===
template <typename T> class Heap {
private:
    std::vector<T> v0;
public:
    // Setter
    void setVec(std::vector<T> v0);

    // Getters
    std::vector<T> getVec();
    
    T getRoot();
    int parent(int i);
    int lChild(int i);
    int rChild(int i);
    int lastNonLeafNode();
    virtual bool compareNodes(int i, int j) = 0;    // Use this for comparison between nodes.

    // Modifiers
    void swapNodes(int i, int j);
    void heapify(int i);
    void initHeap();
    void insVal(T val);
    T popVal(int i);
};

class MaxIntHeap : public Heap<int> {
public:
    bool compareNodes(int i, int j);
    MaxIntHeap(std::vector<int> v0);
};

class MinIntHeap : public Heap<int> {
public:
    bool compareNodes(int i, int j);
    MinIntHeap(std::vector<int> v0);
};

#include "heap.tpp"
// === END Heap ===