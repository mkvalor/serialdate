# serialdate
Provides monotonically incrementing day IDs over any 179-year period starting with a Jan. 1.

This is library, written in C, allows any Gregorian calendar January 1 to beconsidered "day zero" and then provides monotonically incrementing day IDs for any date thereafter, for up to 179 years. (unsigned 16-bit integer range of days)  The library accounts for leap-years.

I wrote this to provide a 16-bit date field in a packed structure which I wished to keep as small as possible to help improve CPU cache-locality for arrays of these structures.  The problem space I was dealing with lent itself to algorithms that considered dates as a stream of sorted numbers within such a small time-span.
