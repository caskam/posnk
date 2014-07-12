/* Area:	ffi_call
   Purpose:	Check structures with fastcall/thiscall convention.
   Limitations:	none.
   PR:		none.
   Originator:	From the original ffitest.c  */

/* { dg-do run { target i?86-*-cygwin* i?86-*-mingw* } } */
#include "ffitest.h"

typedef struct
{
  unsigned char uc;
  double d;
  unsigned int ui;
} test_structure_1;

static __attribute__ ((fastcall)) test_structure_1 struct1(test_structure_1 ts)
{
  ts.uc++;
  ts.d--;
  ts.ui++;

  return ts;
}

int main (void)
{
  ffi_cif cif;
  ffi_type *args[MAX_ARGS];
  void *values[MAX_ARGS];
  ffi_type ts1_type;
  ffi_type *ts1_type_elements[4];
  ts1_type.size = 0;
  ts1_type.alignment = 0;
  ts1_type.type = FFI_TYPE_STRUCT;
  ts1_type.elements = ts1_type_elements;
  ts1_type_elements[0] = &ffi_type_uchar;
  ts1_type_elements[1] = &ffi_type_double;
  ts1_type_elements[2] = &ffi_type_uint;
  ts1_type_elements[3] = NULL;
  
  test_structure_1 ts1_arg;
  /* This is a hack to get a properly aligned result buffer */
  test_structure_1 *ts1_result = 
    (test_structure_1 *) malloc (sizeof(test_structure_1));
  
  args[0] = &ts1_type;
  values[0] = &ts1_arg;
  
  /* Initialize the cif */
  CHECK(ffi_prep_cif(&cif, FFI_FASTCALL, 1, 
		     &ts1_type, args) == FFI_OK);
  
  ts1_arg.uc = '\x01';
  ts1_arg.d = 3.14159;
  ts1_arg.ui = 555;

  ffi_call(&cif, FFI_FN(struct1), ts1_result, values);
  
  CHECK(ts1_result->ui == 556);
  CHECK(ts1_result->d == 3.14159 - 1);
 
  free (ts1_result);
  exit(0);
}