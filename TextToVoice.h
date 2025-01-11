//
// Created by viniciuskl on 10/01/25.
//

#ifndef TEXTTOVOICE_H
#define TEXTTOVOICE_H

#include <espeak/speak_lib.h>
#include <iostream>
#include <string>

class TextToVoice {
public:
    static void speak(const std::string& text);
};



#endif //TEXTTOVOICE_H
