#include "arvbinaria.h"


int main(int argc, char** argv) {

    tiporegistro x;
  
    tipoapontador h;
        inicializa(&h);
        int op=0;
        while(op!=5){
        
        printf("\nO que deseja fazer : \n\t1-Inserir item\n\t2-Remover item\n\t3-Pesquisar item\n\t4-Imprimir\n\t5-Sair\n\tOpcao escolhida: ");
        scanf("%d",&op);
        
        
            switch(op){
                case 1: 
                    printf("Digite um item a ser inserido: ");
                    scanf("%d",&x);
                    insere(x, &h);
                    break;
                    
                case 2: 
                    printf("Digite o item a ser retirado: ");
                    scanf("%d", &x);
                    retira(x, &h);
                    break;
                    
                case 3:
                    printf("Digite o item a ser pesquisado: ");
                    scanf("%d", &x);
                    pesquisa(&x, &h);
                    
                    break;
                    
                case 4:
                    imprime(h);break;
                    
                    
            }
        }
        
    
    
    return (EXIT_SUCCESS);
}


    

