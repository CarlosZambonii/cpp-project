#!/bin/bash
cd "$(dirname "$0")/.."   # volta pra raiz do projeto

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # sem cor

echo -e "${GREEN}🚀 Bem-vindo ao gerenciador do CRUD C++!${NC}"
echo
echo "Escolha uma opção:"
echo "1️⃣  Subir containers (app + banco)"
echo "2️⃣  Rodar o app interativamente"
echo "3️⃣  Ver logs do app"
echo "4️⃣  Entrar no banco de dados"
echo "5️⃣  Derrubar containers"
echo "6️⃣  Limpar TUDO (inclusive banco)"
echo "7️⃣  Checar status dos containers"
echo "0️⃣  Sair"
echo

read -p "> " opt

case $opt in
  1)
    echo -e "${YELLOW}📦 Subindo containers...${NC}"
    cd docker
    docker compose up -d
    ;;
  2)
    echo -e "${YELLOW}💻 Rodando app interativamente...${NC}"
    cd docker
    docker compose run --rm app
    ;;
  3)
    echo -e "${YELLOW}📜 Logs do app:${NC}"
    docker logs -f crud-app
    ;;
  4)
    echo -e "${YELLOW}🐬 Conectando ao banco MariaDB...${NC}"
    docker exec -it crud-db mariadb -u root -p
    ;;
  5)
    echo -e "${RED}🛑 Derrubando containers...${NC}"
    cd docker
    docker compose down
    ;;
  6)
    echo -e "${RED}⚠️  Atenção: Essa ação vai apagar TODOS os containers, volumes e cache do Docker.${NC}"
    echo -e "${YELLOW}Isso inclui o banco de dados MariaDB e os dados salvos.${NC}"
    read -p "Tem certeza que deseja continuar? (s/n): " confirm
    if [[ "$confirm" == "s" || "$confirm" == "S" ]]; then
        echo -e "${RED}🔥 Limpando tudo...${NC}"
        cd docker
        docker compose down -v
        docker system prune -af -f
        echo -e "${GREEN}✅ Limpeza completa.${NC}"
    else
        echo -e "${GREEN}🟢 Operação cancelada. Nada foi removido.${NC}"
    fi
    ;;
  7)
    echo -e "${YELLOW}📊 Status atual:${NC}"
    docker ps --format "table {{.Names}}\t{{.Image}}\t{{.Status}}\t{{.Ports}}"
    echo
    echo -e "${GREEN}💡 Dica:${NC} Use 'docker logs -f crud-app' para ver o output em tempo real."
    ;;
  0)
    echo -e "${GREEN}👋 Saindo...${NC}"
    exit 0
    ;;
  *)
    echo -e "${RED}❌ Opção inválida.${NC}"
    ;;
esac
