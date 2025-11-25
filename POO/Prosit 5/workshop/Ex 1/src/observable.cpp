#include "observable.hpp"
#include <algorithm>

Observable::~Observable() {}
void Observable::notify() {
    for (Observers* obs : follower) {
        obs->update(this);
    }
}
int Observable::subscribe(Observers* obs) {
    follower.push_back(obs);
    return 0;
}
int Observable::unsuscribe(Observers* obs) {
    follower.erase(std::remove(follower.begin(), follower.end(), obs), follower.end());
    return 0;
}