#include <stdio.h>
#include "serialdate.h"

int main() {
	char *sDate1 = "19920415";
	char *sDate2 = "19191231";
	char *sDate3 = "20080229";
	char *sDate4 = "19130101";
	char *sDate5 = "19131231";
	char *sDate6 = "19141231";
	char *sDate7 = "19161231";
	char *sDate8 = "19201231";

	serialdate nDate1 = getSerialDate(sDate1);
	printf("For %s, getSerialDate returned %d\n", sDate1, nDate1);
	serialdate nDate2 = getSerialDate(sDate2);
	printf("For %s, getSerialDate returned %d\n", sDate2, nDate2);
	serialdate nDate3 = getSerialDate(sDate3);
	printf("For %s, getSerialDate returned %d\n", sDate3, nDate3);
	serialdate nDate4 = getSerialDate(sDate4);
	printf("For %s, getSerialDate returned %d\n", sDate4, nDate4);
	serialdate nDate5 = getSerialDate(sDate5);
	printf("For %s, getSerialDate returned %d\n", sDate5, nDate5);
	serialdate nDate6 = getSerialDate(sDate6);
	printf("For %s, getSerialDate returned %d\n", sDate6, nDate6);
	serialdate nDate7 = getSerialDate(sDate7);
	printf("For %s, getSerialDate returned %d\n", sDate7, nDate7);
	serialdate nDate8 = getSerialDate(sDate8);
	printf("For %s, getSerialDate returned %d\n", sDate8, nDate8);

	return 0;
}
