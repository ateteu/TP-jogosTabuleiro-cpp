# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
BIN_DIR = .

# Nome do executável
TARGET = $(BIN_DIR)/jogo.exe

# Coleta todos os arquivos .cpp em SRC_DIR
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Gera a lista de arquivos .o a partir dos .cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Regras de compilação
all: $(TARGET)

# Regra para linkar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar os .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	del /Q $(OBJ_DIR)\*.o $(TARGET)

distclean: clean
	del /Q $(TARGET)

mrproper: distclean
	rd /S /Q $(OBJ_DIR)
