# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -Wextra -std=c++17 -g -O2

# Diretórios onde o compilador vai procurar os arquivos de cabeçalho
INCLUDES = -I"D:\Programação\Projetos_C++\Trabalhos\TPFinal\20242-team-8-master"

# Bibliotecas necessárias
LIBS = -lespeak -L"D:\Programação\Projetos_C++\Trabalhos\TPFinal\20242-team-8-master" -lsqlite3

# Nome do executável
TARGET = programa

# Busca automaticamente todos os arquivos .cpp no diretório atual
SRCS = $(wildcard *.cpp)

# Gera os nomes dos arquivos objeto correspondentes
OBJS = $(SRCS:.cpp=.o)

# Verifica o sistema operacional
RM = rm -f
ifeq ($(OS),Windows_NT)
    RM = del /Q
    EXEC = $(TARGET).exe
else
    EXEC = ./$(TARGET)
endif

# Regra padrão: compilar o programa
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LIBS)

# Regra para compilar arquivos fonte em objetos
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Limpa os arquivos gerados (executável e objetos)
clean:
	$(RM) $(OBJS) $(TARGET)

# Executa o programa após a compilação
run: all
	$(EXEC)