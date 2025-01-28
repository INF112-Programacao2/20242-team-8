//
// Created by viniciuskl on 27/01/25.
//

#ifndef ACESSIBILIDADE_H
#define ACESSIBILIDADE_H
#include <string>

class Acessibilidade {

private:

    static bool aciona;
    static bool iniciado;

public:

    explicit Acessibilidade(bool _aciona);

    static void colocaTexto(const std::string &texto);
    static bool getAciona();
    static void setAciona(bool _aciona);
    ~Acessibilidade();

};

#endif //ACESSIBILIDADE_H
