#include "avatar.hpp"
#include "avatarState.hpp"
#include "happy.hpp"
#include "sad.hpp"
#include "angry.hpp"
#include "grumpy.hpp"
#include "glad.hpp"

#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

int main() {
    bool run = true;
    AvatarState* StartState;
    StartState = new Happy;
    Avatar avatar(StartState);
    while (run)
    {
        avatar.run();
        std::this_thread::sleep_for (std::chrono::seconds(5));
    }
    return 0;
}