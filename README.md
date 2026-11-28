# Sistema de Backup de Arquivos

Projeto acadêmico desenvolvido para a disciplina de **Estrutura de Dados** do curso de Análise e Desenvolvimento de Sistemas da **UniRuy Wyden**.

## 👨‍🎓 Aluno

- **Nome:** Rodrigo Santos Araújo
- **Matrícula:** 202503356751
- **Curso:** Análise e Desenvolvimento de Sistemas (ADS)
- **Instituição:** UniRuy Wyden
- **Local:** Salvador - BA
- **Ano:** 2026

## 📌 Sobre o projeto

O projeto apresenta a modelagem e um protótipo funcional de um **Sistema de Backup de Arquivos**, aplicando conceitos de Estruturas de Dados Lineares para gerenciar versões de arquivos, consultar o histórico e restaurar estados anteriores.

Na documentação, são analisadas e comparadas três estruturas de dados:

- **Pilha (Stack)** — estrutura principal adotada para o histórico de versões e implementada no protótipo
- **Fila (Queue)** — analisada para o processamento ordenado de backups em lote
- **Lista Encadeada** — analisada para o catálogo geral de arquivos

## 🎯 Objetivo

Demonstrar, de forma teórica e prática, como as Estruturas de Dados resolvem problemas reais de controle de versões e recuperação de arquivos.

## 🧩 Estruturas de Dados

### Pilha (LIFO)
Segue o princípio **LIFO** (*Last In, First Out* — o último a entrar é o primeiro a sair). No projeto, representa o histórico de backups: a versão mais recente fica sempre no topo, permitindo restauração imediata com complexidade $O(1)$.

Principais operações implementadas:
- `push`: cria e empilha uma nova versão de backup no topo.
- `pop`: remove e restaura a versão mais recente do topo.
- Consulta de histórico: exibe as versões empilhadas do topo até a base.

### Fila (FIFO)
Segue o princípio **FIFO** (*First In, First Out*). No modelo conceitual, organiza arquivos aguardando processamento de backup por ordem de chegada.

### Lista Encadeada
Formada por nós ligados por ponteiros, permitindo inserções dinâmicas para organizar o catálogo de arquivos do sistema.

## 💻 Tecnologias

- **HTML, CSS e JavaScript** (protótipo interativo da Pilha no navegador)
- **Linguagem C** (modelagem do algoritmo e código-fonte na documentação do trabalho)
- **Estruturas de Dados** (Pilha, Fila e Lista Encadeada)

## ⚙️ Funcionalidades do protótipo

- Criar novas versões de backup (**Push**)
- Consultar o histórico de versões em ordem LIFO (do topo para a base)
- Restaurar o último backup criado (**Pop**)
- Exibição de mensagens de status das operações

## ▶️ Como executar o protótipo

1. Baixe ou clone este repositório.
2. Localize o arquivo HTML do protótipo (`IMPLEMENTADO Backup de arquivos.html`).
3. Dê um clique duplo no arquivo para abri-lo diretamente em qualquer navegador (Chrome, Edge, Firefox, etc.).

*(O código-fonte em linguagem C referente à modelagem teórica também pode ser consultado no documento PDF do trabalho.)*

## 📂 Estrutura do repositório

```text
Trabalho-Estrutura-de-Dados/
├── DOC_Trabalho_Rodrigo.pdf          # Documento completo do trabalho acadêmico
├── IMPLEMENTADO Backup de arquivos.html # Protótipo funcional da Pilha (LIFO)
├── Slide.pdf                         # Apresentação em slides do projeto
├── VIDEO backup Pilha.mp4            # Vídeo demonstrando o funcionamento da Pilha
├── VÍDEO-EXEMPLO-HTML.mp4            # Vídeo demonstrando o protótipo em HTML
└── README.md                         # Documentação do repositório
