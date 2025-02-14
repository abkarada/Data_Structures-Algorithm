#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void* veri;            
    int referansSayisi;    
} AkilliIsaretci;

AkilliIsaretci* yeniAkilliIsaretci(size_t boyut) {
    AkilliIsaretci* ptr = (AkilliIsaretci*)malloc(sizeof(AkilliIsaretci));
    ptr->veri = malloc(boyut);
    ptr->referansSayisi = 1; 
    return ptr;
}

void referansArttir(AkilliIsaretci* ptr) {
    if (ptr) {
        ptr->referansSayisi++;
    }
}

void referansAzalt(AkilliIsaretci* ptr) {
    if (ptr) {
        ptr->referansSayisi--;
        if (ptr->referansSayisi == 0) {
            free(ptr->veri); 
            free(ptr);      
        }
    }
}

int main() {
	
    AkilliIsaretci* p = yeniAkilliIsaretci(sizeof(int));

    *(int*)p->veri = 42;
    printf("Veri: %d\n", *(int*)p->veri);

    referansArttir(p);

    referansAzalt(p);
    referansAzalt(p); 

    return 0;
}

