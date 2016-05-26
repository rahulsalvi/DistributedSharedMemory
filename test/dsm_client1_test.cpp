#include <iostream>
#include <thread>
#include "../src/Client/DSMClient.h"

int main() {
    dsm::Client _client("server1", 0);
    _client.registerLocalBuffer("remote0", 4);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    _client.setLocalBufferContents("remote0", "start");
    std::string input;
    while (input != "kill") {
        std::getline(std::cin, input);
        _client.setLocalBufferContents("remote0", input.data());
    }
}
