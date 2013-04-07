#include <stdio.h>
#include <stdbool.h>
#include <complex.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/select.h>

// Inline functions
// Bool type
static inline bool foo()
{
  printf("Bye!\n");
	return true;
}

double bar()
{
	return rand();
}

int main()
{
	// Nice C++ style comments
	int n;

	scanf("%d",&n);

	// Intermingled variable declaration and code
	// and variable length arrays
	char buf[n];

	double k = bar();
	// New function snprintf
	snprintf(buf,n,"Hello!\n");

	// Buffers not allowed to overlap! No warning but results are undefined
	snprintf(buf,n, "%s some further text", buf);
	printf("%s\n",buf);

	// Inline function returnin bool
	if (foo()) {
		printf("Yes %f!\n",k);
	}

	//Complex numbers support
	complex c=2+2i;
	printf("arg=%f %d\n",carg(c));

	//Portable integers
	int_fast16_t my_fast_int=123;
	short my_slow_short = 234;
	printf("my_fast_int=%"PRIdFAST16" size=%ld\n",my_fast_int,
		sizeof(my_fast_int));
	printf("my_slow_short=%d size=%ld\n",my_slow_short,
		sizeof(my_slow_short));

	//Compound literals
	struct test1 {
		int a;
		char b[5];
	};

	struct test1 t1 = {4,"abc"};
	printf("%d %s\n",t1.a,t1.b);

	char **str = (char *[]){"x","y","z"};
	printf("%s %s %s\n",str[0],str[1],str[2]);

	// New initialization mechanism
	struct test1 t2 = {  .b="xyz" ,.a=5 };
	printf("%d %s\n",t2.a,t2.b);

	// No need for temporary structs!
	select(0, 0, 0, 0, & (struct timeval) { .tv_usec = 1000 });

	// Also arrays
	struct test1 t3[5] = { 
		[3] = {.a=3}, 
		[4] = { .b = "qwe" }
	};
	printf("%d %s\n",t3[0].a,t3[0].b);
	printf("%d %s\n",t3[3].a,t3[3].b);
	printf("%d %s\n",t3[4].a,t3[4].b);

	//Better Unicode support
	printf("It's all \u03B5\u03BB\u03BB\u03B7\u03BD\u03B9\u03BA\u03AC to me.\n");

	return 0;
}
