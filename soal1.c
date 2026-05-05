/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4
 *   Hari dan Tanggal    : Selasa, 5 Mei 2025
 *   Nama (NIM)          : Kenneth Harrison Siswanto (13224032)
 *   Nama File           : Modul4.c
 *   Deskripsi           : Melihat apakah segel balance atau tidak. 
 *   Reference           : https://www.geeksforgeeks.org/dsa/c-program-to-check-for-balanced-brackets-in-an-expression-well-formedness-using-stack/ 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char data;
    struct Stack* next;
} Stack;

Stack* top = NULL;

// fungsi push stack
void push(char newdata){
    Stack* new = (Stack*)malloc(sizeof(Stack));

    if (new == NULL) {
        printf("Stack overflow n");
        getchar();
        exit(0);
    }

    new->data = newdata;
    new->next = top;
    top = new;
}


// fungsi pop stack
char pop() {
    if (top == NULL) {
        return '\0';
    }

    Stack* hapus = top;
    char x = hapus->data;
    top = top->next;
    free(hapus);
    return x;
}

// cek antara dua karakter apakah saling menutup
int isMatch(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

// cek atas tanpa pop
char cekAtas(){
    if (top == NULL) return '\0';
    return top->data;
}

int cekSegel(char exp[]){
    int i = 0;
    int valid = 1;

    // kalau kurung buka
    while(exp[i]){
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(exp[i]);
        }

        // kalau kurung tutup
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (top == NULL || !isMatch(cekAtas(exp[i]), exp[i])) {
                valid = 0;
                break;
            }
            pop();
        }
    i++;    
    }

    // kalau masih ada sisa kurung buka
    if (top != NULL) {
        valid = 0;
    }

    if (valid){
        printf("VALID\n");
    } else {
        printf("INVALID\n");
    }
    return 0;
}

int main(){
    char str[1000];
    fgets(str, sizeof(str), stdin); // ambil input
    str[strcspn(str, "\n")] = '\0';


    // cek input
    // for (int i = 0; i < strlen(str); i++) {
    //     char c = str[i];
    // }
    // printf("%s", str);

    // cek segel
    cekSegel(str);
    return 0;
}
