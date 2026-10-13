#pragma once
#include <math.h>
#include <stdint.h>
namespace Curso {
inline bool transcurrido(uint32_t ahora, uint32_t antes, uint32_t periodo) {
  return uint32_t(ahora - antes) >= periodo;
}
inline uint8_t pwmDesdeAdc(uint16_t raw) {
  if (raw > 1023)
    raw = 1023;
  return (uint32_t(raw) * 255) / 1023;
}
inline bool temperaturaTmp36(uint16_t raw, float referencia, float &t) {
  if (raw > 1023 || !isfinite(referencia) || referencia <= 0)
    return false;
  t = ((raw + 0.5f) * referencia / 1024.0f - 0.5f) * 100.0f;
  return isfinite(t) && t >= -40 && t <= 125;
}
inline bool distanciaCm(uint32_t tiempo, float &cm) {
  if (!tiempo)
    return false;
  cm = tiempo * 0.0343f / 2.0f;
  return cm >= 2 && cm <= 400;
}
inline bool histeresisAlta(float valor, bool anterior, float alto, float bajo) {
  return anterior ? valor > bajo : valor >= alto;
}
struct Boton {
  bool crudo = true, estable = true;
  uint32_t cambio = 0;
  bool actualizar(bool nivel, uint32_t ahora) {
    if (nivel != crudo) {
      crudo = nivel;
      cambio = ahora;
    }
    if (crudo != estable && transcurrido(ahora, cambio, 30)) {
      estable = crudo;
      return !estable;
    }
    return false;
  }
};
} // namespace Curso
