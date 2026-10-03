# Unidad 12 — Distancia por ultrasonido y tiempo de vuelo

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Generar un disparo, medir un pulso de eco con timeout y convertir tiempo a distancia reconociendo limitaciones físicas.

# 1. Principio

Un transductor emite sonido ultrasónico y mide el tiempo hasta recibir un eco.

El recorrido es ida y vuelta:

```text
distancia = velocidad × tiempo / 2
```

# 2. Módulo real

No todos los módulos tienen el mismo:
- pinout;
- alimentación;
- nivel de ECHO;
- temporización;
- rango.

Verifica documentación antes de copiar un circuito.

Especialmente al usar placas de 3.3 V, comprueba si ECHO necesita adaptación de nivel.

# 3. TRIG

Un módulo común puede requerir un pulso corto en TRIG.

La duración exacta debe salir de la hoja de datos del modelo.

No memorices 10 µs como ley universal.

# 4. ECHO

El ancho del pulso representa tiempo de vuelo según el protocolo del módulo.

`pulseIn()` puede medir duración de un nivel:

```cpp
unsigned long duracion =
  pulseIn(ECHO, HIGH, timeoutUs);
```

# 5. Timeout

Sin timeout apropiado, esperar un eco ausente puede bloquear demasiado tiempo el programa.

Si devuelve 0 en el caso correspondiente, interprétalo como medición no obtenida, no como “objeto a 0 cm”.

# 6. Unidades

Si tiempo está en microsegundos y velocidad en m/s, debes convertir unidades coherentemente.

Una aproximación común a temperatura ambiente es cerca de 343 m/s, pero la velocidad del sonido cambia con condiciones, especialmente temperatura.

# 7. Fórmula práctica

Puedes expresar:

```text
d = t × c / 2
```

y hacer explícitas todas las conversiones.

Evita constantes mágicas como “divide por 58” sin saber qué unidades/condiciones representan.

# 8. Geometría

Problemas:
- superficie inclinada refleja fuera del receptor;
- material blando absorbe;
- objeto pequeño;
- zona mínima/máxima;
- ecos múltiples.

Un valor raro no siempre es un bug de código.

# 9. Validación

Define rango físicamente plausible del sensor.

Descarta/marca:
- timeout;
- distancia fuera de rango;
- salto imposible para la aplicación.

No reemplaces silenciosamente una lectura inválida por 0.

# 10. Filtrado

Mediana de varias lecturas puede ayudar con outliers.

Pero respeta el intervalo mínimo recomendado entre disparos para no mezclar ecos.

# 11. Recursos

Realiza [PRACTICA.md](PRACTICA.md) y [ejercicios/README.md](ejercicios/README.md).

# 12. Práctica guiada

Mide objetos a distancias conocidas:
1. 10 muestras;
2. promedio/mediana;
3. error absoluto;
4. error relativo cuando tenga sentido;
5. prueba superficie inclinada.

# 13. Errores frecuentes
- ECHO conectado sin revisar nivel;
- pulseIn sin timeout;
- timeout = 0 cm;
- constante mágica sin unidades;
- ignorar geometría;
- disparar demasiado rápido.

# 14. Reto
Sensor con timeout, validación, mediana y alerta por umbral con histéresis.

# 15. Autoevaluación
1. ¿Por qué dividir por 2?
2. ¿TRIG universal?
3. ¿Para qué timeout?
4. ¿0 siempre es 0 cm?
5. ¿Qué afecta velocidad del sonido?
6. ¿Por qué superficie inclinada falla?

# 16. Checklist
- [ ] Pinout/niveles verificados.
- [ ] Timeout.
- [ ] Unidades explícitas.
- [ ] Lecturas inválidas separadas.
- [ ] Limitaciones físicas reconocidas.

Continúa con sensores ambientales.


---

## Continuar el curso

- **Unidad anterior:** [Unidad 11 — Sensores analógicos, calibración y filtrado](../unidad11-sensores-analogicos/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 13 — Temperatura, humedad y sensores ambientales](../unidad13-temperatura-ambiente/README.md)
