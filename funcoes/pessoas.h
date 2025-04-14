#ifndef PESSOAS_H
#define PESSOAS_H

int cadastro(char nome_enviar[], char cpf_enviar[], char senha_enviar[]);

int login(char nome_enviar[], char cpf_enviar[], char senha_enviar[]);

int criar_banco(char cpf[], int *numero_conta, float *saldo);

int acessar_banco(char cpf[], int *numero_conta, float *saldo, char bens_usuario[]);

#endif