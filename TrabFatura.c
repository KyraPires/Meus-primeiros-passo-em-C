#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    FILE *arq;
    FILE *errofat;
    char *aux;
    int tam;
    typedef struct Fatura{
        int codFat;
        char codProd[4];
        char produto [34];
        int qtde;
        double valor;
        double frete;
        double total;
        char fornecedor[5];  
        }Fatura;

    Fatura campofat[500];

void Substring(char *entrada, int inicio, int fim)
{	
    *(entrada + fim + 1) = '\0';
    entrada = (entrada + inicio);
    aux = entrada;
}

void Leitura()
{
    char linhacod[70];
    char temp[70];
    int i = 0;

    arq = fopen("fatura.txt", "r");

    if(arq == NULL)
    {
        printf("Erro ao abrir arquivo");
    }   
    fgets(linhacod,70,arq);

    while(!feof(arq))
    {
        strcpy(temp, linhacod);
        aux = linhacod;        
        Substring(aux, 0, 3);
        campofat[i].codFat = atoi(aux);

		strcpy(linhacod, temp);
        aux = linhacod;
        Substring(aux, 4, 6);
        strcpy(campofat[i].codProd, aux);

       strcpy(linhacod, temp);
		aux = linhacod;
        Substring(aux, 7, 39);
        strcpy(campofat[i].produto, aux);

        strcpy(linhacod, temp);
		aux = linhacod;
        Substring(aux, 40, 43);
        campofat[i].qtde = atoi(aux);

        strcpy(linhacod, temp);
		aux = linhacod;
        Substring(aux, 44, 53);
        campofat[i].valor= atof(aux)/100;

        strcpy(linhacod, temp);
		aux = linhacod;
        Substring(aux, 54, 63);
        campofat[i].frete = atof(aux)/100;

        strcpy(linhacod, temp);
		aux = linhacod;
        Substring(aux, 64, 67);
        strcpy(campofat[i].fornecedor, aux);

        campofat[i].total = (campofat[i].valor * campofat[i].qtde + campofat[i].frete);
        i++;
        tam = i;

        fgets(linhacod,70,arq);

    }

    fclose(arq);

}
void Erro()
{
    char listaErro[70], linhacod[70];
    int i;

    errofat = fopen("ErroFatura.txt", "w");
    arq = fopen("fatura.txt", "r");  
    
    for(i = 0; i < tam; i++)
    { 
        fgets(linhacod,70,arq);
        linhacod[68] = '\0';
        if((campofat[i].qtde == 0) || (campofat[i].valor == 0.0) || (strcmp(campofat[i].fornecedor, "0000")==0))
        {            
            if(campofat[i].qtde == 0)
            {
                fprintf(errofat, "%s QUANTIDADE DEVE SER MAIOR QUE ZERO \n", linhacod);
            }
            if(campofat[i].valor == 0.0)
            {
                fprintf(errofat, "%s VALOR DEVE SER INFORMADO \n", linhacod);
            }
            if(strcmp(campofat[i].fornecedor, "0000")==0)
            {
                fprintf(errofat, "%s FORNECEDOR DEVE SER INFORMADO \n", linhacod);
            }            
        }     
    }
    fclose(errofat);
    fclose(arq);       
}

void Exibir(Fatura *ordenar)
{
    char listagem[70];
    int i, j=1;
    Fatura temp;

    arq = fopen("fatura.txt", "r");
    fgets(listagem,80,arq);
    
    while (j<tam)
    {
        temp = ordenar[j];
        i = j - 1;
        while (i >= 0 && ordenar[i].codFat > temp.codFat)
        {
            ordenar[i+1] = ordenar[i];
            i = i - 1;
        }
        ordenar[i+1] = temp;
        j = j + 1;
    }

    printf("Fatura   Produto                               Qtde  Valor Un.      Frete        Total   Fornecedor \n");
    for(i=0; i < tam; i++){

        if((campofat[i].qtde == 0) || (campofat[i].valor == 0.0) || (strcmp(campofat[i].fornecedor, "0000")==0))
            continue;

        printf("%5i     %s %s %4i %10.2f %10.2f %12.2f   %s \n", campofat[i].codFat, campofat[i].codProd, campofat[i].produto, campofat[i].qtde, campofat[i].valor, campofat[i].frete, campofat[i].total, campofat[i].fornecedor);
    }
    fclose(arq);
}

int main()
{
    Leitura();
    Erro();    
    Exibir(campofat);   
}