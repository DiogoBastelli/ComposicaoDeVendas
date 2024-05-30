#include <stdio.h>

int main() {
    int quantidade, i, a, codigoRepetido, codigoInserido;
    
    printf("Insira a quantidade de produtos: ");
    scanf("%d", &quantidade);
    int codigo[quantidade] , qntd_produto[quantidade]; 
    float valor_por_unidade[quantidade];
    char nome[quantidade][60];

    for(i = 0; i < quantidade; i++) {
            printf("Insira o nome do produto %d:\n", i + 1);
            scanf("%s", &nome[i]);

            printf("Insira o valor unitario do produto %d:\n", i + 1);
            scanf("%f", &valor_por_unidade[i]);

            printf("Insira a quantidade deste produto %d:\n", i + 1);
            scanf("%d", &qntd_produto[i]);

        do {
        codigoRepetido = 0; // Resetar a flag de código repetido
            printf("Insira o codigo do produto %d:\n", i + 1);
            scanf("%d", &codigoInserido);

            // Verificar se o código já foi inserido
            for(a = 0; a < i; a++) {
                if(codigo[a] == codigoInserido) {
                    codigoRepetido = 1; // Código repetido encontrado
                    printf("Codigo repetido! Por favor, insira um codigo diferente.\n");
                    break;
                }
            }
        } while(codigoRepetido == 1); // Repetir enquanto encontrar código repetido
        
        codigo[i] = codigoInserido; // Adicionar o código ao array
    }

    printf("Nome     Codigo     Valor     quantidade     Total\n");
    for(i = 0; i < quantidade; i++) {
        float total = valor_por_unidade[i] * qntd_produto[i];
        printf("%s     %d          %.2f          %d            %.2f\n", nome[i] ,  codigo[i] , valor_por_unidade[i] , qntd_produto[i] , total );
    }
    return 0;
}
