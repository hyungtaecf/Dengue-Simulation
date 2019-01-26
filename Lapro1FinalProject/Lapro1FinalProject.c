#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
void imagem(char city[20][20], int P, int total, int n, int key, int s) {//Imagem do ambiente
	int l,/*Linha*/c;//Coluna
	if (key == 0) getchar();
	else Sleep(s);//Tempo até atualizar de novo
	system("cls");
	printf("\t\t\tPessoas: %d/%d\tMosquitos: %d\n\t\t# # # # # # # # # # # # # # # # # # # # # ", P, total, n);
	for (l = 0; l < 20; l++) {
		printf("#\n\t\t# ");
		for (c = 0; c < 20; c++) printf("%c ", city[l][c]);
	}
	printf("#\n\t\t# # # # # # # # # # # # # # # # # # # # # #\n");
}
void andar(char tipo, char mat[20][20], int l, int c) {//Andar para uma casa vazia
	int l2, c2/*sentido que vai andar*/, key = 0;//chave do ciclo
	while (key == 0) {
		l2 = rand() % 3 - 1;
		c2 = rand() % 3 - 1;
		if ((mat[l + l2][c + c2] == ' ') && ((l + l2) <= 19) && ((l + l2) >= 0) && ((c + c2) <= 19) && ((c + c2) >= 0)) {
			mat[l + l2][c + c2] = tipo;
			mat[l][c] = ' ';
			key = 1;//Sai do ciclo
		}
	}
}
int perception(char tipo, char mat[20][20], int l, int c) {//Percepção
	int l2, c2/*sentido que vai perceber*/, r = 0/*return*/, m = 0/*percepção do macho*/;
	for (c2 = -1; c2 < 2; c2++) for (l2 = -1; l2 < 2; l2++) if ((((l + l2) >= 0) && ((l + l2) <= 19)) && (((c + c2) >= 0) && ((c + c2) <= 19))) if (mat[l + l2][c + c2] == ' ') r = 1;
	if (tipo == 'P') if (r == 1) for (c2 = -1; c2 < 2; c2++) for (l2 = -1; l2 < 2; l2++) if ((((l + l2) >= 0) && ((l + l2) <= 19)) && (((c + c2) >= 0) && ((c + c2) <= 19))) if (mat[l + l2][c + c2] == 'F') r = 2;//Vira C
	if (tipo == 'F') for (c2 = -1; c2 < 2; c2++) for (l2 = -1; l2 < 2; l2++) if ((((l + l2) >= 0) && ((l + l2) <= 19)) && (((c + c2) >= 0) && ((c + c2) <= 19))) if ((mat[l + l2][c + c2] == 'M') || (mat[l + l2][c + c2] == 'P')) r = 2;//Tem M ou P ao redor
	if (tipo == 'M') for (c2 = -1; c2 < 2; c2++) for (l2 = -1; l2 < 2; l2++) if ((((l + l2) >= 0) && ((l + l2) <= 19)) && (((c + c2) >= 0) && ((c + c2) <= 19)) && (m == 0)) if (mat[l + l2][c + c2] == 'F') {
		if (perception('f', mat, (l + l2), (c + c2)) == 1) {//É enviada uma letra diferente de F para apenas ver se tem espaços livres
			andar('f', mat, (l + l2), (c + c2));//Para não se acasalar mais durante o ciclo
			mat[l + l2][c + c2] = 'o';//Bota ovo. A letra é minúscula para não nascer quando for lido
			m = 1;//Chave
			r = 2;//Para testar se pode andar
		}
	}
	return(r);//0: Está cercado; 1: Tem casas vazias ao redor; 2: Tem M ou P ao redor(para F's)
}
void inserir(char tipo, char city[20][20], int n) {//Inserir personagens no ambiente
	int
		l/*Linha*/, c/*Coluna*/, cont = 0;//Contador
	while (cont < n) {
		l = rand() % 20;
		c = rand() % 20;
		if (city[l][c] == ' ') {
			city[l][c] = tipo;
			cont++;
		}
	}
}
main() {
	char city[20][20]/*Ambiente*/, tipo/*letra*/, mat[20][20];//matriz auxiliar
	int l/*Linha*/, c/*Coluna*/, l2, c2/*sentido que vai fazer a ação (F)*/, k2/*chave do ciclo (F)*/,
		n/*Nº de mosquitos totais*/, P/*Nº de pessoas*/, A/*Nº de agentes de saúde*/, F/*Nº de mosquitos-fêmea*/,
		M/*Nº de mosquitos-macho*/, total/*Nº total de pessoas*/, key/*Chave-ciclo*/, kill = 0/*Mosquitos mortos pelos agentes*/,
		eggkill = 0/*Ovos mortos pelos agentes*/, born = 0/*Novos mosquitos*/, s=0/*Segundos por ciclo*/, celulas = 1,/*Casas disponíveis*/cont;//Contador/Variável auxiliar
	float s2=1;//aux para s
	srand(time(NULL));
	for (c = 0; c < 20; c++) for (l = 0; l < 20; l++) city[l][c] = ' ';//Declarando todas as casas como "vazio"
	printf("\n\n\tEpidemia da Dengue\n\t\tpor Hyung Tae C. Figur\n\n\n\t- Configurações:\n\n\t\tNúmero de pessoas: ");//Inserindo pessoas no ambiente
	scanf("%d", &P);
	total = P;
	inserir('P', city, P);
	printf("\t\tNúmero de agentes de saúde: ");//Inserindo agentes de saúde no ambiente
	scanf("%d", &A);
	inserir('A', city, A);
	printf("\t\tNúmero de mosquitos-fêmea: ");//Inserindo mosquitos-fêmea no ambiente
	scanf("%d", &F);
	inserir('F', city, F);
	printf("\t\tNúmero de mosquitos-macho: ");//Inserindo mosquitos-macho no ambiente
	scanf("%d", &M);
	inserir('M', city, M);
	n = F + M;//Quantidade atual de mosquitos
	do {
		printf("\t\tPassar ciclos (automáticamente[1], manulamente[0]): ");
		scanf("%d", &key);
	} while ((key != 0) && (key != 1));
	if (key == 1) {
		printf("\t\tSegundos por ciclo: ");
		scanf("%f", &s2);
	}
	s = s2 * 1000;//Precisa de uma variável auxiliar para passar de real para inteiro
	for (l = 0; l < 20; l++)for (c = 0; c < 20; c++) mat[l][c] = city[l][c];//Igualando a matriz principal com a matriz auxiliar
	imagem(city, P, total, n, key, s);//Atualiza a imagem
	while ((P > 0) && (celulas > 0) && (n > 0)) {//Limites da simulação
		celulas = 0;//Reseta nº de célular livres
		P = 0;//Reseta nº de pessoas
		n = 0;//Reseta nº de mosquitos
		for (l = 0; l < 20; l++) for (c = 0; c < 20; c++) switch (city[l][c]) {
		case 'P': {//Pessoas
			if (perception('P', mat, l, c) == 0) P++;
			else if (perception('P', mat, l, c) == 1) {
				andar('P', mat, l, c);
				P++;//Contador de pessoas no ambiente
			}
			else if (perception('P', mat, l, c) == 2) andar('c', mat, l, c);
		} break;
		case 'C': {//Pessoas contaminadas
			if (perception('C', mat, l, c) == 1) andar('C', mat, l, c);
		} break;
		case 'O': {//Ovos de mosquito
			cont = rand() % 2;
			if (cont == 0) mat[l][c] = 'm';//Para nenhuma fêmea se acasalar com ele até o fim do ciclo
			else mat[l][c] = 'f';//Para nenhum macho se acasalar com ela até o fim do ciclo
			n++,//Contador de mosquitos no ambiente
				born++;//Contador de novos mosquitos
		} break;
		case 'M': {//Mosquitos-macho
			cont = perception('M', mat, l, c);
			if (cont == 1) andar('m', mat, l, c);
			else if (cont == 2) {
				if (perception('m', mat, l, c) == 1) andar('m', mat, l, c);//É enviada uma letra diferente de M para apenas ver se tem espaços livres
			}
			n++;//Contador de mosquitos no ambiente
		} break;
		case 'F': {//Mosquitos-fêmea
			if (perception('F', mat, l, c) == 1) andar('f', mat, l, c);
			else if (perception('F', mat, l, c) == 2) {
				k2 = 0;//chave
				while (k2 == 0) {
					l2 = rand() % 3 - 1;
					c2 = rand() % 3 - 1;
					if (mat[l + l2][c + c2] == 'M') {
						if (perception('f', mat, l, c) == 1) {//É enviada uma letra diferente de F para apenas ver se tem espaços livres
							andar('f', mat, l, c);//Para não se acasalar mais durante o ciclo
							mat[l][c] = 'O';//Bota ovo
						}
						k2 = 1;//Chave do ciclo
					}
					if (mat[l + l2][c + c2] == 'P') {
						mat[l + l2][c + c2] = 'C';//Contamina
						if (perception('f', mat, l, c) == 1) {//É enviada uma letra diferente de F para apenas ver se tem espaços livres
							andar('f', mat, l, c);
							if ((l2 == -1) || (l2 == 0 && c2 == -1)) P--;//Contador de pessoas no ambiente
						}
						k2 = 1;//Chave do ciclo
					}
				}
			}
			n++;//Contador de mosquitos no ambiente
		} break;
		case 'A': {//Agentes de saúde
			if ((l == 19) && (c == 19)) {
				if ((mat[0][0] == ' ') || (mat[0][0] == 'M') || (mat[0][0] == 'F') || (mat[0][0] == 'O')) {
					if ((mat[0][0] == 'M') || (mat[0][0] == 'F')) kill++;//Contador de mosquitos mortos
					if (mat[0][0] == 'O') eggkill++;//Contador de ovos de mosquito mortos
					mat[0][0] = 'A';
					mat[19][19] = ' ';
				}
			}
			else if ((mat[l][c + 1] == ' ') || (mat[l][c + 1] == 'M') || (mat[l][c + 1] == 'F') || (mat[l][c + 1] == 'O')) {
				if ((mat[l][c + 1] == 'M') || (mat[l][c + 1] == 'F'))
					kill++;//Contador de mosquitos mortos
				if (mat[l][c + 1] == 'O')
					eggkill++;//Contador de ovos de mosquito mortos
				mat[l][c + 1] = 'A';
				mat[l][c] = ' ';
				if (c == 19) {
					l++;
					c = 1;//Para não ler a casa seguinte
				}
				else c++;//Para não ler a casa seguinte
			}
		} break;
		case ' ': celulas++; break;//Contador de células vazias
		}
		for (l = 0; l < 20; l++) for (c = 0; c < 20; c++) if (mat[l][c] == 'f') mat[l][c] = 'F';//Destroca F
		for (l = 0; l < 20; l++) for (c = 0; c < 20; c++) if (mat[l][c] == 'm') mat[l][c] = 'M';//Destroca M
		for (l = 0; l < 20; l++) for (c = 0; c < 20; c++) if (mat[l][c] == 'o') mat[l][c] = 'O';//Destroca O
		for (l = 0; l < 20; l++) for (c = 0; c < 20; c++) if (mat[l][c] == 'c') mat[l][c] = 'C';//Destroca C
		for (l = 0; l < 20; l++) for (c = 0; c < 20; c++) city[l][c] = mat[l][c];//Iguala a matriz principal à matriz auxiliar
		imagem(city, P, total, n, key, s);//Atualiza a imagem
	}//Fim
	printf("\t\t    Fim da simulação\t(APERTE ENTER)");
	getchar();
	if (key == 1) getchar();
	system("cls");
	printf("\n\n\t- Relatório da simulação:\n\n\t\tDesfecho: ");
	if (P == 0) printf("Todas as pessoas foram contaminadas.\n\n");
	if (n >= 360) printf("O ambiente lotou.\n\n");
	if (n == 0) printf("Os agentes de saúde conseguiram eliminar\n\t\t\t  todos os mosquitos da dengue.\n\n");
	printf("\t\tNº de mosquitos mortos: %d\n\t\tNº de ovos mortos: %d\n\t\tNº de novos mosquitos: %d\n", kill, eggkill, born);
}
