# Análise dos Evals — C++ Módulos 05 a 09

Cada módulo é avaliado contra o respectivo `42 EvalHub.pdf`. Onde há conflito entre eval e subject, **o subject prevalece**. A legenda de status usada é:

| Símbolo | Significado |
|---------|-------------|
| ✅ | Passa no critério |
| ⚠️ | Ponto de atenção / grey area |
| ❌ | Falha clara no critério do eval |

---

## Módulo 05 — Exceções

### Problemas Críticos

#### ❌ Módulos 00 e 01: `CXX = g++` nos Makefiles

O eval diz textualmente:

> "A Makefile compiles without the required flags **and/or another compiler than c++** → you must not grade this exercise."

- `05-cpp/00/Makefile`: `CXX = g++`
- `05-cpp/01/Makefile`: `CXX = g++`
- `05-cpp/02/Makefile`: `CXX = c++` ✅
- `05-cpp/03/Makefile`: `CXX = c++` ✅

**Efeito:** Um avaliador rigoroso não gradua os exercícios 00 e 01. Os exercícios 02 e 03 dependem de 00 e 01 no contexto da avaliação progressiva, então a nota do módulo é gravemente afetada.

**Correção necessária:** trocar `CXX = g++` por `CXX = c++` nos Makefiles de `00/` e `01/`.

#### ⚠️ Nomes de diretórios: `00/`, `01/` em vez de `ex00/`, `ex01/`

O subject e as regras gerais especificam: *"Os diretórios dos exercícios serão nomeados desta forma: ex00, ex01, …"*. O módulo 05 usa `00/`, `01/`, `02/`, `03/` — sem o prefixo `ex`. Os módulos 06–09 usam o padrão correto (`ex00/`, `ex01/`…). O corretor automático da plataforma 42 pode não encontrar os arquivos nos lugares esperados.

**Correção necessária:** renomear para `ex00/`, `ex01/`, `ex02/`, `ex03/`.

---

### Avaliação por Exercício

#### Ex00 — Bureaucrat
| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile compila com `c++` e flags corretas | ❌ | `CXX = g++` |
| Classe `Bureaucrat` com nome `const` | ✅ | `const std::string name` |
| Grade 1–150 com exceções no construtor | ✅ | Lança `GradeTooHighException` / `GradeTooLowException` |
| Accessors para os atributos | ✅ | `getName()`, `getGrade()` |
| `incrementGrade()` / `decrementGrade()` com exceções | ✅ | Correto (incrementar 1 → tenta ir para 0 → lança) |
| Exceções herdam de `std::exception` | ✅ | Classes aninhadas com `what()` |
| `operator<<` para ostream | ✅ | Presente e funcional |
| Main com testes suficientes | ✅ | Testa criação, incremento, decremento e exceções |

#### Ex01 — Form
| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile compila com `c++` e flags corretas | ❌ | `CXX = g++` |
| Classe `Form` com atributos `private` (não `protected`) | ✅ | Correto |
| Atributos `name`, `gradeToSign`, `gradeToExecute` são `const` | ✅ | Correto |
| `isSigned` começa como `false` | ✅ | Inicializado no construtor |
| Validação de grades com exceções | ✅ | Mesmo padrão do Bureaucrat |
| Accessors e `operator<<` | ✅ | Presentes |
| `Form::beSigned()` | ✅ | Lança se grau do burocrata for insuficiente |
| `Bureaucrat::signForm()` | ✅ | try/catch com mensagem de sucesso/falha |

#### Ex02 — AForm + Formulários Concretos
| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile com `c++` | ✅ | |
| Formas concretas com graus e nomes corretos | ✅ | Shrubbery(145/137), Robotomy(72/45), Presidential(25/5) |
| Construtores recebem apenas `target` | ✅ | |
| `AForm::execute()` / verificação de grau | ✅ | Verificação feita em cada subclasse (abordagem válida) |
| `Bureaucrat::executeForm()` | ✅ | Presente com tratamento de exceção |
| OCF para todas as classes | ✅ | |
| Main com testes suficientes | ✅ | |

#### Ex03 — Intern
| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile com `c++` | ✅ | |
| Classe `Intern` presente | ✅ | |
| `makeForm()` funciona conforme o subject | ✅ | |
| **Good dispatching**: usa array de ponteiros para funções | ✅ | `AForm* (*constructors[])(const std::string&)` — sem if/else |

---

## Módulo 06 — Casts em C++

### Problemas Críticos

#### ❌ Ex00: `ScalarConverter` sem construtor privado

O eval pergunta explicitamente: *"Did the student create a class with a private constructor, and static methods?"*

O código em `ScalarConverter.cpp` tem o construtor e destrutor **comentados**:
```cpp
//ScalarConverter::ScalarConverter() {}
//ScalarConverter::~ScalarConverter() {}
```
Não há nenhuma declaração de construtor privado em `ScalarConverter.hpp`. A classe não é explicitamente não-instanciável. O avaliador marcará esta pergunta como **No**.

**Correção necessária:** declarar o construtor (e idealmente também cópia e atribuição) como `private` no `.hpp` e defini-los (ou deixá-los sem corpo) no `.cpp`.

#### ❌ Ex02: `identify(Base& p)` usa pointer trick em vez de try/catch

O eval diz explicitamente:

> "void identify(Base& p) should use a try and catch block to check if the cast failed."

O código **ativo** faz:
```cpp
void identify(Base& p) {
    if (dynamic_cast<A*>(&p))   // ← pointer trick, não try/catch
    ...
}
```

A implementação correta com try/catch **existe mas está comentada** logo abaixo. O avaliador marcará esta pergunta como **No**.

**Correção necessária:** descomentar a implementação com try/catch e comentar/remover a versão com pointer.

#### ⚠️ Ex00: `CXX = c++ -g` no Makefile

O flag `-g` (debug) está embutido na variável `CXX` em vez de `CXXFLAGS`. A linha `CXX = c++ -g` ainda invoca `c++` como compilador, então a maioria dos avaliadores aceita. Porém um avaliador rigoroso pode alegar que o CXX não é estritamente `c++`. Risco baixo mas existente.

**Correção sugerida:** mover `-g` para `CXXFLAGS` ou removê-lo.

---

### Avaliação por Exercício

#### Ex00 — ScalarConverter
| Critério do Eval | Status | Observação |
|---|---|---|
| Classe com construtor privado | ❌ | Construtor comentado no `.cpp`, nada no `.hpp` |
| Métodos estáticos | ✅ | `convert()` e `get_type()` são `static` |
| Usa `static_cast` | ✅ | Todas as conversões usam `static_cast` |
| Programa funciona conforme requerido | ✅ | Trata char, int, float, double, nan, ±inf |
| Makefile com `c++` | ⚠️ | `CXX = c++ -g` (ver acima) |

#### Ex01 — Serializer
| Critério do Eval | Status | Observação |
|---|---|---|
| Classe com construtor privado | ✅ | Todos os membros especiais são `private` |
| Métodos estáticos | ✅ | `serialize()` e `deserialize()` são `static` |
| `reinterpret_cast` de `Data*` → inteiro | ✅ | `reinterpret_cast<unsigned long>(ptr)` |
| `reinterpret_cast` de inteiro → `Data*` | ✅ | `reinterpret_cast<Data*>(raw)` |
| Tipo de retorno de `serialize` é `uintptr_t` | ⚠️ | Retorna `unsigned long`; o eval pede `uintptr_t`. Na maioria dos sistemas 64-bit são equivalentes, mas tecnicamente diverge. Baixo risco. |
| Struct `Data` não-vazio | ✅ | `int number` e `std::string text` |
| Round-trip preserva dados | ✅ | `main` verifica endereço e valores |

#### Ex02 — Identify Real Type
| Critério do Eval | Status | Observação |
|---|---|---|
| `dynamic_cast` usado para identificar tipo | ✅ | Usado em ambas as sobrecargas |
| `identify(Base* p)` verifica se cast retornou NULL | ✅ | Usa `if (dynamic_cast<A*>(p))` corretamente |
| `identify(Base& p)` usa try/catch | ❌ | Usa pointer trick; try/catch correto está comentado |
| `<typeinfo>` ausente do código ativo | ✅ | Apenas em comentário |

---

## Módulo 07 — Templates

### Problemas Críticos

Nenhum problema crítico identificado.

### Avaliação por Exercício

#### Ex00 — swap / min / max
| Critério do Eval | Status | Observação |
|---|---|---|
| Funciona com tipos simples (int) | ✅ | Testado no main |
| Funciona com tipos complexos (string) | ✅ | `std::string` testado no mesmo main |
| Usa `::swap`, `::min`, `::max` | ✅ | Evita ambiguidade com `std::` |
| `min` retorna o segundo argumento em caso de empate | ✅ | `a < b ? a : b` |
| `max` retorna o segundo argumento em caso de empate | ✅ | `a > b ? a : b` |

> **Nota:** O eval menciona um arquivo de teste `ex00.cpp` em anexo com tipos complexos. O avaliador pode tentar compilar esse arquivo com o `whatever.hpp` do projeto. A implementação é genérica e deve funcionar para qualquer tipo com `operator<`, `operator>` e construtor de cópia.

#### Ex01 — Iter
| Critério do Eval | Status | Observação |
|---|---|---|
| Funciona conforme o subject | ✅ | Itera corretamente aplicando função a cada elemento |
| Makefile com `c++` | ✅ | |

> **Nota:** O eval fornece um `ex01.cpp` em anexo e espera saída específica (`0 1 2 3 4 / 42 42 42 42 42`). O avaliador vai compilar esse arquivo usando o `iter.hpp` do projeto. A assinatura `void (*func)(T const &)` é suficientemente genérica para suportar callbacks de qualquer tipo.

#### Ex02 — Array
| Critério do Eval | Status | Observação |
|---|---|---|
| Construtor vazio (`Array()`) | ✅ | `_size=0`, `arr=NULL` |
| Construtor com tamanho (`Array(unsigned int n)`) | ✅ | `new T[n]()` — inicializa elementos |
| Usa `new[]` para alocação | ✅ | Explicitamente verificado pelo eval |
| `operator[]` lança `std::exception` fora dos limites | ✅ | Lança `std::out_of_range` |
| Acesso de leitura em instância `const` | ✅ | Sobrecarga `const` de `operator[]` presente |
| Funciona com tipos simples e complexos | ✅ | Testado com `int` e `std::string` |
| `main2.cpp` (teste do subject) presente | ✅ | Arquivo incluído; Makefile tem target `test` para ele |

---

## Módulo 08 — Containers, Iteradores e Algoritmos STL

### Problemas Críticos

#### ❌ Ex02: `operator=` do `MutantStack` causa UB / erro de compilação

```cpp
MutantStack &operator=(const MutantStack &other) {
    if (this != &other) {
        std::stack<T>::operator=(other);
        return *this;
    }
    // ← sem return aqui! control cai fora da função
}
```

Quando `this == &other`, a função retorna sem valor. `-Wall` inclui `-Wreturn-type`, e com `-Werror` isso pode virar **erro de compilação** dependendo do compilador/versão. Mesmo que compile, é undefined behavior.

**Correção necessária:** adicionar `return *this;` após o fechamento do `if`:
```cpp
MutantStack &operator=(const MutantStack &other) {
    if (this != &other)
        std::stack<T>::operator=(other);
    return *this;
}
```

---

### Avaliação por Exercício

#### Ex00 — easyfind
| Critério do Eval | Status | Observação |
|---|---|---|
| Função template `easyfind(T, int)` | ✅ | |
| **Obrigatório usar algoritmos STL** (`std::find`) | ✅ | Usa `std::find` explicitamente |
| Main com testes suficientes | ✅ | Testa vector, list, caso não-encontrado |

#### Ex01 — Span
| Critério do Eval | Status | Observação |
|---|---|---|
| Classe conforme as restrições do subject | ✅ | |
| Usa algoritmos STL | ✅ | `std::sort`, `std::min_element`, `std::max_element` |
| `shortestSpan` não usa apenas subtração dos dois menores | ✅ | Ordena cópia e itera pares adjacentes — correto |
| Forma prática de adicionar múltiplos números | ✅ | `addRange<Iterator>` template com `insert` |

> **Nota sobre shortestSpan:** O eval diz "use STL algorithms as much as possible". O loop manual sobre pares adjacentes após o `std::sort` é aceitável — a alternativa seria `std::adjacent_find` com predicado customizado, mas o comportamento é equivalente.

#### Ex02 — MutantStack
| Critério do Eval | Status | Observação |
|---|---|---|
| Herda de `std::stack` e expõe todas as funções | ✅ | |
| Tem iterador; operações do subject funcionam | ✅ | `begin()`, `end()`, `rbegin()`, `rend()` |
| **operator= com UB** | ❌ | `return *this` ausente no caminho de self-assignment |
| "Better tests" — main vai além dos exemplos do subject | ✅ | Inclui iteração reversa além do exigido |

---

## Módulo 09 — STL (uso real)

### Problemas Críticos

Nenhum problema crítico identificado. Todos os três exercícios passam nos critérios do eval.

### Avaliação por Exercício

#### Ex00 — Bitcoin Exchange
| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile com regras padrão | ✅ | |
| Usa pelo menos um container | ✅ | `std::map<std::string, double>` |
| Pode justificar a escolha do container | ✅ | Map mantém datas ordenadas; `lower_bound` dá busca O(log n) para data mais próxima |
| Trata arquivo vazio ou com erros | ✅ | Imprime mensagens de erro por linha sem parar |
| Data inválida | ✅ | `isValidDate()` com validação de calendário |
| Valor > 1000 ou < 0 | ✅ | Validado em `parseValue()` / `processLine()` |
| Usa data inferior mais próxima quando exata não existe | ✅ | `rateForDateOrPrev()` via `lower_bound` + step-back |

#### Ex01 — Reverse Polish Notation
| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile com regras padrão | ✅ | |
| Usa pelo menos um container **diferente do ex00** | ✅ | `std::stack<int>` (ex00 usou `std::map`) |
| Pode justificar a escolha | ✅ | Stack LIFO é a estrutura natural para RPN |
| Funciona com fórmulas diversas | ✅ | |
| **Teste avançado 1:** `8 9 * 9 - 9 - 9 - 4 - 1 +` → 42 | ✅ | Verificado |
| **Teste avançado 2:** `9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -` → 42 | ✅ | Verificado |
| **Teste avançado 3:** `1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /` → 15 | ✅ | Verificado |

#### Ex02 — PmergeMe
| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile com regras padrão | ✅ | |
| Usa pelo menos **dois** containers **diferentes dos anteriores** | ✅ | `std::vector<int>` e `std::deque<int>` — nenhum usado antes |
| Pode justificar a escolha de ambos | ✅ | vector: acesso contíguo, cache-friendly; deque: inserções eficientes nas extremidades |
| Algoritmo Ford-Johnson presente e usado em cada container | ✅ | `fordJohnsonVec` e `fordJohnsonDeq` separados, com Jacobsthal |
| Pode explicar o algoritmo brevemente | ✅ | Pareamento → recursão → cadeia principal → inserção por ordem de Jacobsthal com binary search limitado |
| OCF para a classe `PmergeMe` | ✅ | Todos os 4 membros canônicos presentes |
| Main com testes suficientes | ✅ | |
| Funciona com 5–10 inteiros | ✅ | Testado e verificado |
| Funciona com 3000 inteiros (`shuf -i 1-1000 -n 3000`) | ✅ | Testado; resultado verificado como ordenado corretamente |
| Diferença de tempo visível entre os dois containers | ✅ | Deque consistentemente mais lento que vector (ambos em µs) |

---

## Resumo Geral — Ações Necessárias

| Módulo | Exercício | Problema | Prioridade |
|--------|-----------|----------|------------|
| **05** | ex00, ex01 | `CXX = g++` nos Makefiles | 🔴 CRÍTICO — não gradua |
| **05** | todos | Pastas nomeadas `00/`…`03/` em vez de `ex00/`…`ex03/` | 🔴 CRÍTICO — submissão incorreta |
| **06** | ex00 | `ScalarConverter` sem construtor privado | 🔴 CRÍTICO — pergunta do eval falha |
| **06** | ex02 | `identify(Base& p)` usa pointer trick; try/catch está comentado | 🔴 CRÍTICO — pergunta do eval falha |
| **08** | ex02 | `MutantStack::operator=` sem `return *this` no caminho de self-assignment | 🔴 CRÍTICO — UB / possível erro de compilação |
| **06** | ex00 | `CXX = c++ -g` (flag `-g` na variável do compilador) | 🟡 MENOR — risco baixo |
| **06** | ex01 | `serialize` retorna `unsigned long` em vez de `uintptr_t` | 🟡 MENOR — equivalente em 64-bit |

---
