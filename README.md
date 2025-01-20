TIME 8 - 2024

OS COMANDOS ABAIXO SÃO PARA LINUX

Requisitos: suporte ao SQLite
  -> sudo apt update
     sudo apt install sqlite3
     sqlite3 --version (VERIFICA SE A INSTALAÇÃO FOI BEM SUCEDIDA)
     sudo apt install sqlitebrowser

Obs: Para recurso de acessibilidade:
  .ESpeak (C++):
    -> sudo apt update
       sudo apt install espeak
       sudo apt install libespeak-dev
       sudo apt install espeak-ng-data

Para compilação: g++ *.cpp -lespeak -lsqlite3

OU 

make -> make run (se tiver o make e mingw(suporte ao g++) instalado)


WINDOWS:
------------------------------------------------------------------------------------------------------------
1. Baixando o eSpeak NG para Windows
A versão mais recente do eSpeak, chamada eSpeak NG, pode ser obtida diretamente do repositório GitHub. Siga estas etapas:

Acesse o repositório do eSpeak NG no GitHub:
eSpeak NG no GitHub

Vá até a seção de releases:
Releases do eSpeak NG

Encontre a versão mais recente (normalmente com a tag vX.Y.Z) e baixe o arquivo compactado Windows binaries. O arquivo será algo como espeak-ng-X.Y.Z-win32.zip ou similar.

Extraia o conteúdo do arquivo ZIP para um diretório de sua escolha.

2. Instalando o eSpeak NG no Windows
Após extrair o arquivo, você encontrará a pasta contendo os arquivos binários e cabeçalhos do eSpeak.

O diretório geralmente terá a seguinte estrutura:

bin/ (contém os executáveis, como espeak-ng.exe)
include/ (contém os cabeçalhos, como speak_lib.h)
lib/ (contém as bibliotecas de link, como espeak-ng.dll)
3. Configurando no Visual Studio Code
Depois de ter extraído o eSpeak NG, você pode configurar o Visual Studio Code para encontrar os arquivos de cabeçalho e biblioteca.

Atualize o includePath:
No arquivo c_cpp_properties.json, adicione o caminho para o diretório include do eSpeak NG.

Exemplo:

json
Copiar
Editar
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:/path/to/espeak-ng/include"  // Substitua pelo caminho correto
            ],
            "defines": [],
            "compilerPath": "C:/path/to/your/compiler",  // Caminho do compilador
            "intelliSenseMode": "windows-gcc-x64",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "browse": {
                "limitSymbolsToIncludedHeaders": true
            }
        }
    ],
    "version": 4
}
Configuração do Linker:
Adicione o diretório lib ao caminho do linker e vincule a biblioteca espeak-ng ao seu projeto. Caso esteja usando o MinGW, o comando de compilação pode ser algo como:

bash
Copiar
Editar
g++ -o my_program main.cpp -L"C:/path/to/espeak-ng/lib" -lespeak-ng
Certifique-se de substituir "C:/path/to/espeak-ng/lib" pelo diretório correto onde as bibliotecas estão localizadas.

DLL no PATH:
Certifique-se de que o arquivo espeak-ng.dll esteja no mesmo diretório que o seu executável ou no diretório especificado no PATH do sistema. Caso contrário, o programa não conseguirá carregar a biblioteca durante a execução.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1. Baixando o SQLite3 para Windows
Acesse o site oficial do SQLite:
Vá para a página de downloads do SQLite:
SQLite Download Page

Baixe os arquivos necessários:
Na seção "Precompiled Binaries for Windows", você verá as opções de download. Para Windows, baixe os seguintes arquivos:

SQLite DLL:
sqlite-dll-win32-x86-*.zip (se você estiver usando uma arquitetura de 32 bits)
sqlite-dll-win64-x86-*.zip (se você estiver usando uma arquitetura de 64 bits)
SQLite Command-Line Tools (opcional, mas útil para testar diretamente):
sqlite-tools-win32-x86-*.zip ou sqlite-tools-win64-x86-*.zip (dependendo de sua arquitetura).
Descompacte os arquivos:

Extraia os arquivos ZIP que você baixou em uma pasta de sua escolha. Você verá o arquivo sqlite3.dll (biblioteca) e sqlite3.exe (ferramenta de linha de comando).
2. Configuração no Windows
Adicionar ao PATH (opcional, mas recomendado): Para facilitar o uso do SQLite em qualquer lugar no terminal, adicione o diretório onde você extraiu o sqlite3.exe e sqlite3.dll ao PATH do sistema.

Passo 1: Clique com o botão direito em "Este PC" ou "Computador" e selecione "Propriedades".
Passo 2: Clique em "Configurações avançadas do sistema".
Passo 3: Na janela de "Propriedades do Sistema", clique em "Variáveis de ambiente".
Passo 4: Na seção "Variáveis do sistema", encontre a variável Path e clique em "Editar".
Passo 5: Adicione o caminho completo da pasta onde você extraiu os arquivos sqlite3.exe e sqlite3.dll à variável Path. Por exemplo, se você extraiu os arquivos em C:\sqlite, adicione C:\sqlite ao PATH.
Passo 6: Clique em "OK" para confirmar as alterações.
Verificar se o SQLite3 foi instalado corretamente: Abra o terminal (Prompt de Comando ou PowerShell) e digite o seguinte comando para verificar se o SQLite3 está acessível:

bash
Copiar
Editar
sqlite3 --version
Se tudo estiver configurado corretamente, você verá a versão do SQLite3 sendo exibida.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
