#include <stdio.h>
#include <stdlib.h>

int mutex = 1;

int full = 0;

int empty = 10, x = 0;

void producer()
{
	--mutex;

	++full;

	--empty;

	x++;
	printf("\nProducer produces item %d\n",
		x);
	++mutex;
		printf("%d %d %d",mutex, full, empty);
}

void consumer()
{
	--mutex;

	--full;

	++empty;
	printf("\nConsumer consumes item %d\n", x);
	x--;

	++mutex;
	printf("%d %d %d",mutex, full, empty);
}

// Driver Code
int main()
{
	int n, i;
	printf("\n1. Press 1 for Producer"
		"\n2. Press 2 for Consumer"
		"\n3. Press 3 for Exit");


	for (i = 1; i > 0; i++) {

		printf("\nEnter your choice:  ");
		scanf("%d", &n);

		// Switch Cases
		switch (n) {
		case 1:
			if ((mutex == 1)
				&& (empty != 0)) {
				producer();
			}
			else {
				printf("\n  Buffer is full!\n");
			}
			break;

		case 2:
			if ((mutex == 1)
				&& (full != 0)) {
				consumer();
			}
			else {
				printf("\n  Buffer is empty!\n");
			}
			break;

		case 3:
			exit(0);
			break;
		}
	}
}
