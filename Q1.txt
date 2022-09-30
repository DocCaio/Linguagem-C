// 1 -   Crie uma estrutura do tipo lista simples, com os seguintes campos;

typedef struct dependente TDependente;
struct dependente{
    int codigo;
    char nome[30];
    int anoNascimento;
    // Deve ser entre 1920 e Hoje.
    char status;
    // Char deve ser F (filho), C (conjuje), P(pais)
    TDependente *proximo;
};