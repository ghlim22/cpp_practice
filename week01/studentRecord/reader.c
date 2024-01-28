#include "studentRecord.h"
#include <stdio.h>
int main(void)
{
	FILE *fin = fopen("studentRecord.dat", "rb");

	if (fin == NULL) {
		perror("fopen() failed");
		return 0;
	}

	struct StudentRecord s;
	fread(&s, sizeof(s), 1, fin);
	printf("grade: %d\nname: %s\n", s.grade, s.name);

	return 0;
}