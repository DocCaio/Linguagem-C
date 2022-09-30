// 9 - Escreva uma função para inserir um funcionário no cadastro. Lembre-se do tipo de lista que está utilizando.

TFuncionario* insereFuncionario(TFuncionario* lista){
    TFuncionario *aux = (TFuncionario*)malloc(sizeof(TFuncionario));
    aux->anterior = inicializaFuncionarios();
    aux->proximo = lista;
    if(lista != NULL)
        lista->anterior = aux;
    // a)O código do funcionário será criado com um número sequencial
    int codigo;
    if(aux->proximo == NULL)
        codigo = 0;
    else 
        codigo = aux->proximo->codigo + 1;
    aux->codigo = codigo;
    //b)Executar a função da questão 05 para inserir o nome.
    char texto[50]= "Digite o nome do Funcionario:";
    inserirNome(aux->nome, texto);
    //c)  Utilizando a função da questão 03, pergunte ao cliente a quantidade de dependentes deste funcionário.

// Se o valor digitado for igual a zero, coloque NULL no campo lista de dependentes,
 //Se for maior que zero, inicia a inserção de dependentes.
    int numeroDependentes = verificaNumeroPositivo("Digite a quantidade de dependentes:");
    if(numeroDependentes == NULL || numeroDependentes == 0){
        aux->dependentes = NULL;
    }else{
        TDependente *dependentes = inicializaDependentes();
        aux->numeroDependentes = numeroDependentes;
        aux->dependentes = insereDependente(dependentes, numeroDependentes);
    };
    return aux;
};
// d) Executar a função da questão 08.