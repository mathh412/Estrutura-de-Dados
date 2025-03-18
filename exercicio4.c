/*
implemente, em linguagem C, funções recursivas para imprimir uma
lista ligada, sem e com cabeça.
*/

//sem cabeça

void imprimirRecursivo(struct node *lista) {
    struct node *p = lista; 
    if(p==NULL)
    return;
        if (p->next != NULL)
            printf("%d -> ", p->item); 
        else
            printf("%d", p->item);
        imprimirRecursivo(p->next); 
    }

// com cabeça


void imprimirRecursivo(link lista) {
    link p = lista->next; 
    if(p==NULL) return;
        if (p->next != NULL)
            printf("%d -> ", p->item); 
        else
            printf("%d", p->item);
        imprimirRecursivo(p); 
    }
