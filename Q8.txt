// 8 - Escreva uma função recursiva para inserir os dependentes da empresa, considerando a quantidade de dependentes de cada funcionário;

TDependente* insereDependente(TDependente* lista,int numeroDependentes){
    TDependente *aux = (TDependente*)malloc(sizeof(TDependente));
    aux->proximo = lista;
    // a)   O código do dependente será criado com um número sequencial, reiniciado a cada funcionário
    int codigo;
    if(aux->proximo == NULL)
        codigo = 0;
    else 
        codigo = aux->proximo->codigo + 1;
    aux->codigo = codigo;
    //b) Executar a função da questão 05 para inserir o nome.
    char texto[50]= "Digite o nome do Dependente:";
    inserirNome(aux->nome, texto);
    //c) Executar a função da questão 06 para inserir o ano.   
    int ano = inserirAno();
    aux->anoNascimento = ano;
    //d)  Executar a função da questão 07 para inserir o status.
    inserirStatus(aux->status);
    
    
    if(--numeroDependentes > 0){
        insereDependente(aux, --numeroDependentes);
    } else {
        return aux;
    }
};