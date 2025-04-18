#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tarefas.h"


// funções básicas
void trabalhar(char bens[], float *dinheiro) {
    // colocando os métodos de trabalho
    puts("\033[36m-------------------------------\033[m");
    printf("\033[32m     Bem-vindo ao trabalho!\033[m\n");
    puts("\033[36m-------------------------------\033[m");
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
    puts("\033[36m-------------------------------\033[m");
    printf("\033[32m     Bem-vindo a faculdade!\033[m\n");
    puts("\033[36m-------------------------------\033[m");
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
    puts("\033[36m-------------------------------\033[m");
    printf("\033[32m     Bem-vindo ao Shopping!\033[m\n");
    puts("\033[36m-------------------------------\033[m");
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
    puts("\033[36m-------------------------------\033[m");
    printf("\033[32m     Bem-vindo ao Banco Center!\033[m\n");
    puts("\033[36m-------------------------------\033[m");
    printf("Seu saldo é de: R$%.2f\n", saldo);
    char total[10][30] = {"Curso Técnico", "Engenharia", "Administração", "Medicina", "Bicicleta", "Moto", "Carro", "Casa normal", "Apartamento", "Mansão"};
    printf("Seus bens e cursos são: \n");
    for (int c=0; c < 9; c++) {
        if (bens[c] == '1') {
            printf("%d - %s\n", c+1, total[c]);
        }
    }
}

// parte de salvar dados


void removeQuebrasDeLinha(char *str) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\r') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}


int salvar_dados_banco(int numero_conta, char bens[], float *dinheiro, char cpf[]) {
    // parte dos banco

    // aqui eu vou mudar, eu vou saber o inicio e o termino da linha e apagar, e depois criar outra com as novas informações!
    FILE *fp = fopen("database/banco.txt", "rb");
    if (!fp) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END); // Move o ponteiro até o final do arquivo.
    long file_size = ftell(fp); //  Retorna o número de bytes do arquivo.
    rewind(fp); // Volta o ponteiro para o início, porque agora a gente já sabe o tamanho e vai começar a leitura.

    char *byte_copiado = (char *)malloc(file_size + 1);
    if (!byte_copiado) {
        printf("Erro ao alocar memória!\n");
        fclose(fp);
        return 1;
    }

    fread(byte_copiado, 1, file_size, fp);
    byte_copiado[file_size] = '\0';  // Finaliza string
    fclose(fp);
    // sabendo disso, eu posso pecorrer isso até o '\n'
    int ultima_virgula = 0, ultimo_ponto = 0, tamanho;
    char comparar[18];
    int c ;
    int inicio_usuario = 0;
    int tamanho_total = strlen(byte_copiado);
    while (1) {
        for (c = ultimo_ponto; byte_copiado[c] != '\n' && byte_copiado[c] != '\0'; c++) { 
            // Encontrar a vírgula que separa o valor
            if (byte_copiado[c] == ',') {
                ultima_virgula = c;
            }
        } 
        ultimo_ponto = c + 1; // Ajusta para sair da linha com '\n'; 
    
        // Aqui eu verifico se o CPF é dele
        tamanho = ultimo_ponto - (ultima_virgula + 2);
        strncpy(comparar, &byte_copiado[ultima_virgula + 1], tamanho);
        comparar[tamanho - 1] = '\0';

    
        if ((strcmp(comparar, cpf) == 0)) {
            char novos_dados_antes[1024];
            char novos_dados_depois[1024];
            char novos_dados_atualizados[2048];
            int tamanho_string;
            // primeiro vamos fazer para se caso o cpf dele não esteja na 1 linha
            // o antes
            if (inicio_usuario != 0) {
                // o antes
                memmove(&novos_dados_antes, &byte_copiado[0], inicio_usuario + 1);
                tamanho_string = inicio_usuario + 1;
                novos_dados_antes[tamanho_string] = '\0'; // isso é para evitar qualquer erro!
                // o depois
                memmove(&novos_dados_depois, &byte_copiado[ultimo_ponto], strlen(&byte_copiado[ultimo_ponto]) + 1);
                tamanho_string = strlen(&byte_copiado[ultimo_ponto]) + 1;
                novos_dados_depois[tamanho_string] = '\0'; // isso é para evitar qualquer erro!
                // atualização
                snprintf(novos_dados_atualizados, sizeof(novos_dados_atualizados), "%s%d,%.2f,%s\n%s", novos_dados_antes, numero_conta,*dinheiro,cpf,novos_dados_depois);
            }
            else {
                // o depois
                memmove(&novos_dados_depois, &byte_copiado[ultimo_ponto], strlen(&byte_copiado[ultimo_ponto]) + 1);
                tamanho_string = strlen(&byte_copiado[ultimo_ponto]) + 1;
                novos_dados_depois[tamanho_string] = '\0'; // isso é para evitar qualquer erro!
                // a atualização
                snprintf(novos_dados_atualizados, sizeof(novos_dados_atualizados), "%d,%.2f,%s\n%s", numero_conta,*dinheiro,cpf,novos_dados_depois);
            }

            removeQuebrasDeLinha(novos_dados_atualizados); // para tirar os caracteres de "\r" que tava dando erro!

            // colocando os dados para novamente
            FILE *adicionar_novosdados = fopen("database/banco.txt", "w");
            if (!adicionar_novosdados) {
                printf("Houve algum erro!\n");
                return 1;
            }

            fprintf(adicionar_novosdados, "%s", novos_dados_atualizados); // 0 é o saldo
            fclose(adicionar_novosdados);
            break; // encerrando esse while
            // colocando os dados para novamente
        }
        else {
            inicio_usuario = c; // para saber o inicio 
        }

    }   
    free(byte_copiado); 
    return 0;
}

int salvar_dados_bens(char bens[], char cpf[]) {
    // parte dos bens
    FILE *file = fopen("database/bens.txt", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fseek(file, 0, SEEK_END); // Move o ponteiro até o final do arquivo.
    long size_bens = ftell(file); //  Retorna o número de bytes do arquivo.
    rewind(file); // Volta o ponteiro para o início, porque agora a gente já sabe o tamanho e vai começar a leitura.

    char *byte_bens = (char *)malloc(size_bens + 1);
    if (!byte_bens) {
        printf("Erro ao alocar memória!\n");
        fclose(file);
        return 1;
    }

    fread(byte_bens, 1, size_bens, file);
    byte_bens[size_bens] = '\0';  // Finaliza string
    fclose(file);

    // sabendo disso, eu posso pecorrer isso até o '\n'
    int ultimo_espaco = 0, inicio_copia = 0;
    int c ;
    int inicio_usuario = 0;
    int tamanho_total;
    char comparar[80];
    while (1) {
        // for para achar o ','
        for (c = ultimo_espaco; byte_bens[c] != '\0'; c++) { 
            // Encontrar a vírgula que separa o valor
            if (byte_bens[c] == '\n') {
                ultimo_espaco = c + 1;
                break; // isso significa que ele achou
            }
        } 
        tamanho_total = (ultimo_espaco - inicio_copia - 13);
        strncpy(comparar, &byte_bens[inicio_copia], tamanho_total);
        comparar[tamanho_total] = '\0';
        inicio_copia = ultimo_espaco;
        // veririfar se os cpf são iguais!
        if ((strcmp(comparar, cpf) == 0)) {
            // vou ter que fazer o antes e o depois para copiar corretamente! No caso descubro o antes, o depois e copio.
            char novos_dados_antes[1024];
            char novos_dados_depois[1024];
            char novos_dados_atualizados[2048];
            int tamanho_string;
            // primeiro vamos fazer para se caso o cpf dele não esteja na 1 linha
            //sprintf(bens, "%s", "1840132018");
            if (inicio_usuario != 0) {
                // o antes
                memmove(&novos_dados_antes, &byte_bens[0],  inicio_usuario + 1);
                tamanho_string = (inicio_usuario + 1);
                novos_dados_antes[tamanho_string] = '\0';
                // o depois
                memmove(&novos_dados_depois, &byte_bens[ultimo_espaco], strlen(byte_bens) - ultimo_espaco);
                tamanho_string =  strlen(byte_bens) - ultimo_espaco;
                novos_dados_depois[tamanho_string] = '\0';
                // atualização
                snprintf(novos_dados_atualizados, sizeof(novos_dados_atualizados), "%s%s,%s\n%s", novos_dados_antes, cpf, bens, novos_dados_depois);
            }
            else {
                // o depois
                memmove(&novos_dados_depois, &byte_bens[ultimo_espaco],  strlen(byte_bens) - ultimo_espaco);
                novos_dados_depois[strlen(byte_bens) - ultimo_espaco] = '\0'; // pra evitar o bug de lixo de memória

                // a atualização
                snprintf(novos_dados_atualizados, sizeof(novos_dados_atualizados), "%s,%s\n%s", cpf, bens, novos_dados_depois);
            }
            //removeQuebrasDeLinha(novos_dados_atualizados); // para tirar os caracteres de "\r" que tava dando erro!
            //printf("Novos dados: %s", novos_dados_depois);

            // colocando os dados para novamente
            removeQuebrasDeLinha(novos_dados_atualizados); // para tirar os caracteres de "\r" que tava dando erro!
     
            FILE *adicionar_novosdados = fopen("database/bens.txt", "w");
            if (!adicionar_novosdados) {
                printf("Houve algum erro!\n");
                return 1;
            }

            fprintf(adicionar_novosdados, "%s", novos_dados_atualizados); // 0 é o saldo
            fclose(adicionar_novosdados);
            break;
        }
        else {
            inicio_usuario = c;
        }
      
    }
    free(byte_bens);
    return 0;
}
