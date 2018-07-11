/*
    Darius Hooks
    Comp 222 at 9:30AM
    Assignment 3 - Hamming Code Error Detection and Correction
    November 10, 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int menu();
void set();
void check();
int isPower(int);
void convert(int, int, char*);

int max;    //HOLDS MAX LENGTH OF CODE
int parity; //HOLDS PARITY OF CODE
char* Code = NULL; //HOLDS CODE

struct Hamming
{
    int num;    //HOLDS VALUE OF BIT
    int bitPosition;    //HOLDS POSITION OF BIT
    char* binary;   //HOLD BINARY NUMBER OF BIT POSITION
};

/*/================================================================================================\\
||=================================================================================================||
||                                                                                                 ||
||                                         MAIN FUNCTION                                           ||
||                                                                                                 ||
||=================================================================================================||
\\================================================================================================/*/
int main()
{
    int choice;
    do
    {
        switch(choice = menu())
        {
            case 1: set();
                    break;
            case 2: check();
                    break;
        }
    }while(choice != 3);

    if(Code != NULL)
        free(Code);

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
    int sel;
    printf("Darius Hooks\n");
    printf("\nError detection/correction:");
    printf("\n---------------------------");
    printf("\n1) Enter parameters");
    printf("\n2) Check hamming code");
    printf("\n3) Quit");
    printf("\nEnter selection: ");
    scanf("%d", &sel);
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
    printf("\n\nEnter the maximum length: ");
    scanf("%d", &max);
    if(Code == NULL)
    {
        Code = (char*)malloc((max + 1) * sizeof(char)); //SIZE OF MAX + 1 TO ACCOUNT FOR THE NULL CHARACTER
        printf("\n\nAllocating Memory\n\n");
    }
    else if(Code != NULL)
    {
        Code = (char*)realloc(Code, (max + 1) * sizeof(char));
        printf("\n\nReallocating Memory\n\n");
    }
    printf("\nEnter the parity (0 = even, 1 = odd): ");
    scanf("%d", &parity);
    printf("\n\n");
}

/*/================================================================================================\\
||=================================================================================================||
||                                                                                                 ||
||                                          CHECK                                                  ||
||                                                                                                 ||
||=================================================================================================||
\\================================================================================================/*/
void check()
{

    printf("\n\nEnter the hamming code: ");
    scanf("%s", Code);
    if(strlen(Code) > max)
    {
        printf("\n\n***Invalid Entry: Exceeds maximum code length of %d\n\n\n", max);
        return;
    }
    else if(isPower(strlen(Code)))
    {
        printf("\n\n***Invalid Entry: Code length is a power of 2\n\n\n");
        return;
    }
    int codeSize = strlen(Code);
    int cBitCount = ceil(log2(codeSize));   //DETERMINES AMOUNT OF CHECK BITS
    int dBitCount = codeSize - cBitCount;   //DETERMINES AMOUND OF DATA BITS
    int i, j = 0, k = 0;

    struct Hamming checkBit[cBitCount];     //ARRAYS OF HAMMING STRUCTURE TO HOLD THE VALUE, POSITION, AND THE POSITION'S BINARY NUMBER
    struct Hamming dataBit[dBitCount];      //OF THE CHECK BITS AND DATA BITS

    int calculated[cBitCount];              //ARRAYS TO HOLD THE CALCULATED CODE
    int errorBit[cBitCount];                //AND THE BINARY VALUE OF ERROR BIT
    int error = 0;                          //HOLDS DECIMAL VALUE OF ERROR BIT


    /*GOES THROUGH THE INPUT CODE AND POPULATES THE HAMMING STRUCTURE ARRAYS
      BASED ON THE POSITION OF EACH BIT. ALL THE VALUES ARE STORED BACKWARDS*/
    for (i = 0; i < codeSize; i++)
    {
        if((i + 1 == codeSize) || !isPower(i + 1))
        {
            dataBit[k].num = Code[(codeSize - 1) - i] - '0';    //CHANGES NUMBER TO INTEGER AND STORES IT
            dataBit[k].bitPosition = i + 1;                     //I + 1 SINCE ARRAY STARTS FROM 0
            dataBit[k].binary = (char*)malloc((cBitCount + 1)*sizeof(char));    //CREATES ARRAY FOR BINARY VALUE OF POSITION NUMBER
            convert(dataBit[k].bitPosition, cBitCount, dataBit[k].binary);      //CONVERTS POSITION NUMBER TO BINARY
            k++;                                                                //INCREMENTS DATA BIT ARRAY
        }
        else if(isPower(i + 1))
        {
            checkBit[j].num = Code[(codeSize - 1) - i] - '0';   //CHANGES NUMBER TO INTEGER AND STORES IT
            checkBit[j].bitPosition = i + 1;                    //I + 1 SINCE ARRAY STARTS FROM 0
            checkBit[j].binary = (char*)malloc((cBitCount + 1)*sizeof(char));   //CREATES ARRAY FOR BINARY VALUE OF POSITION NUMBER
            convert(checkBit[j].bitPosition, cBitCount, checkBit[j].binary);    //CONVERTS POSITION NUMBER TO BINARY
            j++;                                                                //INCREMENTS CHECK BIT ARRAY
        }
    }

    /*DETERMINES THE CORRESPONDING DATA BITS OF EACH CHECK BIT BY
      COMPARING THE BINARY NUMBERS OF THE CHECK BITS AND DATA BITS.
      THEN CALCULATES THE NEW CODE. THE NEW CODE IS STORED BACKWARDS*/
    for(i = 0; i < cBitCount; i++)
    {
        calculated[i] = parity;
        for(j = 0; j < dBitCount; j++)
            if(checkBit[i].binary[i] == dataBit[j].binary[i])
                calculated[i] ^= dataBit[j].num;
    }

    /*CALCULATES THE BINARY NUMBER OF THE ERROR BIT
      WHICH IS STORED BACKWARDS IN AN ARRAY*/
    for(i = 0; i < cBitCount; i++)
    {
        if((checkBit[i].num == 1) && (calculated[i] == 1))
            errorBit[i] = 0;
        else if((checkBit[i].num == 0) && (calculated[i] == 0))
            errorBit[i] = 0;
        else
            errorBit[i] = 1;
    }

    /*CONVERTS THE BINARY NUMBER OF THE ERROR BIT TO DECIMAL*/
    for(i = 0; i < cBitCount; i++)
        if(errorBit[i] == 1)
            error += pow(2, i);

    /*PRINTS THE ERROR BIT IN DECIMAL THEN CORRECTS THE BIT WHERE
      THE ERROR OCCURS*/
    if(error > 0)
    {
        printf("\n\n***There is an error in bit: %d", error);
        switch(Code[codeSize - error])
        {
            case '0': Code[codeSize - error] = 1 + '0';
                      break;
            case '1': Code[codeSize - error] = 0 + '0';
                      break;
        }
        printf("\n***The corrected hamming code is: %s\n\n", Code);
    }
    else
        printf("\n\n***There is no bit error\n\n");

    /*THE ARRAY DYNAMICALLY ALLOCATED TO HOLD THE BINARY NUMBERS
      OF THE CHECK BITS AND DATA BITS ARE FREED*/
    for(i = 0; i < cBitCount; i++)
        free(checkBit[i].binary);
    for(i = 0; i < dBitCount; i++)
        free(dataBit[i].binary);

}

/*/================================================================================================\\
||=================================================================================================||
||                                                                                                 ||
||                                          CONVERT                                                ||
||                                                                                                 ||
||=================================================================================================||
\\================================================================================================/*/
void convert(int num, int size, char* bin)
{
    /*A TEMPORARY ARRAY IS CREATED TO HOLD THE BINARY NUMBER OF THE POSITION NUMBER
      THEN COPIED INTO THE ARRAY PARAMETER THAT WAS PASSED TO THE FUNCTION. THE BINARY
      NUMBER IS STORED BACKWARDS*/
    int i;
    char binNum[size + 1];
    binNum[size + 1] = '\0';    //SIZE + 1 TO ACCOUNT FOR THE NULL CHARACTER
    for(i = 0; i < size; i++)
    {
        binNum[i] = num % 2 - '0';
        num /= 2;
    }
    strcpy(bin, binNum);
}

/*/================================================================================================\\
||=================================================================================================||
||                                                                                                 ||
||                                            IsPOWER                                              ||
||                                                                                                 ||
||=================================================================================================||
\\================================================================================================/*/
int isPower(int bit)
{
    /*CHECKS IF NUMBER PASSED DOWN IS A POWER OF 2*/
    if((float)log2(bit) == (int)log2(bit))
        return 1;
    return 0;
}
