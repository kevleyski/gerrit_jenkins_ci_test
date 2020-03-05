// atoi(const char*) - base 10 return int (32-bit)

#include "stdlib.h"
#include "stdio.h"
#include "assert.h"
#include "string.h"

int atoi_s(const uint8_t* in, uint8_t max_buf) {
  assert(in);
  assert(max_buf > 0);

  // other asserts might be max_buf would hold +/- max_int

  uint8_t* str_ptr = (uint8_t*)in;
  uint8_t* str_ptr_sentinel = (uint8_t*)in + max_buf;
  int is_negative = false;

  // Ah also need to check for negative
  if (*str_ptr == '-') {
    is_negative = true;
    str_ptr++; // parse the sign bit so move to number
  }

  // Going to work backwards - find last number character
  while (str_ptr < str_ptr_sentinel) {
    if ((*str_ptr < '0') || (*str_ptr > '9'))
      break;
    str_ptr++;
  }


  int retval = 0;
  int base10_multiply = 1;

  while (str_ptr >= in) {
    if ((*str_ptr >= '0') && (*str_ptr <= '9')) {
      retval += ((*str_ptr) - '0') * base10_multiply;
      base10_multiply *= 10;
    }

    str_ptr--;
  }

  if (is_negative)
    retval = -retval;

  return retval;
}

int atoi(const char* in)
{
  return atoi_s((uint8_t*)in, strlen(in));
}

int main_4(int argc, char *argv[]) {
  // Test
  int out = atoi("-42");

  printf("%d\n", out);
}

