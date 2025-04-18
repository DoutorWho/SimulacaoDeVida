# 💰 Simulador de Vida Financeira em C

<div align="center">
  <img src="https://img.shields.io/badge/Linguagem-C-blue?style=for-the-badge&logo=c" alt="linguagem" />
  <img src="https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow?style=for-the-badge" alt="status" />
  <img src="https://img.shields.io/badge/Versão-Alpha%200.8-orange?style=for-the-badge" alt="versão" />
  <img src="https://img.shields.io/badge/Console%20Game-black?style=for-the-badge" alt="modo de jogo" />
</div>

<p align="center">
  <p align="center"> <img src="https://media.giphy.com/media/f9k1tV7HyORcngKF8v/giphy.gif" width="200" alt="money gif"/> </p>
</p>

---

## 📌 Sobre o Projeto

O **Simulador de Vida Financeira em C** é um projeto **iniciante** criado com o objetivo de **aprender e praticar programação estruturada em C**, com foco em **manipulação de arquivos**, **modularização** e **interação via console**.  

🧠 Você será desafiado a tomar decisões que afetam a **carreira, finanças e estilo de vida** do seu personagem — equilibrando **trabalho, estudo e consumo** para evoluir social e financeiramente.  

> 💬 Ideal para quem está começando na linguagem C e quer entender melhor como aplicar a lógica de programação de forma prática e divertida!

---

## 🔧 Funcionalidades Principais

### 🏦 Sistema Bancário
- Criação de conta com **nome, CPF e senha**
- Visualização e movimentação de saldo (depósitos e retiradas)

### 💼 Sistema de Trabalho
- Comece como **operário** com um **curso técnico**
- Salários fixos por cargo (com possibilidade futura de promoções!)

### 🎓 Sistema de Estudos
- Curso técnico já disponível para iniciar
- Futuras opções:
  - Engenharia 🏗️
  - Administração 📊
  - Medicina 🏥
- Pagamentos à vista

### 🛒 Sistema de Compras
- Compre **imóveis** e **veículos**:
  - 🏠 Imóveis
    - Casa Normal (já inclusa desde o início do jogo)
    - Apartamento (disponível para compra)
    - Mansão (disponível para compra)
  - 🚗 Veículos
    - Bicicleta (já disponível desde o início do jogo)
    - Moto 🏍️ (disponível para compra)
    - Carro 🚗 (disponível para compra)
- No futuro, cada tipo de imóvel e veículo afetará diferentes aspectos da vida do personagem, como o tempo de deslocamento. ⏳

---

## ⚠️ Avisos Importantes

🔧 O projeto está em **desenvolvimento ativo**, e algumas funções ainda estão sendo implementadas:

- ❌ **Armário de itens** ainda não disponível
- ❌ Sistema de transporte **não afeta tempo de chegada**
- ❌ Apenas o cargo de **operário** está disponível atualmente

---

## 🔄 Atualizações

✨ O que foi adicionado:

- 💾 Sistema de **salvamento** adicionamento, agora é possível salvar seu progresso.
- 🎨 Melhor **feedback visual.**

---

---

## 📝 **Estrutura do Projeto**

> 📂 **Diretórios**:

📁 **.vscode**  
├── launch.json  
├── settings.json  
└── tasks.json  

📁 **database**  
├── banco.txt  
├── bens.txt  
└── cadastro.txt  

📁 **funcoes**  
├── geral.c / geral.h  
├── pessoas.c / pessoas.h  
├── tarefas.c / tarefas.h  

📄 **main.c**

---

## 🧠 Créditos

Criado como parte dos estudos em linguagem C para reforçar:
- 🧩 **Modularização de código**
- 📁 **Manipulação de arquivos**
- 🖥️ **Interação com o usuário via console**
- 📊 **Organização e estruturação de dados**

---

## 🚀 **Como Rodar o Projeto**

1. **Clone o repositório**:
   ```bash
   git clone https://github.com/doutorwho/simulacaoDeVida.git
   cd simulador-vida-financeira
   ./simulador

## 📜 Licença

Este projeto está licenciado sob a MIT License. Sinta-se livre para usar, modificar e distribuir. Aproveite para aprender e criar sua própria versão! 💻🚀
