#include <string.h>
#include <iostream>

int main(int argc, char** argv) {
    bool multiplayer = true, sameKeyboard = true;
    
    if (argc == 1) {
        std::cout << "No arguments entered, starting multiplayer same keyboard" << std::endl;
    } else {
        for (size_t i = 0; i < argc; i++) {
            if (strcmp(argv[i], "-s") == 0) {
                sameKeyboard = false;
            }
        }
    }

    // Todo: replace with application class declaration
    std::cout << "Multiplayer: " << multiplayer << " Same KeyBoard: " << sameKeyboard << std::endl;

    return 0;
}