#include "uniqueList.hpp"
#include <algorithm>
#include <iostream>

UniqueList::UniqueList() {}
UniqueList::~UniqueList() {}
bool UniqueList::hasValue(int val) const {
    auto it = dico.find(val);
    if ( it != dico.end()) return it->second; 
    return false;   
}
bool UniqueList::add(int val) {
    auto it = dico.find(val);
    if ( it != dico.end() && it->second == true) return false; 
    dico.insert(make_pair(val,true));
    list.push_back(val);
    return true;
}
bool UniqueList::remove(int val) {
    auto it = dico.find(val);
    if ( it != dico.end()) {
        if (it->second == true)
        {
            list.erase(std::remove(list.begin(), list.end(), val), list.end());
            it->second = false;
            return true;
        }
        return false;
    }
    return false;
}
void UniqueList::print() const {
    std::cout << "[";
    for (int i = 0; i < list.size() - 1; i++)
    {
       std::cout << list[i] << ",";
    }
    std::cout << list[list.size() - 1] << "]\n";
}