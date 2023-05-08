// 4 -    Escreva uma função com o seguinte menu;

int executaMenu(int jaExecutouAPrimeiraVez, TFuncionario *funcionarios){
    char opcaoEscolhida;
    // Previne mostrar mensagem de boas vindas em uma re-execução do menu. 
    if(!jaExecutouAPrimeiraVez){
        printf("Bem vindo, voce pode executar as seguintes acoes: \n");
        printf("A - Inserir funcionario\n");
        printf("B – Inserir Dependente\n");
        printf("C - Excluir funcionario\n");
        printf("D - Excluir dependente\n");
        printf("E - Listar funcionários\n");
        printf("F - Sair\n");
    }
    printf("Digite sua opção: \n");
    scanf(" %c", &opcaoEscolhida);
    printf("Opcao escolhida: %c\n", opcaoEscolhida);
    opcaoEscolhida = putchar(tolower(opcaoEscolhida));
    if(opcaoEscolhida == 'f'){
        printf("Saindo...");
        return 0;
    }
    int codigo;
    TFuncionario* funcionario;
    switch(opcaoEscolhida){
        case 'a': 
            funcionarios = insereFuncionario(funcionarios);
            break;
        case 'b': 
            printf("Digite o codigo do funcionario:\n");
            scanf("%i", &codigo);
            funcionario = buscaFuncionario(funcionarios, codigo);
            if(funcionario == NULL){
                printf("Funcionario nao encontrado");
                insereDependente(funcionario->dependentes, funcionario->numeroDependentes);
            }
            break; 
        case 'c': 
            printf("Digite o codigo do funcionario:\n");
            scanf("%i", &codigo);
            excluirFuncionario(funcionarios, codigo);
            break; 
        case 'd': 
            printf("Digite o codigo do funcionario:\n");
            scanf("%i", &codigo);
            excluirFuncionario(funcionarios, codigo);
            break; 
        case 'e': 
            imprimeFuncionarios(funcionarios);
            break; 
        default: 
            printf("Ops, essa opcao nao existe.. tente novamente\n");
    };
    executaMenu(1, funcionarios);
};


int main(void)
{
    TFuncionario* funcionarios = inicializaFuncionarios();
    executaMenu(0, funcionarios);
    return 0;
}
