
#include "studentRecord.h"
#include <stdio.h>

int main(void)
{
	FILE *fp = fopen("studentRecord.dat", "wb");

	if (fp == NULL) {
		perror("fopen() failed");
		return 0;
	}

	struct StudentRecord s = {.grade = 42, .name = "HM Son"};
	fwrite(&s, sizeof(s), 1, fp);
	return 0;
}