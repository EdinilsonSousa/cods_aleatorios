# Prática 2

Elaborar um modelo lógico na notação James Martin utilizando [Draw.io](https://app.diagrams.net).

1. 

```text
    (*)codigo                              (*)matricula
     |    ( )nome                           |   ( )nome
     |     |                 +              |    |               +
   +--------------+ (1,1)   / \    (0,N) +-------------+ (1,1)  / \
   | Departamento |--------+   +---------| Funcionario |-------+   + gerencia
   +--------------+         \ /          +-------------+        \ /
                             +                |      | (0,N)     +
                           lota       salario( )     +-----------+
```

2. 

```text
    ( )logradouro                     (*)id
     | ( )numero                       | ( )nome
     |  |                +             |  |
   +----------+ (1,1)   / \    (1,1) +--------+
   | Endereco |========+   +---------| Pessoa |
   +----------+         \ /          +--------+
     |  |  |             +               |
     |  | ( )cep       possui            + é
     | ( )uf                            / \
    ( )cidade                     +----+---+-----+
                                  |              |
                             +--------+     +----------+
                             | Fisica |     | Juridica |
                             +--------+     +----------+
                               |  |           |  |  
                               | ( )sexo      | ( )inscricao
                              ( )cpf         ( )cnpj
```

3. 

```text
     (*)cpf             ( )data      (*)crm
      |  ( )nome         |            |  ( )nome  
      |   |            +-+-+          |   |  
   +----------+ (0,N)  |/ \|  (1,N) +--------+
   | Paciente |--------+   +--------| Medico |
   +----------+        |\ /|        +--------+
      |                +-+-+          |
    (( ))telefone     consulta       ( )especialidade
```
