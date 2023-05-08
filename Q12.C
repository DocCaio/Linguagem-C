//12 - Excluir Dependente;

TFuncionario* buscaFuncionario(TFuncionario* funcionarios, int codigo){
    TFuncionario *aux = funcionarios;
    if(funcionarios == NULL)
        return NULL;
    while(aux != NULL){
        if(codigo == aux->codigo){
            return aux;
        };
    };
};

int excluirDependente(TFuncionario* funcionarios, int funcionarioCodigo){
    TFuncionario* funcionario = buscaFuncionario(funcionarios, funcionarioCodigo);
    if(funcionario == NULL){
        printf("Funcionario inexistente");
    }else{
        printf("Funcionario de nome %s encontrado", funcionario->nome);
        if(funcionario->numeroDependentes <= 0 || funcionario->dependentes == NULL){
            printf("Sem dependentes!");
            return 0;
        }else{
            imprimeDependentes(funcionario->dependentes);
            printf("Digite o codigo do dependente que desja excluir: \n");
            int codigo;
            scanf("%i", &codigo);
            funcionario->numeroDependentes = --funcionario->numeroDependentes;
            TDependente *dependentes = funcionario->dependentes;
            TDependente *aux = dependentes;
            TDependente *auxsecundario;
            if(aux->codigo ==codigo){
                dependentes = dependentes->proximo;
                free(aux);
                return dependentes;
            }else{
                while(aux->proximo != NULL){
                    if(aux->proximo->codigo == codigo){
                        auxsecundario = aux->proximo;
                        aux->proximo = aux->proximo->proximo;
                        free(auxsecundario);
                    }else{
                        aux = aux->proximo;
                    };
                };
            };
            return 1;   
        };
    };
};