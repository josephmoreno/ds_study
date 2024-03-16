template <typename T> void printVec(std::vector<T> v0) {
    unsigned int i;

    for(i = 0; i < v0.size() - 1; ++i) {
        std::cout << v0[i] << ", ";
    }

    std::cout << v0[i] << std::endl;
}