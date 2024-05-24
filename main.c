#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memoria
#include <locale.h> // bliblioteca de alocação de texto por região
#include <string.h>
int registro()
{

 char arquivo[40];
 char cpf[40];
 char nome[40];
 char sobrenome[40];
 char cargo[40];
 //apresentação
 printf("\t\t\t###Bem Vindo### \n");
 printf("\t\t\t###Área de registrar usuários!###");
 printf("\nPara começarmos digite seu cpf: ");

 scanf("%s", cpf);
 strcpy(arquivo , cpf); //Responsavel por copiar os valores da string
 FILE *file; //cria o arquivo
 file= fopen(arquivo,"w");
 fprintf(file,cpf);// escreve valor da variavel no arquivo
 fclose(file);

 file= fopen(arquivo,"a");
 fprintf(file,",");
 fclose(file);
 printf("Digite o nome:");
 scanf("%s", nome);

 file= fopen(arquivo, "a");
 fprintf(file,nome);
 fclose(file);

 file= fopen(arquivo,"a");
 fprintf(file,",");
 fclose(file);

 printf("Digite o sobrenome:");
 scanf("%s", sobrenome);

 file= fopen(arquivo, "a");
 fprintf(file,sobrenome);
 fclose(file);

 file= fopen(arquivo,"a");
 fprintf(file,",");
 fclose(file);

 printf("E o cargo:");
 scanf("%s", cargo);

 file= fopen(arquivo, "a");
 fprintf(file,cargo);
 fclose(file);
 file = fopen(cpf, "r");

 if(file == NULL){
     printf("A sua requesição não existe!");
 }else{
 printf("Cadastro Realizado com sucesso!");
 system("pause");
 }



}
int consulta()
{

 setlocale(LC_ALL, "Portuguese");
 char cpf[40];
 char conteudo[200];

 printf("Digite o cpf a ser consultado:");
 scanf("%s",cpf);

 FILE *file;
 file = fopen(cpf, "r");

 if(file == NULL){
     printf("A sua requesição não existe!");
 }
 while(fgets(conteudo,200,file )!= NULL){
     printf("\nEssas são as informações do usuario:");
     printf("%s", conteudo);
     printf("\n\n");
 }
 system("pause");
 system("cls");

}
int deletar()
{
 char cpf[40];

 printf("Digite o CPF a ser deletado:");
 scanf("%s",cpf);

 remove(cpf);

 FILE *file;
 file= fopen(cpf,"r");

 if(file == NULL)
 {
    printf("Usuário não encontrado!\n");
    system("pause");
 }

}
int main()
{
    int opcao=0;
    int x = 1;
    for (x=1;x=1;){
        setlocale(LC_ALL, "Portuguese");
        printf("### Catálogo da EBAC ### \n\n"); // inicio do menu
        printf("Escolha opção: \n");
        printf("\t1 - Resgistrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n");
        printf("\t4 - Sair\n");
        printf("Opção:");// final do menu

        scanf("%d", &opcao); //ler oque é digitado e registrado na variavel opcao

        system("cls"); // limpa a tela
        switch(opcao){
            case 1:
            registro();
            break;
            case 2:
            consulta();
            break;
            case 3:
             deletar();
            break;
            case 4:
             printf("Obrigado por utilizar,até uma proxima!");
             return 0;
            break;
            default:
             printf("Essa alternativa não existe");
             system("pause");
            break;
    }
  }
}
