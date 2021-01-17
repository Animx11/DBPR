#include <stdlib.h>
#include <sys/mman.h>
#include <time.h>

int main()
{
    int i;
	mlockall(MCL_CURRENT);
    srand (time(NULL));

    char preKey[16];  
    for(i = 1; i <= 16; i++) {
        preKey[i] = rand() % 2;
    }

	munlockall();

	return 0;	
}