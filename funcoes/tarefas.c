#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tarefas.h"

void adicionar_dinheiro() {

}

void status() { // vê o status do usuário

}


// funções básicas
void trabalhar(char bens[], float *dinheiro) {
    // colocando os métodos de trabalho
    puts("-----------------------------");
    printf("Bem-vindo ao trabalho!\n");
    puts("-----------------------------");
    int escolha;
    while (1) {
        puts("[1] - Operário");
        puts("[2] - Engenharia");
        puts("[3] - Comerciante");
        puts("[4] - Medicina");
        printf("Qual trabalho deseja realizar? ");
        scanf("%d", &escolha);
        if (escolha > 0 && escolha < 5) {
            // vamos veririficar se ele tem esse trabalho
            if (bens[escolha-1] == '1') {
                break;
            }
            else {
                printf("Você não possui esse emprego!\n");
            }
        }
        printf("Erro - Por favor digite um número válido!\n");
    }
    // a parte de trabalho. O jogo é igual para todos, tem números de 1 a 10, ele escolhe o salário é retornado.
    srand(time(NULL));
    int minimo=1, maximo=2;
    switch (escolha) {
        case 1:
            minimo = 10;
            maximo = 20;
            break;
        case 2:
            minimo = 50;
            maximo = 100;
            break;
        case 3:
            minimo = 200;
            maximo = 500;
            break;
        case 4:
            minimo = 800;
            maximo = 1200;
    }
    // colocar um sleep de trabalho
    float valores=0;
    for (int c=0; c < 5; c++) {
        valores += minimo + ((float)rand() / RAND_MAX) * (maximo - minimo);
    }
    *dinheiro += *dinheiro + valores;
    printf("Parabéns, você ganhou no total: R$%.2f.\nSeu saldo atualmente é de: R$%.2f\n", valores, *dinheiro);
    // salvar o novo dinheiro no banco de dados
}


void estudar(char bens[], float *dinheiro) {
    // fazer uma verificação lá, pq se ele tiver todos os tipos de curso, não precisa vim aqui!
    puts("-----------------------------");
    printf("Bem-vindo a faculdade!\n");
    puts("-----------------------------");
    int escolha;
    // Aqui ele retorna o índice da opção, que após tudo isso, é salvo, assim como o dinheiro!!
    while (1) {
        puts("[1] - Engenharia (R$ 2300,00)");
        puts("[2] - Administração (R$ 8300,00)");
        puts("[3] - Medicina (R$ 15300,00)");
        printf("O que deseja estudar? ");
        scanf("%d", &escolha);
        if (escolha > 0 && escolha < 4) {
            // vamos veririficar se ele tem esse trabalho
            if (bens[escolha] == '1') {
                printf("Você já possui esse curso!!\n");
                continue;;
            }
            break;
        }
        printf("Erro - Por favor digite um número válido!\n");
    }
    int opcao;
    if (escolha == 1) {
        // verifica se ele tem dinheiro
        if (*dinheiro >= 2300.00) {
            *dinheiro = *dinheiro - 2300;
            bens[1] = '1';
            printf("Parabéns, você acaba de se tonar Engenheiro!\n");
        }
    }
    else if (escolha == 2) {
        // verifica se ele tem dinheiro
        if (*dinheiro >= 8300.00) {
            *dinheiro = *dinheiro - 8300;
            bens[2] = '1';
            printf("Parabéns, você acaba de se tonar Administrador!\n");
        }
    }
    else if (escolha == 3) {
        // verifica se ele tem dinheiro
        if (*dinheiro >= 15300.00) {
            *dinheiro = *dinheiro - 15300;
            bens[2] = '3';
            printf("Parabéns, você acaba de se tonar Médico!\n");
        }
    }

}

void comprar(char bens[], float *dinheiro) {
    puts("-----------------------------");
    printf("Bem-vindo a Shop!\n");
    puts("-----------------------------");
    int escolha;
    while (1) {
        puts("[1] - Automoveis");
        puts("[2] - Casa");
        printf("O que deseja comprar? ");
        scanf("%d", &escolha);
        if (escolha > 0 && escolha < 3) {
            break;
        }
        printf("Por favor, escolha uma das opções!\n");
    }
    char automoveis[3][30] = {"Bicicleta", "Moto", "Carro"};
    char casas[3][30] = {"Casa normal", "Apartamento", "Mansão"};
    // valores
    float valor_automovel[3] = {500.00, 20000.20, 100000.00};
    float valores_casas[3] = {3000.40, 80000.80, 850000.78};
    int produto_escolhido;
    if (escolha == 1) { 
        while (1) {
            for (int c=0; c < 3; c++) {
                printf("[%d] - %s (R$%.2F)\n", c+1, automoveis[c], valor_automovel[c]);
            }
            printf("O que você deseja comprar? ");
            scanf("%d", &produto_escolhido);
            if (escolha > 0 && escolha < 4) {
                // se caso for isso mesmo, vamos verificar se ele tem
                if ((bens[3+produto_escolhido] == '0') && (*dinheiro >= valor_automovel[produto_escolhido-1])) {
                    *dinheiro = *dinheiro - valor_automovel[produto_escolhido-1];
                    bens[3+produto_escolhido] = '1';
                    printf("Parabéns, você acaba de adquirir um %s por R$%.2f!\n", automoveis[produto_escolhido-1], valor_automovel[produto_escolhido-1]);
                    break;
                }
                printf("Você já tem esse produto ou o dinheiro é insuficiente!\n");
            }
            else {
                printf("Por favor, escolha uma das opções\n");
            }
        }
    }
    else if (escolha == 2) {
        while (1) {
            for (int c=0; c < 3; c++) {
                printf("[%d] - %s (R$%.2F)\n", c+1, casas[c], valores_casas[c]);
            }
            printf("O que você deseja comprar? ");
            scanf("%d", &produto_escolhido);
            if (escolha > 0 && escolha < 4) {
                // se caso for isso mesmo, vamos verificar se ele tem
                if ((bens[3+produto_escolhido] == 0) && (*dinheiro >= valores_casas[produto_escolhido-1])) {
                    *dinheiro = *dinheiro - valores_casas[produto_escolhido-1];
                    bens[3+produto_escolhido] = '1';
                    printf("Parabéns, você acaba de adquirir um %s por R$%.2f!\n", casas[produto_escolhido-1], valores_casas[produto_escolhido-1]);
                    break;
                }
                printf("Você já tem esse produto ou o dinheiro é insuficiente!\n");
            }
            else {
                printf("Por favor, escolha uma das opções!\n");
            }
        }
    }


}


void ver_banco(float saldo, char bens[]) { // transferir ou vê status de pagamento
    puts("-----------------------------");
    printf("Bem-vindo ao banco!\n");
    puts("-----------------------------");
    printf("Seu saldo é de: R$%.2f\n", saldo);
    char total[10][30] = {"Curso Técnico", "Engenharia", "Administração", "Medicina", "Bicicleta", "Moto", "Carro", "Casa normal", "Apartamento", "Mansão"};
    printf("Seus bens e cursos são: \n");
    for (int c=0; c < 9; c++) {
        if (bens[c] == '1') {
            printf("%d - %s\n", c+1, total[c]);
        }
    }
}


int salvar_dados(char bens[], float *dinheiro, char cpf[]) {
    // parte do banco
    return 0;
}
