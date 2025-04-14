# 💰 **Simulador de Vida Financeira em C**  

[![Lingua C](https://img.shields.io/badge/linguagem-C-blue?style=flat-square&logo=c)](https://www.cprogramming.com/)
[![Status: Em Desenvolvimento](https://img.shields.io/badge/status-em%20desenvolvimento-yellow?style=flat-square)](https://github.com/usuario/simulador-vida-financeira)
[![Modo de Jogo: Console](https://img.shields.io/badge/console%20game-sim-black?style=flat-square)](https://github.com/usuario/simulador-vida-financeira)

---

## 📌 **Sobre o Projeto**  

Este é um **projeto iniciante** de **simulação de vida financeira**, desenvolvido em **linguagem C** 🖥️. O jogo é jogado inteiramente via **console** e foi criado com o objetivo de **aprendizado** e prática de **programação estruturada**, **manipulação de arquivos** e **organização modular em C**.

Com este projeto, você simula a rotina de um personagem que precisa equilibrar **trabalho, estudos e finanças pessoais**, tomando decisões que afetam diretamente sua **evolução profissional e financeira**. 🚀

> **Nota:** Este projeto é uma excelente oportunidade para quem está começando a aprender **C** e quer entender a interação entre o código e o console. 😎

---

## 🔧 **Funcionalidades Principais**  

### 🏦 **Sistema Bancário**  
- Criação de conta bancária com **nome, CPF e senha**.  
- Acesso à conta para visualização e movimentação de saldo.  
- Sistema de **impostos** que deduz automaticamente valores sobre salários recebidos.

### 💼 **Sistema de Trabalho**  
- O jogador **começa como operário** com um **Curso Técnico já concluído**.  
- Os salários são **fixos por cargo**, sendo que cargos superiores darão acesso a melhores salários (futuramente desbloqueáveis com formações).  
- Horários de trabalho precisam ser respeitados para garantir o pagamento.

### 🎓 **Sistema de Estudos**  
- Atualmente disponível apenas o **Curso Técnico**, necessário para iniciar como operário.  
- Futuramente estarão disponíveis:
  - Engenharia 🏗️  
  - Administração 📊  
  - Medicina 🏥  
- Sistema de pagamento **à vista ou parcelado** para cursos.

### 🛒 **Sistema de Compras**  
- Compra de **veículos e casas**:
  - **Casa 🏠** (melhora condições de vida).
  - **Moto 🏍️**, **Carro 🚗**, **Bicicleta 🚲** (futuramente reduzirão tempo de deslocamento).
- Loja possui **três localidades** com variações em **preço, frete e impostos**.

---

## ⚠️ **Avisos Importantes**

🚧 **Este projeto ainda está em desenvolvimento**, e por isso algumas funcionalidades estão incompletas ou ausentes:

- ❌ **Progresso de saldo e bens não é salvo** (em breve será corrigido!).  
- ❌ **Armário de itens ainda não implementado**.  
- ❌ **Sistema de transporte não afeta o tempo de chegada** no trabalho (mas será adicionado!).  
- ❌ **Personagem começa como operário e não é possível trocar de cargo ainda**.

---

## 🔄 **Atualizações Futuras**

- ✅ Sistema de **salvamento automático** de progresso.  
- ✅ Inclusão de novos cargos e desbloqueio via formações.  
- ✅ Sistema de **veículos influenciando o tempo de chegada ao trabalho**.  
- ✅ Interface no console mais intuitiva.  
- ✅ Sistema de **crédito e parcelamento mais avançado**.  
- ✅ Melhorias visuais no console (barras, animações simples, feedbacks).

---

## 📝 **Estrutura do Projeto**

> 📂 **Diretórios conforme imagem abaixo**:

![Estrutura de Pastas](https://raw.githubusercontent.com/seu-usuario/seu-repositorio/main/imagens/estrutura.png)

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

## 💡 **Créditos**

- Desenvolvido como parte dos estudos em **linguagem C** para reforçar conceitos como:
  - **Modularização**  
  - **Manipulação de arquivos**  
  - **Interação com usuário no console**  
  - **Organização de dados**

---

## 🚀 **Como Rodar o Projeto**

1. **Clone o repositório**:
   ```bash
   git clone https://github.com/seu-usuario/simulador-vida-financeira.git
   cd simulador-vida-financeira
   ./simulador

## 📜 Licença

Este projeto está sob a licença MIT, o que significa que você pode usá-lo, modificá-lo e distribuí-lo livremente. Aproveite para aprender e criar a sua versão! 🚀
