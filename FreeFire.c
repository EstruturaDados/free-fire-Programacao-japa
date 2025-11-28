#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

/*
    Estrutura que representa um item da mochila.
    Contém nome, tipo (ex: comida, ferramenta, arma)
    e quantidade disponível.
*/
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

int main() {

    struct Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n=== MENU - MOCHILA DE SOBREVIVENCIA ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: // Adicionar item
                if (totalItens >= MAX_ITENS) {
                    printf("A mochila esta cheia! Nao eh possivel adicionar mais itens.\n");
                } else {
                    printf("\n--- Adicionando Item ---\n");
                    printf("Nome do item: ");
                    scanf("%s", mochila[totalItens].nome);

                    printf("Tipo do item (comida, ferramenta, etc): ");
                    scanf("%s", mochila[totalItens].tipo);

                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);

                    totalItens++;
                    printf("Item adicionado com sucesso!\n");
                }
                break;

            case 2: ; // Remover item
                if (totalItens == 0) {
                    printf("A mochila esta vazia! Nada para remover.\n");
                } else {
                    char nomeRemover[30];
                    int encontrado = 0;

                    printf("Digite o nome do item a remover: ");
                    scanf("%s", nomeRemover);

                    for (int i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                            // Substitui pelo último item
                            mochila[i] = mochila[totalItens - 1];
                            totalItens--;
                            encontrado = 1;
                            printf("Item removido com sucesso!\n");
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("Item nao encontrado na mochila.\n");
                    }
                }
                break;

            case 3: // Listar itens
                if (totalItens == 0) {
                    printf("A mochila esta vazia!\n");
                } else {
                    printf("\n=== ITENS NA MOCHILA ===\n");
                    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("-------------------------------------------------\n");

                    for (int i = 0; i < totalItens; i++) {
                        printf("%-20s %-15s %-10d\n",
                                mochila[i].nome,
                                mochila[i].tipo,
                                mochila[i].quantidade);
                    }
                }
                break;

            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}