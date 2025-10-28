# Etapa 1: Base Debian
FROM debian:bookworm

# Etapa 2: Instalar dependências
RUN apt update && apt install -y \
    g++ cmake libmariadb-dev libmariadb-dev-compat mariadb-client

# Etapa 3: Definir diretório
WORKDIR /app

# Etapa 4: Copiar código-fonte e includes
COPY ../src ./src
COPY ../include ./include

# Etapa 5: Compilar o projeto
RUN g++ src/*.cpp -Iinclude $(mysql_config --cflags --libs) -std=gnu++17 -o crud

# Etapa 6: Executar o binário
CMD ["./crud"]
