//
// Created by viniciuskl on 10/01/25.
//

#include "../include/TextToVoice.h"
#include <iostream>
#include <string>

bool TextToVoice::initialized = false;
std::mutex TextToVoice::speakMutex;
bool TextToVoice::isSpeaking = false;

bool TextToVoice::initialize() {
    if (initialized) return true;

    std::lock_guard<std::mutex> lock(speakMutex);

    if (espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 0, NULL, 0) == -1) {
        std::cerr << "Falha ao inicializar" << std::endl;
        return false;
    }

    if (espeak_SetVoiceByName("pt") != EE_OK) {
        std::cerr << "Falha ao colocar no portugue" << std::endl;
        espeak_Terminate();
        return false;
    }

    initialized = true;
    return true;
}

void TextToVoice::cleanup() {
    if (!initialized) return;

    std::lock_guard<std::mutex> lock(speakMutex);

    if (isSpeaking) {
        espeak_Cancel();
    }

    espeak_Terminate();
    initialized = false;
}

bool TextToVoice::speak(const std::string& text) {
    if (!initialized && !initialize()) {
        std::cout << text << std::endl;
        return false;
    }

    std::lock_guard<std::mutex> lock(speakMutex);

    if (isSpeaking) {
        espeak_Cancel();
    }

    isSpeaking = true;

    espeak_Synth(text.c_str(), text.size() + 1, 0, POS_CHARACTER, 0,
                 espeakCHARS_AUTO, NULL, NULL);

    espeak_Synchronize();
    isSpeaking = false;
    return true;
}