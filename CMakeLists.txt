cmake_minimum_required(VERSION 3.30)
project(ProjetoFinal)

set(CMAKE_CXX_STANDARD 14)

find_package(SQLite3 REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${SQLite3_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SQLite3_LIBRARIES})

add_executable(ProjetoFinal main.cpp
        DatabaseConnection.cpp
        DatabaseConnection.h
        TipoProduto.cpp
        TipoProduto.h
        Fluido.cpp
        Fluido.h
        Peca.cpp
        Peca.h
        Produto.cpp
        Produto.h
        Marca.cpp
        Marca.h
        TipoCarro.cpp
        TipoCarro.h
        Carro.cpp
        Carro.h
        Registro.cpp
        Registro.h
        Funcionario.cpp
        Funcionario.h
        Manutencao.cpp
        Manutencao.h
        Mensagem.cpp
        Mensagem.h
        TextToVoice.cpp
        TextToVoice.h
        KeyboardInput.cpp
        KeyboardInput.h
)
