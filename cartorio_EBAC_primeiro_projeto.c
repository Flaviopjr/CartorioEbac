#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //blblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registrar() //função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//início de criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Você escolheu registrar nomes!\n");
	system("pause");
	
	system("cls"); //responsável por limpar a tela
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Você escolheu consultar nomes!\n");
	system("pause");
	
	system("cls");
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não foi encontrado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário.");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	int opcao=0;
	
	printf("Você escolheu deletar nomes!\n");
	system("pause");
	
	system("cls");
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não foi encontrado no sistema.\n\n");
		system("pause");
	}
	
	if(file != NULL)
	{
		printf("Deseja mesmo deletar este usuário?\n\n");
		printf("Digite 1 para deletar ou 2 para retornar ao menu: ");
		scanf("%d", &opcao);
    }
	
	system("cls");
		
	switch(opcao)
	{		
		case 1:
		fclose(file);
		remove(cpf);
		printf("O usuário foi deletado com sucesso.\n\n");
		system("pause");
		break;
		
		case 2:
		break;
	}
	
}

int main() 
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
		printf("\t Cartório da EBAC \n\n"); //inicio do menu
		printf("  Escolha a opção desejada no menu abaixo: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando escolha do usuário
	
		system("cls");
		
		switch(opcao) //início de seleção do menu
		{
			case 1:
			registrar();//chamada de funções
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.\n");
			return 0;
			break;
			
			default:
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
		}
	
	}	
}
