#include <stdio.h>
#include <windows.h>
#include "funcoes/pessoas.h"
#include "funcoes/geral.h"
#include "funcoes/tarefas.h"

#define vermelho "\033[31m"
#define verde "\033[32m"
#define amarelo "\033[33m"

// aqui as estastitivas vai ser os 2 primeiros serão escolaridade e emprego, e o resto os bens!


// criação dos struct

typedef struct Banco {
    int numero_conta;
    float saldo;
    char chave[18]; // chave para a trasfêrencia
} Banco;


// sistema de bens segue uma string númerica, por exemplo: 1110001110011. Sendo 0 o que ele não possui e 1 oq ele possui e é seguido para essa ordem! No caso, como é string, se eu sei a ordem, por exemplo, casa é o índice 0, então, se casa tá 1, é pq ele tem!

typedef struct Pessoa {
    char nome[1024];
    char cpf[18];
    char senha[10];
    Banco banco;

} Pessoa;



// criação das funções



int main(int argc, char const *argv[]) {
    inicial("Simulação de Vida", amarelo);
    printf("Bem-vindo ao simulador de vida! Este é um jogo interativo onde você pode simular uma vida, podendo criar contas pessoas, bancárias ");
    printf("além de poder trabalhar e fazer faculdade! Jogue o jogo e aprenda!\n");
    //mensagem("Carregando...", verde);
    //Sleep(3000);

    // parte do menu
    Pessoa jogador;
    // conta
    char nome[1024];
    char cpf[18];
    char senha[10];
    // banco
    int numero_conta;
    float saldo;
    char bens[12];
    while (1) {
        switch (menu_perfil()) {
            case 1:
                cadastro(nome, cpf, senha);
                criar_banco(cpf, &numero_conta, &saldo);
                break;
            case 2:

                login(nome, cpf, senha);

                // agora eu vou criar as instâncias
                strcpy(jogador.nome, nome);
                strcpy(jogador.cpf, cpf);
                strcpy(jogador.senha, senha);

                // acesando o banco
                acessar_banco(cpf, &numero_conta, &saldo, bens);

                jogador.banco.numero_conta = numero_conta;
                jogador.banco.saldo = saldo;
                strcpy(jogador.banco.chave, cpf);
            

                // verificando os bens
                //printf("Os bens aqui são: %s\n", bens);
                break;
            case 3:
                printf("Obrigado por acessar nosso jogo!\n");
                exit(0);
        }
        // parte para o jogo!
        while (1) {
            int retorno = menu_estudo_trabalho();
            if (retorno == 1) { // caso ele queira trabalhar
               //printf("Os bens aqui são: %s\n", bens);
                trabalhar(bens, &jogador.banco.saldo);
            } 
            else if (retorno == 2) {
                estudar(bens, &jogador.banco.saldo);
            }
            else if (retorno == 3) {
                comprar(bens, &jogador.banco.saldo);
            }
            else if (retorno == 4) {
                ver_banco(jogador.banco.saldo, bens);
            }
            else {
                salvar_dados_banco(jogador.banco.numero_conta, bens, &jogador.banco.saldo, jogador.cpf);
                salvar_dados_bens(bens, jogador.cpf);
                printf("Dados salvos com sucesso! Indo para a página principal!\n");
                break;
            }
        // aqui é parte para salvar o dinheiro, as compras de estudo, trabalho, coisas, afins!
        }
        // No caso aqui é a parte de trabalho ou emprego
    }
    return 0;
}
