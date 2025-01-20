#include "KeyboardInput.h"
#include <iostream>

#ifdef LINUX
void KeyboardInput::enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios raw = orig_termios;

    // Desativa o modo canônico e o echo
    raw.c_lflag &= ~(ICANON | ECHO);

    // Define o timeout de leitura
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void KeyboardInput::disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}
#endif

KeyboardInput::KeyboardInput() {
    #ifdef LINUX
    enableRawMode();
    #endif
}

KeyboardInput::~KeyboardInput() {
    #ifdef LINUX
    disableRawMode();
    #endif
}

bool KeyboardInput::kbhit() {
    #ifdef WINDOWS
    return _kbhit() != 0;
    #else
    fd_set fds;
    struct timeval tv = {0, 0};

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) == 1;
    #endif
}

int KeyboardInput::getch() {
    #ifdef WINDOWS
    return _getch();
    #else
    if (kbhit()) {
        char c;
        if (read(STDIN_FILENO, &c, 1) == 1) {
            if (c == '\x1b') {  // ESC ou tecla especial
                char seq[2];
                if (read(STDIN_FILENO, &seq[0], 1) != 1) return '\x1b';
                if (read(STDIN_FILENO, &seq[1], 1) != 1) return '\x1b';

                if (seq[0] == '[') {
                    switch(seq[1]) {
                        case 'A': return 128; // Seta para cima
                        case 'B': return 129; // Seta para baixo
                        case 'C': return 130; // Seta para direita
                        case 'D': return 131; // Seta para esquerda
                    }
                }
                return '\x1b';
            }
            return c;
        }
    }
    return -1;
    #endif
}

std::string KeyboardInput::getTeclaDescricao(int tecla) {
    switch (tecla) {
        case 27: return "ESC";
        case 128: return "SETA CIMA";
        case 129: return "SETA BAIXO";
        case 130: return "SETA DIREITA";
        case 131: return "SETA ESQUERDA";
        default:
            if (tecla >= 32 && tecla <= 126) {
                return std::string(1, (char)tecla) + " (ASCII: " + std::to_string(tecla) + ")";
            } else {
                return "Código: " + std::to_string(tecla);
            }
    }
}