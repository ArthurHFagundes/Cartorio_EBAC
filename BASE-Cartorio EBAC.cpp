#include <stdio.h> // BIBLIOTECA DE COMUNICA��O
#include <stdlib.h> // RESERVA DE MEM�RIA PARA ALGO
#include <locale.h> // BIB. DE TEXTO "DICION�RIO"
#include <string.h> // BIB. PARA AS STRING FUNCIONAREM

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //ARMAZENA VAR. TIPO STRING >> LE A STRING "CPF"
	
	strcpy(arquivo, cpf); //COPIA O CPF PARA O ARQUIVO
	
	FILE *file; //CRIA O ARQUIVO(file) NO BANCO DE DADOS DO PC(FILE)
	file = fopen(arquivo, "w"); //ABRE O ARQUIVO(file)
	fprintf(file, cpf); //SALVA NO ARQUIVO(file)
	fclose(file);  //FECHA O ARQUIVO(file)
	
	file = fopen(arquivo, "a"); //ABRE O ARQUIVO E ATUALIZA
	fprintf(file, ", "); //SEPARA OS CPFs COM ","
	fclose(file);
	
	printf("Digite o NOME a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fprintf(file, ", "); 
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fprintf(file, ", "); 
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //CONTINUA APARECENDO AT� O USU�RIO � QUERER MAIS
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //L� O ARQUIVO
	
	if(file == NULL) //SE FILE FOI INEXISTENTE
	{
		printf("\nArquivo n�o localizado!\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL) //ENQUANTO O PC TENTA PEGAR AS INFORMA��ES DE NO M�XIMO 200 CARACTERES NO ARQUIVO(file) E FOR DIFERENTE DE NULO
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O CPF do Usu�rio n�o foi encontrado \n");
		system("pause");
	}
}

int main()
{
	
	int opcao=0; // PRIMEIRA VARIAVEL SEMPRE SETAR COMO "0"
	int laco=1;
	
	for(laco=1;laco=1;) //LA�O INFINITO
	{
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese"); // SETAR PARA A LIGUAGEM & ACENTUA��O DO BR
	
		printf(" ### Cart�rio da EBAC \n\n"); 
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); //ARMAZENA VAR. TIPO INT. >> LE A VARIAVEL OP��O
		
		system("cls"); // LIMPAR A TELA
		
		switch(opcao) // SWITCH > IF ( MEM�RIA E PROCESSAMENTO)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}

	}
}
