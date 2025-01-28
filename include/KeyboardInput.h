#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include <string>

#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>
    #define WINDOWS
#else
    #include <termios.h>
    #include <unistd.h>
    #include <sys/select.h>
    #include <stdio.h>
    #define LINUX
#endif

class KeyboardInput {
private:
#ifdef LINUX
    struct termios orig_termios;
    void enableRawMode();
    void disableRawMode();
#endif

public:
    KeyboardInput();
    ~KeyboardInput();
    bool kbhit();
    int getch();
    std::string getTeclaDescricao(int tecla);
};

#endif // KEYBOARD_INPUT_H