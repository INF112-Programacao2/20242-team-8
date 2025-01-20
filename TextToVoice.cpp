//
// Created by viniciuskl on 10/01/25.
//

#include "TextToVoice.h"
#include <iostream>
#include <string>

// Função que converte texto em fala usando a API do eSpeak
void TextToVoice::speak(const std::string& text) {
    // Inicializa o eSpeak para reprodução de áudio.
    // Parâmetros:
    // - AUDIO_OUTPUT_PLAYBACK: indica que a saída será reproduzida pelo alto-falante.
    // - 0: tamanho do buffer de áudio em milissegundos (0 usa o padrão interno).
    // - NULL: diretório de idiomas personalizado (NULL indica que o padrão será usado).
    // - 0: opções adicionais (não usamos nenhuma).
    if (espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 0, NULL, 0) == -1) {
        std::cerr << "Falha ao inicializar o eSpeak." << std::endl;
        return;  // Encerra a função em caso de erro de inicialização
    }

    // Configura a voz para português do Brasil.
    // A função espeak_SetVoiceByName recebe o nome do idioma como string.
    // Retorna EE_OK (0) se a configuração for bem-sucedida.
    if (espeak_SetVoiceByName("pt") != EE_OK) {
        std::cerr << "Falha ao configurar a voz para português do Brasil." << std::endl;
        return;  // Encerra a função em caso de falha ao configurar o idioma
    }

    // Converte o texto passado como parâmetro em áudio.
    // Parâmetros:
    // - text.c_str(): retorna o ponteiro para os caracteres da string (char*).
    // - text.size() + 1: comprimento do texto, incluindo o caractere nulo de término ('\0').
    // - 0: início da fala (0 indica que a reprodução começa no início do texto).
    // - POS_CHARACTER: indica que a posição inicial está em caracteres.
    // - 0: velocidade adicional da fala (0 usa a velocidade padrão do eSpeak).
    // - espeakCHARS_AUTO: permite que o eSpeak detecte automaticamente o tipo de codificação (ASCII ou UTF-8).
    // - NULL: ponteiro para identificador de evento de fala (não usado aqui).
    // - NULL: ponteiro para dados do usuário (não usado aqui).
    espeak_Synth(text.c_str(), text.size() + 1, 0, POS_CHARACTER, 0, espeakCHARS_AUTO, NULL, NULL);

    // Aguarda até que toda a reprodução do áudio seja concluída antes de continuar.
    espeak_Synchronize();
}