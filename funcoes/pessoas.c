#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "pessoas.h"
#include "geral.h"


int cadastro(char nome_enviar[], char cpf_enviar[], char senha_enviar[]) {
    puts("\033[36m---------------------------------------------------\033[m");
    printf("                Bem-vindo ao cadastramento de usuário!\n");
    puts("\033[36m---------------------------------------------------\033[m");
    
    // digitação de nome
    DWORD quantidade;
    wchar_t input[512];
    char utf8_input[1024];
    int utf_len = 0; // Variável para armazenar o tamanho real da string convertida

    while (1) {
        printf("Digite seu nome completo: ");
        ReadConsoleW(GetStdHandle(STD_INPUT_HANDLE), input, 512, &quantidade, NULL);
        // remover caracteres de nova linha presente
        if (input[quantidade - 1] = L'\n') {
            input[quantidade - 1] = L'\0';
        }

        //conventer para utf-8
        utf_len = 0; // Variável para armazenar o tamanho real da string convertida
        if (quantidade > 5) {
            utf_len = WideCharToMultiByte(CP_UTF8, 0, input, quantidade, utf8_input, sizeof(utf8_input), NULL, NULL);
            utf8_input[utf_len-2] = '\0'; // pra tirar o '\n'. 
            break;
        }
        else {
            printf("\033[31ERRO\033[m - Digite seu nome completo!\n");
        }
    }
    // outras partes como senha e cpf
    char cpf[18];
    char senha[10];
    int c = 0;
    // criar uma config aqui! Uma variável temp de teste para cpf e senha!
    while (1) {

        printf("Digite seu CPF (Somente números): ");
        scanf("%s", &cpf);
        if (!saoNumericos(cpf)) {
            printf("\033[31mERRO\033[m - Digite somente números em seu CPF!\n");
            continue;
        } 
        break;
    }
    while (1){
        printf("Digite sua senha (8 caracteres): ");
        scanf("%s", senha);
        if (strlen(senha) == 8) {
            break;
        }
        printf("\033[31mERRO\033[m - Digite uma senha de 8 caracteres!\n");
    }
    // abrindo os nomes já existentes
    FILE *fp = fopen("database/cadastros.txt", "rb");
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

    // colocando os dados para cadastrar
    FILE *file = fopen("database/cadastros.txt", "w");
    if (!file) {
        printf("Houve algum erro!\n");
        return 1;
    }
    size_t len = strlen(byte_copiado);
    if (len > 0 && byte_copiado[len - 1] == '\n') { // garante que não haja o erro do '\n' que pula uma linha no inicio do nome!
        byte_copiado[len - 1] = '\0';
    }
    fprintf(file, "%s%s,%s,%s\n", byte_copiado, utf8_input, cpf, senha);
    fclose(file);

    // copiando os dados

    strncpy(nome_enviar, utf8_input, 1024);
    nome_enviar[strlen(utf8_input)] = '\0';

    strncpy(cpf_enviar, cpf, 18);
    cpf_enviar[18] = '\0';

    strncpy(senha_enviar, senha, 10);
    senha_enviar[8] = '\0';


    return 1;
}

int login(char nome_enviar[], char cpf_enviar[], char senha_enviar[]) {
    puts("\033[36m---------------------------------------------------\033[m");
    printf("                Bem-vindo ao login de usuário!\n");
    puts("\033[36m---------------------------------------------------\033[m");
    char cpf[18];
    char senha[10];
    printf("Digite seu CPF: ");
    scanf("%s", cpf);
    printf("Digite sua senha: ");
    scanf("%s", senha);
    // indentificando a senha dele
    FILE *fp = fopen("database/cadastros.txt", "rb");
    rewind(fp);
    if (!fp) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    // passando por cada conta
    char temp[1024];
    char temporal[2] = {0, 0};
    int cumprimento_linha;
    int tempo_verificao=0;
    // para verificação
    char nome_confirmado[1024];
    char cpf_confirmado[18];
    char senha_confirmada[10];
    while (fgets(temp, 1024, fp) != NULL) {
        // Alexandre Matos,100,12345678
        cumprimento_linha = strlen(temp);

        // Tira o \n e ajusta comprimento real
        if (temp[cumprimento_linha - 1] == '\n') {
            temp[cumprimento_linha - 1] = '\0';
            cumprimento_linha--;
        }

        for (int c=0; c < cumprimento_linha; c++) {
            if (temp[c] == ',')  {
                if (tempo_verificao == 0) {
                    strncpy(nome_confirmado, temp, c);
                    nome_confirmado[c] = '\0';
                }
                temporal[tempo_verificao++] = c;
            }
        }
        // pegando o valor de cpf e senha
        // pegando o cpf
        int inicio1 = temporal[0] + 1;
        int fim1 = temporal[1] - inicio1;
        strncpy(cpf_confirmado, &temp[inicio1], fim1);
        cpf_confirmado[fim1] = '\0';

        // valor de senha
        int inicio2 = temporal[1] + 1;
        int fim2 = cumprimento_linha - inicio2;
        strncpy(senha_confirmada, &temp[inicio2], fim2);
        if (temp[cumprimento_linha - 1] == '\n') fim2--; // Remove \n do final se existir
        senha_confirmada[fim2-1] = '\0'; // para consertar o erro do '\n' no final!

        
        // verificando se é o do usuário que digitou
        if ((strcmp(cpf, cpf_confirmado) == 0) && (strcmp(senha, senha_confirmada) == 0)) {
            // colocando os dados para retornar

            strncpy(nome_enviar, nome_confirmado, 1024);
            nome_enviar[strlen(nome_confirmado)] = '\0';

            strncpy(cpf_enviar, cpf_confirmado, 18);
            cpf_enviar[18] = '\0';

            strncpy(senha_enviar, senha_confirmada, 10);
            senha_enviar[8] = '\0';

            return 1;
        }

        // resetando tudo
        temporal[0] = 0;
        temporal[1] = 0;
        tempo_verificao = 0;
    }
    return 0;
    fclose(fp);
    return 0;
}

// criar e acessar os bancos

int criar_banco(char cpf[], int *numero_conta, float *saldo) {
    // criação de conta bancária
    srand(time(NULL));
    int numero_da_conta = rand() % 90000000 + 10000000; // aqui é o número da conta, e a chave pix é o spf dele
    // abrindo os nomes já existentes

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

    // colocando os dados para cadastrar
    FILE *file = fopen("database/banco.txt", "w");
    if (!file) {
        printf("Houve algum erro!\n");
        return 1;
    }
    size_t len = strlen(byte_copiado);
    if (len > 0 && byte_copiado[len - 1] == '\n') { // garante que não haja o erro do '\n' que pula uma linha no inicio do nome!
        byte_copiado[len - 1] = '\0';
    }
    fprintf(file, "%s%d,%.2f,%s\n", byte_copiado, numero_da_conta, 0.0, cpf); // 0 é o saldo
    fclose(file);
    // retornar os dados do banco
    *numero_conta = numero_da_conta;
    *saldo = 0.0;

    // criar o arquivo na parte de bens

    // abrindo os bens já existentes

    FILE *bens_acessar = fopen("database/bens.txt", "rb");
    if (!bens_acessar) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fseek(bens_acessar, 0, SEEK_END); // Move o ponteiro até o final do arquivo.
    long size_bens_acessar = ftell(bens_acessar); //  Retorna o número de bytes do arquivo.
    rewind(bens_acessar); // Volta o ponteiro para o início, porque agora a gente já sabe o tamanho e vai começar a leitura.

    char *byte_bens_acessar = (char *)malloc(size_bens_acessar + 1);
    if (!byte_bens_acessar) {
        printf("Erro ao alocar memória!\n");
        fclose(bens_acessar);
        return 1;
    }

    fread(byte_bens_acessar, 1, size_bens_acessar, bens_acessar);
    byte_bens_acessar[size_bens_acessar] = '\0';  // Finaliza string
    fclose(bens_acessar);

    // colocando os dados para cadastrar
    FILE *bens_adicionar = fopen("database/bens.txt", "w");
    if (!bens_adicionar) {
        printf("Houve algum erro!\n");
        return 1;
    }
    size_t len_bens = strlen(byte_bens_acessar);
    if (len_bens > 0 && byte_bens_acessar[len_bens - 1] == '\n') { // garante que não haja o erro do '\n' que pula uma linha no inicio do nome!
        byte_bens_acessar[len_bens - 1] = '\0';
    }
    fprintf(bens_adicionar, "%s%s,1000100100\n", byte_copiado, cpf); // 0 é o saldo
    fclose(bens_adicionar);

    return 1;
}

int acessar_banco(char cpf[], int *numero_conta, float *valor, char bens_usuario[]) {
    // indentificando a senha dele
    FILE *fp = fopen("database/banco.txt", "rb");
    rewind(fp);
    if (!fp) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    // passando por cada conta
    int cumprimento_linha;
    char temp[1024];

    // valores 
    char numero_da_conta_str[9];
    char saldo_str[32];
    int ultima_virgula;
    // comparação
    char comparar[18];
    while (fgets(temp, 1024, fp) != NULL) {
        // 10003172,0.00,100
        temp[strcspn(temp, "\r\n")] = '\0'; // para tirar o erro de contar mais do que deve
        cumprimento_linha = strlen(temp);
        
        

        for (int c=9; c < cumprimento_linha; c++) {
            if (temp[c] == ',')  {
                ultima_virgula = c; // aqui ele vai pegar a última vírgula
            }
        }   

        strncpy(comparar, &temp[ultima_virgula+1], cumprimento_linha);
        comparar[cumprimento_linha - ultima_virgula - 1] = '\0';

        if (strcmp(cpf, comparar) == 0) { // significa que é esse CPF a conta!
            // pegando o numero da conta    
            strncpy(numero_da_conta_str, &temp[0], 8);
            numero_da_conta_str[8] = '\0';   
            *numero_conta = atoi(numero_da_conta_str);

            // pegando o valor da conta bancária
            char *endptr;
            strncpy(saldo_str, &temp[9], ultima_virgula-9);
            saldo_str[ultima_virgula - 9] = '\0';
            *valor = strtof(saldo_str, &endptr);
      
            break;
            
        }
    }
    fclose(fp);

    // acessar os bens
    FILE *bens = fopen("database/bens.txt", "rb");
    rewind(bens);
    if (!bens) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    int ultima_virgula_bens;
    char temp_bens[1024];
    // comparação
    char comparar_bens[18];

    while (fgets(temp_bens, 1024, fp) != NULL) {
        // 10003172,0.00,100
        temp_bens[strcspn(temp, "\r\n")] = '\0'; 
        cumprimento_linha = strlen(temp_bens);
        

        for (int c=0; c < cumprimento_linha; c++) {
            if (temp_bens[c] == ',')  {
                ultima_virgula_bens = c; // aqui ele vai pegar a última vírgula
                break;
            }
        }   

        strncpy(comparar_bens, &temp_bens[0], ultima_virgula_bens); // retornar o cpf
        if (strcmp(cpf, comparar_bens) == 0) { // significa que é esse CPF a conta!
            // retornando a lista de bens

            strncpy(bens_usuario, &temp_bens[ultima_virgula_bens]+1, cumprimento_linha - ultima_virgula_bens);
            bens_usuario[10] = '\0';

            fclose(bens);
            return 1;
        }
    }
    fclose(bens);
    return 0;

}