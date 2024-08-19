# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++14 -Iinclude -Wall -Wextra -g

# Diretórios
SRC_DIR = ../src
OBJ_DIR = ../obj
BIN_DIR = ../bin

# Arquivo executável final
TARGET = $(BIN_DIR)/jogosTabuleiro

# Arquivos de origem
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Arquivos objeto correspondentes
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Regra padrão: compilar tudo
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar arquivos .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Limpar os arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Limpar tudo, incluindo o executável
cleanall: clean
	rm -f $(TARGET)

# Recompilar forçadamente
rebuild: cleanall all

.PHONY: all clean cleanall rebuild
