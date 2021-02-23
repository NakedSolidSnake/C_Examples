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
#include <time.h>

#define NUMERO_TENTATIVAS 5

void mensagemErro(void)
{
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

int pegaNumeroMagico(void)
{
	srand(time(NULL));
	return (rand() % 100) + 1 ;
}

int subtraiPontos(int pontos, int tentativas)
{
	return pontos - (pontos / tentativas);
}

int selecionaDificuldade(void)
{
	int dificuldade = 0;
	int tentativas = 0;
	printf("Selecione a dificuldade:\n");
	printf("[1] - Fácil\n");
	printf("[2] - Médio\n");
	printf("[3] - Difícil\n");

	scanf("%d", &dificuldade);

	switch(dificuldade)
	{
	case 1:
		tentativas = 20;
		break;

	case 2:
		tentativas = 10;
		break;

	case 3:
		tentativas = 5;
		break;

	default:
		printf("Esse jogo não possui essa dificuldade. Saindo...\n");
		exit(1);
	}

	return tentativas;
}

int analisaChute(int chute)
{
	return 0;
}


int main(void) {
	printf("****************************************\n");
	printf("*Bem vindo ao nosso jogo de adivinhação*\n");
	printf("****************************************\n");

	int pontos = 1000;
	int chute;
	int tentativas = selecionaDificuldade();
	int numero_secreto = pegaNumeroMagico();

	for(int i = 1; i <= tentativas; i++){
		printf("Adivinhe um numero entre 1 e 100.\tPontos %d.\n", pontos);
		printf("Tentativas %d de %d\n", i, tentativas);
		printf("Qual é o seu chute? ");
		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);

		if(chute < 1 || chute > 100)
		{
			printf("Por favor entre com um valor dentro dos limites.\n");
			printf("Penalidade perde 100 pontos.\n");
			pontos -= 100;
			continue;
		}

		int acertou = (chute == numero_secreto);
		int maior = (chute > numero_secreto);

		if(acertou)
		{
			mensagemVitoria();
			printf("Parabéns! Você acertou! Fez %d pontos em %d tentativas\n", pontos, i);
			break;
		}
		else if(maior)
		{
			pontos = subtraiPontos(pontos , tentativas);
			mensagemErro();
			printf("Chute maior que o numero secreto.\n");
		}
		else
		{
			mensagemErro();
			pontos = subtraiPontos(pontos , tentativas);
			printf("Chute menor que o numero secreto.\n");
		}
		printf("Você Errou!\n");

	}

	return EXIT_SUCCESS;
}
