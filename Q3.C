//3 - Escreva uma função que solicite a digitação de um número inteiro, positivo ou nulo. Após a validação o número será retornado via função;

Esta função deverá receber uma frase, como parâmetro, para ser exibida na solicitação da digitação.
int verificaNumeroPositivo(char* frase){
    int numero;
    printf("%s\n", frase);
    scanf("%i", &numero);
    if(numero >=0 || numero == NULL){
        printf("O valor %i eh valido\n", numero);
        return numero;
    }else {
        printf("O valor %i nao eh valido, digite novamente\n", numero);
        verificaNumeroPositivo(frase);
        return 0;
    };
};