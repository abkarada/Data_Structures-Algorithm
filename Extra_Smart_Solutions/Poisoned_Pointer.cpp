void silDugum(Dugum** dugum) {
    if (*dugum) {
        free(*dugum);
        *dugum = (Dugum*)0xDEADBEEF;  // Zehirli iþaretçi
    }
}

