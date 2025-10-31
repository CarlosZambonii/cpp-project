<h1 align="center"> CRUD Extreme — C++ DevOps Evolution Project</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C++-17-blue?logo=cplusplus">
  <img src="https://img.shields.io/badge/MariaDB-Running-blue?logo=mariadb">
  <img src="https://img.shields.io/badge/Docker-Enabled-blue?logo=docker">
  <img src="https://img.shields.io/badge/Kubernetes-Ready-blue?logo=kubernetes">
  <img src="https://img.shields.io/badge/Linux-WSL2-success?logo=linux">
</p>

---

###  About the Project

CRUD Extreme started as a **simple C++ CRUD** and is evolving into a **full enterprise-grade stack** using:
✅ DevOps ✅ Cloud ✅ Security ✅ Observability ✅ Scalability ✅ AI

Each milestone upgrades the project into a more powerful professional system 🚀

---

##  Technologies Used

| Area | Tools / Tech |
|------|--------------|
| Programming | C++17, Standard Library, RAII, Lambdas |
| Database | MariaDB 11 |
| Containers | Docker, Docker Compose |
| Orchestration | Kubernetes (Minikube + Ingress) |
| Architecture | DAO, Singleton, Clean Code |
| Logging | Timestamp logs with `<chrono>` |
| Security (coming next) | JWT + Argon2/Bcrypt |
| Monitoring | Prometheus + Grafana *(Future)* |
| Cloud | AWS EKS *(Future)* |
| UI | REST API + React *(Future)* |

---

## ✅ Stage 1 — C++ CRUD + Clean Architecture

✔ Full CRUD operations  
✔ UUID v4 for user IDs  
✔ Secure SQL escaping (avoid injection)  
✔ Layered architecture:  
➡️ `Database` (**Singleton**)  
➡️ `UserDAO` (**DAO Pattern**)  

Code execution (local):
```sh
g++ src/*.cpp -Iinclude $(mysql_config --cflags --libs) -std=gnu++17 -o crud
./crud
✅ Stage 2 — Dockerization
✔ Multi-container application using Docker Compose
✔ MariaDB initialization using SQL script
✔ ENV-based DB configuration
✔ Portable and production-ready execution

Run:

sh
Copiar código
docker compose up --build
✅ Stage 3 — Kubernetes + Ingress
The project now runs in a real orchestrated infrastructure 🎯

✔ Deployments (App + DB)
✔ ClusterIP Services
✔ Ingress exposing: http://crud.local
✔ Logs and pod lifecycle managed by Kubernetes

Useful commands:

sh
Copiar código
kubectl apply -f k8s/
kubectl get pods
kubectl get svc
kubectl get ingress
minikube addons enable ingress
minikube tunnel
The app is still console-based → REST API comes on Stage 8

🪜 Overall Progress Roadmap
Stage	Status
CRUD + Database	✅
Docker	✅
Kubernetes	✅
Security (hashed passwords + JWT)	🔜
CI/CD Pipeline	🔜
Monitoring + Observability	🔜
Cloud (AWS EKS) Deployment	🔜
REST API (Web Access)	🔜
Frontend (React Dashboard)	🔜
Enterprise Mode (IaC, TLS, Scaling)	🔜

Goal & Learning Outcomes
Develop modern and scalable C++ backend solutions
Showcase DevOps, security, and cloud engineering skills
Target international job opportunities in backend/cloud roles

This project demonstrates real-world software engineering maturity

 Author
Carlos Zamboni
Backend Developer • C++ • DevOps • Cloud
Brazil
Open to remote international jobs

GitHub: https://github.com/CarlosZambonii

 Want to support the project?
Give a star  on GitHub and follow the evolution!
Next milestone → Security Stage 