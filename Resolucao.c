#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Constantes
#define ANOATUAL 2020

//Estrutura
//QuestÃ£o 01
typedef struct dependente dependente;
struct dependente{
    //Dados bÃ¡sicos
    int codigoDep;
    char nomeDep[30];
    int ano;
    char status;
    
    //Ponteiro
    dependente *proximo;
};

//QuestÃ£o 02
typedef struct func funcionario;
struct func{
    //Dados bÃ¡sicos
    int codigoFunc;
    char nomeFunc[30];
    int qtdeDep;
    dependente *listaDep;
    
    //Ponteiros
    funcionario *anterior;
    funcionario *proximo;
};

//ProtÃ³tipos
int receberNumero(char*);
void menu();
void inserirNome(char *nome, char *texto);
int inserirAno();
void inserirStatus(char *status);
dependente* inserirDependente(int quantidade, int codDep, dependente *dep);
funcionario* inserirFuncionario(int codFunc, funcionario *ultimoFuncionario);
void listar(int nFunc, int nDep, dependente *dep, funcionario *func);
funcionario* buscarFuncionario(funcionario *func, int codigo);
void excluirFuncionario(funcionario *excluir);
void excluirDepFuncionario(dependente *depExcluir);
char excluirDependente(funcionario *func, dependente *excluir, dependente *pai, int codDependente);

//Principal
int main(){
    menu();
    return 0;
}

//FunÃ§Ãµes
//QuestÃ£o 03
int receberNumero(char *frase){
    int numero;
    do{
        printf("%s", frase);
        scanf("%i", &numero);
        
        if (numero < 0) {
            printf("\nInvÃ¡lido.");
        }
    } while (numero < 0);
    return numero; 
}

//QuestÃ£o 04
void menu(){
    char op = 'l';
    funcionario *func = NULL, //InÃ­cio da lista de funcionÃ¡rio
                *ultimoFunc = NULL, //Fim da lista de funcionÃ¡rio
                *buscar = NULL; //Localizar um funcionÃ¡rio
    int codFunc = 0;
    int codigo;
    int codDependente;
    
    while (op != 'F') {
        printf("\nA - Inserir FuncionÃ¡rio"
                "\nB - Inserir Dependente"
                "\nC - Excluir FuncionÃ¡rio"
                "\nD - Excluir Dependente"
                "\nE - Listar"
                "\nF - Sair"
                "\nDigite sua opÃ§Ã£o: ");
        //fflush(stdin);
        scanf(" %c", &op);
        op = toupper(op);
        
        switch (op){
            case 'A':
                    codFunc++;
                    ultimoFunc = inserirFuncionario(codFunc, ultimoFunc);
                    if (func == NULL) {
                        func = ultimoFunc;
                    }
                    break;
            case 'B':
                if (codFunc > 0) {
                        codigo = receberNumero("\nDigite o cÃ³digo do funcionÃ¡rio: ");
                        buscar = buscarFuncionario(func, codigo);
                        if (buscar != NULL) {
                            buscar->listaDep = inserirDependente(1, buscar->qtdeDep+1, buscar->listaDep);
                            buscar->qtdeDep++;
                        } else {
                            printf("\nFuncionÃ¡rio nÃ£o encontrado.");
                        }
                    } else {
                         printf("\nNÃ£o existe cadastro de funcionÃ¡rios.");
                    }
                    break;
            case 'C':
                    if (codFunc > 0) {
                        codigo = receberNumero("\nDigite o cÃ³digo do funcionÃ¡rio: ");
                        buscar = buscarFuncionario(func, codigo);
                        if (buscar == ultimoFunc) {
                            ultimoFunc = ultimoFunc->anterior;
                        }
                        
                        if (buscar != NULL) {
                            if (buscar->anterior == NULL) {
                                func = func->proximo;
                            }
                            
                            excluirFuncionario(buscar);
                        } else {
                            printf("\nFuncionÃ¡rio nÃ£o encontrado.");
                        }
                    } else {
                         printf("\nNÃ£o existe cadastro de funcionÃ¡rios.");
                    }
                    break;
            case 'D':
                    if (codFunc > 0) {
                        codigo = receberNumero("\nDigite o cÃ³digo do funcionÃ¡rio: ");
                        buscar = buscarFuncionario(func, codigo);
                        if (buscarFuncionario != NULL) {
                            if (buscar->qtdeDep > 0) {
                                codDependente = receberNumero("\nDigite o cÃ³digo do dependente: ");
                                if (excluirDependente(buscar, buscar->listaDep, NULL, codDependente) == 'S') {
                                    buscar->qtdeDep--;
                                } else {
                                    printf("\nDependente nÃ£o encontrado.");
                                }
                            } else {
                                printf("\nFuncionÃ¡rio nÃ£o possui dependentes");
                            }
                        } else {
                            printf("\nFuncionÃ¡rio nÃ£o encontrado.");
                        }
                    } else {
                         printf("\nNÃ£o existe cadastro de funcionÃ¡rios.");
                    }
                    break;
            case 'E':
                    if (codFunc > 0) {
                        listar(1, 0, NULL, func);
                    } else {
                        printf("\nNÃ£o existe cadastro de funcionÃ¡rios.");
                    }
                    break;
            case 'F':
                    printf("\nPrograma finalizado.");
                    break;
            default:
                    printf("\nInvÃ¡lido.");
        }    
    }
}

//QuestÃ£o 05
void inserirNome(char *nome, char *texto){
    printf("%s", texto);    
    getchar();
    fgets(nome, 30, stdin);
    nome[strlen(nome) - 1] = '\0';
}

//QuestÃ£o 06
int inserirAno(){
    int ano;
    printf("\nDigite o ano de nascimento: ");
    scanf("%i", &ano);
    while (ano < 1920 || ano > ANOATUAL) {
        printf("\nAno invÃ¡lido.");
        printf("\nDigite o ano de nascimento: ");
        scanf("%i", &ano);
    }
    return ano;
}

//QuestÃ£o 07
void inserirStatus(char *status){
    *status = 'i';
    while (*status != 'C' && *status != 'P' && *status != 'F'){
        printf("\nDigite o status do dependente: ");
        scanf(" %c", status);
        *status = toupper(*status);
        
        if (*status != 'C' && *status != 'P' && *status != 'F') {
            printf("\nInvÃ¡lido");
        }
    }
}

//QuestÃ£o 08
dependente* inserirDependente(int quantidade, int codDep, dependente *dep){
    if (quantidade > 0) { //Caso recursivo
        //Alocar espaÃ§o de memÃ³ria
        dependente *novoDep = (dependente*) malloc (sizeof(dependente));
    
        //Dados bÃ¡sicos
        novoDep->codigoDep = codDep;
        inserirNome(novoDep->nomeDep, "\nDigite o nome do dependente: ");
        novoDep->ano = inserirAno();
        inserirStatus(&novoDep->status);
        
        //Preencher ponteiro - inserÃ§Ã£o pelo inÃ­cio
        novoDep->proximo = dep;
        return inserirDependente(quantidade - 1, codDep + 1, novoDep);
    } else { //Caso base
        return dep;
    }
}

//QuestÃ£o 09
funcionario* inserirFuncionario(int codFunc, funcionario *ultimoFuncionario) {
    //Alocar espaÃ§o de memÃ³ria
    funcionario *novoFunc = (funcionario*) malloc (sizeof(funcionario));
    
    //Dados bÃ¡sicos
    novoFunc->codigoFunc = codFunc;
    inserirNome(novoFunc->nomeFunc, "\nDigite o nome do FuncionÃ¡rio: ");
    novoFunc->qtdeDep = receberNumero("\nQuantidade de dependentes: ");
    if (novoFunc->qtdeDep > 0) { //Inserir dependentes
        novoFunc->listaDep = inserirDependente(novoFunc->qtdeDep, 1, NULL);
    } else { //NÃ£o possui dependentes
        novoFunc->listaDep = NULL;
    }
    
    //Atualizar Ponteiros - InserÃ§Ã£o pelo fim
    novoFunc->anterior = ultimoFuncionario;
    novoFunc->proximo = NULL;
    if (ultimoFuncionario != NULL) {
        ultimoFuncionario->proximo = novoFunc;
    }
    return novoFunc;
}

//QuestÃ£o 10
void listar(int nFunc, int nDep, dependente *dep, funcionario *func) {
    if (dep != NULL) { //Caso recursivo
        printf("\n\t%iÂº - CÃ³digo %i - Nome %s - Ano de nascimento %i - Status %c.", 
                nDep, dep->codigoDep, dep->nomeDep, dep->ano, dep->status);
        listar(nFunc, nDep+1, dep->proximo, func);
    } else if (func != NULL) { //Caso recursivo
        printf("\nFuncionÃ¡rio %i", nFunc);
        printf("\nCÃ³digo %i - Nome %s - %i dependentes.", 
                func->codigoFunc, func->nomeFunc, func->qtdeDep);
        if (func->qtdeDep > 0) {
            printf("\nLista de dependentes");
            listar(nFunc+1, 1, func->listaDep, func->proximo);
        } else {
            listar(nFunc+1, 0, NULL, func->proximo);
        }
    }
}

funcionario* buscarFuncionario(funcionario *func, int codigo){
    if (func == NULL) { //Caso base
        return NULL;
    } else if (codigo == func->codigoFunc) {
        return func;
    } else {
        return buscarFuncionario(func->proximo, codigo);
    }
}

//QuestÃ£o 11
void excluirFuncionario(funcionario *excluir){
    //Se tiver dependente exclui
    if (excluir->listaDep != NULL) {
        excluirDepFuncionario(excluir->listaDep);    
    }
    
    //Excluir FuncionÃ¡rio
    if (excluir->anterior != NULL) {
        excluir->anterior->proximo = excluir->proximo;
    }
    if (excluir->proximo != NULL) {
        excluir->proximo->anterior = excluir->anterior;
    }
    
    free(excluir);
}

//QuestÃ£o 12
void excluirDepFuncionario(dependente *depExcluir) {
    if (depExcluir->proximo != NULL){
        excluirDepFuncionario(depExcluir->proximo);
        free(depExcluir);
    }
}

char excluirDependente(funcionario *func, dependente *excluir, dependente *pai, int codDependente){
    if (excluir == NULL) { //Caso base
        return 'N';
    } else if (codDependente == excluir->codigoDep) { //Caso base
        if (pai == NULL) {
            func->listaDep = func->listaDep->proximo;
        } else {
            pai->proximo = excluir->proximo;
        }
        free(excluir);
        return 'S';
    } else {
        excluirDependente(func, excluir->proximo, excluir, codDependente);
    }
}