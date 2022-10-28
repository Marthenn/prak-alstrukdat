#include <stdio.h>
#include <stdlib.h>
#include "listdinpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
    CAPACITY(*l)=capacity;
    BUFFER(*l)=(ElType*)malloc(capacity*sizeof(ElType));
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */

void dealocate(ListDin *l){
    CAPACITY(*l)=0;
    free(BUFFER(*l));
}
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l){
    int i;
    for(i=0;i<CAPACITY(l);i++){
        if(ELMT(l,i)==VAL_UNDEF)return i;
    }
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l){
    return length(l)-1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
    return (i<=0 && i<CAPACITY(l));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i){
    return (i<=0 && i<=getLastIdx(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..getLastIdx(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
    return length(l)==0;
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l){
    return length(l)==CAPACITY(l);
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
    int n,i,x;
    do{
        scanf("%d",&n);
    }while(n<0||n>CAPACITY(*l));
    for(i=0;i<n;i++){
        scanf("%d",&x);
        ELMT(*l,i)=x;
    }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void displayList(ListDin l){
    printf("[");
    
    int i;
    for(i=0;i<length(l);i++){
        printf("%d",ELMT(l,i));
        if(i!=getLastIdx(l))printf(",");
    }

    printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    int i;
    ListDin l3;
    CreateListDin(&l3,CAPACITY(l1));

    if(plus){
        for(i=0;i<length(l1);i++){
            ELMT(l3,i)=ELMT(l1,i)+ELMT(l2,i);
        }
    }
    else{
        for(i=0;i<length(l1);i++){
            ELMT(l3,i)=elmt(l1,i)+ELMT(l2,i);
        }
    }
    return l3;
}
/* Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
    if(length(l1)==length(l2)){
        int i;
        for(i=0;i<length(l1);i++){
            if(ELMT(l1,i)!=ELMT(l2,i))return false;
        }
        return true;
    }
    return false;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
    int i;
    for(i=0;i<length(l);i++)if(ELMT(l,i)==val)return i;
    return IDX_UNDEF;
}
/* Search apakah ada elemen list l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan VAL_UNDEF */
/* Menghasilkan nilai tak terdefinisi (VAL_UNDEF) jika list l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min){
    *min = ELMT(l,0);
    *max = ELMT(l,0);
    int i;
    for(i=0;i<length(l);i++){
        if(ELMT(l,i)>*max)*max=ELMT(l,i);
        if(ELMT(l,i)<*min)*min=ELMT(l,i);
    }
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
    CreateListDin(lOut,CAPACITY(lIn));
    int i;
    for(i=0;i<length(lIn);i++)ELMT(*lOut,i)=ELMT(lIn,i);
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
ElType sumList(ListDin l){
    int res=0;
    int i;for(i=0;i<length(l);i++){
        res+=ELMT(l,i);
    }
    return res;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val){
    int res=0;
    int i;
    for(i=0;i<length(l);i++){
        if(ELMT(l,i)==val)res++;
    }
    return res;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
boolean isAllEven(ListDin l){
    int i;
    for(i=0;i<length(l);i++){
        if(ELMT(l,i)%2)return false;
    }
    return true;
}
/* Menghailkan true jika semua elemen l genap. l boleh kosong */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
    int i,j,idx;
    ElType temp;
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val);
/* Proses: Menambahkan X sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num);
/* Proses : Menambahkan kapasitas sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num);
/* Proses : Mengurangi kapasitas sebanyak num */
/* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compactList(ListDin *l);
/* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran Capacity = nEff */