#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
typedef struct node{
    char data[N];
    struct node *next;
    int quantity;
}node;
typedef struct LL{
    node *start;
}LL;
void addBook(LL *l,char name[],int q){
    node *newrec , *p;
    newrec= (node *) malloc(sizeof(node));
    strcpy(newrec->data,name);
    newrec->next=NULL;
    newrec->quantity=q;
    if (l->start==NULL){
        l->start=newrec;
    }
    else {
        p=l->start;
        while (p->next!=NULL){
            p=p->next;
        }
        p->next=newrec;
    }
    printf("Book added successfully!\n");
}
void deleteBook(LL *l,char name[]){
    node *p,*prev;
    p=l->start;
    prev=NULL;
    int flag=0;
    while (p!=NULL){
        if (strcmp(p->data,name)==0){
            flag=1;
            if (prev==NULL){
                l->start=p->next;
            }
            else {
                prev->next=p->next;
            }
            free(p);
            printf("Book deleted successfully!\n");
            break;
        }
        prev=p;
        p=p->next;
    }
    if (flag==0){
        printf("Invalid name book not found\n");
    }
}
void searchBook(LL *l,char name[]){
    node *p;
    p=l->start;
    int flag=0;
    while (p!=NULL){
        if (strcmp(p->data,name)==0){
            flag=1;
            printf("The book %s is available in %d quantity\n",name,p->quantity);
            break;
        }
        else {
            p=p->next;
        }
    }
    if (flag==0){
        printf("Book not found!\n");
    }
}
void display(LL *l){
    node *p;
    p=l->start;
    int i=1;
    if (l->start==NULL){
        printf("No books to display!\n");
    }
    else {
        printf("\t List of available books:\n");
        while (p!=NULL){
            printf("\t%d.Name: %s\n\t  Quantity: %d\n",i,p->data,p->quantity);
            p=p->next;
            i++;
        }
    }
}
int main(){
    LL l;
    l.start=NULL;
    int choice;
    char name[50];
    int quantity;
    while (1){
        printf("Choose any of the following operation: \n");
        printf("1. Add new book\n2. Delete book\n3. Search book\n4. Display all available books\n5. Exit\n");
        printf("Your choice: ");
        scanf("%d",&choice);
        fflush(stdin);
        if (choice==5){
            break;
        }
        switch (choice){
            case 1:
            printf("Enter the name of book to add: ");
            gets(name);
            printf("Enter the quantity of the book: ");
            scanf("%d",&quantity);
            fflush(stdin);
            addBook(&l,name,quantity);
            break;
            case 2:
            printf("Enter the name of the book to delete: ");
            gets(name);
            deleteBook(&l,name);
            break;
            case 3:
            printf("Enter the name of the book to search: ");
            gets(name);
            searchBook(&l,name);
            break;
            case 4:
            display(&l);
            break;
            default:
            printf("Invalid choice please try again!");
        }
    }
    printf("Thank you!");
}