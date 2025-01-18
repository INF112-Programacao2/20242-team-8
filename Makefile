# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -Wextra -std=c++17 -g -O2

# Bibliotecas necessárias
LIBS = -lespeak -lsqlite3

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
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Regra para compilar arquivos fonte em objetos
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpa os arquivos gerados (executável e objetos)
clean:
	$(RM) $(OBJS) $(TARGET)

# Executa o programa após a compilação
run: all
	$(EXEC)
