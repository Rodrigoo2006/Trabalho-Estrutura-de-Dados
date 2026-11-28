# Sistema de Backup de Arquivos

Projeto acadêmico desenvolvido para a disciplina de **Estrutura de Dados** do curso de Análise e Desenvolvimento de Sistemas da **UniRuy Wyden**.

## 👨‍🎓 Aluno

- **Nome:** Rodrigo Santos Araújo
- **Matrícula:** 202503356751
- **Curso:** Análise e Desenvolvimento de Sistemas (ADS)
- **Instituição:** UniRuy Wyden
- **Local:** Salvador - BA
- **Ano:** 2026

## 📌 Situação-Problema e Solução Proposta

No desenvolvimento de software e na edição constante de documentos, arquivos passam por diversas modificações diárias. Sem um controle organizado de histórico, alterações incorretas ou sobrescritas acidentais causam perda definitiva de versões anteriores.

Para resolver esse problema, foi desenvolvido um protótipo de **Sistema de Backup de Arquivos** aplicando Estruturas de Dados Lineares para gerenciar arquivos, organizar backups pendentes, salvar versões, consultar o histórico e restaurar estados anteriores.

## 🧩 Estruturas de Dados Analisadas e Aplicadas

### 1. Pilha (Stack — LIFO) *(Estrutura Principal)*
Segue o princípio **LIFO** (*Last In, First Out* — o último a entrar é o primeiro a sair). Armazena o histórico de versões de backup, mantendo sempre a cópia mais recente no topo para restauração imediata.

- **Operações:** `push` (criar backup), `pop` (restaurar último backup) e consulta ao histórico.
- **Vantagens:** inserção e remoção em tempo constante `O(1)`, implementação simples e ordem cronológica reversa natural.
- **Limitações:** acesso restrito ao topo, não sendo ideal para buscar versões intermediárias diretamente.

### 2. Fila (Queue — FIFO)
Segue o princípio **FIFO** (*First In, First Out* — o primeiro a entrar é o primeiro a sair). Organiza os arquivos cadastrados ou modificados que aguardam processamento em lote antes da gravação no histórico.

- **Operações:** `enqueue` (enfileirar alteração) e `dequeue` (processar próximo backup).
- **Vantagens:** garante ordem de chegada justa com custo `O(1)` na entrada e saída.
- **Limitações:** não permite acessar diretamente a versão mais recente, tornando-se inadequada como histórico de restauração.

### 3. Lista Encadeada
Estrutura dinâmica formada por nós ligados por ponteiros. Armazena o catálogo geral de arquivos monitorados pelo sistema (nome, última modificação e número de revisões).

- **Operações:** inserção, busca sequencial por nome, atualização de revisões e listagem.
- **Vantagens:** crescimento dinâmico de memória e inserção rápida em `O(1)` no início.
- **Limitações:** busca sequencial com custo `O(n)` e uso extra de memória para ponteiros.

## 📊 Comparação entre as Estruturas

| Critério | Pilha (Stack) | Fila (Queue) | Lista Encadeada |
| :--- | :--- | :--- | :--- |
| **Política de Acesso** | LIFO (Último a entrar, primeiro a sair) | FIFO (Primeiro a entrar, primeiro a sair) | Acesso sequencial por ponteiros |
| **Inserção** | `O(1)` no topo | `O(1)` no final | `O(1)` no início ou `O(n)` no fim |
| **Remoção** | `O(1)` no topo | `O(1)` no início | `O(n)` busca + `O(1)` remoção |
| **Busca e Acesso** | `O(1)` no topo; `O(n)` internos | `O(1)` no início; `O(n)` internos | `O(n)` busca sequencial por chave |
| **Facilidade de Implementação** | Alta (um ponteiro de topo) | Alta (ponteiros de início e fim) | Moderada (controle de busca e ligações) |
| **Organização de Dados** | Ordem cronológica reversa | Ordem de chegada | Flexível para inserções dinâmicas |
| **Adequação ao Versionamento** | Perfeita (Histórico de versões) | Inadequada para histórico linear | Moderada (Catálogo geral) |

## ✅ Justificativa da Escolha da Pilha

A **Pilha** foi escolhida como estrutura central do sistema porque, em cenários de falha ou alteração incorreta, a necessidade imediata do usuário é recuperar a versão mais recente salva. Uma Fila devolveria a versão mais antiga primeiro, e uma Lista Encadeada exigiria buscas sequenciais em `O(n)`. A Pilha resolve o problema com complexidade `O(1)` tanto para salvar quanto para restaurar backups.

## 💻 Tecnologias

- **Linguagem C** (`sistema_backup.c` — implementação completa com Pilha, Fila e Lista Encadeada)
- **HTML, CSS e JavaScript** (protótipo visual simplificado da Pilha no navegador)
- **Estruturas de Dados Lineares** (structs e ponteiros)

## ▶️ Como executar

### Código em C (completo — Pilha, Fila e Lista Encadeada)

Compile usando GCC:

```bash
gcc sistema_backup.c -o backup
