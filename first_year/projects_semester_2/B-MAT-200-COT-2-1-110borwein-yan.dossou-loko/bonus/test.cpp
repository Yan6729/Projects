#include "borwein.h"

int re_main (void)
{
 double val = 18.2;
 double val2 = 17;

 string s1 = to_string(val);
 string s2 = to_string(val2);
 string s = to_string(val) + to_string(val2) + "Work";
 printf("%s\n", s.c_str());
 return 0;
}