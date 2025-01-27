//
// Created by viniciuskl on 10/01/25.
//

#ifndef TEXTTOVOICE_H
#define TEXTTOVOICE_H

#include <espeak/speak_lib.h>
#include <iostream>
#include <string>
#include <mutex>

class TextToVoice {
    public:
        static bool initialize();
        static void cleanup();
        static bool speak(const std::string& text);
        static bool isInitialized() { return initialized; }

    private:
        static bool initialized;
        static std::mutex speakMutex;
        static bool isSpeaking;
};



#endif //TEXTTOVOICE_H
