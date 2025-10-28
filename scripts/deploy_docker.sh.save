#!/bin/bash

cd "$(dirname "$0")/.."

echo "🚀 Parando containers anteriores..."
docker compose -f docker/docker-compose.yml down -v --remove-orphans

echo "🧹 Limpando caches e imagens..."
docker system prune -af --volumes

echo "🐳 Subindo o ambiente com Docker Compose..."
docker compose -f docker/docker-compose.yml up --build
