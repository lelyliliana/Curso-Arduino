# Unidad 05 — Entradas analógicas y ADC

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Comprender qué mide analogRead, relacionar cuentas ADC con tensión y reconocer resolución, referencia, ruido y límites.

# 1. Mundo analógico y digital

Una tensión puede variar continuamente dentro de un rango.

El ADC convierte esa tensión a un número discreto.

```text
tensión → ADC → número
```

# 2. Arduino Uno clásico

En el Uno clásico, `analogRead()` usa normalmente un ADC de 10 bits:

```text
0 ... 1023
```

Eso son 1024 niveles.

No generalices este rango a todas las placas Arduino.

# 3. Referencia

La cuenta depende de la tensión de referencia del ADC.

Modelo aproximado:

```text
Vin ≈ lectura × Vref / 1023
```

para el caso clásico correspondiente.

La referencia real y precisión dependen de placa/configuración.

# 4. Nunca excedas rango

Una entrada analógica sigue siendo un pin eléctrico con límites.

No conectes una señal por encima de lo permitido por la placa solo porque “analogRead la medirá”.

Usa acondicionamiento/divisor cuando el diseño lo requiera.

# 5. Potenciómetro

Consulta [CONEXIONES.md](CONEXIONES.md).

```text
extremo → alimentación compatible
cursor  → A0
extremo → GND
```

El cursor entrega una fracción de la tensión entre extremos.

# 6. Código

```cpp
const int POT = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(POT);
  Serial.println(valor);
  delay(100);
}
```

# 7. Porcentaje

```cpp
float porcentaje =
  valor * 100.0 / 1023.0;
```

Usamos punto flotante para evitar truncamiento entero cuando queremos decimales.

También puedes trabajar solo con enteros si el requisito lo permite.

# 8. map

```cpp
int porcentaje =
  map(valor, 0, 1023, 0, 100);
```

`map()` en Arduino trabaja con enteros y no limita automáticamente valores al rango destino.

Si necesitas limitar, estudia `constrain()` y entiende el dato.

# 9. Resolución

Con Vref≈5 V y 10 bits, cada cuenta representa aproximadamente:

```text
5 V / 1024 ≈ 4.88 mV
```

Esto es resolución teórica de cuantización, **no precisión garantizada** del sistema.

# 10. Ruido

La lectura puede variar por:
- fuente;
- cableado;
- sensor;
- interferencia;
- referencia;
- ADC.

No filtres automáticamente todo. Primero mide la variación y decide si afecta la aplicación.

# 11. Muestreo

delay(100) hace la gráfica/Serial manejable, pero bloquea.

Más adelante podrás muestrear periódicamente con millis.

# 12. Práctica guiada

1. lee potenciómetro;
2. registra mínimo/máximo;
3. convierte a porcentaje;
4. estima tensión;
5. compara con multímetro;
6. registra error/diferencia.

# 13. Errores frecuentes
- 0–1023 universal;
- 1023 niveles en vez de 1024;
- resolución = precisión;
- señal fuera de rango;
- map como float/clamp;
- filtrar sin observar ruido.

# 14. Reto
Crea monitor que muestre lectura, porcentaje y tensión estimada, documentando Vref asumida.

# 15. Autoevaluación
1. ¿Qué hace ADC?
2. ¿Por qué 0–1023?
3. ¿Cuántos niveles?
4. ¿Qué es Vref?
5. ¿Resolución = precisión?
6. ¿map limita?

# 16. Checklist
- [ ] Comprendo ADC.
- [ ] Respeto rango eléctrico.
- [ ] Convierto unidades.
- [ ] Distingo resolución/precisión.
- [ ] Observo ruido.

Continúa con PWM.


---

## Continuar el curso

- **Unidad anterior:** [Unidad 04 — Entradas digitales y pulsadores](../unidad04-entradas-digitales/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 06 — PWM: brillo y control proporcional](../unidad06-pwm/README.md)
