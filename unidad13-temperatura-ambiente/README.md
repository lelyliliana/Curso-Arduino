# Unidad 13 — Temperatura, humedad y sensores ambientales

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Integrar una biblioteca/sensor real verificando protocolo, frecuencia de muestreo, validez y plausibilidad de las mediciones.

# 1. No existe “el sensor de temperatura”

Puedes encontrar:
- sensores analógicos;
- sensores de un solo hilo/protocolo propietario;
- I²C;
- SPI;
- módulos que miden varias magnitudes.

Cada uno tiene contrato distinto.

# 2. Proceso universal

```text
identificar modelo
→ datasheet
→ alimentación/niveles
→ protocolo
→ biblioteca
→ ejemplo mínimo
→ validar
→ integrar
```

No empieces copiando un sketch de un sensor visualmente parecido.

# 3. Biblioteca

Antes de instalar:
- identifica autor/procedencia;
- compatibilidad;
- dependencias;
- ejemplo;
- licencia/mantenimiento cuando sea relevante.

Una biblioteca simplifica protocolo; no elimina la necesidad de comprender el sensor.

# 4. Ejemplo mínimo

Ejecuta primero el ejemplo oficial/confiable de lectura.

No mezcles pantalla, Wi‑Fi, relé y sensor antes de confirmar una lectura básica.

# 5. Frecuencia de muestreo

Sensores ambientales pueden requerir tiempo entre mediciones.

Leerlos miles de veces por segundo puede:
- repetir valores;
- producir fallos;
- violar especificación;
- bloquear innecesariamente.

Usa el intervalo del datasheet/biblioteca.

# 6. Datos inválidos

Algunas APIs devuelven NaN, códigos o estados de error.

```cpp
if (isnan(temperatura)) {
  // medición inválida
}
```

La forma exacta depende de la biblioteca.

No conviertas error en 0 °C: cero puede ser una temperatura válida.

# 7. Plausibilidad

Aunque la biblioteca entregue un número, pregunta si es físicamente plausible para el contexto.

Ejemplo conceptual:
- 23 °C puede ser plausible;
- 230 °C en un salón probablemente indica fallo/sensor equivocado.

Los límites deben provenir de aplicación/sensor, no de un ejemplo universal.

# 8. Precisión y resolución

Un sensor que devuelve 23.47 no necesariamente tiene ±0.01 °C de exactitud.

Consulta:
- accuracy;
- resolution;
- repeatability;
- operating range.

# 9. Ubicación

La medición ambiental cambia si el sensor está:
- junto a regulador caliente;
- al sol;
- dentro de caja cerrada;
- cerca de corriente de aire;
- tocado por la mano.

Montaje forma parte del sistema de medición.

# 10. No bloquear

Programa lectura periódica con millis según intervalo permitido.

Entre lecturas, el sistema puede atender botones, alarmas o comunicación.

# 11. Recursos

Usa [GUIA_SENSOR.md](GUIA_SENSOR.md) y [ejercicios/README.md](ejercicios/README.md).

# 12. Práctica guiada

Para tu sensor:
1. registra modelo;
2. datasheet/biblioteca;
3. intervalo mínimo;
4. 20 lecturas;
5. inválidas;
6. mínimo/máximo/promedio;
7. compara con referencia si dispones.

# 13. Errores frecuentes
- librería de sensor parecido;
- leer demasiado rápido;
- error convertido a cero;
- decimales = exactitud;
- integrar todo antes de ejemplo mínimo;
- ignorar ubicación física.

# 14. Reto
Monitor ambiental no bloqueante que marque lecturas inválidas y genere alerta configurable solo con datos válidos.

# 15. Autoevaluación
1. ¿Todos los sensores usan analogRead?
2. ¿Biblioteca reemplaza datasheet?
3. ¿Por qué intervalo?
4. ¿NaN = 0?
5. ¿Resolución = precisión?
6. ¿Ubicación afecta?

# 16. Checklist
- [ ] Modelo/protocolo.
- [ ] Biblioteca confiable.
- [ ] Intervalo correcto.
- [ ] Datos inválidos tratados.
- [ ] Plausibilidad/precisión.

Continúa con buzzer.


---

## Continuar el curso

- **Unidad anterior:** [Unidad 12 — Distancia por ultrasonido y tiempo de vuelo](../unidad12-ultrasonido/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 14 — Buzzer, tono y señales audibles](../unidad14-buzzer/README.md)
