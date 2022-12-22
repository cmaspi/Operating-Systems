#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


// global variables
// so that it can be used in functions without passing separately
int N, K;


// function to check if the given number is a perfect number
/*
	Summary
	-------
	Checks whether given number is perfect or not

	Args
	----
	num(int) : input number
*/
int check(int num)
{	
	int factor_sum = 0;
	for(int i=1; i<num; i++)
	{
		if (num % i == 0)
			factor_sum += i;
	}
	return factor_sum == num;
}


// thread function
/*
	Summary
	-------
	the code that will be run by each thread

	Args
	----
	vargp (void*): it is the pointer to thread number (with void* typecast)
*/
void* myThread(void *vargp)
{
	// Store the value argument passed to this thread
	int myid = *(int*)vargp;
	// printf("%d\n", myid);
	char* s = (char*)malloc(20 * sizeof(char));
	sprintf(s, "OutFile%d.log", myid);
	FILE* ptr = fopen(s, "w");
	int* data = (int*) malloc(sizeof(int)*1);
	data[0] = 0;
	for(int i=myid; i<=N; i+=K)
	{
		if(check(i))
		{
			fprintf(ptr, "%d: Is a perfect number\n", i);
			data[0] += 1;
			data = (int*) realloc(data, data[0]*sizeof(int));
			data[data[0]] = i;
		}
		else
			fprintf(ptr, "%d: Not a perfect number\n", i);
	}
	fclose(ptr);
	return (void*)data;
}




int main()
{
	FILE* file_ptr = fopen("input.txt", "r"); //opening the file in read mode
	if (file_ptr == NULL) // if file couldn't be opened
		printf("Error opening input.txt");

	fscanf(file_ptr, "%d", &N);
	fscanf(file_ptr, "%d", &K);
	fclose(file_ptr);
	// Some basic error handling
	if(K < 1)
		printf("Error: It makes no sense to use %d threads", K);
	if(N < 1)
		printf("Error: N cannot be less than 1");
	
	pthread_t* tids;
	tids = (pthread_t*) malloc(K * sizeof(pthread_t));
	int* addresses = (int*) malloc(K * sizeof(int)); //basically index of thread (1-indexed)
	for(int num_thread=0; num_thread<K; num_thread++)
	{
		addresses[num_thread] = num_thread+1;
		pthread_create(&tids[num_thread], NULL, myThread, (void*)&addresses[num_thread]);
	}

	void* results[K];
	for(int num_thread=0; num_thread<K; num_thread++)
	{
		pthread_join(tids[num_thread], &results[num_thread]);
	}

	FILE* ptr = fopen("OutMain.log", "w");
	for(int num_thread=0; num_thread<K; num_thread++)
	{
		fprintf(ptr, "Thread%d :", num_thread+1);
		int* temp = (int*) results[num_thread];
		for(int i=1; i<temp[0]+1; i++)
			fprintf(ptr, " %d", temp[i]);
		fprintf(ptr, "\n");
	}
	fclose(ptr);

	return 0;
}
