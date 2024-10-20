#include <iostream>
#include "LinkedList.hpp"

void printInt(const int& value) {
    std::cout << "Value: " << value << std::endl;
}

int main() {
    LinkedList<int> list;

    list.add(1);
    list.add(2);
    list.add(3);

    std::cout << "ForEach example:" << std::endl;
    list.forEach(printInt);

    std::cout << "Removing element 2..." << std::endl;
    list.remove(2);

    std::cout << "ForEach after removal:" << std::endl;
    list.forEach(printInt);

    return 0;
}
