#ifndef SERIALDATE_H
#define SERIALDATE_H

#include <stdint.h>

typedef uint16_t serialdate;

serialdate SERDATE_10S[4];
serialdate SERDATE_BASEYEAR;
serialdate SERDATE_LEAPSTRIDE;
serialdate SERDATE_YEARDAYS;
serialdate SERDATE_MONTHDAYS[13];
int SERDATE_DATELEN;

serialdate getSerialDate(char* strDate);
serialdate SD_getYear(char *strDate);
serialdate SD_getMonth(char *strDate);
serialdate SD_getDay(char *strDate);

#endif

