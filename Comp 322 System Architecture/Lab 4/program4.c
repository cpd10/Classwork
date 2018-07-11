/*
	Darius Hooks
	COMP 322
	LAB #4
*/

#include <stdio.h>
#include <time.h>

void randomwait();
void barber_run();
void customer_run();

int seats[2];
int customers[2];
int barber[2];
int freeseats[2];

void V(int pd[]) 
{
	int a=1;
	write(pd[1],&a,sizeof(int));
}

void P(int pd[]) 
{
	int a;
	read(pd[0],&a,sizeof(int));
}

void main() 
{
	pipe(seats); // pipes used to implement semaphores
	pipe(customers);
	pipe(barber);
	
	pipe(freeseats); // implemented to pass the integer value for number of seats
	
	V(seats); // Sets the initial value of seats to 1
	
	int num=3; // Free Seats = 3
	int cust = 0; //Customers = 0;
	write(freeseats[1],&num,sizeof(int));
	write(customers[1], &cust, sizeof(int));
	
	if (fork() == 0) 
	{  // Start 1 barber
		srand(time(0)+11); // Randomized seed
		barber_run();
		return;
	}
	
	int i;
	for (i=1;i<=10;i++) 
	{ // Start 10 customers randomly
		if (fork() == 0) 
		{
			randomwait(i); // random wait before next customer arrives
			srand(time(0)+ i); // different seed than barber for different delays
			customer_run();
			return;
		}
	}
}

void barber_run() 
{
	int num,i, c;
	for (i=1;i<=10;++i)
	{ 
		// at most 10 customers will get their hair cut
		P(barber);
		printf("Barber %d is trying to get a customer\n",i);
		read(customers[0], &c, sizeof(int));
		if(c > 0)
		{
			c-=1;
			write(customers[1], &c, sizeof(int));
			printf("Barber %d is waiting for the seat to become free\n", i);
			P(seats);
			read(freeseats[0], &num, sizeof(int));
			num += 1;
			printf("Barber %d is increasing the number of free seats to %d\n", i, num);
			write(freeseats[1], &num, sizeof(int));
			printf("Barber is now cutting hair %d\n",i);
			printf("- Customer is now getting hair cut\n");
			randomwait(1); // random wait before finishing haircut
			printf("- Barber %d finished hair cut\n", i);
			V(seats);
		}
		
		else
			V(barber);
	}
}

void customer_run() 
{
	int num, c;
	printf("- New customer trying to find a seat\n");
	read(freeseats[0], &num, sizeof(int));
	if (num > 0)
	{
		read(customers[0], &c, sizeof(int));
		c += 1;
		num -= 1;
		printf("- Customer is decreasing the number of free seats to %d\n", num);
		write(freeseats[1], &num, sizeof(int));
		printf("- Customer is now waiting for the barber\n");
		write(customers[1], &c, sizeof(int));
		V(barber);
	}
	
	else
	{
		printf("* Customer giving up: No free chairs in waiting room\n");
		write(freeseats[1], &num, sizeof(int));
	}
		
}

void randomwait(int d) 
{ 
	// random 0 to d sec delay
	int delay;
	struct timespec tim, tim2;
    tim.tv_sec = 0;
	delay = abs(rand() % 1000000000) * d;
	tim.tv_nsec = delay;
	nanosleep(&tim,&tim2);
}

