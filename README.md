# serialdate
Provides monotonically incrementing day IDs over any 179-year period starting with a Jan. 1.

This is library, written in C, allows any Gregorian calendar January 1, stringified as YYYYMMDD, to beconsidered "day zero" and then provides monotonically incrementing day IDs for any date thereafter, for up to 179 years. (unsigned 16-bit integer range of days)

* The current source has a hard-coded start date of January 1, 1913.  Change the source for your needs or feel free to fork this repo and make the start year more configurable.
* The count of days is one-based (starts at 1).  So January 1, 1913 is day 1 in the current code.
* The library accounts for the year 2000 leap-year, but doesn't yet account for non-evenly-divisible-by-400 centuries (which are not leap years)

I wrote this to provide a 16-bit date field in a packed structure which I wished to keep as small as possible to help improve CPU cache-locality for arrays of these structures.  The problem space I was dealing with lent itself to algorithms that considered dates as a stream of sorted numbers within such a small time-span.

On any &ast;NIX system with c build tools, simply typing

**make**

in the directory containing the code should build the library and the test program, which will be saved as "testserialdate".  Run testserialdate to see some examples of how the library transforms stringified dates to serial numbers.

Have a look at the source of testserialdate.c to understand how to use the library in your own project.

Enjoy!
