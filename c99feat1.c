#include <stdbool.h>
#include <sys/time.h>
#include <string.h>

struct bureaucrat {
  int rank;
	char name[20];
};

bool isAlreadyInPijamas(const char *name)
{
	if (strcmp(name,"Prof. Farnsworth") == 0) {
		return true;
	}
	return false;
}

int main()
{
	struct bureaucrat hermes = {34,"Hermes Conrad"};
	struct bureaucrat morgan = {  .name="Morgan Proctor" ,.rank=19 };
	struct bureaucrat central_bureaucracy[100] = { 
		[34] = {.name = "Hermes Conrad"}, 
		[19] = {.name = "Morgan Proctor" }
	};

	select(0, 0, 0, 0, & (struct timeval) { .tv_usec = 1000 });

}
