#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE *file;

void newClientList() { // Making a new file for client list
    file = fopen("ListaClientes.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }
    printf("Arquivo criado com sucesso.\n");
    fprintf(file, "%-50s %-10s %-15s %-10s\n", "NOME", "IDADE", "DOCUMENTO", "USER_ID");
    fclose(file);
}

void addClientList(){ // Add. new clients
    srand(time(NULL));
    struct client {
        char name[50];
        int age;
        char cpf[15];
        int user_id;
    } newClient;

    printf("Digite o nome do cliente:\n");
    fgets(newClient.name, 49, stdin); 

    size_t len = strlen(newClient.name);
    if (len > 0 && newClient.name[len - 1] == '\n') {
        newClient.name[len - 1] = '\0';
    }

    printf("Qual a idade do Cliente:\n");
    scanf("%d", &newClient.age); 

    printf("Digite um documento sem pontos e traços:\n");
    scanf("%14s", newClient.cpf);

    // Definindo um ID para o cliente
    newClient.user_id = ((rand() % 1000) + 1);

    // Abre o arquivo no modo append
    file = fopen("ListaClientes.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }

    fprintf(file, "%-50s %-10d %-15s %-10d\n", newClient.name, newClient.age, newClient.cpf, newClient.user_id);
    fclose(file);
    printf("Cliente adicionado com sucesso!\n");
}

#include <stdio.h>
#include <string.h>

void editorfiles() {
    struct client {
        char name[50];
        int age;
        char cpf[15];
        int user_id;

    } searchClient;

    char pesquisa[50];
    char clienteEncontrado[100];

    file = fopen("ListaClientes.txt", "r");

    if(file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Qual pessoa voce esta procurando? ");
    scanf("%49s", pesquisa);

    int found = 0;
    while (fscanf(file, "%49s", clienteEncontrado) != EOF) {
        if (strcmp(clienteEncontrado, pesquisa) == 0) {
            printf("Cliente encontrado: %s\n", clienteEncontrado);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Cliente não encontrado.\n");
    }

    fclose(file);
}

