// 10 - Escreva uma função recursiva para listar todas as informações de todos os funcionários, incluindo dependente;

void imprimeFuncionarios(TFuncionario* funcionarios){
    printf("Imprimindo Funcionarios..\n");
    while(funcionarios != NULL){
        printf("Funcionario Codigo %i, Nome %s \n", funcionarios->codigo, funcionarios->nome);
        if(funcionarios->numeroDependentes > 0){
            printf("Esse funcionario tem %i dependentes\n", funcionarios->numeroDependentes);
            printf("Dependentes: \n");
            imprimeDependentes(funcionarios->dependentes);
        }else{
          printf("Esse funcionario tem 0 dependentes!\n");  
        };
        printf("*********************\n");
        funcionarios = funcionarios->proximo;
    };
    return;
};

void imprimeDependentes(TDependente* dependentes){
    while(dependentes != NULL){
        printf("Dependente Codigo %i \n", dependentes->codigo);
        printf("Nome %s \n", dependentes->nome);
        printf("Nascimento %i \n", dependentes->anoNascimento);
        printf("Status %c\n", dependentes->status);
        printf("----------------\n");
        dependentes = dependentes->proximo;
    };
    return;
};