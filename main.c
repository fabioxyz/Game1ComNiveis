#include <stdio.h>
#define TMAX 100
#define TENTATIVAS 10

void interface() {
	int i;
	for (i = 0; i < 26; i++) {
		printf("*");
	}
	putchar('\n');
	printf("*"); printf("\t  M E N U \t"); printf(" *"); putchar('\n');
	printf("*"); printf("\tby:fabioxyz\t"); printf(" *"); putchar('\n');
	printf("*"); printf("\t\t\t *"); putchar('\n');
	printf("*"); printf(" (1) Comecar | (2) Sair "); printf("*"); putchar('\n');
	for (i = 0; i < 26; i++) {
		printf("*");
	}
	putchar('\n');
	putchar('\n');
}

int ler() {
	int e;
	printf(" - ");
	scanf("%d", &e);
	return e;
}

int gerador(int maximo) {
	int numero;
	numero = rand() % maximo;

	return numero;
}

int niveis(int i) {
	int n;
	if (i == 0) {
		n = 0;
	}
	else if (i == 1) {
		n = 3;
	}
	else if (i == 2) {
		n = 5;
	}
	else if (i == 3) {
		n = 8;
	}
	else if (i == 4) {
		n = 9;
	}

	return n;
}

int main() {
	int e, num, n, ch, i;
	int numcerto;
	int nivel[] = {1,2,3,4,5};
	int tent[] = { 10,7,5,2,1 };

	interface();
	srand(time(NULL)); // Inicializa o gerador de numeros aleatorios



	do {
		e = ler();
		switch (e) {
		case 1: //NIVEL 1-10,NIVEL2-7,NIVEL3-5,NIVEL4-2-NIVEL5-1
			
			do {
				n = 0;
				i = 0;
				
				printf("\tNIVEL %d (%d tentativas)\n\n", nivel[i], TENTATIVAS - n);
				numcerto = gerador(TMAX);
				while ((TENTATIVAS - n) != 0) {
				printf("Acerte o numero certo entre 0 a %d\n", TMAX);
				printf("Tentativas restantes : %d\n", TENTATIVAS - n);
				printf("Numero certo %d\n", numcerto);

					num = ler();
					n++;
					if (num == numcerto) {
						printf("Acertou, o numero certo era %d\n", num);
						printf("Parabens,passou para o nivel seguinte.\n\n");
						i++;
						if (i == 5) {
							printf("\n\t\tPARABENS, Completou todos os niveis.\n\n");
							return -1;
						}
						numcerto = gerador(TMAX);
						n = niveis(i);
						printf("\tNIVEL %d (%d tentativas)\n\n", nivel[i], TENTATIVAS - n);
					}
					else {
						printf("Errou,agora tem %d tentativas.\n", TENTATIVAS - n);
					}
				}
				printf("\tInfelizmente as suas tentativas esgotaram-se :(\n");
				printf("\t\tO numero certo era %d\n\n", numcerto);
				printf("Recomecar (1) ou sair (2)");
				ch = ler();
				putchar('\n');
			} while (ch != 2);

			printf("\nSaiu.\n\n");

			break;
		case 2: printf("\nSaiu.\n\n");
			return 1; break;
		default: printf("Opcao invalida!\n");
			break;
		}
	} while (e != 1 && e != 2);


	return 0;
}
