// 6 -Faça uma função para a inserção do ano de nascimento do dependente;
int inserirAno(){
    int ano; 
    time_t hoje = time(NULL);
    struct tm tm = *localtime(&hoje);
    int esseAno = tm.tm_year + 1900;
    printf("Digite o ano de nascimento valido: \n");
    scanf("%i", &ano);
    if(ano >= 1920 && ano <= esseAno){
        printf("o ano %i eh valido!\n", ano);
    }else {
        printf("Ano invalido, tente novamente! \n");
        ano = inserirAno();
    }
    return ano;
};