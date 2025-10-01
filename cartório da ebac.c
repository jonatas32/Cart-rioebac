#include <stdio.h> // Comunicação com usuário
#include <stdlib.h> // Alocação de espaço em memória
#include <locale.h> // Alocação de texto por região
#include <string.h> //responsável por cuidar das string
 
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
		printf("não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // while = enquanto
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	 system("pause");
}

int registro()//função responsavel por cadastrar os usuário no sistema
{
	// inicia criação de variávveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variávveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usuário não se encontra no sistema!.\n");
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
	
		printf("******  CARTÓRIO DA EBAC  *****\n\n"); // Inicio do menu
		printf("Opções:\n\n ");
		printf("\t - 1 - Consultar nomes\n");
		printf("\t - 2 - Registrar nomes\n");
		printf("\t - 3 - Deletar nomes\n");
		printf("\t - 4 - Sair do sistema\n\n");
		printf("Opção: "); // fim do menu
		
		scanf("%d", &opcao); // armazenando a escolha do usuário
	
		system("cls"); // responsavel por limparba tela
		
		switch(opcao)  // inicio da seleção do menu
		{
			case 1: 
			consultar();	 //  chamada de funções
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
			printf("Essa opção não está disponivel!\n");	
			system("pause");
			break;	
				
		}// fim da seleção	
	
	}
}
