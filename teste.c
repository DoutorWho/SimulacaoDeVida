#include <stdio.h>
#include <string.h>

int login(char *nome_enviar, int *cpf_enviar, char *senha_enviar) {
    char nome_confirmado[] = "João";
    char senha_confirmada[] = "12345678";

    strncpy(nome_enviar, nome_confirmado, 1024);  // Cópia segura
    nome_enviar[1023] = '\0';  // Garante null-terminator

    *cpf_enviar = 80;

    strncpy(senha_enviar, senha_confirmada, 8); // Cópia segura
    senha_enviar[7] = '\0';  // Garante null-terminator

    return 0;
}

int main() {
    char nome[1024] = {0};
    int valor = 0;
    char senha[8] = {0};

    login(nome, &valor, senha);

    printf("O nome é: %s\n", nome);
    printf("O valor de cpf é: %d\n", valor);
    printf("A senha é: %s\n", senha);

    return 0;
}
