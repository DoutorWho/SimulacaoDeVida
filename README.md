<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Simulador de Vida Financeira em C</title>
</head>
<body>

  <h1>💰 Simulador de Vida Financeira em C</h1>

  <div class="badges">
    <span class="badge">Linguagem: C</span>
    <span class="badge">Console Game</span>
    <span class="badge">Status: Em Desenvolvimento 🚧</span>
  </div>

  <h2>📌 Sobre o Projeto</h2>
  <p>
    Projeto simples em C de simulação de vida financeira via terminal. O jogador gerencia trabalho, estudos e compras,
    iniciando como operário com um curso técnico, evoluindo conforme suas decisões.
  </p>

  <hr>

  <h2>🔧 Funcionalidades Principais</h2>

  <h3>🏦 Sistema Bancário</h3>
  <ul>
    <li>Cadastro com <strong>nome, CPF e senha</strong></li>
    <li>Consulta e movimentação de saldo</li>
    <li>Sistema de <strong>impostos automáticos</strong> sobre salário</li>
  </ul>

  <h3>💼 Sistema de Trabalho</h3>
  <ul>
    <li>Início como <strong>operário</strong> (curso técnico já completo)</li>
    <li><strong>Salário fixo por cargo</strong></li>
    <li>Necessário cumprir horários para receber salário</li>
  </ul>

  <h3>🎓 Sistema de Estudos</h3>
  <ul>
    <li>Curso técnico incluso</li>
    <li>Futuras formações:
      <ul>
        <li>Engenharia 🏗️</li>
        <li>Administração 📊</li>
        <li>Medicina 🏥</li>
      </ul>
    </li>
    <li>Pagamento à vista ou parcelado</li>
  </ul>

  <h3>🛒 Sistema de Compras</h3>
  <ul>
    <li>Compra de veículos e imóveis:</li>
    <ul>
      <li>Casa 🏠</li>
      <li>Moto 🏍️</li>
      <li>Carro 🚗</li>
      <li>Bicicleta 🚲</li>
    </ul>
    <li>Três localidades diferentes com preços e impostos variados</li>
  </ul>

  <hr>

  <h2>⚠️ Avisos Importantes</h2>
  <ul>
    <li>❌ O progresso (saldo/bens) ainda <strong>não é salvo</strong>.</li>
    <li>❌ Armário de itens <strong>ainda não implementado</strong>.</li>
    <li>❌ Transporte <strong>não afeta o tempo de chegada</strong> ainda.</li>
    <li>❌ Começo fixo como operário — <strong>sem troca de cargo</strong> ainda.</li>
  </ul>

  <hr>

  <h2>🔄 Atualizações Futuras</h2>
  <ul>
    <li>✅ Sistema de <strong>salvamento automático</strong></li>
    <li>✅ Novos cargos desbloqueáveis</li>
    <li>✅ Transporte afetando chegada</li>
    <li>✅ Interface mais intuitiva</li>
    <li>✅ Parcelamento inteligente e sistema de crédito</li>
    <li>✅ Mais feedback visual no console</li>
  </ul>

  <hr>

  <h2>📝 Estrutura do Projeto</h2>

  <p>Organização de diretórios conforme imagem:</p>

  <img src="https://raw.githubusercontent.com/seu-usuario/seu-repositorio/main/imagens/estrutura.png" alt="estrutura de pastas" class="structure">

  <pre><code>
📁 .vscode
 ├── launch.json
 ├── settings.json
 └── tasks.json

📁 database
 ├── banco.txt
 ├── bens.txt
 └── cadastro.txt

📁 funcoes
 ├── geral.c / geral.h
 ├── pessoas.c / pessoas.h
 └── tarefas.c / tarefas.h

📄 main.c
  </code></pre>

  <hr>

  <h2>🚀 Como Rodar o Projeto</h2>

  <ol>
    <li>Clone o repositório:
      <pre><code>git clone https://github.com/seu-usuario/simulador-vida-financeira.git</code></pre>
    </li>
    <li>Compile:
      <pre><code>gcc main.c funcoes/*.c -o simulador</code></pre>
    </li>
    <li>Execute:
      <pre><code>./simulador</code></pre>
    </li>
  </ol>

  <p><strong>💡 Dica:</strong> mantenha os arquivos `.txt` no local correto.</p>

  <hr>

  <h2>🤝 Contribuição</h2>
  <ul>
    <li>Faça um fork 🍴</li>
    <li>Crie uma branch: <code>git checkout -b sua-feature</code></li>
    <li>Commit: <code>git commit -m 'feat: nova funcionalidade'</code></li>
    <li>Push: <code>git push origin sua-feature</code></li>
    <li>Abra um Pull Request ✅</li>
  </ul>

  <hr>

  <h2>📜 Licença</h2>
  <p>Projeto sob licença MIT. Livre para uso, modificação e distribuição.</p>

  <hr>

  <h2>💡 Créditos</h2>
  <p>Desenvolvido como exercício prático de:</p>
  <ul>
    <li>Modularização em C</li>
    <li>Manipulação de arquivos</li>
    <li>Organização de dados</li>
    <li>Interação via terminal</li>
  </ul>

</body>
</html>
