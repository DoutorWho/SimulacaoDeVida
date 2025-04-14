#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include "geral.h"

#define vermelho "\033[31m"
#define verde "\033[32m"
#define amarelo "\033[33m"


bool saoNumericos(const char *str) {
    while (*str) {
        if (!isdigit((unsigned char)*str)) {
            return false; // Retorna falso se algum caractere não for numérico
        }
        str++;
    }
    return true; // Todos os caracteres são numéricos
}

void inicial(char *texto, char *cor) {
    puts("\033[36m----------------------\033[m");
    printf("  %s%s\033[m\n", cor, texto);
    puts("\033[36m----------------------\033[m");
}

void mensagem(char *texto, char *cor) {
    printf("%s%s\033[m\n", cor, texto);
}

int menu_perfil() {
    int escolha;
    while (1) {
        printf("Tela de cadastro/login\n");
        puts("[1] - Cadastrar uma conta");
        puts("[2] - Logar em uma conta");
        puts("[3] - Sair do jogo");
        printf("Qual opção deseja escolher? ");
        scanf("%d", &escolha);
        if (escolha == 1) {
            return 1;
        }   
        if (escolha == 2) {
            return 2;
        }
        if (escolha == 3) {
            return 3;
        }
        mensagem("Digite uma opção válida!", vermelho);
        Sleep(2000);
    }
}

int menu_estudo_trabalho() {
    int escolha;
    while (1) {
        inicial("Simulação de Vida - Jogo", verde);
        puts("[1] - Trabalhar (Para ganhar dinheiro)");
        puts("[2] - Estudar (Aprende algum conteúdo!)");
        puts("[3] - Comprar (Compre um carro, casa, veículos)");
        puts("[4] - Banco (Ver saldo e os bens em seu nome)!");
        puts("[5] - Sair e Salvar");
        printf("Qual opção deseja escolher? ");
        scanf("%d", &escolha);
        if (escolha == 1) {
            return 1;
        }   
        if (escolha == 2) {
            return 2;
        }
        if (escolha == 3) {
            return 3;
        }
        if (escolha == 4) {
            return 4;
        }
        if (escolha == 5) {
            return 5;
        }
        mensagem("Digite uma opção válida!", vermelho);
        Sleep(2000);
    }

}