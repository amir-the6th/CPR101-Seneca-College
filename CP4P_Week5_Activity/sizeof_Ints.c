/* limits.c - print limits of integer types.

   You can use this program to find out if your system's int integers
   are same as or longer than its short integers.
*/

/* limits.h is an include file defined by the POSIX standard which
   tells us about various limits on our system, including those 
	 of the integer types. */

#include <limits.h> // contains _MAX _MIN values
#include <stdbool.h> // Boolean data type
#include <stdint.h>  // Standard Integer Types
#include <stdio.h>

int main()
{
	bool trueFalse;

	printf("Size of various data types...\n\nUnsigned U_type_MAX should be avoided. Value is type_MAX + |type_MIN|\n\n");

	/* Print limits of boolean.  Note use of u
   character in format strings to indicate "unsigned". */

	printf("sizeof(bool)  = %11d byte,   %d bits\n", sizeof(bool), sizeof(bool) * 8);
	printf("sizeof(true)  = %11d bytes, %d bits with value of %d\n", sizeof(true), sizeof(true) * 8, true);
	printf("sizeof(false) = %11d bytes, %d bits with value of %d\n", sizeof(false), sizeof(false) * 8, false);
	trueFalse = 12345; // any non-zero integer assigned to a bool data type results in true. 
	printf("trueFalse     = %11d resulting from trueFalse = 12345\n", trueFalse);
	trueFalse = 0; // a zero integer assigned to a bool data type results in false. 
	printf("trueFalse     = %11d resulting from trueFalse = 0\n", trueFalse);
	
	/* Print limits of characters, signed and unsigned. */

	printf("\nsizeof(char)  = %11d bytes, %d bits\n", sizeof(char), sizeof(char) * 8);
	printf("CHAR_MAX      = %11d\n", CHAR_MAX);
	printf("CHAR_MIN      = %11d\n", CHAR_MIN);
	printf("SCHAR_MAX     = %11d\n", SCHAR_MAX);
	printf("SCHAR_MIN     = %11d\n", SCHAR_MIN);

	/* Print limits of integers, signed and unsigned.  Note use of u
   character in format strings to indicate "unsigned". */

	printf("\nsizeof(int)   = %11d bytes, %d bits\n", sizeof(int), sizeof(int) * 8);
	printf("INT_MAX       = %11d\n", INT_MAX);
	printf("INT_MIN       = %11d\n", INT_MIN);

	/* Print limits of long integers, signed and unsigned.  Note use
	   of l character in format strings to specify "long". */

	printf("\nsizeof(long)  = %11d bytes, %d bits\n", sizeof(long), sizeof(long) * 8);
	printf("LONG_MAX      = %11li\n", LONG_MAX);
	printf("LONG_MIN      = %11li\n", LONG_MIN);

	/* Print limits of short integers, signed and unsigned.  Note use
	   of hd character in format strings to indicate "short". */

	printf("\nsizeof(short) = %11d bytes, %d bits\n", sizeof(short), sizeof(short) * 8);
	printf("SHRT_MAX      = %11hd\n", SHRT_MAX);
	printf("SHRT_MIN      = %11hd\n", SHRT_MIN);

	/* Print limits of long long integers, signed and unsigned.  Note use
		   of ll characters in format strings to specify "long long" type. */

	printf("\nsizeof(long long)  = %d bytes, %d bits\n", sizeof(long long), sizeof(long long) * 8);
	printf("LLONG_MAX          = %11lld\n", LLONG_MAX);
	printf("LLONG_MIN          = %11lld\n", LLONG_MIN);
	
	/* Print Minimum-width integer types.  Note use of u
character in format strings to indicate "unsigned". */
	printf("\nint is preferred when the size of the integer does not matter.\ni.e. the number will ALWAYS fit within the range of a 2 byte,\n16-bit signed integer, a short, the minimum size in C.\ne.g. counting from 1 to 30000, arrays with <16,000 elements.\nThis will cover the vast majority of use cases.\n\nC99 guarantees variables to be a particular size across platforms:\n~ for performance, use int_FAST#_t where # is bit width: 8, 16, 32, 64\n~ for memory conservation over performance,\n  use int_LEAST#_t, when allocating a great many variables.\n\n");

	printf("Minimum-width integer types for memory conservation at the expense of performance:\n");
	printf("\nsizeof(int_least8_t)  = %11d bytes, %d bits\n", sizeof(int_least8_t), sizeof(int_least8_t) * 8);
	printf("INT_LEAST8_MIN        = %11d\n", INT_LEAST8_MIN);
	printf("INT_LEAST8_MAX        = %11d\n", INT_LEAST8_MAX);

	printf("\nsizeof(int_least16_t) = %11d bytes, %d bits\n", sizeof(int_least16_t), sizeof(int_least16_t) * 8);
	printf("INT_LEAST16_MIN       = %11d\n", INT_LEAST16_MIN);
	printf("INT_LEAST16_MAX       = %11d\n", INT_LEAST16_MAX);

	printf("\nsizeof(int_least32_t) = %11d bytes, %d bits\n", sizeof(int_least32_t), sizeof(int_least32_t) * 8);
	printf("INT_LEAST32_MIN        = %11d\n", INT_LEAST32_MIN);
	printf("INT_LEAST32_MAX        = %11d\n", INT_LEAST32_MAX);

	printf("\nsizeof(int_least64_t) = %11d bytes, %d bits\n", sizeof(int_least64_t), sizeof(int_least64_t) * 8);
	printf("INT_LEAST64_MIN        = %11I64d\n", INT_LEAST64_MIN);
	printf("INT_LEAST64_MAX        = %11I64d\n", INT_LEAST64_MAX);

	/* Print Minimum-width integer types.  Note use of u
character in format strings to indicate "unsigned". */
	printf("\nFast minimum-width integer types for performance at the expense of memory usage:\n");
	printf("\nsizeof(INT_FAST8_t)  = %11d bytes, %d bits\n", sizeof(int_fast8_t), sizeof(int_fast8_t) * 8);
	printf("INT_FAST8_MIN        = %11d\n", INT_FAST8_MIN);
	printf("INT_FAST8_MAX        = %11d\n", INT_FAST8_MAX);

	printf("\nsizeof(INT_FAST16_t) = %11d bytes, %d bits\n", sizeof(int_fast16_t), sizeof(int_fast16_t) * 8);
	printf("INT_FAST16_MIN       = %11d\n", INT_FAST16_MIN);
	printf("INT_FAST16_MAX       = %11d\n", INT_FAST16_MAX);

	printf("\nsizeof(int_fast32_t) = %11d bytes, %d bits\n", sizeof(int_fast32_t), sizeof(int_fast32_t) * 8);
	printf("INT_FAST32_MIN        = %11d\n", INT_FAST32_MIN);
	printf("INT_FAST32_MAX        = %11d\n", INT_FAST32_MAX);

	printf("\nsizeof(int_fast64_t) = %11d bytes, %d bits\n", sizeof(int_fast64_t), sizeof(int_fast64_t) * 8);
	printf("INT_FAST64_MIN        = %11I64d\n", INT_FAST64_MIN);
	printf("INT_FAST64_MAX        = %11I64d\n", INT_FAST64_MAX);

	/* see https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/ */

	/* Print size of floating point types */

	printf("\nsizeof(float)  = %d bytes, %d bits\n", sizeof(float), sizeof(float) * 8);
	printf("\nsizeof(double) = %d bytes, %d bits\n", sizeof(double), sizeof(double) * 8);

	printf("\nfloat has 6 decimals of precision\nWith multiple calcs, some values may drift and become less accurate.\n");
	float floatTest, oneThird;
	oneThird = 1.0f / 3.0f;
	
	floatTest = 1.0f;
	printf("\nfloat  1 is %.32f\n", floatTest);
		for (int i = 1; i <= 10; i++)
	{
		floatTest = floatTest / 3;
		printf("float /3 is %.32f\n", floatTest);
	}
	
		floatTest = 1.0f;
	printf("\nfloat    is %.32f\n", floatTest);
	for (int i = 1; i <= 10; i++)
	{
		floatTest = floatTest * .3f;
		printf("float*.3 is %.32f\n", floatTest);
	}
	
	floatTest = oneThird;
	printf("\nfloat    is %.32f\n", floatTest);
	for (int i = 1; i <= 20; i++)
	{
		floatTest += oneThird; // cumulative addition of 1/3
		printf("float += is %.32f\n", floatTest);
	}

	floatTest = 12345;
	printf("\nfloat    is %.32f\n", floatTest);
	for (int i = 1; i <= 10; i++)
	{
		floatTest *= 10; // cumulative multiplication by ten
		printf("float *= is %.32f\n", floatTest);
	}

	printf("\n\n Use mouse to scroll and view from the top.\n A change to the window's Properties, Options, Buffer size may be required.\n");
	return 0;
}