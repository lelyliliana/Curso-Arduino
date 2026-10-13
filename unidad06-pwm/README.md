# Unidad 06 — PWM: brillo y control proporcional

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Comprender duty cycle, diferenciar PWM de una salida analógica real y controlar una carga pequeña apropiada.

# 1. Qué es PWM

Pulse Width Modulation conmuta una salida entre LOW y HIGH repetidamente.

Cambia cuánto tiempo permanece activa dentro de cada periodo.

# 2. Duty cycle

```text
0%    siempre LOW
25%   activa 1/4 del periodo
50%   activa 1/2
100%  siempre HIGH
```

Para ciertas cargas, el efecto promedio cambia.

# 3. No es un DAC

PWM no genera por sí mismo una tensión DC analógica estable intermedia.

Un multímetro puede mostrar un promedio aproximado, pero la forma real sigue siendo pulsos.

Con filtro/carga apropiada puede obtenerse un comportamiento diferente; eso ya es diseño de señal.

# 4. Pines compatibles

No todos los GPIO soportan PWM por hardware/API de la misma forma.

En un Uno clásico, identifica los pines marcados como PWM y verifica documentación.

No generalices el pin 9 a todas las placas.

# 5. analogWrite

En el Uno clásico, el uso típico:

```cpp
analogWrite(LED, valor);
```

trabaja con valores 0–255 para esa API/configuración tradicional.

Otras placas pueden tener APIs/resoluciones diferentes.

# 6. Ejemplo

```cpp
const int LED = 9;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  for (int brillo = 0;
       brillo <= 255;
       brillo++) {
    analogWrite(LED, brillo);
    delay(5);
  }
}
```

# 7. Potenciómetro → PWM

Entrada Uno clásica:
```text
0–1023
```

Salida PWM tradicional:
```text
0–255
```

Puedes transformar:

```cpp
int pwm = map(
  analogRead(A0),
  0, 1023,
  0, 255
);
```

# 8. Percepción de brillo

La percepción humana del brillo no es lineal.

50% de duty no necesariamente “se ve como la mitad” del brillo.

En proyectos de iluminación puedes usar curvas/gamma si el requisito lo exige.

# 9. Frecuencia

PWM tiene una frecuencia determinada por placa/pin/configuración.

Cambiar timers/frecuencias puede afectar otras funciones/librerías.

No modifiques timers sin comprender qué recursos comparten.

# 10. Motores

Un motor no se conecta al pin PWM.

```text
GPIO PWM → driver/etapa de potencia → motor
```

El GPIO proporciona control; la fuente/driver proporciona potencia.

Lo veremos en Unidad 16.

# 11. Diagnóstico

Usa [README_DIAGNOSTICO.md](README_DIAGNOSTICO.md).

Imprime simultáneamente:
- ADC;
- PWM calculado.

Así separas lectura y salida.

# 12. Ejemplo integrado

Revisa [ejemplos/potenciometro_led.ino](ejemplos/potenciometro_led.ino).

# 13. Práctica guiada

1. fade;
2. potenciómetro;
3. Serial ADC/PWM;
4. limita PWM a 30–200;
5. observa percepción;
6. mide tensión promedio con multímetro y explica por qué no significa una DC pura.

# 14. Errores frecuentes
- PWM = voltaje analógico real;
- cualquier pin;
- 0–255 universal;
- motor directo;
- duty=brillo percibido lineal;
- tocar timers sin analizar.

# 15. Reto
Control de brillo con potenciómetro, rango configurable y diagnóstico Serial.

# 16. Autoevaluación
1. ¿Qué es duty cycle?
2. ¿PWM es DAC?
3. ¿Todos los pines?
4. ¿0–255 universal?
5. ¿Por qué motor necesita driver?
6. ¿50% duty = mitad visual exacta?

# 17. Checklist
- [ ] Comprendo PWM.
- [ ] Elijo pin compatible.
- [ ] Transformo rangos.
- [ ] No alimento cargas grandes.
- [ ] Diagnostico entrada/salida.

Continúa con Monitor Serie.


---


## Laboratorio completo de referencia

Esta unidad incluye [montaje, programas y práctica paso a paso](LABORATORIO.md), [soluciones razonadas](SOLUCIONES.md) y [registro de evidencias](../docs/EVIDENCIAS.md).

**Práctica:** Brillo mediante PWM.

**Alcance:** No alimentes motor desde este pin; necesita driver de Unidad16.

## Continuar el curso

- **Unidad anterior:** [Unidad 05 — Entradas analógicas y ADC](../unidad05-entradas-analogicas/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 07 — Monitor serie y diagnóstico](../unidad07-monitor-serie/README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2006%20%E2%80%94%20PWM%3A%20brillo%20y%20control%20proporcional%20del%20curso%20Arduino%20desde%20cero%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-Arduino%2Ftree%2Fmain%2Funidad06-pwm%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
