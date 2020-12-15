// C program to generate deterministic and pseudo random numbers 
#include <stdio.h> 
#include <stdlib.h> 
#include<time.h> 

int main(void)
{
	printf("rand() will create this sequence of random numbers every time program is run\n");
	printf("    41 18467  6334 26500 19169 15724 11478 29358 26962 24464\nRunning rand() ten times\n");

	for (int i = 0; i < 10; i++)
		printf("%6d", rand());
	printf(" ... See?\n");

	// srand() will create different sequence of random numbers every time program is run. call srand() only once.

	printf("\n\nsrand(NULL); defaults to current time as seed for random generator\n");
	printf("i.e. seconds since 1970-01-01 00:00:00 is %ld \n", time(NULL));
	srand(NULL);

	for (int i = 0; i < 10; i++) // output 10 random numbers
		printf("%6d", rand());
	
	printf("\nRunning rand() again without re-seeding\n");
	
	for (int i = 0; i < 10; i++)
		printf("%6d", rand());

	printf("\n\nsrand(NULL); to re-seed. It is likely still the same number of seconds.\n");
	printf("i.e. seconds since 1970-01-01 00:00:00 is %ld \n", time(NULL));
	
	srand(NULL);
	for (int i = 0; i < 10; i++)
		printf("%6d", rand());
	printf("\n\nNote that the C rand() function is not for cryptographic use.\n\n");

	// On Windows platforms, the BCryptGenRandom() function can be used to generate cryptographically strong random numbers. The Microsoft Developer Network BCryptGenRandom() reference [MSDN] states it "complies with the NIST SP800-90 standard, specifically the CTR_DRBG portion of that standard."
	
	return 0;
}
