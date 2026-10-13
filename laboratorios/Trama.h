#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
namespace Curso {
inline bool leerTrama(const char *linea, int &valor) {
  if (strncmp(linea, "VAL ", 4) != 0)
    return false;
  const char *p = linea + 4;
  if (!*p)
    return false;
  for (const char *q = p; *q; q++)
    if (*q < '0' || *q > '9')
      return false;
  if (strlen(p) > 4)
    return false;
  long n = strtol(p, nullptr, 10);
  if (n < 0 || n > 1023)
    return false;
  valor = n;
  return true;
}
} // namespace Curso
