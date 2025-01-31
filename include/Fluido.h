//
// Created by viniciuskl on 06/01/25.
//

#ifndef FLUIDO_H
#define FLUIDO_H
#include "TipoProduto.h"


class Fluido : public TipoProduto{
private:
    double volume_minimo;
    char unidade;
public:
    Fluido(std::string _nome, double _volume_minimo, char _unidade);
    void set_volume_minimo(double num);
    void set_unidade(char c);

    virtual void obterDados() override;
    double get_volume_minimo() const;

    char get_unidade() const;

    ~Fluido();
};



#endif //FLUIDO_H
