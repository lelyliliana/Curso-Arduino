# Unidad 08 — Funciones y organización del código

## Qué aprenderás
Separar responsabilidades, pasar datos y reducir dependencias ocultas antes de construir sistemas con varios sensores/actuadores.

# 1. Por qué funciones

Un loop de 150 líneas mezcla:
- lectura;
- cálculo;
- decisiones;
- salidas;
- diagnóstico.

Separar funciones permite razonar y probar cada responsabilidad.

# 2. Función sin retorno

```cpp
void encenderLed() {
  digitalWrite(LED, HIGH);
}
```

`void` indica que no retorna un valor.

# 3. Parámetros

```cpp
void escribirLed(int pin, bool activo) {
  digitalWrite(pin, activo ? HIGH : LOW);
}
```

Ahora la función no depende de un único LED global.

# 4. Retorno

```cpp
bool superaUmbral(int lectura, int umbral) {
  return lectura >= umbral;
}
```

Esta función expresa lógica y no toca hardware: es más fácil de razonar/probar.

# 5. Separar entrada, decisión y salida

```text
leerSensor()
→ calcularEstado()
→ aplicarSalida()
→ registrarDiagnostico()
```

No es obligatorio tener exactamente cuatro funciones; la idea es separar motivos de cambio.

# 6. Variables locales

Prefiere una variable local cuando solo una función la necesita.

Las globales son apropiadas para estado/configuración compartida, pero demasiadas crean dependencias ocultas.

# 7. Constantes

```cpp
const int LED = 8;
const int UMBRAL = 600;
```

Evitan números mágicos.

Para proyectos más avanzados existen alternativas como `constexpr`; aquí priorizamos fundamentos claros.

# 8. Paso de parámetros

En C++, los argumentos simples pueden copiarse al pasar por valor.

Objetos/estructuras grandes pueden usar referencias cuando corresponda.

No optimices firmas sin necesidad; primero comprende el contrato.

# 9. Nombre

Mejor:
```text
leerTemperatura()
alarmaActiva()
actualizarLed()
```

que:
```text
hacerCosas()
func1()
procesar()
```

# 10. Comentarios

Malo:
```cpp
i++; // incrementa i
```

Útil:
```cpp
// Se descartan los primeros 3 s para estabilización del sensor.
```

Explica decisiones/limitaciones.

# 11. Recursos

Revisa [semaforo_modular.ino](ejemplos/semaforo_modular.ino) y [ejercicios/README.md](ejercicios/README.md).

# 12. Práctica guiada

Toma un sketch con sensor+LED+Serial y sepáralo en funciones.

Después identifica qué globales pueden convertirse en parámetros/locales.

# 13. Errores frecuentes
- función de 100 líneas;
- todo global;
- función que lee sensor, decide y además imprime;
- nombres genéricos;
- comentarios obvios;
- abstraer cada línea en una función.

# 14. Reto
Reorganiza un semáforo y deja loop como una secuencia comprensible de alto nivel.

# 15. Autoevaluación
1. ¿Qué significa void?
2. ¿Parámetro vs global?
3. ¿Qué hace return?
4. ¿Por qué lógica pura ayuda?
5. ¿Qué comentar?
6. ¿Una función por línea?

# 16. Checklist
- [ ] Responsabilidades claras.
- [ ] Nombres descriptivos.
- [ ] Globales justificadas.
- [ ] Parámetros/retornos.
- [ ] loop legible.

Continúa con tiempo no bloqueante.
