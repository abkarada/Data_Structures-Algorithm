#include <stdlib.h>
#include <stdio.h>

#define MAX_NODES 1000
typedef struct Dugum {
    int veri;
    struct Dugum* sol;
    struct Dugum* sag;
} Dugum;

Dugum havuz[MAX_NODES];
int kullanilan = 0;

Dugum* yeniDugumHavuz(int veri) {
    if (kullanilan >= MAX_NODES) {
        printf("Havuz dolu!\n");
        return NULL;
    }
    Dugum* dugum = &havuz[kullanilan++];
    dugum->veri = veri;
    dugum->sol = dugum->sag = NULL;
    return dugum;
}

