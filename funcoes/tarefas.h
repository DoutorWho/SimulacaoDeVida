#ifndef TAREFAS_H
#define TAREFAS_H

void trabalhar(char bens[], float *dinheiro);

void estudar(char bens[], float *dinheiro); 

void comprar(char bens[], float *dinheiro);

void ver_banco(float saldo, char bens[]);

int salvar_dados_banco(int numero_conta, char bens[], float *dinheiro, char cpf[]);

int salvar_dados_bens(char bens[], char cpf[]);
#endif
