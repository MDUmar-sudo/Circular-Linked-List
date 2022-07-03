#include <stdio.h>
#include <stdlib.h>
#define rep(y,x) for(int i=y;i<x;i++)


typedef struct Node cll;
struct Node{
    int data;
    struct Node *next;
};

cll*tail=NULL;


//Creating initial LinkedList

void createNode(){
    cll *temp,*ptr;

    temp = (cll *)malloc(sizeof(cll));
    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }

    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(tail==NULL){
        tail=temp;
        temp->next=tail;
    }
    else{   ptr=tail->next;
            while(ptr->next!=tail->next){
                ptr=ptr->next;
            }
        temp->next=ptr->next;
        ptr->next=temp;
        tail=temp;


    }
}

//Displaying the LinkedList

void display(){
    cll *ptr;
    int node_no=1;
    if(tail==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else{
        ptr = tail->next;
        printf("\n");
        rep(0,30) printf("-");
        printf("\nDISPLAYING THE LINKED LIST\n");
        rep(0,30) printf("-");
        printf("\n[  ");
        do{
        printf("(Data:%d||Node:%d)-->",ptr->data,node_no++);
        ptr = ptr->next;
        }while(ptr!=tail->next);
        printf("HEAD ]\n");
    }

}

/*
Insertion functions starts
*/

//Insertion at the beginning of the linked list
void insertAtBegin(){
    cll *temp;
    temp = (cll *)malloc(sizeof(cll));
    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }
    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(tail==NULL){
        tail=temp;
        temp->next=tail;
    }
    else{
        temp->next=tail->next;
        tail->next=temp;
    }
}

//Insertion at the end of the linked list
void insertAtEnd(){

    cll *temp,*ptr;
    temp = (cll *)malloc(sizeof(cll));
    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }

    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->next=NULL;

    if(tail==NULL){
        tail=temp;
        tail->next=tail;
    }
    else{
        ptr=tail->next;
        while(ptr->next!=tail->next){
        ptr=ptr->next;
        }
    temp->next=ptr->next;
    ptr->next=temp;
    tail=temp;
    }

}

//Insertion at a given position in the linked list
void insertAtPosition(){
    cll *temp,*ptr;
    temp = (cll *)malloc(sizeof(cll));
    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }

    if(tail==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    ptr=tail->next;
    int pos;
    printf("\nENTER POSITION FOR NODE INSERTION: ");
    scanf("%d",&pos);

    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(pos==1){
        temp->next=tail->next;
        tail->next=temp;
    }
    else{
        int i=1;
        while(i!=pos-1){
            if(ptr==tail){
              printf("\nPOSITION NOT FOUND!!\n");
              return;
            }
            ptr=ptr->next;
            i++;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }

}

//Insertion after a specified node in the linked list
void insertAfterNode(){
    cll *temp,*ptr;
    temp = (cll *)malloc(sizeof(cll));
    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }

    if(tail==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else{
        int nd;
        printf("\nENTER NODE VALUE FOR NODE INSERTION: ");
        scanf("%d",&nd);

        printf("\nENTER NODE DATA: ");
        scanf("%d",&temp->data);
        temp->next=NULL;

        ptr=tail->next;
        while(ptr->data!=nd){
            if(ptr->next==tail->next){
              printf("\nNODE NOT FOUND!!\n");
              return;
            }
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}

/*
Insertion functions ends
*/


/*
Deletion functions starts
*/

//Deletion of node at the beginning of the linked list
void deleteAtFirst(){
    cll *ptr;
    if(tail==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else if(tail->next==tail){
        ptr=tail;
        tail=NULL;
        free(ptr);
        printf("DELETION COMPLETE");
    }
    else{
        ptr=tail->next;
        tail->next=ptr->next;
        free(ptr);
        printf("DELETION COMPLETE");
    }
}

//Deletion of node at the end of the linked list
void deleteAtLast(){
    cll *prev,*ptr;
    if(tail==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else if(tail->next==tail){
        ptr=tail;
        tail=NULL;
        printf("DELETION COMPLETE");
        free(ptr);

    }

    else{
        ptr=tail->next;
        while(ptr->next!=tail->next){
            prev=ptr;
            ptr=ptr->next;

        }
        prev->next=ptr->next;
        tail=prev;
        free(ptr);
        printf("DELETION COMPLETE");
    }
}

//Deletion of node at a given position in the linked list
void deleteAtPosition(){
    cll *prev,*ptr;
    if(tail==NULL){
        printf(" \nLINKED LIST IS EMPTY");
        return;
    }


    else{
            int pos;
            printf("\nENTER POSITION FOR NODE TO DELETE : ");
            scanf("%d",&pos);

            if(pos==1){
                if(tail->next==tail){
                    ptr=tail;
                    tail=NULL;
                    printf("DELETION COMPLTETE");
                    free(ptr);
                }
                else{
                    ptr=tail->next;
                    tail->next=ptr->next;
                    free(ptr);
                    printf("DELETION COMPLTETE");
                }

            }

            else{
            ptr=tail->next;
            int i=1;
            while(i<pos){

                if(ptr->next==tail->next){
                  printf("\nPOSITION NOT FOUND!!\n");
                  return;
                }
                prev=ptr;
                ptr=ptr->next;
                i++;
            }
            if(prev->next==tail){
                 prev->next=ptr->next;
                 tail=prev;
                 free(ptr);
                 printf("DELETION COMPLTETE");
                }
            else{
                prev->next=ptr->next;
                free(ptr);
                printf("DELETION COMPLTETE");
            }

        }
    }


}

//Deletion of a specified node in the linked list
void deleteSpecifiedNode(){

    cll *prev,*ptr;
    if(tail==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }

    else{
        ptr=tail->next;
        int nd;
        printf("\nENTER NODE VALUE FOR NODE DELETION: ");
        scanf("%d",&nd);
        if(ptr->data==nd){
            if(tail->next==tail){
                ptr=tail;
                tail=NULL;
                free(ptr);
                printf("DELETION COMPLTETE");
            }
            else{
                ptr=tail->next;
                tail->next=ptr->next;
                free(ptr);
                printf("DELETION COMPLTETE");
            }

        }
            else{
                while(ptr->data!=nd){
                if(ptr->next==tail->next){
                  printf("\nNODE NOT FOUND!!\n");
                  return;
                }
                prev=ptr;
                ptr=ptr->next;
            }
            if(prev->next==tail){
              prev->next=ptr->next;
              tail=prev;
              free(ptr);
              printf("DELETION COMPLTETE");
            }
            else{
                prev->next=ptr->next;
                free(ptr);
                printf("DELETION COMPLTETE");
            }

            }

    }
}

/*
Deletion functions ends
*/



int main()
{
    int choice;
    rep(0,10) printf("*");
            printf("WELCOME TO CIRCULAR LINKED LIST");
            rep(0,10) printf("*");
            printf("\n");
    while(1){

            rep(0,30) printf("=");
            printf("\n<-<-<-MAIN MENU->->->\n(1)CREATE\n(2)INSERT\n(3)DELETE\n(4)DISPLAY\n(5)EXIT\n");
            rep(0,30) printf("-");
            printf("\nENTER YOUR CHOICE: ");
            scanf("%d",&choice);
            printf("\n");
            rep(0,30) printf("-");
            printf("\n");

            switch(choice){
                case 1: {   int num;
                            printf("\nENTER NUMBER OF NODES IN THE STARTING LINKED LIST: ");
                            scanf("%d",&num);
                            while(num!=0){
                                createNode();
                                num--;
                            }
                            break;
                        }

                case 2: {
                            int ch1;
                            rep(0,30) printf(">");
                            printf("\n<-<-<-INSERTION MENU->->->\n(1)INSERT AT THE BEGINNING\n(2)INSERT AT THE END\n(3)INSERT NODE AT POSITION\n(4)INSERT AFTER A SPECIFIED NODE\n");
                            rep(0,30) printf(">");
                            printf("\nENTER YOUR CHOICE: ");
                            scanf("%d",&ch1);
                            switch(ch1){
                                case 1: insertAtBegin();
                                        break;

                                case 2:
                                        insertAtEnd();
                                        break;

                                case 3: insertAtPosition();
                                        break;

                                case 4: insertAfterNode();
                                        break;

                                default: exit(0);
                            }
                            break;

                        }


                case 3: {
                            int ch2;
                            printf("\n");
                            rep(0,30) printf("<");
                            printf("\n<-<-<-DELETION MENU->->->\n(1)DELETE THE FIRST NODE\n(2)DELETE THE LAST NODE\n(3)DELETE NODE AT POSITION\n(4)DELETE A NODE OF SPECIFIED VALUE\n");
                            rep(0,30) printf("<");
                            printf("\nENTER YOUR CHOICE: ");
                            scanf("%d",&ch2);
                            switch(ch2){
                                case 1: deleteAtFirst();
                                        break;

                                case 2: deleteAtLast();
                                        break;

                                case 3: deleteAtPosition();
                                        break;

                                case 4: deleteSpecifiedNode();
                                        break;

                                default: exit(0);
                            }
                            break;

                        }

                case 4: display();
                        break;

                case 5: exit(0);
                        break;
                default: printf("WRONG OPTION SELCTED!!TRY AGAIN\n");

            }
            printf("\n");
            rep(0,30) printf("=");
            printf("\n\n\n");

    }
    getch();
    return 0;

}
