/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "forca.h"

static char palavrasecreta[20] = {0};
static char chutes[26];
static int tentativas = 0;

void abertura(void)
{
	printf("    ______                         ______                       \n");
	printf("   / ____/___  ______________ _   / ____/___ _____ ___  ___     \n");
	printf("  / /_  / __ \\/ ___/ ___/ __ `/  / / __/ __ `/ __ `__ \\/ _ \\ \n");
	printf(" / __/ / /_/ / /  / /__/ /_/ /  / /_/ / /_/ / / / / / /  __/    \n");
	printf("/_/    \\____/_/   \\___/\\__,_/   \\____/\\__,_/_/ /_/ /_/\\___/\n\n\n");

	printf("Instruções: As palavras são frutas, vale acentos e até mesmo hífen\n\n");
}

void desenhaforcaASCII(int status)
{
	switch(status)
	{
	case 0:
		printf("  _______      \n");
		printf(" |/      |     \n");
		printf(" |             \n");
		printf(" |             \n");
		printf(" |             \n");
		printf(" |             \n");
		printf(" |             \n");
		printf("_|___          \n");
		printf("\n\n");
		break;

	case 1:
		printf("  _______      \n");
		printf(" |/      |     \n");
		printf(" |      (_)    \n");
		printf(" |             \n");
		printf(" |             \n");
		printf(" |             \n");
		printf(" |             \n");
		printf("_|___          \n");
		printf("\n\n");
		break;

	case 2:
		printf("  _______      \n");
		printf(" |/      |     \n");
		printf(" |      (_)    \n");
		printf(" |       |     \n");
		printf(" |       |     \n");
		printf(" |             \n");
		printf(" |             \n");
		printf("_|___          \n");
		printf("\n\n");
		break;

	case 3:
		printf("  _______      \n");
		printf(" |/      |     \n");
		printf(" |      (_)    \n");
		printf(" |      \\|    \n");
		printf(" |       |     \n");
		printf(" |             \n");
		printf(" |             \n");
		printf("_|___          \n");
		printf("\n\n");
		break;

	case 4:
		printf("  _______      \n");
		printf(" |/      |     \n");
		printf(" |      (_)    \n");
		printf(" |      \\|/   \n");
		printf(" |       |     \n");
		printf(" |             \n");
		printf(" |             \n");
		printf("_|___          \n");
		printf("\n\n");
		break;

	case 5:
		printf("  _______      \n");
		printf(" |/      |     \n");
		printf(" |      (_)    \n");
		printf(" |      \\|/   \n");
		printf(" |       |     \n");
		printf(" |        \\   \n");
		printf(" |             \n");
		printf("_|___          \n");
		printf("\n\n");
		break;

	case 6:
		printf("  _______      \n");
		printf(" |/      |     \n");
		printf(" |      (_)    \n");
		printf(" |      \\|/   \n");
		printf(" |       |     \n");
		printf(" |      / \\   \n");
		printf(" |             \n");
		printf("_|___          \n");
		printf("\n\n");
		break;

	}
}

void escolhepalavra()
{
	FILE *fd = fopen("palavras.txt", "r");
	if(fd == NULL){
		perror("Arquivo de palavras não disponível\n");
		exit(1);
	}

	int qtddepalavras;
	fscanf(fd, "%d", &qtddepalavras);

	srand(time(NULL));
	int randomico = rand() % qtddepalavras;

	for(int i = 0; i <= randomico; i++)
	{
		fscanf(fd, "%s", palavrasecreta);
	}

	fclose(fd);
}

void adicionapalavra()
{
	char quer;
	printf("\n\nVocê deseja adicionar uma nova palavra no jogo?(S/N)");
	scanf(" %c", &quer);

	if(toupper(quer) == 'S')
	{
		char novapalavra[26];
		printf("QUal a nova palavra? ");
		scanf("%s", novapalavra);

		FILE *f = fopen("palavras.txt", "r+");

		if(f == NULL){
			perror("Arquivo de palavras não disponível\n");
			exit(1);
		}

		int qtd;

		fscanf(f, "%d", &qtd);
		qtd++;

		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d", qtd);

		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", novapalavra);

		fclose(f);
	}
}

void chuta()
{
	char chute;
	scanf(" %c", &chute);	//ignora o enter

	chutes[tentativas] = chute;
	tentativas++;
}

int jachutou(char letra)
{
	int achou = 0;

	for(int j = 0; j < tentativas; j++)
	{
		if(tolower(chutes[j]) == letra){
			achou  = 1;
			break;
		}
	}


	return achou;
}

void desenhaforca()
{
	for(int i = 0; i < strlen(palavrasecreta); i++)
	{
		int achou = jachutou( palavrasecreta[i]);

		if(achou){
			printf("%c ", palavrasecreta[i]);
		}else{
			printf("_ ");
		}
	}
}

int enforcou(){
	int erros = 0;

	for(int i = 0; i < tentativas; i++)
	{
		int existe = 0;
		for(int j = 0; j < strlen(palavrasecreta); j++){
			if(tolower(chutes[i]) == palavrasecreta[j])
			{
				existe = 1;
				break;
			}
		}

		if(!existe)
			erros++;
	}

	desenhaforcaASCII(erros);

	return erros >= 6;
}

int acertou(void)
{
	for(int i = 0; i < strlen(palavrasecreta); i++){
		if(!jachutou(palavrasecreta[i])){
			return 0;
		}
	}
	return 1;
}

void mensagemErro(void)
{
	printf("\n\n\n Você Perdeu!!!\n");
	printf("                          oooo$$$$$$$$$$$$oooo\n");
	printf("                      oo$$$$$$$$$$$$$$$$$$$$$$$$o\n");
	printf("                   oo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o         o$   $$ o$\n");
	printf("   o $ oo        o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o       $$ $$ $$o$\n");
	printf("oo $ $ \"$      o$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$o       $$$o$$o$\n");
	printf("\"$$$$$$o$     o$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$o    $$$$$$$$\n");
	printf("  $$$$$$$    $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("  $$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$$$$$  \"\"\"$$$\n");
	printf("   \"$$$\"\"\"\"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     \"$$$\n");
	printf("    $$$   o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     \"$$$o\n");
	printf("   o$$\"   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$o\n");
	printf("   $$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" "$$$$$$ooooo$$$$o\n");
	printf("  o$$$oooo$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   o$$$$$$$$$$$$$$$$$\n");
	printf("  $$$$$$$$\"$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$\"\"\"\"\"\"\"\"\n");
	printf(" \"\"\"\"       $$$$    \"$$$$$$$$$$$$$$$$$$$$$$$$$$$$\"      o$$$\n");
	printf("            \"$$$o     \"\"\"$$$$$$$$$$$$$$$$$$\"$$\"         $$$\n");
	printf("              $$$o          \"$$\"\"$$$$$$\"\"\"\"           o$$$\n");
	printf("               $$$$o                 oo             o$$$\"\n");
	printf("                \"$$$$o      o$$$$$$o\"$$$$o        o$$$$\n");
	printf("                  \"$$$$$oo     \"\"$$$$o$$$$$o   o$$$$\"\"  \n");
	printf("                     \"\"$$$$$oooo  \"$$$o$$$$$$$$$\"\"\"\n");
	printf("                        \"\"$$$$$$$oo $$$$$$$$$$       \n");
	printf("                                \"\"\"\"$$$$$$$$$$$        \n");
	printf("                                    $$$$$$$$$$$$       \n");
	printf("                                     $$$$$$$$$$\"      \n");
	printf("                                      \"$$$\"\"\"\"\n");
	printf("\n\n\n");
}

void mensagemVitoria(void)
{
	printf("\n\nParabéns você ganhou!!!\n");

	printf("                                       .\n");
	printf("              . .                     -:-             .  .  .\n");
	printf("            .'.:,'.        .  .  .     ' .           . \\ | / .\n");
	printf("            .'.;.`.       ._. ! ._.       \\          .__\\:/__.\n");
	printf("             `,:.'         ._\\!/_.                     .';`.      . ' .\n");
	printf("             ,'             . ! .        ,.,      ..======..       .:.\n");
	printf("            ,                 .         ._!_.     ||::: : | .        ',\n");
	printf("     .====.,                  .           ;  .~.===: : : :|   ..===.\n");
	printf("     |.::'||      .=====.,    ..=======.~,   |\\\"|: :|::::::|   ||:::|=====|\n");
	printf("  ___| :::|!__.,  |:::::|!_,   |: :: ::|\"|l_l|\"|:: |:;;:::|___!| ::|: : :|\n");
	printf(" |: :|::: |:: |!__|; :: |: |===::: :: :|\"||_||\"| : |: :: :|: : |:: |:::::|\n");
	printf(" |:::| _::|: :|:::|:===:|::|:::|:===F=:|\"!/|\\!\"|::F|:====:|::_:|: :|::__:|\n");
	printf(" !_[]![_]_!_[]![]_!_[__]![]![_]![_][I_]!//_:_\\![]I![_][_]!_[_]![]_!_[__]!\n");
	printf(" -----------------------------------\"---\'\'\'\'\'\'\'---\"-----------------------\n");
	printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |= _ _:_ _ =| _ _ _ _ _ _ _ _ _ _ _ _\n");
	printf("                                     |=    :    =|                Valkyrie\n");
	printf("_____________________________________L___________J________________________\n");
	printf("--------------------------------------------------------------------------\n");
}

int main(void) {

	abertura();
	escolhepalavra(palavrasecreta);

	desenhaforcaASCII(0);
	do{

		desenhaforca();
		chuta();

	}while(!acertou() && !enforcou());

	desenhaforca();

	if(acertou()){
		mensagemVitoria();
	}
	else{
		mensagemErro();
		printf("A palavra era %s\n\n", palavrasecreta);
	}


	adicionapalavra();

	return EXIT_SUCCESS;
}
