# Unidad 04 — Entradas digitales y pulsadores

**[Desarrollo paso a paso: Leer un botón sin multiplicar pulsaciones](DESARROLLO.md)**. Sigue el recorrido del código, las tablas y los experimentos antes de resolver la práctica.

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Leer niveles digitales sin entradas flotantes, usar INPUT_PULLUP y distinguir nivel eléctrico, evento y rebote.

# 1. Entrada digital

```cpp
pinMode(BOTON, INPUT);
int nivel = digitalRead(BOTON);
```

El pin interpreta un nivel como LOW/HIGH según umbrales eléctricos de la placa.

No significa que cualquier voltaje sea seguro: respeta el rango del GPIO.

# 2. Entrada flotante

Un pin INPUT sin una referencia definida puede captar ruido y cambiar aparentemente al azar.

Necesita una estrategia pull-up/pull-down apropiada.

# 3. INPUT_PULLUP

Arduino puede habilitar una resistencia pull-up interna:

```cpp
pinMode(BOTON, INPUT_PULLUP);
```

Con pulsador entre pin y GND:

```text
reposo  → HIGH
pulsado → LOW
```

La lógica queda activa en LOW.

# 4. Circuito

```text
GPIO ─ pulsador ─ GND
  ↑
pull-up interna hacia alimentación lógica
```

No necesitas una resistencia pull-up externa para esta práctica porque usas la interna.

# 5. Código

```cpp
const int BOTON = 2;
const int LED = 8;

void setup() {
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  bool pulsado =
    digitalRead(BOTON) == LOW;

  digitalWrite(
    LED,
    pulsado ? HIGH : LOW
  );
}
```

La variable `pulsado` traduce nivel eléctrico a significado del dominio.

# 6. Nivel vs evento

```text
nivel: el botón está pulsado
evento: el botón acaba de pasar a pulsado
```

Para hacer toggle necesitas detectar transición, no ejecutar cambio durante todo el tiempo que permanece LOW.

# 7. Detección de flanco

Guarda estado anterior:

```cpp
bool anterior = HIGH;
```

y compara lectura actual.

Pero aparece otro fenómeno: rebote.

# 8. Rebote mecánico

Un contacto físico puede oscilar HIGH/LOW varias veces durante pocos milisegundos.

Un solo gesto humano puede producir varios flancos eléctricos.

Soluciones:
- debounce temporal por software;
- hardware apropiado.

No “arregles” con delay largo sin comprender el costo.

# 9. Pulsador de cuatro patas

Muchas unidades tienen pares de patas internamente conectados.

Si lo giras/conectas en la orientación equivocada en protoboard, puede parecer siempre cerrado/abierto.

Comprueba continuidad.

# 10. Diagnóstico

Usa [DIAGNOSTICO.md](DIAGNOSTICO.md).

Antes de controlar LED:
1. imprime lectura por Serial;
2. confirma HIGH/LOW;
3. después conecta la lógica de salida.

Así separas entrada y salida.

# 11. Práctica guiada

1. lectura simple;
2. observa HIGH/LOW;
3. implementa LED mientras pulsa;
4. detecta flanco;
5. observa rebote;
6. diseña debounce.

# 12. Errores frecuentes
- INPUT flotante;
- olvidar lógica invertida;
- toggle basado en nivel;
- pulsador mal orientado;
- delay enorme como debounce;
- tensión fuera de rango.

# 13. Reto
Cada pulsación válida alterna el LED exactamente una vez, sin bloquear otras tareas.

# 14. Autoevaluación
1. ¿Qué es flotante?
2. ¿INPUT_PULLUP reposo?
3. ¿Pulsado?
4. ¿Nivel vs evento?
5. ¿Qué es rebote?
6. ¿Por qué imprimir antes de accionar?

# 15. Checklist
- [ ] Entrada con referencia.
- [ ] Comprendo lógica activa-baja.
- [ ] Detecto flancos.
- [ ] Diagnostico por Serial.
- [ ] Considero debounce.

Continúa con analógico.


---


## Laboratorio completo de referencia

Esta unidad incluye [montaje, programas y práctica paso a paso](LABORATORIO.md), [soluciones razonadas](SOLUCIONES.md) y [registro de evidencias](../docs/EVIDENCIAS.md).

**Práctica:** Pulsador con estabilización y estado.

**Alcance:** 30ms es una elección de laboratorio; verifica el pulsador y no confundir evento con nivel sostenido.

## Continuar el curso

- **Unidad anterior:** [Unidad 03 — Salidas digitales y LED](../unidad03-salidas-digitales/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 05 — Entradas analógicas y ADC](../unidad05-entradas-analogicas/README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2004%20%E2%80%94%20Entradas%20digitales%20y%20pulsadores%20del%20curso%20Arduino%20desde%20cero%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-Arduino%2Ftree%2Fmain%2Funidad04-entradas-digitales%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
