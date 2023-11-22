#include <stdio.h>
#include <stdlib.h>

struct fun {
    int id;
    char nome[50];
    char cargo[50];
};

struct cl {
    int id;
    char nome[50];
    char cidade[50];
};

struct prod {
    int id;
    char nome[50];
    float valor;
};

int main() {

    struct fun funcionarios[5][3];
    struct cl clientes[5][3];
    struct prod produtos[10][3];

    int lin = 0, col;
    int id_procurado, encontrado = 0;
    int qtd = 0;
    int op, x = 1;

    float subtot = 0, tot = 0;
    float valor, troco;

    for (col = 0; col < 3; col++) {
        for (lin = 0; lin < 5; lin++) {
            printf("Em relação ao funcionario [%i], preencha:\n", lin + 1);
            printf("1- Qual e o ID do funcionario? ");
            scanf("%d", &funcionarios[lin][col].id);

            printf("2- Qual e o nome do funcionario? ");
            scanf("%s", funcionarios[lin][col].nome);

            printf("3- Qual e o cargo do funcionario? ");
            scanf("%s", funcionarios[lin][col].cargo);

        }
        col = col + 3;
        system("cls");
    }

    for (col = 0; col < 3; col++) {
        for (lin = 0; lin < 5; lin++) {
            printf("Em relação ao cliente [%i], preencha:\n", lin + 1);
            printf("1- Qual e o ID do cliente? ");
            scanf("%d", &clientes[lin][col].id);

            printf("2- Qual e o nome do cliente? ");
            scanf("%s", clientes[lin][col].nome);

            printf("3- Qual e a cidade do cliente? ");
            scanf("%s", clientes[lin][col].cidade);

        }
        col = col + 3;
        system("cls");
    }

    for (col = 0; col < 3; col++) {
        for (lin = 0; lin < 10; lin++) {
            printf("Sobre o produto [%i], preencha:\n", lin + 1);
            printf("1- Qual e o ID do produto? ");
            scanf("%d", &produtos[lin][col].id);

            printf("2- Qual e o nome do produto? ");
            scanf("%s", produtos[lin][col].nome);

            printf("3- Qual e o valor do produto? ");
            scanf("%f", &produtos[lin][col].valor);

        }
        col = col + 3;
        system("cls");
    }

    while (x >= 1) {

        printf("Digite o ID do funcionario que realizou a venda: ");
        scanf("%d", &id_procurado);
        system("cls");

        for (col = 0; col < 3; col++) {
            for (lin = 0; lin < 5; lin++) {
                if (funcionarios[lin][col].id == id_procurado) {
                    printf("Funcionario encontrado:\n");
                    printf("\nID: %d\n", funcionarios[lin][col].id);
                    printf("Nome: %s\n", funcionarios[lin][col].nome);
                    printf("Cargo: %s\n", funcionarios[lin][col].cargo);
                    encontrado = 1;
                    break;
                }
            }
            if (encontrado) {
                break;
            } else {
                printf("Funcionario com ID %d nao encontrado.\n", id_procurado);
                return 0;
            }
        }

        printf("\nDigite o ID do cliente que fez a compra: ");
        scanf("%d", &id_procurado);
        system("cls");

        for (col = 0; col < 3; col++) {
            for (lin = 0; lin < 5; lin++) {
                if (clientes[lin][col].id == id_procurado) {
                    printf("Cliente encontrado:\n");
                    printf("\nID: %d\n", clientes[lin][col].id);
                    printf("Nome: %s\n", clientes[lin][col].nome);
                    printf("Cidade: %s\n", clientes[lin][col].cidade);
                    encontrado = 1;
                    break;
                }
            }
            if (encontrado) {
                break;
            } else {
                printf("Cliente com ID %d nao encontrado.\n", id_procurado);
                return 0;
            }
        }

        printf("\nInsira o ID correspondente ao produto comprado: ");
        scanf("%d", &id_procurado);
        system("cls");

        for (col = 0; col < 3; col++) {
            for (lin = 0; lin < 5; lin++) {
                if (produtos[lin][col].id == id_procurado) {
                    printf("Quanto de %s foi comprado? ", produtos[lin][col].nome);
                    scanf("%d", &qtd);
                    subtot = (produtos[lin][col].valor) * (qtd);
                    tot = tot + subtot;

                    printf("\nVendido O produto de ID %d:\n", produtos[lin][col].id);
                    printf("%s em quantidade %d, subtotal de R$ %.2f", produtos[lin][col].nome, qtd, subtot);

                    printf("\nqQual foi o segundo produto a ser comprado? ");
                    scanf("%d", &id_procurado);

                    for (col = 0; col < 3; col++) {
                        for (lin = 0; lin < 5; lin++) {
                            if (produtos[lin][col].id == id_procurado) {
                                printf("\nQuanto de %s foi comprado? ", produtos[lin][col].nome);
                                scanf("%d", &qtd);
                                subtot = (produtos[lin][col].valor) * (qtd);
                                tot = tot + subtot;

                                printf("\nVendido produto de ID %d:\n", produtos[lin][col].id);
                                printf("%s em quantidade %d, subtotal de R$ %.2f");

                                printf("\nQual foi o terceiro produto a ser comprado? ");
                                scanf("%d", &id_procurado);

                                for (col = 0; col < 3; col++) {
                                    for (lin = 0; lin < 5; lin++) {
                                        if (produtos[lin][col].id == id_procurado) {
                                            printf("\nQuanto de %s foi comprado? ", produtos[lin][col].nome);
                                            scanf("%d", &qtd);
                                            subtot = (produtos[lin][col].valor) * (qtd);
                                            tot = tot + subtot;

                                            printf("\nVendido produto de ID %d:\n", produtos[lin][col].id);
                                            printf("%s em quantidade %d, subtotal de R$ %.2f", produtos[lin][col].nome, qtd, subtot);

                                            col = col + 3;
                                            lin = lin + 5;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        system("pause");
        system("cls");
        printf("Valor total a pagar: R$ %.2f\n", tot);

        printf("\nOpcoes de pagamento:\n\n");
        printf("[1] Dinheiro\n");
        printf("[2] Cartao de credito\n");
        printf("[3] Cancelar\n");
        printf("\n\tDigite o numero correspondente a forma de pagamento escolhida: ");
        scanf("%i", &op);

        switch (op) {

        case 1:
            printf("\nInsira o valor a ser pago: ");
            scanf("%f", &valor);

            if (valor >= tot) {
                troco = valor - tot;

                printf("\nO seu troco e de R$ %.2f", troco);
            }

            if (valor < tot) {
                printf("\nValor insuficiente.");
                return 0;
            }

            break;

        case 2:
            printf("\nInsira o valor a ser pago: ");
            scanf("%f", &valor);

            if (valor == tot) {
                printf("\nCompra realizada!");
            }

            if (valor < tot) {
                printf("\nSaldo insuficiente.");
                return 0;
            }

            break;

        case 3:
            printf("\nCompra cancelada!");
            return 0;
            break;

        default:
            return 0;
        }
        printf("\nGostaria de realizar mais alguma compra? ");
        printf("\n[1] Sim\n");
        printf("\n[2] Nao\n\t");
        scanf("%i", &op);

        if (op == 1) {
            x++;
            system("cls");
        } else {
            break;
        }
    }
    getchar();
}

