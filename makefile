# Variáveis
CC = g++
CFLAGS = -Wall -ftest-coverage -fprofile-arcs
OBJS = romano.o testa_romano.o
EXEC = testa_romano

# Regra principal
all: $(EXEC)

# Compilação do programa principal
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Padrão de compilação para arquivos .cpp
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

# Regra para executar testes automaticamente
test: $(EXEC)
	./$(EXEC)

# Regra para gerar relatório de cobertura com gcov
coverage: test
	gcov romano.cpp

# Limpeza de arquivos temporários
clean:
	rm -f *.o *.gcov *.gcda *.gcno $(EXEC)

# Define quais regras não são arquivos
.PHONY: all test coverage clean