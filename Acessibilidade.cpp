//
// Created by viniciuskl on 27/01/25.
//
#include <iostream>
#include "Acessibilidade.h"
#include "TextToVoice.h"

bool Acessibilidade::aciona;
bool Acessibilidade::iniciado = false;

Acessibilidade::Acessibilidade(const bool _aciona) {
    if (!iniciado) {
        aciona = _aciona;
        if (aciona) {
            // Initialize text-to-speech if accessibility is enabled
            TextToVoice::initialize();
        }
        iniciado = true;
    }
}

void Acessibilidade::colocaTexto(const std::string &texto) {
    std::cout << texto;

    if (getAciona()) {
        // If text-to-speech fails, the text will still be printed to console
        TextToVoice::speak(texto);
    }
}

// Add cleanup in destructor or shutdown method
Acessibilidade::~Acessibilidade() {
    if (iniciado) {
        TextToVoice::cleanup();
    }
}

bool Acessibilidade::getAciona() {
    return aciona;
}

void Acessibilidade::setAciona(const bool _aciona) {
    aciona = _aciona;
}