#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Menu();
void choice_one();
void choice_two();
void choice_three();

struct Machine
{
	int cpi, i_count;
};

int i_classes, freq;
struct Machine* m;

int main()
{
	int choice;

	do
    {
		switch (choice = Menu())
		{
			case 1: choice_one();
					break;

            case 2: choice_two();
                    break;

            case 3: choice_three();
                    break;
        }
	} while (choice != 4);

	free(m);
	//printf("\nPress any key to continue...");
	//_getch();
	return 0;
}

int Menu()
{
    int selection;
    printf("\n|----Darius Hooks----|");
    printf("\nPerformance assessment:\n");
    printf("-----------------------\n");
    printf("1) Enter parameters\n");
    printf("2) Print table of parameters\n");
    printf("3) Print table of performance\n");
    printf("4) Quit\n");
    printf("Enter Selection: ");
    scanf("%d", &selection);
    return selection;
}

void choice_one()
{
    int i;
    printf("\nEnter the number of instruction classes: ");
	scanf("%d", &i_classes);
    printf("\nEnter the frequency of the machine (MHz): ");
    scanf("%d", &freq);

    m = (struct Machine*) malloc(i_classes * sizeof(struct Machine));
    for (i = 0; i < i_classes; i++)
    {
        printf("\nEnter CPI of class %d: ", i + 1);
        scanf("%d", &m[i].cpi);
        printf("\nEnter instruction count of class %d (millions): ", i + 1);
        scanf("%d", &m[i].i_count);
    }
}

void choice_two()
{
    int i;
    if(m == NULL)
        printf("\nNo Data\n");
    else
    {
        printf("\n-------------------------");
        printf("\n|Class\t|CPI\t|Count\t|");
        printf("\n-------------------------");
        for (i = 0; i < i_classes; i++)
        {
            printf("\n|%d\t|%d\t|%d\t|", i + 1, m[i].cpi, m[i].i_count);
            printf("\n-------------------------");
        }
        printf("\n");
    }
}

void choice_three()
{
    int i, total = 0, total_ins = 0;
    float avg_cpi, cpu_time, mips;
    if(m == NULL)
        printf("\nNo Data\n");
    else
    {
        for(i = 0; i < i_classes; i++)
        {
            total += m[i].cpi * (m[i].i_count * pow(10,6));
            total_ins += m[i].i_count * pow(10,6);
        }

        avg_cpi = (float)total/total_ins;
        cpu_time = (float)((total_ins * avg_cpi)/freq) * pow(10,-3);
        mips = (float)((freq * pow(10,6))/(avg_cpi * pow(10,6)));
        printf("\n-------------------------");
        printf("\n|Performance\t|Value\t|");
        printf("\n-------------------------");
        printf("\n|Average CPI\t|%.2f\t|", avg_cpi);
        printf("\n-------------------------");
        printf("\n|CPU Time(ms)\t|%.2f\t|", cpu_time);
        printf("\n-------------------------");
        printf("\n|MIPS\t\t|%.2f\t|", mips);
        printf("\n-------------------------\n");
    }
}
