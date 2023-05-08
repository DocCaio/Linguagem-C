// 2 - Crie uma estrutura do tipo lista dupla, com os seguintes campos;

typedef struct funcionario TFuncionario;
struct funcionario{
    int codigo;
    char nome[30];
    int numeroDependentes;
    // Deve ser >= 0
    TDependente *dependentes;
    // Se numeroDependentes for 0 atribuir NULL automatico;
    TFuncionario *proximo;
    TFuncionario *anterior;
};