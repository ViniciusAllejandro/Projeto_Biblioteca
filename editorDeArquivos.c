#include <stdio.h>
#include  "editorDeArquivos.h"

int teste = 1;
int c;

int main(){

if(fopen("ListaClientes.txt" , "r") ==  NULL){
    newClientList(); 
}
while(teste == 1){
    addClientList();
    editorfiles();
    printf("Deseja continuar?");
    scanf("%d", &teste);
    while ((c = getchar()) != '\n' && c != EOF);
}
return 0 ;
}