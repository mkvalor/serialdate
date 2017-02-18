#include "serialdate.h"
#include <string.h>
#include <stdio.h>

serialdate SERDATE_10S[4] = {1, 10, 100, 1000};
serialdate SERDATE_BASEYEAR = 1912; //1913 will be year 1.  Subtract this value to get the serial year.
serialdate SERDATE_LEAPSTRIDE = 4; // Divide serial year by this value to get number of leaps (Y2K was a leap year)
serialdate SERDATE_YEARDAYS = 365;
serialdate SERDATE_MONTHDAYS[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 303, 334};
int SERDATE_DATELEN = 8;

serialdate getSerialDate(char* strDate) {
	serialdate serDate = 0;

	if (NULL != strDate && SERDATE_DATELEN == strlen(strDate)) {
		serialdate year = SD_getYear(strDate);
		serialdate leapSemaphore  = 2;
		if (0 == (year % SERDATE_LEAPSTRIDE))
			--leapSemaphore;
		serialdate serialYear = year - 1 - SERDATE_BASEYEAR;
		serDate += (serialYear * SERDATE_YEARDAYS) + (serialYear / SERDATE_LEAPSTRIDE);

		serialdate month = SD_getMonth(strDate);
		serDate += SERDATE_MONTHDAYS[month];
		if (month > 2)
			--leapSemaphore;

		if (0 == leapSemaphore)
			++serDate;

		serialdate day = SD_getDay(strDate);
		serDate += day;

		printf("The date portions were converted as: %d/%d/%d.\n", month, day, year);
	}

	return serDate;
}

serialdate SD_getYear(char *strDate) {
	serialdate year = 0;

	//strDate has already been validated
	int tens = 0;
	char curr = 0x00;
	for (int i = 3; i >= 0; --i) {
		if (strDate[i] > 0x2F && strDate[i] < 0x3A) {
			curr = strDate[i] - 0x30;
			year += curr * SERDATE_10S[tens++];
		} else {
			year = 0;
			break;
		}
	}

	return year;
}

serialdate SD_getMonth(char *strDate) {
	serialdate month = 0;

	int tens = 0;
	char curr = 0x00;
	for (int i = 5; i >= 4; --i) {
		if (strDate[i] > 0x2f && strDate[i] < 0x3A) {
			curr = strDate[i] - 0x30;
			month += curr * SERDATE_10S[tens++];
		} else {
			month = 0;
			break;
		}
	}

	if (month > 12)
		month = 0;

	return month;
}

serialdate SD_getDay(char *strDate) {
	serialdate day = 0;

	int tens = 0;
	char curr = 0x00;
	for (int i = 7; i >= 6; --i) {
		if (strDate[i] > 0x2F && strDate[i] < 0x3A) {
			curr = strDate[i] - 0x30;
			day += curr * SERDATE_10S[tens++];
		} else {
			day = 0;
			break;
		}
	}

	return day;
}

