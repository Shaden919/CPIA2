#include "uniqueList.hpp"

int main() {
    UniqueList list;
    list.add(1);
    list.add(1);
    list.add(2);
    list.add(3);
    list.print();
    list.remove(3);
    list.remove(6);
    list.print();
    return 0;
}