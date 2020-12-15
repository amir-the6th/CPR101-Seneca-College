#include <stdio.h>   // standard I/O
#include <stdbool.h> // booleans
#include <stdint.h>  // Standard Integer Types

// test of binary search which should find all values between rangeLow & rangeHigh below.

/****************************************
   CHANGE THE MID= FORMULA NEAR LINE 80
*****************************************/

// Binary search
//  target is the value to find
bool binarySearchTest(int target);
int errorsFound = 0;
int totalSearches = 0;
int countSuccessfulSearches;
const int rangeLow = 1;
const int rangeHigh = 100;

int main()
{
	printf("Searching for values within and just outside the range %d -- %d\n\n", rangeLow, rangeHigh);

	// search for each possible value in the range and a few values just outside range to check edge conditions

	for (int i = rangeLow - 3; i <= rangeHigh + 3; i++)
	{
		binarySearchTest(i);
		printf("\n");
	}
	printf("\nErrors found: %d", errorsFound);
	printf("\n%.2f is average number of tries in %d successful searches over %d items\n\n", (float)totalSearches / countSuccessfulSearches, countSuccessfulSearches, rangeHigh - rangeLow + 1);

	printf("\npress Enter to end.");
	getchar(); // pause terminal window

	return errorsFound;
}

/* simulates overflow problem in binary search using 8-bit integer */
bool binarySearchTest(int target)
{
	int
		low = rangeLow,		// initial lowest search range
		high = rangeHigh,	// initial highest search range = maximum value of 8-bit signed integer
		mid = low;			// calculate middle point of search range
	int
		prevLow = low,		// previous values for quality evaluation
		prevHigh = high,
		prevMid = high;

	int	counter = 0;			// iterations of search

	printf("search for %3d, mid ", target); // print width is 3 columns for target searched

	do  // search between low & high for target
	{
		counter++; // iterations for current search

		prevLow = low; 			// previous values for quality evaluation
		prevHigh = high; 		// previous values for quality evaluation
		prevMid = mid; 			// previous values for quality evaluation BUG: was being set to zero

		// N.B. intermediate result of integer arithmetic will be stored, by default, in an int data type. int width is minimum 16-bit; it is 32-bit on most platforms but that cannot be guaranteed. 
		// Here, the intermediate result is cast to an 8-bit integer in order to cause overflow for demonstration and testing with only 2^7 iterations.

		// (int8_t)(intermediate_result) will cast to 8-bit in order to test formula for overflow

		mid = (int8_t)(low + high) / 2; // calc mid-point using original binary search bug forcing overflow for any intermediate result > INT8_MAX
		/*
				(low+high) will overflow MAX value if both are in upper half of range. e.g.
		0------------------low--------high-----MAX    <== simulated integer range of values, calc new mid point

		0------------------low
		 PLUS
		0-----------------------------high
		 EQUALS
		0------------------low-----------------------------high
		0 -------------------------------------MAX============= oops! overflow

		*/
		// comment the above mid= and rewrite below

		// *****************************************************************************************************
		// mid = (int8_t)(intermediateValue)  ;	// new calc for mid which avoids intermediate value overflow
		// *****************************************************************************************************

		/* Hint: instead of finding the average of low+high as in the bug version, first find the middle point between low and high.
		0------------------low--------high-----MAX
						   |-------------|
		1st find mid point        ^        between low and high
		*/

		printf("%3d ", mid); // print width is 3 columns

		if (target < mid) // target is LT mid point
		{
			high = mid - 1; // new high is LT mid
		}
		else if (target > mid)  // target is GT mid point
		{
			low = mid + 1; // new low is GT mid
		}
		else if (mid >= rangeLow && mid <= rangeHigh) // mid == target found at calculated mid-point 
			// Check for edge case, e.g. target == mid == 0 but outside range. This is required only for QA testing. Normally, this line would be an unconditional else
		{
			printf("%*.0dfound in %d tries", ((7 - counter) * 4), 0, counter); // calc minimum print width to position "found..."
			totalSearches += counter; // accumulate for average number of tries in successful searches
			countSuccessfulSearches += 1; // count number of successful searches 
			return true;
		}

		/* QA evaluation of algorithm, expected values:"
		   Low ascends towards target,
		   High descends towards target,
		   either Low or High change each iteration,
		   Mid always changes each iteration.
		   in debugged code, the following error checks are not necessary
		*/

		if (low < prevLow) // ERROR 
		{
			printf("ERROR: new low value should ascend. %d iterations. low=%d  high=%d", counter, low, high);
			errorsFound++; // increment error counter
			return false; // target not found due to error
		}

		if (high > prevHigh) // ERROR
		{
			printf("ERROR: new high value should descend. %d iterations. low=%d  high=%d", counter, low, high);
			errorsFound++; // increment error counter
			return false; // target not found due to error
		}

		if (mid == prevMid) // ERROR: new mid is same as previous mid
		{
			printf("ERROR: new mid value did not change. %d iterations. low=%d  high=%d", counter, low, high);
			errorsFound++; // increment error counter
			return false; // target not found due to error
		}

		if (low == prevLow && high == prevHigh) // ERROR: neither low nor high changed value
		{
			printf("ERROR: neither low nor high changed value. %d iterations. low=%d  high=%d", counter, low, high);
			errorsFound++; // increment error counter
			return false; // target not found due to error
		}
		// end of QA evaluation

	} while (low <= high); // post-test loop. repeat search if a gap between low and high. not found cases will result in low/high values crossing over each other.

	printf("NOT found in %d tries. low=%d high=%d", counter, low, high);
	return false; // valid case of target not found
}
