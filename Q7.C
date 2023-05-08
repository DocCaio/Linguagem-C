// 7 -  Faça uma função para a inserção da situação (status) do dependente;

void inserirStatus(char *status){
    char opcaoEscolhida;
    printf("Status \n");
    printf("Opcoes: F - Filho(a) ou Enteado(a)  / C - Cônjuge / P - Pais \n");
    printf("Escolha um: \n");
    scanf(" %c", &opcaoEscolhida);
    char aux = opcaoEscolhida = putchar(tolower(opcaoEscolhida));
    if(aux == 'f' || aux == 'c' || aux == 'p'){
        status = opcaoEscolhida;
    }else{
        printf("Opcao invalida, tente novamente! \n");
        inserirStatus(status);
    };
    return;
};

// inicializadores do exercico
TDependente* inicializaDependentes(){
    return NULL;
};
TFuncionario* inicializaFuncionarios(){
    return NULL;
};