#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum* sol;
    struct Dugum* sag;
};

Dugum* yeniDugum(int veri) {
    Dugum* dugum = (Dugum*)malloc(sizeof(Dugum));
    dugum->veri = veri;
    dugum->sol = dugum->sag = NULL;
    return dugum;
}

int duzeyGetir(int aranan, Dugum* root) {
    if (root == NULL)
        return -1;

    if (root->veri == aranan)
        return 0;

    
    int solDuzey = duzeyGetir(aranan, root->sol);
    if (solDuzey != -1)
        return solDuzey + 1; 

    int sagDuzey = duzeyGetir(aranan, root->sag);
    if (sagDuzey != -1)
        return sagDuzey + 1; 

    return -1;
}

int main() {
    Dugum* root = yeniDugum(1);
    root->sol = yeniDugum(2);
    root->sag = yeniDugum(3);
    root->sol->sol = yeniDugum(4);
    root->sol->sag = yeniDugum(5);
    root->sag->sol = yeniDugum(6);
    root->sag->sag = yeniDugum(7);
    int aranan = 3;
    printf("Agacta aranan deger: %d \nAranan degerin seviyesi:%d",aranan,duzeyGetir(aranan, root));

    return 0;
}
