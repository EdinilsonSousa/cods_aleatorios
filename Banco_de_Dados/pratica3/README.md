# Prática 3

Elaborar um modelo físico na notação James Martin utilizando [SqlDBM](https://app.sqldbm.com).

1. 

```text
   +--------------------+
   |     MENSALISTA     |
   +--------------------+
   |nome: string        |
   +--------------------+
           =|=
            |                      +--------------------+
           =|=                     |      ESTACIONA     |
    +-------------------+          +--------------------+         +--------------------+
    |      CLIENTE      |         /|entrada: data       |         |        VAGA        |
    +-------------------+-|------+-|saida: data         |\        +--------------------+
    |PK codigo: inteiro |         \|FK vaga: inteiro    |-+-----|-|PK numero: inteiro  |
    +-------------------+          |FK cliente: inteiro |/        |staus: booleano     |
           =|=                     |valor: numerico     |         +--------------------+
            |                      +--------------------+
           =|=
    +----------------+
    |     AVULSO     |
    |----------------+
    |placa: string   |
    |marca: string   |
    |cor: string     |
    +----------------+
```

2. 

```text
   +-------------------+
   |      CLIENTE      |
   +-------------------+           +---------------------+
   |PK cnpj: string    |           |       PEDIDO        |
   |nome: string       |           +---------------------+
   |endereco: string   |          /|PK numero: inteiro   |
   |cidade: string     |-|-------+-|data_pedido: data    |
   |estado: string     |          \|FK cnpj: string      |
   |cep: string        |           |valor_total: numerico|
   |telefone: string   |           +---------------------+
   |contato: string    |                    _|_
   +-------------------+                     |
                                            /|\
                                +---------------------------+
                                |           ITEM            |
                                +---------------------------+
                                |PK,FK pedido: inteiro      |
                                |PK,FK medicamento: inteiro |
                                |quantidade: inteiro        |
                                |preco: numerico            |
                                +---------------------------+
                                         \|/
                                         _|_
                                          |
                              +------------------------+
                              |      MEDICAMENTO       |         +-------------------+
                              +------------------------+         |    LABORATORIO    |
                              |PK codigo: inteiro      |\        +-------------------+
                              |tipo: caracter          |-+-----|-|PK codigo: inteiro |
                              |data_validade: inteiro  |/        |nome: string       |
                              |nome: string            |         +-------------------+
                              |principio_ativo: string |
                              |cor_tarja: string       |
                              |FK laboratorio: inteiro |
                              +------------------------+
```

3. 

```text
     +-----------------------+           +-------------------+
     |        CURSO          |           |      MODULO       |
     +-----------------------+          /+-------------------+
     |PK codigo: inteiro     |-|-------+-|PK modulo: inteiro |
     |nome: string           |          \|nome: string       |
     |carga_horaria: inteiro |           |ementa: string     |
     +-----------------------+           |FK curso: inteiro  |
                                         +-------------------+
                                                  _|_
                                                   |
                                                  /|\
                                          +----------------------+
        +----------------------+          |       MINISTRA       |
        |      PROFESSOR       |          +----------------------+
        +----------------------+         /|FK modulo: inteiro    |
        |PK matricula: inteiro |-|------+-|FK professor: inteiro |
        |nome: strig           |         \|FK aluno: inteiro     |
        |titulacao: string     |          |media: numerico       |
        +----------------------+          |frequencia: numerico  |
                                          +----------------------+
                                                    \|/
                                                    _|_
                                                     |
        +----------------------+           +----------------------+
        |   PLANO_MENSALIDADE  |           |         ALUNO        |
        +----------------------+          /+----------------------+
        |PK plano: inteiro     |-|-------+-|PK matricula: inteiro |
        |quantidade: inteiro   |          \|nome: string          |
        |desconto: numerico    |           |telefone: string      |
        +----------------------+           |FK plano: inteiro     |
                                           +----------------------+
```
