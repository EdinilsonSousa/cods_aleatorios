# Prática 4

Elaborar um script DDL no padrão SQL ANSI utilizando [Replit](https://replit.com).

1. 

```text
                                         FUNCIONARIO
   DEPARTAMENTO                          +-------------------------------+
   +--------------------------+          |matricula INT NOT NULL PK      |
   |codigo INT NOT NULL PK    |         /+-------------------------------+\
   +--------------------------+-|-----o+-|nome VARCHAR(100) NOT NULL     |-+o---+
   |nome VARCHAR(100) NOT NULL|         \|salario NUMERIC(10,2) NOT NULL |/     |
   +--------------------------+          |gerente INT FK                 |      |
                                         |departamento INT FK NOT NULL   |-|----+
                                         +-------------------------------+  
```

2. 

```text
   ENDERECO                               PESSOA
   +-------------------------+            +--------------------------+
   |id INT PFK               |            |id INT NOT NULL PK        |
   +-------------------------+            +--------------------------+
   |logradouro VARCHAR(100)  |-|o-------|-|nome VARCHAR(100) NOT NULL|
   |numero INT DEFAULT 0     |            +--------------------------+
   |cep CHAR(8) NOT NULL     |                 |               |
   |cidade VARCHAR(30)       |                =|=             =|=
   |uf CHAR(2) NOT NULL      |                 |               |
   +-------------------------+                 |               |
                                              =|=             =|=
                               FISICA          |               |          JURIDICA
                               +---------------------+    +----------------------+
                               |id INT NOT NULL PFK  |    |id INT NOT NULL PFK   |
                               +---------------------+    +----------------------+
                               |sexo CHAR(1)         |    |inscricao INT NOT NULL|
                               |cpf CHAR(11) NOT NULL|    |cnpj CHAR(14) NOT NULL|
                               +---------------------+    +----------------------+
```

3. 

```text
   PACIENTE                                  TELEFONE
   +----------------------------+            +------------------------------+
   |cpf CHAR(11) NOT NULL PK    |           /|cpf CHAR(11) NOT NULL PFK     |
   +----------------------------+-|-------o+-|telefone char(11) NOT NULL PK |
   |nome VARCHAR(100) NOT NULL  |           \+------------------------------+
   +----------------------------+            +------------------------------+
               _|_
                |
                |
   CONSULTA    /|\
   +----------------------------+            MEDICO
   |consulta INT NOT NULL PK    |            +-----------------------------+
   +----------------------------+            |crm CHAR(10) NOT NULL PK     |
   |cpf CHAR(11) NOT NULL FK    |\           +-----------------------------+
   |crm CHAR(10) NOT NULL FK    |-+--------|-|nome VARCHAR(100) NOT NULL   |
   |data DATE NOT NULL          |/           |especialidade VARCHAR(30)    |
   +----------------------------+            +-----------------------------+
```
