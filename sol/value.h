// Value -- represents a value (doh!)
#ifndef S_VALUE_H_
#define S_VALUE_H_
#include <sol/common.h>

typedef enum {
  // Atoms, value types that are their own values
 _SValueTAtomsBegin,
  SValueTNil,
  SValueTTrue,
  SValueTFalse,
 _SValueTAtomsEnd,

  // Non-atom value types
  SValueTNumber,
  SValueTFunc,
  SValueTOpaque,
} SValueT;

#define SNumberFormat "%f"
typedef double SNumber;

typedef struct {
  union { void* p; SNumber n; } value;
  uint8_t type;
} SValue;

// Atoms
const SValue SValueNil;
const SValue SValueTrue;
const SValue SValueFalse;

// SValue SValueNumber(SNumber v)
#define SValueNumber(v) \
  ((SValue){.type = SValueTNumber, .value = {.n = v}})

#define SValueFunc(v) \
  ((SValue){.type = SValueTFunc, .value = {.p = v}})

#define SValueOpaque(v) \
  ((SValue){.type = SValueTOpaque, .value = {.p = v}})

char* SValueRepr(char* buf, size_t bufsize, SValue* v);

#endif // S_VALUE_H_
