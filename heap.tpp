// Implemented template code shouldn't be in .cpp file.
// Sources:
// https://stackoverflow.com/questions/1111440/undefined-reference-error-for-template-method
// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

// Setter
template <typename T> void Heap<T>::setVec(std::vector<T> v0) {
    this->v0 = v0;
}

// Getters
template <typename T> std::vector<T> Heap<T>::getVec() {
    return this->v0;
}

template <typename T> T Heap<T>::getRoot() {
    return this->v0[0];
}

template <typename T> int Heap<T>::parent(int i) {
    return (i - 1) / 2;
}

template <typename T> int Heap<T>::lChild(int i) {
    return (2 * i) + 1;
}

template <typename T> int Heap<T>::rChild(int i) {
    return (2 * i) + 2;
}

template <typename T> int Heap<T>::lastNonLeafNode() {
    return (this->v0.size() / 2) - 1;
}

// Modifiers
template <typename T> void Heap<T>::swapNodes(int i, int j) {
    T temp = this->v0[i];
    this->v0[i] = this->v0[j];
    this->v0[j] = temp;
}

template <typename T> void Heap<T>::heapify(int i) {
    int l = this->lChild(i);
    int r = this->rChild(i);
    int cur = i;

    if ((l < this->v0.size()) && this->compareNodes(cur, l))
        cur = l;

    if ((r < this->v0.size()) && this->compareNodes(cur, r))
        cur = r;

    if (cur != i) {
        this->swapNodes(cur, i);
        this->heapify(cur);
    }
}

template <typename T> void Heap<T>::initHeap() {
    for(int i = this->lastNonLeafNode(); i >= 0; --i)
        this->heapify(i);
}

template <typename T> void Heap<T>::insVal(T val) {
    this->v0.push_back(val);

    int i = this->v0.size() - 1;

    while((i > 0) && this->compareNodes(this->parent(i), i)) {
        this->swapNodes(this->parent(i), i);
        i = this->parent(i);
    }
}

template <typename T> T Heap<T>::popVal(int i) {
    T ret = this->v0[i];
    this->v0[i] = this->v0[this->v0.size() - 1];
    this->v0.pop_back();

    this->heapify(i);

    return(ret);
}