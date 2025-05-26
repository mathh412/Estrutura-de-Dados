#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno *link;

struct Aluno {
    int matricula; // Número de matrícula do aluno
    float cr; // Coeficiente de Rendimento
};

typedef struct Aluno *Hash; // Hash é um vetor de ponteiros para structs do tipo Aluno

void inicializar(Hash *tab, int m) {
    for (int i = 0; i < m; i++) {
        tab[i] = NULL;
    }
}

int hash_linha(int mat, int m) {
    return mat % m; // Método da divisão
}

// Tentativa quadrática
int hash(int mat, int m, int k) {
    int c1 = 1;
    int c2 = 1;
    return (hash_linha(mat, m) + c1 * k + c2 * k * k) % m;
}

int buscar(Hash *tab, int m, int mat, int *achou) {
    *achou = 0;
    int endereco = -1;
    int posicao_livre = -1;
    int k = 0;

    while (k < m) {
        endereco = hash(mat, m, k);
        if (tab[endereco] != NULL && tab[endereco]->matricula == mat) {
            *achou = 1;
            break;
        } else {
            if (tab[endereco] == NULL && posicao_livre == -1) {
                posicao_livre = endereco;
            }
            k++;
        }
    }

    if (*achou)
        return endereco;
    else 
        return posicao_livre;
}

void inserir(Hash *tab, int m, int mat, float cr) {
    int achou;
    int endereco = buscar(tab, m, mat, &achou);
    if (!achou) {
        if (endereco != -1) {
            tab[endereco] = (link) malloc(sizeof(struct Aluno));
            tab[endereco]->matricula = mat;
            tab[endereco]->cr = cr;            
        } else {
            printf("A tabela está cheia. Ocorreu overflow. Inserção não realizada!\n");
        }
    } else {
        printf("Matrícula já existe. Inserção inválida!\n");
    }
}

void remover(Hash *tab, int m, int mat) {
    int achou;
    int endereco = buscar(tab, m, mat, &achou);
    if (achou) {
        free(tab[endereco]);
        tab[endereco] = NULL;
    } else {
        printf("Matrícula não encontrada - Remoção não realizada!\n");
    }
}

void imprimir(Hash *tab, int m) {
    for (int i = 0; i < m; i++) {
        if (tab[i] != NULL) {
            link p = tab[i];
            printf("tab[%d]:\tmat:%d\tcr:%.2f\n", i, p->matricula, p->cr);
        } else {
            printf("tab[%d]:\n", i);
        }
    }
}

int main(void) {
    int n, m;
    printf("Digite o valor de m (tamanho da tabela hash): ");
    scanf("%d", &m);
    printf("Digite o valor de n (quantidade de matrículas): ");
    scanf("%d", &n);

    Hash tab[m];
    inicializar(tab, m);
    imprimir(tab, m);

    int mat;
    float cr;
    for (int i = 0; i < n; i++) {
        printf("Digite a matrícula do aluno %d: ", i + 1);
        scanf("%d", &mat);
        printf("Digite o CR do aluno %d: ", i + 1);
        scanf("%f", &cr);
        inserir(tab, m, mat, cr);
        imprimir(tab, m);
    }

    char resposta;
    do {
        printf("Digite a matrícula que deseja procurar: ");
        scanf("%d", &mat);
        int achou;
        int endereco = buscar(tab, m, mat, &achou);
        if (achou == 0)
            printf("Matrícula não encontrada!\n");
        else {
            link p = tab[endereco];
            printf("Encontrou mat = %d , cr = %.1f\n", p->matricula, p->cr);
        }
        printf("Quer procurar outra matrícula? (s/n) ");
        scanf(" %c", &resposta);
    } while ((resposta != 'N') && (resposta != 'n'));

    imprimir(tab, m);

    do {
        printf("Digite a matrícula que deseja remover: ");
        scanf("%d", &mat);
        remover(tab, m, mat);
        imprimir(tab, m);
        printf("Quer remover outra matrícula? (s/n) ");
        scanf(" %c", &resposta);
    } while ((resposta != 'N') && (resposta != 'n'));

    return 0;
}
