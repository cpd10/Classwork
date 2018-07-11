#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int menu();
void set();
void read();
void write();
int IsPower(int);   //Checks for power of 2
struct Cache_Memory
{
    int tag;
    int* block;
};

struct Memory
{
    int tag;
    int word;
    int block;
};

int mem_size, cache_size, blk_size;
struct Cache_Memory* _cache;
struct Memory* main_memory;

int main()
{
    int choice, i;

    do
    {
        switch(choice = menu())
        {
            case 1: set();
                    break;
            case 2: read();
                    break;
            case 3: write();
                    break;
        }
    }while(choice != 4);

    //Freeing all the allocated memory
    free(main_memory);
    for(i = 0; i < (cache_size/blk_size); i++)
        free(_cache[i].block);
    free(_cache);


    return 0;
}

int menu()
{
    int sel;
    printf("\nDarius Hooks\n");
    printf("\nMain memory to Cache memory mapping:\n");
    printf("------------------------------------\n");
    printf("1) Set parameters\n");
    printf("2) Read cache\n");
    printf("3) Write to cache\n");
    printf("4) Exit\n");
    printf("\nEnter selection: ");
    scanf("%d", &sel);
    return sel;
}

void set()
{
    int i;
    printf("\nEnter main memory size (words): ");
    scanf("%d", &mem_size);
    if(!IsPower(mem_size))
    {
        printf("**Error: Main memory size not a power of 2!\n");
        return;
    }
    printf("\nEnter cache size (words): ");
    scanf("%d", &cache_size);
    if(!IsPower(cache_size))
    {
        printf("**Error: Cache size not a power of 2!\n");
        return;
    }
    printf("\nEnter block size (words/block): ");
    scanf("%d", &blk_size);
    if(!IsPower(blk_size))
    {
        printf("**Error: Block size not a power of 2!\n");
        return;
    }
    else if(cache_size < blk_size)
    {
        printf("**Error: Block size larger than cache size!\n");
        return;
    }
    else if(cache_size % blk_size != 0)
    {
        printf("**Error: Cache size not a multiple of block size\n");
    }

    printf("\n");

    main_memory = (struct Memory*)malloc(mem_size * sizeof(struct Memory));
    for (i = 0; i < mem_size; i++)
    {
        main_memory[i].tag = i / pow(2,(log2(cache_size/blk_size) + log2(blk_size)));
        main_memory[i].word = mem_size - i;
        main_memory[i].block = i / blk_size;
    }

    _cache = (struct Cache_Memory*)malloc((cache_size/blk_size) * sizeof(struct Cache_Memory));
    for (i = 0; i < (cache_size/blk_size); i++)
    {
        _cache[i].tag = -1;
        _cache[i].block = NULL;
    }
}

int IsPower(int num)
{
    if((float)log2(num) == (int)log2(num))
        return 1;
    return 0;
}

void read()
{
    int mem_address, i, line, main_blk, j = 0;
    printf("\nEnter memory address to read from: ");
    scanf("%d", &mem_address);

    line = (mem_address / blk_size) % (cache_size/blk_size); //Cache line index
    main_blk = mem_address / blk_size;  //Main memory block index

    if(_cache[line].block == NULL)
        _cache[line].block = (int*)malloc(blk_size * sizeof(int));

    if(_cache[line].tag == main_memory[mem_address].tag)
        printf("\n**Word %d of block %d with tag %d contains value %d\n\n", (mem_address % blk_size), line, (int)(mem_address / pow(2,(log2(cache_size/blk_size) + log2(blk_size)))), main_memory[mem_address].word);

    else if(_cache[line].tag != main_memory[mem_address].tag)
    {
        printf("\n**Read Miss!");
        printf("\n**Word %d of block %d with tag %d contains value %d\n\n", (mem_address % blk_size), line, (int)(mem_address / pow(2,(log2(cache_size/blk_size) + log2(blk_size)))), main_memory[mem_address].word);
        _cache[line].tag = main_memory[mem_address].tag;
        for(i = 0; i < mem_size; i++)
            if((main_memory[i].tag == _cache[line].tag) && (main_memory[i].block == main_blk))
            {
                _cache[line].block[j] = main_memory[i].word;
                j++;
            }
    }
}

void write()
{
    int mem_address, i, line, value, main_blk, j = 0;
    printf("\nEnter memory address to write to: ");
    scanf("%d", &mem_address);
    printf("Enter value to write: ");
    scanf("%d", &value);

    line = (mem_address / blk_size) % (cache_size/blk_size); //Cache line index
    main_blk = mem_address / blk_size;  //Main memory block index

    if(_cache[line].block == NULL)
        _cache[line].block = (int*)malloc(blk_size * sizeof(int));

    if(_cache[line].tag == main_memory[mem_address].tag)
    {
        main_memory[mem_address].tag = _cache[line].tag;
        main_memory[mem_address].word = value;
        printf("\n**Word %d of block %d with tag %d contains value %d\n\n", (mem_address % blk_size), line, (int)(mem_address / pow(2,(log2(cache_size/blk_size) + log2(blk_size)))), main_memory[mem_address].word);
    }

    else if(_cache[line].tag != main_memory[mem_address].tag)
    {
        printf("\n**Write Miss!");
        _cache[line].tag = main_memory[mem_address].tag;
        main_memory[mem_address].word = value;
        printf("\n**Word %d of block %d with tag %d contains value %d\n\n", (mem_address % blk_size), line, (int)(mem_address / pow(2,(log2(cache_size/blk_size) + log2(blk_size)))), main_memory[mem_address].word);
        for(i = 0; i < mem_size; i++)
            if((main_memory[i].tag == _cache[line].tag) && (main_memory[i].block == main_blk))
            {
                _cache[line].block[j] = main_memory[i].word;
                j++;
            }
    }
}

