#include <stdio.h>
#include <string.h>

typedef struct Book
{
    int id;
    int price;
    char title[100];
}book_t;

void total_price(book_t bk[], int n)
{
    int total=0;
    for(int i=0; i<n; i++)
        total += bk[i].price;
    printf("Total_price: %d\n\n", total);
}

void list_book(book_t bk[], int n)
{
    printf("Id\tPrice\tTitle\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%s\n", bk[i].id, bk[i].price, bk[i].title);
    }
}

int main()
{
    book_t bk[10];

    bk[0].id = 1;
    bk[1].id = 2;
    bk[2].id = 3;
    bk[3].id = 4;
    bk[4].id = 5;
    bk[5].id = 6;

    bk[0].price = 1000;
    bk[1].price = 300;
    bk[2].price = 1000;
    bk[3].price = 550;
    bk[4].price = 870;
    bk[5].price = 1344;

    strcpy(bk[0].title, "All the Light We Cannot See");
    strcpy(bk[1].title, "The 38 Letters from J.D. Rockefeller to his son");
    strcpy(bk[2].title, "The Ballad of Songbirds and Snakes");
    strcpy(bk[3].title, "Killers of the Flower Moon");
    strcpy(bk[4].title, "Elon Musk");
    strcpy(bk[5].title, "Milk and Honey 12-Month 2024");

    total_price(bk, 6);
    list_book(bk, 6);
    return 0;
}
