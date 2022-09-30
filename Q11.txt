// 11  Escreva uma função para excluir um dependente de algum funcionário, já cadastrado. É importante atualizar o campo quantidade e reconectar a lista corretamente.
 
int excluirTodosDependentes(TDependente* dependentes){
    TDependente *aux = dependentes;
    TDependente *auxsecundario;
    if(aux == NULL)
        return 1;
    while(aux->proximo == NULL){
        aux = auxsecundario;
        aux = aux->proximo;
        free(auxsecundario);
    }
        return 1;
};

TFuncionario* excluirFuncionario(TFuncionario* funcionarios, int codigo){
  TFuncionario *aux = funcionarios;
  TFuncionario *auxsecundario;
  if(aux->codigo = codigo){
      funcionarios = funcionarios->proximo;
      funcionarios->anterior = inicializaFuncionarios();
      free(aux);
      return funcionarios;
  }else{
        while(aux->proximo != NULL){
            if(aux->proximo->codigo = codigo){
                auxsecundario = aux->proximo;
                aux->proximo = aux->proximo->proximo;
                aux->proximo->anterior = aux->anterior;
                if(aux->anterior != NULL){
                    aux->anterior->proximo = aux->proximo;
                };
                if(aux->dependentes != NULL){
                    excluirTodosDependentes(aux->dependentes);
                };
                free(auxsecundario);
            }else{
                aux = aux->proximo;
            };
        }
    };
    return funcionarios;
};
