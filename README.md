Sistema de Backup de Arquivos

Projeto acadêmico desenvolvido para a disciplina de Estrutura de Dados do curso de Análise e Desenvolvimento de Sistemas da UniRuy Wyden.

👨‍🎓 Aluno

Nome: Rodrigo Santos Araújo
Matrícula: 202503356751
Curso: Análise e Desenvolvimento de Sistemas (ADS)
Instituição: UniRuy Wyden
Local: Salvador - BA
Ano: 2026

📌 Sobre o projeto

O projeto consiste no desenvolvimento de um protótipo de Sistema de Backup de Arquivos utilizando a linguagem C e conceitos de Estrutura de Dados.

A proposta é representar o gerenciamento de diferentes versões de arquivos, permitindo criar backups, consultar o histórico e restaurar versões anteriores.

O projeto utiliza três estruturas para análise e comparação:

- Pilha
- Fila
- Lista Encadeada

A Pilha é utilizada como estrutura principal para representar o histórico de versões dos backups.

🎯 Objetivo

Demonstrar, por meio de uma aplicação prática, como diferentes Estruturas de Dados podem ser utilizadas para solucionar um problema real relacionado ao gerenciamento de arquivos e backups.

🧩 Estruturas de Dados

Pilha

A Pilha segue o princípio LIFO (Last In, First Out).

No projeto, ela representa o histórico de versões dos backups. A versão mais recente fica no topo e pode ser removida primeiro durante uma operação de restauração.

Principais operações:

- "push": adiciona uma nova versão.
- "pop": remove a versão do topo.
- "peek": consulta a versão do topo sem removê-la.

Fila

A Fila segue o princípio FIFO (First In, First Out).

Ela pode representar arquivos aguardando processamento de backup, fazendo com que o primeiro arquivo colocado na fila seja o primeiro a ser processado.

Lista Encadeada

A Lista Encadeada é formada por nós conectados por ponteiros.

No projeto, pode ser utilizada para armazenar e organizar os arquivos cadastrados no sistema.

💻 Tecnologias

- Linguagem C
- Estruturas de Dados
- Structs
- Ponteiros
- Terminal/Console

⚙️ Funcionalidades

O sistema possui funcionalidades relacionadas ao gerenciamento de backups, como:

- Cadastro de arquivos
- Criação de backups
- Consulta do histórico
- Restauração de versões
- Listagem de arquivos
- Gerenciamento das estruturas de dados

▶️ Como executar

Compile o programa utilizando um compilador C, como GCC:

gcc main.c -o backup

Depois execute:

./backup

No Windows, pode ser utilizado:

backup.exe

📂 Estrutura do projeto

sistema-backup-estruturas-dados/
│
├── src/
│   └── main.c
│
├── docs/
│   └── trabalho.docx
│
├── README.md
│
└── LICENSE

📚 Contexto acadêmico

Este projeto foi desenvolvido como atividade acadêmica da disciplina de Estrutura de Dados, com o objetivo de aplicar conceitos teóricos em uma situação-problema prática.

O sistema utiliza uma simulação de gerenciamento de versões de backup. Não é necessário realizar cópias físicas reais dos arquivos do computador para demonstrar o funcionamento das estruturas estudadas.

👤 Autor

Rodrigo Santos Araújo
Matrícula: 202503356751
ADS — UniRuy Wyden
Salvador - BA