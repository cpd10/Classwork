/*
    Darius Hooks
    Comp 222 at 9:30
    Assignment 4 - Virtual Memory
    November 30, 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int menu();
void set();
void map();
int isEmpty();
int isFull();
void add(int);
void replace(int);
void swap(int);


struct Page
{
    int page;   //PAGE NUMBER
    int frame;  //FRAME NUMBER
};

int memory_size;    //MAIN MEMORY SIZE
int page_size;      //SIZE OF PAGE
int policy;         //VALUE OF REPLACEMENT POLICY
int front, rear, length, MAX;   //VARIABLES TO IMPLEMENT A CIRCULAR QUEUE
int pf = 0;         //KEEPS FRAME COUNT

struct Page* table = NULL;  //INSTANCE OF PAGE TABLE TO BE DYNAMICALLY ALLOCATED



/*/================================================================================================\\
||=================================================================================================||
||                                                                                                 ||
||                                         MAIN FUNCTION                                           ||
||                                                                                                 ||
||=================================================================================================||
\\================================================================================================/*/

int main()
{
    //A MENU IS CONTINUOSLY DISPLAYED UNTIL USER QUITS
    int choice;
    do
    {
        switch(choice = menu())
        {
            case 1: set();
                    break;
            case 2: map();
                    break;
        }
    }while(choice != 3);
    if(table != NULL)
        free(table);
    return 0;
}


/*/================================================================================================\\
||=================================================================================================||
||                                                                                                 ||
||                                              MENU                                               ||
||                                                                                                 ||
||=================================================================================================||
\\================================================================================================/*/

int menu()
{
    //THE MENU DISPLAYED IN THE MAIN FUNCTION.
    //IF THE INPUT IS NOT 1, 2, OR 3 AN ERROR
    //MESSAGE IS DISPLAYED.
    int sel;
    printf("Darius Hooks\n");
    printf("\nVirtual Memory:");
    printf("\n---------------------------");
    printf("\n1) Set Parameters");
    printf("\n2) Map Virtual Address");
    printf("\n3) Quit");
    printf("\nEnter selection: ");
    scanf("%d", &sel);
    if(sel > 3 || sel < 1)
    {
        printf("\n\n***Invalid Entry!\n\n");
        return 0;
    }
    return sel;
}


/*/================================================================================================\\
||=================================================================================================||
||                                                                                                 ||
||                                              SET                                                ||
||                                                                                                 ||
||=================================================================================================||
\\================================================================================================/*/

void set()
{
    /*
      READS THE SIZES OF THE PHYSICAL MEMORY AND PAGE, THEN DYNAMICALLY ALLOCATES
      OR REALLOCATES THE SIZE OF THE PAGE TABLE BASED ON THE INPUTS READ, AND READS
      AN INTEGER THAT REPRESENTS THE DESIRED REPLACEMENT POLICY. ALSO THE VARIABLES
      OF THE QUEUE AS WELL AS THE VARIABLES OF THE PAGE TABLE ARE SET TO DEFAULT VALUES.
    */
    int i;
    printf("\n\nEnter physical memory size(in words): ");
    scanf("%d", &memory_size);
    printf("\nEnter page size(words/page): ");
    scanf("%d", &page_size);
    MAX = memory_size / page_size;  //NUMBER OF FRAMES
    front = - 1;
    rear = - 1;
    length = 0;         //LEGNTH OF QUEUE

    if(table == NULL)
        table = (struct Page*)malloc((memory_size/page_size) * sizeof(struct Page));
    else
        table = (struct Page*)realloc(table, (memory_size/page_size) * sizeof(struct Page));

    for(i = 0; i < memory_size/page_size; i++)
    {
        table[i].page = -1;
        table[i].frame = -1;
    }

    printf("\nEnter replacement policy (LRU = 0, FIFO = 1): ");
    scanf("%d", &policy);
    printf("\n\n");
}

/*/================================================================================================\\
||=================================================================================================||
||                                                                                                 ||
||                                              MAP                                                ||
||                                                                                                 ||
||=================================================================================================||
\\================================================================================================/*/

void map()
{
    /*
      A VIRTUAL ADDRESS IS READ AND CONVERTED TO ITS VIRTUAL PAGE.
      IF THE QUEUE IS EMPTY, WHICH IT WILL INTIALLY WILL BE, A PAGE
      FAULT IS PRINTED AND THE PAGE IS ADDED TO THE QUEUE. OTHERWISE
      THE QUEUE IS SEARCHED FOR THE REFERENCED VIRTUAL PAGE.
      IF IT'S THERE THEN THE PHYSICAL ADDRESS IS CALCULATED AND
      PRINTED. THEN, DEPENDING ON THE REPLACEMENT POLICY CHOSEN, THE
      QUEUE IS UPDATED ACCORDINGLY.
    */
    int i, curr = 0, start = 0, va, vp, pa;

    printf("\n\nEnter virtual memory address to access: ");
    scanf("%d", &va);
    vp = va / page_size;

    if(isEmpty())
    {
        printf("\n\n***Page Fault!");
        add(vp);    //ADDS TO THE QUEUE
    }

    else
    {
        if(table[curr].page == vp)
        {
            pa = ((table[curr].frame * page_size) + (va - (vp * page_size)));
            printf("\n\n***Virtual address %d maps to physical address %d\n", va, pa);
            if(policy == 0)     //IF LRU IS SELECTED THE PAGE IS
                swap(curr);     //MOVED TO THE BACK OF THE QUEUE
        }

        else
        {
            while(table[curr].page != vp)
            {
                curr = (curr + 1) % MAX;    //SEARCHES THROUGH THE PAGE TABLE
                if(curr == start)           //IF THERE'S A FULL LAP IT'S A PAGE FAULT
                {
                    printf("\n\n***Page Fault!");
                    add(vp);
                    break;
                }
                if(table[curr].page == vp)  //IF THE VIRTUAL PAGE IS FOUND THE PHYSICAL ADDRESS IS CALCULATED
                {
                    pa = ((table[curr].frame * memory_size) + (va - (vp * memory_size)));
                    printf("\n\n***Virtual address %d maps to physical address %d", va, pa);
                    if(policy == 0)
                        swap(curr);
                    break;
                }
            }
        }
    }

    for(i = 0; i < MAX; i++)
        if(table[i].page != -1)
            printf("\n***VP%d --> PF%d", table[i].page, table[i].frame);
    printf("\n\n");
}

/*/================================================================================================\\
||=================================================================================================||
||                                                                                                 ||
||                                              ADD                                                ||
||                                                                                                 ||
||=================================================================================================||
\\================================================================================================/*/

void add(int vp)
{
    /*
      TAKES THE VIRTUAL PAGE REFERENCED AS A PARAMETER
      AND ADDS THE PAGE AND FRAME TO THE QUEUE.
      WHEN THE QUEUE IS FULL THE DESIRED REPLACEMENT POLICY
      TAKES PLACE.
    */
    if(isFull())
        replace(vp);
    else
    {
        length++;   //LENGTH OF QUEUE
        rear = (rear + 1) % MAX;    //CIRCULATES FROM 0 TO NUMBER OF FRAMES
        table[rear].page = vp;
        table[rear].frame = pf;
        pf = (pf + 1) % MAX;    //KEEPS TRACK FRAMES (CIRCULATES FROM 0 TO NUMBER OF FRAMES)
    }
}


/*/================================================================================================\\
||=================================================================================================||
||                                                                                                 ||
||                                              REPLACE                                            ||
||                                                                                                 ||
||=================================================================================================||
\\================================================================================================/*/

void replace(int vp)
{
    /*
      THE FIRST ELEMENT OF THE PAGE TABLE IS REPLACED
      WITH THE NEWLY REFERENCED PAGE.
    */
    table[0].page = vp;
    swap(0);
}

void swap(int cur)
{
    /*
      THE INDEX OF THE CURRENT PAGE REFERENCED IS PASSED DOWN
      AND IT'S MOVED TO THE BACK OF THE QUEUE. EVERYTHING
      ELSE IS MOVED UP.
    */
    int i;
    struct Page temp;
    for(i = cur; i < length; i++)
    {
        temp = table[cur];
        table[cur] = table[i];
        table[i] = temp;
    }
}


/*/================================================================================================\\
||=================================================================================================||
||                                                                                                 ||
||                                            IS FULL                                              ||
||                                                                                                 ||
||=================================================================================================||
\\================================================================================================/*/

int isFull()
{
    /*
      RETURNS TRUE IF THE QUEUE IS FULL
    */
    if(rear == MAX - 1)
        return 1;
    return 0;
}

/*/================================================================================================\\
||=================================================================================================||
||                                                                                                 ||
||                                           IS EMPTY                                              ||
||                                                                                                 ||
||=================================================================================================||
\\================================================================================================/*/

int isEmpty()
{
    /*
      RETURNS TRUE IF THE QUEUE IS EMPTY
    */
    if(front == rear)
        return 1;
    return 0;
}

