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

