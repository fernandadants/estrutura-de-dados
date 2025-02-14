# Nome do executável
EXEC = programa

# Compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

# Arquivos-fonte
SRC = main.cpp lista.cpp

# Objetos gerados
OBJ = $(SRC:.cpp=.o)

# Regra padrão
all: $(EXEC)

# Regra para compilar o executável
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra para compilar arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra de limpeza
clean:
	del /f /q $(OBJ) $(EXEC)

# Regra para rodar o programa após compilar
run: all
	./$(EXEC)
