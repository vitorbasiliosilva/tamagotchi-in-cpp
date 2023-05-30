#include <iostream>
#include <fstream>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <unistd.h>
#include <ctime>
using namespace std;

char titulo[1000] = {"TAMAGOTCHI"};

//Centralizar frase
void centralizar(char texto[1000]){
	int cont = ((60 - strlen(texto))/2);
	for(int x=0; x<cont; x++) {
		printf(" ");
	}
	cout<<texto;	
}

//Gera uma frase aleatoria com um tema especificado
void gerar_frase(int n) {
	int m;
	char texto[1000];
	m=1+rand()%4;
	
	//Agradecimento
	if(n==1) {
		if(m==1) {
			strcpy(texto, "\"Você é muito especial\"");
		}
		if(m==2) {
			strcpy(texto, "\"Obrigado por cuidar de mim\"");
		}
		if(m==3) {
			strcpy(texto, "\"Hoje é o melhor dia da minha vida\"");
		}
		if(m==4) {
			strcpy(texto, "\"Muito obrigado por estar aqui\"");
		}
	}
	//Recusa
	if(n==2) {
		if(m==1) {
			strcpy(texto, "\"Eu não quero!\"");
		}
		if(m==2) {
			strcpy(texto, "\"Agora não!\"");
		}
		if(m==3) {
			strcpy(texto, "\"Eu quero outra coisa!\"");
		}
		if(m==4) {
			strcpy(texto, "\"Isso não\"");
		}
	}
	//Feliz
	if(n==3) {
		if(m==1) {
			strcpy(texto, "\"Isso foi muito legal!\"");
		}
		if(m==2) {
			strcpy(texto, "\"Obrigado por isso\"");
		}
		if(m==3) {
			strcpy(texto, "\"Podemos ir de novo?\"");
		}
		if(m==4) {
			strcpy(texto, "\"Amo brincar com você!\"");
		}
	}
	//Triste
	if(n==4) {
		if(m==1) {
			strcpy(texto, "\"Eu não gostei muito disso\"");
		}
		if(m==2) {
			strcpy(texto, "\"Eu fiz algo de errado?\"");
		}
		if(m==3) {
			strcpy(texto, "\"Você sempre ganha, não é legal\"");
		}
		if(m==4) {
			strcpy(texto, "\"Isso me deixou triste\"");
		}
	}
	centralizar(texto);
}

//Criar tabulação
void espacamento(int i) {
	for(int y=0; y<i; y++) {
		printf(" ");
	}
}

//Gera cada quadro da animação
void quadroanim(char texto[4][1000], char nome[1000]) {
	int cont;
	system("cls");
	cout<<"\n\n";
	centralizar(titulo);
	cout<<"\n";
	centralizar(nome);
	cout<<"\n";
	
	for(int qt=0; qt<60; qt++) {
		if(qt>20 && qt<39) {
			cout<<"_";
		}
		else {
			printf(" ");
		}
	}
	
	for(int x=0; x<4; x++) {
		//Calcula a distancia necessaria de borda
		cont = (14 - strlen(texto[x]))/2;
		cout<<"\n";
		
		//Coloca a distancia para iniciar a borda
		espacamento(20);
			
		//Inseri a borda esquerda
		printf("|  ");
			
		//Colocar a margem da animação à borda esquerda
		espacamento(cont);
		
		//Escreve uma linha do desenho
		printf(texto[x]);
		
		//Colocar a margem da animação à borda direita
		espacamento(cont);
			
		//Inseri a borda direita
		cout<<"  |";
	}
	
	cout<<"\n";
	//Cria a borda inferior
	for(int qt2=0; qt2<60; qt2++) {
		if(qt2>20 && qt2<39) {
			printf("_");
		}
		else {
			if (qt2==20 || qt2==39) {
				printf("|");
			}
			else{
				printf(" ");
			}
		}
	}
	
	Sleep(((rand() % 100) + 350));
}

//Desenho padrão
void desenho_p(int idade, char tama[4][1000]) {
	if(idade<3) {
		strcpy(tama[0], "");
		strcpy(tama[1], " ____ ");
		strcpy(tama[2], "|-__-|");
		strcpy(tama[3], "|____|");
	} else {
		if(idade<8) {
			strcpy(tama[0], " ______ ");
			strcpy(tama[1], "| _  _ |");
			strcpy(tama[2], "|  __  |");
			strcpy(tama[3], "|______|");
		} else {
			strcpy(tama[0], " ______ ");
			strcpy(tama[1], "/ o  o \\");
			strcpy(tama[2], "|  __  |");
			strcpy(tama[3], "\\______/");
		}
	}
}

//Inicia a pagina inicial
void pag_inicial() {
	char tama[5][1000], textomenu[3][1000] = {
		"Seja bem vindo ao Tamagotchi",
		"Seu Bichinho Virtual",
		"Clique para iniciar..."
	};
	
	for(int j=0; j<7; j++) {
		system("cls");
		for(int i=0; i<2; i++) {
			cout<<"\n\n\n";
			centralizar(textomenu[i]);
		}
		cout<<"\n";
		if(j%2==0) {
			strcpy(tama[0], "  _\\||/_  ");
			strcpy(tama[1], " | O  O | ");
			strcpy(tama[2], "/  ____  \\");
			strcpy(tama[3], "|  \\__/  |");
			strcpy(tama[4], "\\________/");
		} else {
			strcpy(tama[0], "");
			strcpy(tama[1], "  ______  ");
			strcpy(tama[2], " | -  - | ");
			strcpy(tama[3], "/  ____  \\");
			strcpy(tama[4], "\\________/");
		}
		for(int k=0; k<5; k++) {
			cout<<"\n";
			centralizar(tama[k]);
		}
		Sleep(((rand() % 100) + 350));
	}
	
	cout<<"\n\n";
	centralizar(textomenu[2]);
	
	getch();
	system("cls");
}


void final() {
	char tama[5][1000], textomenu[3][1000] = {
		"Obrigado por jogar Tamagotchi",
		"Volte sempre!",
		"Clique para finalizar..."
	};
	
	for(int j=0; j<7; j++) {
		system("cls");
		for(int i=0; i<2; i++) {
			cout<<"\n\n\n";
			centralizar(textomenu[i]);
		}
		cout<<"\n";
		if(j%2==0) {
			strcpy(tama[0], "  _\\||/_  ");
			strcpy(tama[1], " | O  O | ");
			strcpy(tama[2], "/  ____  \\");
			strcpy(tama[3], "|  \\__/  |");
			strcpy(tama[4], "\\________/");
		} else {
			strcpy(tama[0], "");
			strcpy(tama[1], "  ______  ");
			strcpy(tama[2], " | -  - | ");
			strcpy(tama[3], "/  ____  \\");
			strcpy(tama[4], "\\________/");
		}
		for(int k=0; k<5; k++) {
			cout<<"\n";
			centralizar(tama[k]);
		}
		Sleep(((rand() % 100) + 350));
	}
	cout<<"\n\n";
}

//Gera o menu e retorna o valor do opção escolhida
void menu(int &esc, char nome[1000]) {
	char titulomenu[1000] = {"TAMAGOTCHI - MENU INICIAL"};
	cout<<"\n\n";
	centralizar(titulomenu);
	cout<<"\n";
	
	char itemmenu[4][1000] = {
		"Criar novo bichinho",
		"Continuar jogo",
		"Manual",
		"Sair"
	};
	printf("\n");
	for (int i=0; i<4; i++){
		cout<<"\n\t\t"<<i+1<<". "<<itemmenu[i];
	}
	cout<<"\n";
	if(esc<1 || esc>4) {
		cout<<"\n\t\tA opção escolhida é invalida\n\t\tInsira novamente!\n";
	}
	cout<<"\n\t\tDigite a opção desejada: ";
	cin>>esc;
	
	if(esc==1){
		cout<<"\n\t\tQual será seu nome? ";
		cin>>nome;
		strupr(nome);
		system("cls");
		cout<<"\n\n";
		centralizar(titulomenu);
		cout<<"\n\n";
		char frasenasc[2][1000] = {"É hora de ver ", " nascer!"};
		strcat(frasenasc[0], nome);
		strcat(frasenasc[0], frasenasc[1]);
		centralizar(frasenasc[0]);
		cout<<"\n\n";
		getch();
	}
	system("cls");
}

//Animação de nascimento
void nascimento(int &dormir, int &saude, int &energia, int &fome, int &felicidade, int &peso, int &idade, char nome[1000]) {
	int cont;
	dormir=0;
	saude=8;
	energia=8;
	fome=1;
	felicidade=1;
	peso=1;
	idade=1;
	char tamanascendo[4][1000];
	for(int i=0; i<12; i++) {
		//Uma serie de ifs com cada frame de animação
		if(i==0) {
			strcpy(tamanascendo[0], "  _--_  ");
			strcpy(tamanascendo[1], " /    \\ ");
			strcpy(tamanascendo[2], "|      |");
			strcpy(tamanascendo[3], " \\____/ ");
		}
		if(i==1) {
			strcpy(tamanascendo[0], "    _--_  ");
			strcpy(tamanascendo[1], "   /  | \\ ");
			strcpy(tamanascendo[2], "  |      |");
			strcpy(tamanascendo[3], "   \\____/ ");
		}
		if(i==2) {
			strcpy(tamanascendo[0], "  _--_  ");
			strcpy(tamanascendo[1], " /  | \\ ");
			strcpy(tamanascendo[2], "|  /   |");
			strcpy(tamanascendo[3], " \\____/ ");
		}
		if(i==3) {
			strcpy(tamanascendo[0], "  _--_    ");
			strcpy(tamanascendo[1], " /  | \\   ");
			strcpy(tamanascendo[2], "|  /   |  ");
			strcpy(tamanascendo[3], " \\_\\__/   ");
		}
		if(i==4) {
			strcpy(tamanascendo[0], "  _-_ _-_ ");
			strcpy(tamanascendo[1], " /  |_| \\ ");
			strcpy(tamanascendo[2], "|  /|/   |");
			strcpy(tamanascendo[3], " \\_\\|\\__/ ");
		}
		if(i==5) {
			strcpy(tamanascendo[0], "  _-_ _-_ ");
			strcpy(tamanascendo[1], " /  |_| \\ ");
			strcpy(tamanascendo[2], "|  /|/   |");
			strcpy(tamanascendo[3], " \\_\\|\\__/ ");
		}
		if(i==6) {
			strcpy(tamanascendo[0], "  _-_   _-_ ");
			strcpy(tamanascendo[1], " /  |___| \\ ");
			strcpy(tamanascendo[2], "|  /|-_/   |");
			strcpy(tamanascendo[3], " \\_\\|__\\__/ ");
		}
		if(i==7) {
			strcpy(tamanascendo[0], "  _-_     _-_ ");
			strcpy(tamanascendo[1], " /  |____ | \\ ");
			strcpy(tamanascendo[2], "|  /|-__-/   |");
			strcpy(tamanascendo[3], " \\_\\|____\\__/ ");
		}
		if(i==8) {
			strcpy(tamanascendo[0], " _-_       _-_");
			strcpy(tamanascendo[1], "/  | ____  | \\");
			strcpy(tamanascendo[2], "  / |-__-|/   ");
			strcpy(tamanascendo[3], "\\_\\ |____|\\__/");
		}
		if(i==9) {
			strcpy(tamanascendo[0], "_-_         _-");
			strcpy(tamanascendo[1], "  |  ____   | ");
			strcpy(tamanascendo[2], " /  |-__-| /  ");
			strcpy(tamanascendo[3], "_\\  |____| \\__");
		}
		if(i==10) {
			strcpy(tamanascendo[0], "\\ |  /");
			strcpy(tamanascendo[1], " ____ ");
			strcpy(tamanascendo[2], "|-[]-|");
			strcpy(tamanascendo[3], "|____|");
		}
		if(i==11) {
			strcpy(tamanascendo[0], "      ");
			strcpy(tamanascendo[1], " ____ ");
			strcpy(tamanascendo[2], "|-__-|");
			strcpy(tamanascendo[3], "|____|");
		}
		quadroanim(tamanascendo, nome);
	}
}

//Esoclher a comida
void escolha_comer(int &n, int idade, char nome[1000], int fome) {
	char tama[4][1000];
	cout<<"\n\n";
	centralizar(titulo);
	desenho_p(idade, tama);
	quadroanim(tama, nome);
	cout<<"\n\n";
	char texto[1000]={"Escolha uma comida:"}, opc_comer[5][1000];
	if(fome<8) {
		centralizar(texto);
		cout<<"\n\n";
		strcpy(opc_comer[0], "1. Refeição   ___  | 2. Lanche    __ ");
		strcpy(opc_comer[1], "   Pão       |   | |    Sorvete  /__\\");
		strcpy(opc_comer[2], "             |___| |             \\  /");
		strcpy(opc_comer[3], "                   |              \\/ ");
		for(int i=0; i<4; i++) {
			centralizar(opc_comer[i]);
			cout<<"\n";
		}
		cout<<"\n";
		strcpy(texto, "Opção escolhida: ");
		centralizar(texto);
		cin>>n;
	} else {
		gerar_frase(2);
		cout<<"\n\n";
		strcpy(texto, nome);
		strcat(texto, " não está com fome");
		centralizar(texto);
		getch();
	}
	system("cls");
}

//Animação de comer
void comer(char nome[1000], int n, int idade, int &fome, int &peso, int &felicidade, int &exp) {
	char tamacomendo[4][1000];
	peso++;
	exp++;
	if(n==1) {
		fome++;
	} else {
		peso++;
		felicidade++;
	}
	for(int i=0; i<13; i++) {		
		//Uma serie de ifs com cada frame de animação
		if(n==1) {
			if(idade<3) {
				if(i==0 || 12) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], " ____ ");
					strcpy(tamacomendo[2], "|-__-|");
					strcpy(tamacomendo[3], "|____|");
				}
				if(i==1) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], "_      ____ ");
					strcpy(tamacomendo[2], " |    |-__-|");
					strcpy(tamacomendo[3], "_|    |____|");
				}
				if(i==2) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], "__     ____ ");
					strcpy(tamacomendo[2], "  |   |-__-|");
					strcpy(tamacomendo[3], "__|   |____|");
				}
				if(i==3) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], " ___   ____ ");
					strcpy(tamacomendo[2], "|   | |__- |");
					strcpy(tamacomendo[3], "|___| |____|");
				}
				if(i==4) {
					strcpy(tamacomendo[0], "       ____ ");
					strcpy(tamacomendo[1], " _    |__- |");
					strcpy(tamacomendo[2], "| |_   __| |");
					strcpy(tamacomendo[3], "|___| |____|");
				}
				if(i==5) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], " _     ____ ");
					strcpy(tamacomendo[2], "| |_  |__- |");
					strcpy(tamacomendo[3], "|___| |____|");
				}
				if(i==6) {
					strcpy(tamacomendo[0], "       ____ ");
					strcpy(tamacomendo[1], "      |__- |");
					strcpy(tamacomendo[2], " _     __| |");
					strcpy(tamacomendo[3], "|_|   |____|");
				}
				if(i==7) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], "       ____ ");
					strcpy(tamacomendo[2], " _    |__- |");
					strcpy(tamacomendo[3], "|_|   |____|");
				}
				if(i==8) {
					strcpy(tamacomendo[0], "       ____ ");
					strcpy(tamacomendo[1], "      |__- |");
					strcpy(tamacomendo[2], "       __| |");
					strcpy(tamacomendo[3], "      |____|");
				}
				if(i==9) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], "       ____ ");
					strcpy(tamacomendo[2], "      |__- |");
					strcpy(tamacomendo[3], "      |____|");
				}
				if(i==10) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], "       ____ ");
					strcpy(tamacomendo[2], "      |__- |");
					strcpy(tamacomendo[3], "      |____|");
				}
				if(i==11) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], " ____ ");
					strcpy(tamacomendo[2], "|__- |");
					strcpy(tamacomendo[3], "|____|");
				}
			} else {
				if(idade<8) {
					if(i==0 || 12) {
						strcpy(tamacomendo[0], " ______ ");
						strcpy(tamacomendo[1], "| _  _ |");
						strcpy(tamacomendo[2], "|  __  |");
						strcpy(tamacomendo[3], "|______|");
					}
					if(i==1) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "_     | _  _ |");
						strcpy(tamacomendo[2], " |    |  __  |");
						strcpy(tamacomendo[3], "_|    |______|");
					}
					if(i==2) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "__    |   _  |");
						strcpy(tamacomendo[2], "  |   |___   |");
						strcpy(tamacomendo[3], "__|   |______|");
					}
					if(i==3) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], " ___  |   _  |");
						strcpy(tamacomendo[2], "|   | |___   |");
						strcpy(tamacomendo[3], "|___| |______|");
					}
					if(i==4) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], " _    |___ - |");
						strcpy(tamacomendo[2], "| |_   ___|  |");
						strcpy(tamacomendo[3], "|___| |______|");
					}
					if(i==5) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], " _    |   _  |");
						strcpy(tamacomendo[2], "| |_  |___   |");
						strcpy(tamacomendo[3], "|___| |______|");
					}
					if(i==6) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      |___ - |");
						strcpy(tamacomendo[2], " _     ___|  |");
						strcpy(tamacomendo[3], "|_|   |______|");
					}
					if(i==7) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      |   _  |");
						strcpy(tamacomendo[2], " _    |___   |");
						strcpy(tamacomendo[3], "|_|   |______|");
					}
					if(i==8) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      |___ - |");
						strcpy(tamacomendo[2], "       ___|  |");
						strcpy(tamacomendo[3], "      |______|");
					}
					if(i==9) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      |   _  |");
						strcpy(tamacomendo[2], "      |___   |");
						strcpy(tamacomendo[3], "      |______|");
					}
					if(i==10) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      |   _  |");
						strcpy(tamacomendo[2], "      |___   |");
						strcpy(tamacomendo[3], "      |______|");
					}
					if(i==11) {
						strcpy(tamacomendo[0], " ______ ");
						strcpy(tamacomendo[1], "|   _  |");
						strcpy(tamacomendo[2], "|___   |");
						strcpy(tamacomendo[3], "|______|");
					}
				} else {
					if(i==0 || 12) {
						strcpy(tamacomendo[0], " ______ ");
						strcpy(tamacomendo[1], "/ o  o \\");
						strcpy(tamacomendo[2], "|  __  |");
						strcpy(tamacomendo[3], "\\______/");
					}
					if(i==1) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "_     / o  o \\");
						strcpy(tamacomendo[2], " |    |  __  |");
						strcpy(tamacomendo[3], "_|    \\______/");
					}
					if(i==2) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "__    /   o  \\");
						strcpy(tamacomendo[2], "  |   |___   |");
						strcpy(tamacomendo[3], "__|   \\______/");
					}
					if(i==3) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], " ___  /   o  \\");
						strcpy(tamacomendo[2], "|   | |___   |");
						strcpy(tamacomendo[3], "|___| \\______/");
					}
					if(i==4) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], " _    /___ O \\");
						strcpy(tamacomendo[2], "| |_   ___|  |");
						strcpy(tamacomendo[3], "|___| \\______/");
					}
					if(i==5) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], " _    /   o  \\");
						strcpy(tamacomendo[2], "| |_  |___   |");
						strcpy(tamacomendo[3], "|___| \\______/");
					}
					if(i==6) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      /___ O \\");
						strcpy(tamacomendo[2], " _     ___|  |");
						strcpy(tamacomendo[3], "|_|   \\______/");
					}
					if(i==7) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      /   o  \\");
						strcpy(tamacomendo[2], " _    |___   |");
						strcpy(tamacomendo[3], "|_|   \\______/");
					}
					if(i==8) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      /___ O \\");
						strcpy(tamacomendo[2], "       ___|  |");
						strcpy(tamacomendo[3], "      \\______/");
					}
					if(i==9) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      /   o  \\");
						strcpy(tamacomendo[2], "      |___   |");
						strcpy(tamacomendo[3], "      \\______/");
					}
					if(i==10) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      /   o  \\");
						strcpy(tamacomendo[2], "      |___   |");
						strcpy(tamacomendo[3], "      \\______/");
					}
					if(i==11) {
						strcpy(tamacomendo[0], " ______ ");
						strcpy(tamacomendo[1], "/   o  \\");
						strcpy(tamacomendo[2], "|___   |");
						strcpy(tamacomendo[3], "\\______/");
					}
				}
			}
		} else {
			if(idade<3) {
				if(i==0 || 12) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], " ____ ");
					strcpy(tamacomendo[2], "|-__-|");
					strcpy(tamacomendo[3], "|____|");
				}
				if(i==1) {
					strcpy(tamacomendo[0], "_           ");
					strcpy(tamacomendo[1], "_\\     ____ ");
					strcpy(tamacomendo[2], " /    |-__-|");
					strcpy(tamacomendo[3], "/     |____|");
				}
				if(i==2) {
					strcpy(tamacomendo[0], "__          ");
					strcpy(tamacomendo[1], "__\\    ____ ");
					strcpy(tamacomendo[2], "  /   |-__-|");
					strcpy(tamacomendo[3], "\\/    |____|");
				}
				if(i==3) {
					strcpy(tamacomendo[0], " __         ");
					strcpy(tamacomendo[1], "/__\\   ____ ");
					strcpy(tamacomendo[2], "\\  /  |__- |");
					strcpy(tamacomendo[3], " \\/   |____|");
				}
				if(i==4) {
					strcpy(tamacomendo[0], "       ____ ");
					strcpy(tamacomendo[1], " __   |__- |");
					strcpy(tamacomendo[2], "\\  /   __| |");
					strcpy(tamacomendo[3], " \\/   |____|");
				}
				if(i==5) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], " __    ____ ");
					strcpy(tamacomendo[2], "\\  /  |__- |");
					strcpy(tamacomendo[3], " \\/   |____|");
				}
				if(i==6) {
					strcpy(tamacomendo[0], "       ____ ");
					strcpy(tamacomendo[1], "      |__- |");
					strcpy(tamacomendo[2], " __    __| |");
					strcpy(tamacomendo[3], " \\/   |____|");
				}
				if(i==7) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], "       ____ ");
					strcpy(tamacomendo[2], " __   |__- |");
					strcpy(tamacomendo[3], " \\/   |____|");
				}
				if(i==8) {
					strcpy(tamacomendo[0], "       ____ ");
					strcpy(tamacomendo[1], "      |__- |");
					strcpy(tamacomendo[2], "       __| |");
					strcpy(tamacomendo[3], "      |____|");
				}
				if(i==9) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], "       ____ ");
					strcpy(tamacomendo[2], "      |__- |");
					strcpy(tamacomendo[3], "      |____|");
				}
				if(i==10) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], "       ____ ");
					strcpy(tamacomendo[2], "      |__- |");
					strcpy(tamacomendo[3], "      |____|");
				}
				if(i==11) {
					strcpy(tamacomendo[0], "");
					strcpy(tamacomendo[1], " ____ ");
					strcpy(tamacomendo[2], "|__- |");
					strcpy(tamacomendo[3], "|____|");
				}
			} else {
				if(idade<8) {
					if(i==0 || 12) {
						strcpy(tamacomendo[0], " ______ ");
						strcpy(tamacomendo[1], "| _  _ |");
						strcpy(tamacomendo[2], "|  __  |");
						strcpy(tamacomendo[3], "|______|");
					}
					if(i==1) {
						strcpy(tamacomendo[0], "_      ______ ");
						strcpy(tamacomendo[1], "_\\    | _  _ |");
						strcpy(tamacomendo[2], " /    |  __  |");
						strcpy(tamacomendo[3], "/     |______|");
					}
					if(i==2) {
						strcpy(tamacomendo[0], "__     ______ ");
						strcpy(tamacomendo[1], "__\\   |   _  |");
						strcpy(tamacomendo[2], "  /   |___   |");
						strcpy(tamacomendo[3], "\\/    |______|");
					}
					if(i==3) {
						strcpy(tamacomendo[0], " __    ______ ");
						strcpy(tamacomendo[1], "/__\\  |   _  |");
						strcpy(tamacomendo[2], "\\  / |___   |");
						strcpy(tamacomendo[3], " \\/   |______|");
					}
					if(i==4) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], " __   |___ - |");
						strcpy(tamacomendo[2], "\\  /   ___|  |");
						strcpy(tamacomendo[3], " \\/   |______|");
					}
					if(i==5) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], " __   |   _  |");
						strcpy(tamacomendo[2], "\\  /  |___   |");
						strcpy(tamacomendo[3], " \\/   |______|");
					}
					if(i==6) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      |___ - |");
						strcpy(tamacomendo[2], " __    ___|  |");
						strcpy(tamacomendo[3], " \\/   |______|");
					}
					if(i==7) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      |   _  |");
						strcpy(tamacomendo[2], " __   |___   |");
						strcpy(tamacomendo[3], " \\/   |______|");
					}
					if(i==8) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      |___ - |");
						strcpy(tamacomendo[2], "       ___|  |");
						strcpy(tamacomendo[3], "      |______|");
					}
					if(i==9) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      |   _  |");
						strcpy(tamacomendo[2], "      |___   |");
						strcpy(tamacomendo[3], "      |______|");
					}
					if(i==10) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      |   _  |");
						strcpy(tamacomendo[2], "      |___   |");
						strcpy(tamacomendo[3], "      |______|");
					}
					if(i==11) {
						strcpy(tamacomendo[0], " ______ ");
						strcpy(tamacomendo[1], "|   _  |");
						strcpy(tamacomendo[2], "|___   |");
						strcpy(tamacomendo[3], "|______|");
					}
				} else {
					if(i==0 || 12) {
						strcpy(tamacomendo[0], " ______ ");
						strcpy(tamacomendo[1], "/ o  o \\");
						strcpy(tamacomendo[2], "|  __  |");
						strcpy(tamacomendo[3], "\\______/");
					}
					if(i==1) {
						strcpy(tamacomendo[0], "-      ______ ");
						strcpy(tamacomendo[1], "_\\    / o  o \\");
						strcpy(tamacomendo[2], " /    |  __  |");
						strcpy(tamacomendo[3], "/     \\______/");
					}
					if(i==2) {
						strcpy(tamacomendo[0], "__     ______ ");
						strcpy(tamacomendo[1], "__\\   /   o  \\");
						strcpy(tamacomendo[2], "  /   |___   |");
						strcpy(tamacomendo[3], "\\/    \\______/");
					}
					if(i==3) {
						strcpy(tamacomendo[0], " __    ______ ");
						strcpy(tamacomendo[1], "/__\\  /   o  \\");
						strcpy(tamacomendo[2], "\\  /  |___   |");
						strcpy(tamacomendo[3], " \\/   \\______/");
					}
					if(i==4) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], " __   /___ O \\");
						strcpy(tamacomendo[2], "\\  /   ___|  |");
						strcpy(tamacomendo[3], " \\/   \\______/");
					}
					if(i==5) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], " __   /   o  \\");
						strcpy(tamacomendo[2], "\\  /  |___   |");
						strcpy(tamacomendo[3], " \\/   \\______/");
					}
					if(i==6) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      /___ O \\");
						strcpy(tamacomendo[2], " __    ___|  |");
						strcpy(tamacomendo[3], " \\/   \\______/");
					}
					if(i==7) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      /   o  \\");
						strcpy(tamacomendo[2], " __   |___   |");
						strcpy(tamacomendo[3], " \\/   \\______/");
					}
					if(i==8) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      /___ O \\");
						strcpy(tamacomendo[2], "       ___|  |");
						strcpy(tamacomendo[3], "      \\______/");
					}
					if(i==9) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      /   o  \\");
						strcpy(tamacomendo[2], "      |___   |");
						strcpy(tamacomendo[3], "      \\______/");
					}
					if(i==10) {
						strcpy(tamacomendo[0], "       ______ ");
						strcpy(tamacomendo[1], "      /   o  \\");
						strcpy(tamacomendo[2], "      |___   |");
						strcpy(tamacomendo[3], "      \\______/");
					}
					if(i==11) {
						strcpy(tamacomendo[0], " ______ ");
						strcpy(tamacomendo[1], "/   o  \\");
						strcpy(tamacomendo[2], "|___   |");
						strcpy(tamacomendo[3], "\\______/");
					}
				}
			}			
		}
		quadroanim(tamacomendo, nome);
	}
	cout<<"\n\n";
	gerar_frase(1);
	cout<<"\n\n";
	getch();
}

//Tela principal
void telatama(int dormir, int idade, int &opc, char nome[100], int &energia, int &exp) {
	int cont;
	char tama[4][1000], acoes[6][1000] = {"Comer", "Brincar", "Vacinar", ".", "Status", "Salvar e sair"};
	system("cls");
	cout<<"\n\n";
	centralizar(titulo);
	cout<<"\n\n";
	if(dormir==0) {
		desenho_p(idade, tama);
		strcpy(acoes[3], "Dormir");
	} else {
		energia=8;
		exp++;
		if(idade<3) {
			strcpy(tama[0], "         Z");
			strcpy(tama[1], "  ____  z ");
			strcpy(tama[2], " |-__-|z  ");
			strcpy(tama[3], " |____|   ");			
		} else {
			if(idade<8) {
				strcpy(tama[0], "  ______   Z");
				strcpy(tama[1], " | _  _ | z ");
				strcpy(tama[2], " |  __  |z  ");
				strcpy(tama[3], " |______|   ");
			} else {
				strcpy(tama[0], "  ______   Z");
				strcpy(tama[1], " / _  _ \\ z ");
				strcpy(tama[2], " |  __  |z  ");
				strcpy(tama[3], " \\______/   ");				
			}	
		}
		strcpy(acoes[3], "Acordar");
	}
	quadroanim(tama, nome);
	printf("\n");
	for (int i=1; i<6; i+=2){
		cout<<"\n";
		espacamento(19);
		cout<<i<<". "<<acoes[i-1];
		cont = 7 - strlen(acoes[i-1]);
		espacamento(cont);
		cout<<"  "<<i+1<<". "<<acoes[i];
	}
		
	cout<<"\n\n";
	if(opc<1 || opc>6) {
		espacamento(14);
		cout<<"Ação invalida, insira novamente!\n\n";
	}
	espacamento(17);
	cout<<"Digite a opção desejada: ";
	cin>>opc;
	system("cls");
}

//Tela de morte
void morte(int idade, char nome[1000], int saude, int energia) {
	char tama[4][1000];
	cout<<"\n\n";
	centralizar(titulo);
	if(idade<3) {
		strcpy(tama[0], "");
		strcpy(tama[1], " ____ ");
		strcpy(tama[2], "|x__x|");
		strcpy(tama[3], "|____|");
	} else {
		if(idade<8) {
			strcpy(tama[0], " ______ ");
			strcpy(tama[1], "| x  x |");
			strcpy(tama[2], "|  ~   |");
			strcpy(tama[3], "|______|");
		} else {
			strcpy(tama[0], " ______ ");
			strcpy(tama[1], "/ x  x \\");
			strcpy(tama[2], "|  __  |");
			strcpy(tama[3], "\\______/");
		}
	}
	quadroanim(tama, nome);
	cout<<"\n\n";
	char texto[1000]={"Infelizmente "};
	strcat(texto, nome);
	strcat(texto, " morreu");
	centralizar(texto);
	cout<<"\n\n";
	
	if(idade>10) {
		strcpy(texto, "Mas parabéns, sua vida foi incrivel!");
	}
	else {
		strcpy(texto, "Possiveis causas:");
		centralizar(texto);
		if(saude<1 && energia<1) {
			strcpy(texto, "Fome, sono, depressão ou peso");
		} else {
			if(saude<1) {
				strcpy(texto, "Fome, depressão ou peso");
			} else {
				strcpy(texto, "Sono");
			}
		}
	}
	cout<<"\n";	
	centralizar(texto);
	cout<<"\n\n";
	strcpy(texto, "Meus pesames pela sua perda!");
	centralizar(texto);
	getch();
	system("cls");
}

//Calcula a opcao escolhida no jogo de adivinhar o lago
void opc_escolhida(int opcao, char texto[1000]) {
    if(opcao==1) {
        strcat(texto, "pedra");
    } else {
        if(opcao==2) {
            strcat(texto, "papel");
        } else {
            strcat(texto, "tesoura");
        }
    }
}

//Jogo jokenpo
void jokenpo(int &gan, int idade, char nome[1000]) {
    char texto[2][1000], tama[4][1000];
    int jesc, tesc;
    desenho_p(idade, tama);
    quadroanim(tama, nome);
    cout<<"\n\n";
    strcpy(texto[0], "1. Pedra | 2. Papel | 3. Tesoura");
    centralizar(texto[0]);
    cout<<"\n\n";
    strcpy(texto[0], "Opção desejada: ");
    centralizar(texto[0]);
    cin>>jesc;
    
    system("cls");
    desenho_p(idade, tama);
    quadroanim(tama, nome);
    cout<<"\n\n";
    
    strcpy(texto[0], "Você jogou ");
    strcpy(texto[1], nome);
    strcat(texto[1], " jogou ");
    tesc=1+rand()%3;
    if(jesc==tesc) {
        strcpy(texto[1], nome);
        strcat(texto[1], " tambem");
        gan=2;
    } else {
        opc_escolhida(tesc, texto[1]);
        if(jesc==1) {
    		if(tesc==2) {
    		    gan=0;
    		} else {
    		    gan=1;
    		}
    	} else {
    		if(jesc==2) {
    			if(tesc==1) {
    			    gan=1;
    			} else {
    			    gan=0;
    			}
    		} else {
    			if(tesc==1) {
    				gan=0;
    			} else {
    			    gan=1;
    			}
    		}
    	}
    }
    opc_escolhida(jesc, texto[0]);
    centralizar(texto[0]);
    cout<<"\n\n";
    centralizar(texto[1]);
    cout<<"\n";
    getch();
}

//Calcula a opcao escolhida no jogo de adivinhar o lado
void opc_escolhida_adl(int opcao, char texto[1000]) {
    if(opcao==1) {
        strcat(texto, "esquerda");
    } else {
        strcat(texto, "direita");
    }
}

//Jogo de adivinhar o lado
void adivinha_lado(int &gan, int idade, char nome[1000]) {
    char texto[2][1000], tama[4][1000];
    int jesc, tesc;
    desenho_p(idade, tama);
    quadroanim(tama, nome);
    cout<<"\n\n";
    strcpy(texto[0], "<-- 1. Esquerda | 2. Direita -->");
    centralizar(texto[0]);
    cout<<"\n\n";
    strcpy(texto[0], "Opção desejada: ");
    centralizar(texto[0]);
    cin>>jesc;
    tesc=1+rand()%2;
    
    system("cls");
    if(tesc==1) {
    	if(idade<3) {
			strcpy(tama[0], "");
			strcpy(tama[1], " ____ ");
			strcpy(tama[2], "|__- |");
			strcpy(tama[3], "|____|");
		} else {
			if(idade<8) {
				strcpy(tama[0], " ______ ");
				strcpy(tama[1], "|  _   |");
				strcpy(tama[2], "|__    |");
				strcpy(tama[3], "|______|");
			} else {
				strcpy(tama[0], " ______ ");
				strcpy(tama[1], "/  o   \\");
				strcpy(tama[2], "|__    |");
				strcpy(tama[3], "\\______/");
			}
		}
	} else {
		if(idade<3) {
			strcpy(tama[0], "");
			strcpy(tama[1], " ____ ");
			strcpy(tama[2], "| -__|");
			strcpy(tama[3], "|____|");
		} else {
			if(idade<8) {
				strcpy(tama[0], " ______ ");
				strcpy(tama[1], "|   _  |");
				strcpy(tama[2], "|    __|");
				strcpy(tama[3], "|______|");
			} else {
				strcpy(tama[0], " ______ ");
				strcpy(tama[1], "/   o  \\");
				strcpy(tama[2], "|    __|");
				strcpy(tama[3], "\\______/");
			}
		}
	}
    quadroanim(tama, nome);
    cout<<"\n\n";
    
    strcpy(texto[0], "Você jogou ");
    strcpy(texto[1], nome);
    strcat(texto[1], " jogou ");
    if(jesc==tesc) {
    	strcpy(texto[1], nome);
        strcat(texto[1], " tambem");
        gan=0;
    } else {
        opc_escolhida_adl(tesc, texto[1]);
        gan=1;
    }
    opc_escolhida_adl(jesc, texto[0]);
    centralizar(texto[0]);
    cout<<"\n\n";
    centralizar(texto[1]);
    cout<<"\n";
    getch();
}

//Anuncia o vencedor
void vencedor(int gan, int idade, char nome[1000]) {
	int n;
    char texto[1000], tama[4][1000];
    if(gan==0) {
    	n=3;
    	strcpy(texto, nome);
        strcat(texto, " ganhou!");
        if(idade<3) {
        	strcpy(tama[0], "\\ || /");
			strcpy(tama[1], " ____ ");
			strcpy(tama[2], "|^[]^|");
			strcpy(tama[3], "|____|");
		} else {
			if(idade<8) {
				strcpy(tama[0], " _\\||/_ ");
				strcpy(tama[1], "| ^  ^ |");
				strcpy(tama[2], "|  []  |");
				strcpy(tama[3], "|______|");
			} else {
				strcpy(tama[0], " _\\||/_ ");
				strcpy(tama[1], "/ ^  ^ \\");
				strcpy(tama[2], "|  []  |");
				strcpy(tama[3], "\\______/");
			}
		}
    } else {
        if(gan==1) {
        	n=4;
            strcpy(texto, "Você venceu!");
            if(idade<3) {
	        	strcpy(tama[0], "");
				strcpy(tama[1], " ____ ");
				strcpy(tama[2], "|-  -|");
				strcpy(tama[3], "|____|");
			} else {
				if(idade<8) {
					strcpy(tama[0], " ______ ");
					strcpy(tama[1], "| _  _ |");
					strcpy(tama[2], "|    ^ |");
					strcpy(tama[3], "|______|");
				} else {
					strcpy(tama[0], " ______ ");
					strcpy(tama[1], "/ o  o \\");
					strcpy(tama[2], "|      |");
					strcpy(tama[3], "\\______/");
				}
			}
        } else {
        	n=3;
            strcpy(texto, "Empatou");
            if(idade<3) {
	        	strcpy(tama[0], "\\ || /");
				strcpy(tama[1], " ____ ");
				strcpy(tama[2], "|^[]^|");
				strcpy(tama[3], "|____|");
			} else {
				if(idade<8) {
					strcpy(tama[0], " _\\||/_ ");
					strcpy(tama[1], "| ^  ^ |");
					strcpy(tama[2], "|  []  |");
					strcpy(tama[3], "|______|");
				} else {
					strcpy(tama[0], " _\\||/_ ");
					strcpy(tama[1], "/ ^  ^ \\");
					strcpy(tama[2], "|  []  |");
					strcpy(tama[3], "\\______/");
				}
			}
        }
    }
    quadroanim(tama, nome);
    cout<<"\n\n";
    gerar_frase(n);
    cout<<"\n\n";
    centralizar(texto);
    getch();
}

//Gera menu para escolher jogo
int escolha_jogo(int idade, char nome[1000], int &fome, int &felicidade, int &peso, int &energia, int &exp) {
	fome--;
	felicidade++;
	peso--;
	energia--;
	exp++;
    int escolha;
    char texto[1000], tama[4][1000];
    desenho_p(idade, tama);
    quadroanim(tama, nome);
    cout<<"\n\n";
    strcpy(texto, "1. Jokenpo | 2. Adivinha o lado");
    centralizar(texto);
    cout<<"\n\n";
    strcpy(texto, "Opcao escolhida: ");
    centralizar(texto);
    cin>>escolha;
    system("cls");
    return escolha;
}

//Quando tentar realizar algo e o tamagotchi estiver dormindo
void dormindo(int idade, char nome[1000], int &exp) {
	char tama[4][1000], texto[1000];
	exp++;
	if(idade<3) {
		strcpy(tama[0], "         Z");
		strcpy(tama[1], "  ____  z ");
		strcpy(tama[2], " |-__-|z  ");
		strcpy(tama[3], " |____|   ");
	} else {
		if(idade<8) {
			strcpy(tama[0], "  ______   Z");
			strcpy(tama[1], " | _  _ | z ");
			strcpy(tama[2], " |  __  |z  ");
			strcpy(tama[3], " |______|   ");
		} else {
			strcpy(tama[0], "  ______   Z");
			strcpy(tama[1], " / _  _ \\ z ");
			strcpy(tama[2], " |  __  |z  ");
			strcpy(tama[3], " \\______/   ");
		}
	}
	quadroanim(tama, nome);
	strcpy(texto, "Shh! ");
	strcat(texto, nome);
	strcat(texto, " está dormindo!");
	cout<<"\n\n";
	centralizar(texto);
	getch();
}

//Vacinar
void vacinar(int &saude, int &felicidade, char nome[1000], int idade, int &energia, int &exp) {
	saude+=2;
	felicidade--;
	energia--;
	exp++;
	char tama[4][1000], texto[1000];
	strcat(texto, nome);
	strcat(texto, " está vacinado!");
	for(int i=0; i<2; i++) {
		for(int y=0; y<4; y++) {
			if(y==0) {
				strcpy(tama[0], "     _____    ");
				strcpy(tama[1], "|___| |   |__ ");
				strcpy(tama[2], "|   |_|___|   ");
				strcpy(tama[3], "");
			}
			if(y==1) {
				strcpy(tama[0], "     _____    ");
				strcpy(tama[1], " |__|  |  |__ ");
				strcpy(tama[2], " |  |__|__|   ");
				strcpy(tama[3], "");
			}
			if(y==2) {
				strcpy(tama[0], "     _____    ");
				strcpy(tama[1], "  |_|   | |__ ");
				strcpy(tama[2], "  | |___|_|   ");
				strcpy(tama[3], "");
			}
			if(y==3) {
				strcpy(tama[0], "     _____    ");
				strcpy(tama[1], "  |_|    ||__ ");
				strcpy(tama[2], "  | |____||  ^");
				strcpy(tama[3], "");
			}
			quadroanim(tama, nome);
		}
		if(i==1) {
			desenho_p(idade, tama);
			quadroanim(tama, nome);
		}
	}
	cout<<"\n\n";
	gerar_frase(4);
	cout<<"\n\n";
	centralizar(texto);
	cout<<"\n";
	getch();
}

//Não vacinar
void n_vacinar(int idade, char nome[1000]) {
	char tama[4][1000], texto[1000]={"A saude de "};
	strcat(texto, nome);
	strcat(texto, " está boa!");
	desenho_p(idade, tama);
	quadroanim(tama, nome);
	cout<<"\n\n";
	gerar_frase(2);
	cout<<"\n\n";
	centralizar(texto);
	cout<<"\n";
	getch();
}

//Ver status
void ver_status(int &dormir, int &saude, int &energia, int &fome, int &felicidade, int &peso, int &idade, char nome[1000]) {
	char tama[4][1000], categoria[6][1000]={"Saúde", "Energia", "Fome", "Felicidade", "Peso", "Idade"};
	int n;
	desenho_p(idade, tama);
	quadroanim(tama, nome);
	cout<<"\n\n";
	for(int i=0; i<4; i++) {
		cout<<"\t"<<categoria[i]<<" - ";
		if(i==0) {
			n=saude;
		}
		if(i==1) {
			n=energia;
		}
		if(i==2) {
			n=fome;
		}
		if(i==3) {
			n=felicidade;
		}
		if(n%2!=0) {
			n-=1;
		}
		n=n/2;
		int x=0;
		while(x<n) {
			cout<<"|X";
			x++;
		}
		x=0;
		n=4-n;
		while(x<n) {
			cout<<"| ";
			x++;
		}
		x=0;
		if(i%2==0) {
			cout<<"|   ";
		} else {
			cout<<"|\n\n";
		}
	}
	for(int i=0; i<2; i++) {
		cout<<"\t"<<categoria[i+4]<<" - ";
		if(i+4==4) {
			cout<<peso<<"Kg   ";
		} else {
			cout<<idade<<" ano(s)\n";
		}
	}
	getch();
}

//Checagens
void checagem(int &dormir, int &saude, int &energia, int &fome, int &felicidade, int &peso, int &idade, int opc, int exp) {
	idade=(int)(exp/10);
	if((felicidade<0 || (peso<0 || peso>40) || fome<0) && opc!=6 && opc!=5) {
		saude--;
		if(felicidade<=0) {
			felicidade=0;
		}
		if((peso<=0 || peso>=40)) {
			if(peso<=0) {
				peso=0;
			} else {
				peso=40;
			}
		}
		if(fome<=0) {
			fome=0;
		}
	}
	if(energia<=0) {
		dormir=1;
	}
	if(saude>8) {
		saude=8;
	}
	if(energia>8) {
		energia=8;
	}
	if(fome>8) {
		fome=8;
	}
	if(felicidade>8) {
		felicidade=8;
	}
}

//Controle da tela principal e ações
void principal(int &dormir, int &saude, int &energia, int &fome, int &felicidade, int &peso, int &idade, char nome[1000], int &opc, int &exp) {
	if(saude>0 && idade<11) {
		do {
			checagem(dormir, saude, energia, fome, felicidade, peso, idade, opc, exp);
	       	telatama(dormir, idade, opc, nome, energia, exp);
	       	if(dormir!=0 && opc!=4 && opc!=6 && opc!=5) {
	       		//Não pode realizar ação pois está dormindo
	       		dormindo(idade, nome, exp);
			}
			else {
				if(opc==1) {
					int n;
					//Se ele não estiver cheio, fome<8
					if(fome<8) {
						escolha_comer(n, idade, nome, fome);
						comer(nome, n, idade, fome, peso, felicidade, exp);
					}
					else {
						//Se ele estiver cheio, fome=8
						escolha_comer(n, idade, nome, fome);
					}
				}
				if(opc==2) {
						int gan;
					    if(escolha_jogo(idade, nome, fome, felicidade, peso, energia, exp)==1) {
					        jokenpo(gan, idade, nome);
					    } else {
					        adivinha_lado(gan, idade, nome);
					    }
					    vencedor(gan, idade, nome);
				}
				if(opc==3) {
					//vacinar
					if(saude<8) {
						vacinar(saude, felicidade, nome, idade, energia, exp);
					} else {
						n_vacinar(idade, nome);
					}
				}
				if(opc==4) {
						if(dormir==1) {
							dormir=0;
						} else {
							dormir=1;
						}
				}
				if(opc==5) {
					//Exibe os status
					ver_status(dormir, saude, energia, fome, felicidade, peso, idade, nome);
				}
				if(opc==6) {
					//Jogo irá finalizar
					ofstream salvamentoS;
					salvamentoS.open ("salvamento.txt");
					salvamentoS<<nome<<endl;
					salvamentoS<<dormir<<endl;
					salvamentoS<<saude<<endl;
					salvamentoS<<energia<<endl;
					salvamentoS<<fome<<endl;
					salvamentoS<<felicidade<<endl;
					salvamentoS<<peso<<endl;
					salvamentoS<<idade<<endl;
					salvamentoS<<exp<<endl;
					salvamentoS.close();
				}
			}
		} while(opc!=6);
	}
	else {
		morte(idade, nome, saude, energia);
		ofstream salvamento("salvamento.txt", ofstream::trunc);
	    if (salvamento.is_open()) {
      		salvamento.close();
      		if (remove("salvamento.txt") == 0) {
      		}
   		}
	}
}

//Mensagem se não houver salvamento
void salvamentoinex() {
	char titulomenu[1000] = {"TAMAGOTCHI - MENU INICIAL"};
	cout<<"\n\n";
	centralizar(titulomenu);
	cout<<"\n\n\n\t\tVocê não possui jogo salvo\n";
	getch();
	system("cls");
}

//Exibe o manual
void manual() {
	char tilmanual[1000]={"Manual do jogo"}, texto[1000];
	cout<<"\n\n";
	centralizar(titulo);
	cout<<"\n\n";
	centralizar(tilmanual);
	cout<<"\n\n   Tamagotchi é um bichinho virtual que requer cuidados:"
	"\n   - Alimentação, felicidade e saúde"
	"\n   Ele deve brincar, comer, vacinar e dormir";
	cout<<"\n\n";
	strcpy(texto, "Seu bichinho morre?");
	centralizar(texto);
	cout<<"\n   Sim, quando ficar velho ou saúde/energia acabarem"
	"\n   Portanto, verifique seus status.";
	"\n   Quando alimentação/felicidade/saúde for = 0 a energia diminuirá"
	"\n   Quando peso >40 ou <1, sua saúde diminuirá.\n\n";
	
	cout<<"\n\n";
	strcpy(texto, "Quais as comidas disponíveis?");
	centralizar(texto);
	cout<<"\n   Pão: satisfaz fome, é saudável, não deixa feliz"
	"\n   Sorvete: não satisfaz fome, não é saudável, deixa feliz\n\n";
	strcpy(texto, "Pag. 1/3 - Clique para passar de pagina");
	centralizar(texto);
	
	getch();
	system("cls");
	
	cout<<"\n\n";
	centralizar(titulo);
	cout<<"\n\n";
	centralizar(tilmanual);
	cout<<"\n\n";
	strcpy(texto, "Como brincar?");
	centralizar(texto);
	cout<<"\n     - Jokenpô (Pedra, Papel, Tesoura):"
	"\n   Você e o tamagotchi devem escolher uma da opções:"
	"\n   -> Pedra ganha de tesoura"
	"\n   -> Tesoura ganha de papel"
	"\n   -> Papel ganha de pedra\n"
	"\n     - Adivinhe o lado:"
	"\n   Você deve adivinhar o lado que ele irá virar"
	"\n   Quando ele ganha/empata fica feliz, do contrario, triste\n\n";
	strcpy(texto, "Pag. 2/3 - Clique para passar de pagina");
	centralizar(texto);
	
	getch();
	system("cls");
	
	cout<<"\n\n";
	centralizar(titulo);
	cout<<"\n\n";
	centralizar(tilmanual);
	cout<<"\n\n";
	strcpy(texto, "Por que vacinar?");
	centralizar(texto);
	cout<<"\n   Quando saúde estiver baixa, vacine para melhorar"
	"\n   No entanto, lembre-se de que isso o deixa triste";
	
	cout<<"\n\n";
	strcpy(texto, "Por que dormir?");
	centralizar(texto);
	cout<<"\n   Quando energia estiver baixa coloque para dormir"
	"\n   Ele acordará com a energia renovada";
	
	cout<<"\n\n";
	strcpy(texto, "Ver status:");
	centralizar(texto);
	cout<<"\n   Permite ver informações do tamagotchi, como:"
	"\n   Fome, felicidade, energia, saúde, idade e peso\n\n";
	strcpy(texto, "Pag. 3/3 - Clique para fechar o manual");
	centralizar(texto);
	
	getch();
	system("cls");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	system("mode con:cols=60 lines=20");
	system("color F2");
	
	int esc=1, opc=1, dormir, saude, energia, fome, felicidade, peso, idade, exp=1;
	char nome[1000];
	
	pag_inicial();
	do{
		menu(esc, nome);
		if(esc==1) {
			// Criar novo bichinho
			nascimento(dormir, saude, energia, fome, felicidade, peso, idade, nome);
			principal(dormir, saude, energia, fome, felicidade, peso, idade, nome, opc, exp);
		}
		if(esc==2) {
			// Continuar jogo
			ifstream salvamentoE;
			salvamentoE.open ("salvamento.txt");
			if(salvamentoE.is_open()) {
				char nome1[1000];
				int n[8];
				salvamentoE>>nome1;
				strcpy(nome, nome1);
				cout<<nome;
				for(int i=0; i<8; i++) {
            		salvamentoE>>n[i];
        		}
				dormir=n[0];
				saude=n[1];
				energia=n[2];
				fome=n[3];
				felicidade=n[4];
				peso=n[5];
				idade=n[6];
				exp=n[7];
        		for(int i=0; i<8; i++) {
            		cout<<n[i]<<"\n";
        		}
				salvamentoE.close();
				principal(dormir, saude, energia, fome, felicidade, peso, idade, nome, opc, exp);
			}
			else {
				//Se não houver salvamento
				salvamentoinex();
			}
		}
		if(esc==3) {
			// Manual e Tutorial
			manual();
		}
		if(esc==4) {
			// Sair
	        final();
		}
	} while(esc!=4);
}
