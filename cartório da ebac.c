#include <stdio.h> // Comunica��o com usu�rio
#include <stdlib.h> // Aloca��o de espa�o em mem�ria
#include <locale.h> // Aloca��o de texto por regi�o
#include <string.h> //respons�vel por cuidar das string
 
int consultar()
{
	setlocale(LC_ALL,"Portuguese"); //Definindp a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r"= ler o arquivo
	
	if(file == NULL)
	{
		printf("n�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // while = enquanto
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	 system("pause");
}

int registro()//fun��o responsavel por cadastrar os usu�rio no sistema
{
	// inicia cria��o de vari�vveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�vveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo  ( "w" = criar ou escrever )
	fprintf(file,cpf);// salva o valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usu�rio n�o se encontra no sistema!.\n");
			system("pause");
		}
		
}


int main()
{
	int opcao=0; // Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		

		setlocale(LC_ALL,"Portuguese"); //Definindp a linguagem
	
		printf("******  CART�RIO DA EBAC  *****\n\n"); // Inicio do menu
		printf("Op��es:\n\n ");
		printf("\t - 1 - Consultar nomes\n");
		printf("\t - 2 - Registrar nomes\n");
		printf("\t - 3 - Deletar nomes\n");
		printf("\t - 4 - Sair do sistema\n\n");
		printf("Op��o: "); // fim do menu
		
		scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
		system("cls"); // responsavel por limparba tela
		
		switch(opcao)  // inicio da sele��o do menu
		{
			case 1: 
			consultar();	 //  chamada de fun��es
			break;
			
			case 2:
			registro();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");	
			system("pause");
			break;	
				
		}// fim da sele��o	
	
	}
}
