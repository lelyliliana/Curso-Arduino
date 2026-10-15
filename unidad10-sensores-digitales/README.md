# Unidad 10 — Sensores digitales

**[Desarrollo paso a paso: Del contacto magnético a una interpretación de estado](DESARROLLO.md)**. Sigue el recorrido del código, las tablas y los experimentos antes de resolver la práctica.

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Integrar sensores con salida discreta comprendiendo alimentación, niveles lógicos, polaridad de activación y límites del módulo.

# 1. Qué entrega

Un sensor digital sencillo puede entregar dos estados:

```text
LOW / HIGH
```

Eso no significa necesariamente:
```text
no detecta / detecta
```

El módulo puede ser activo en LOW.

# 2. Cadena

```text
magnitud/evento físico
→ sensor
→ circuito/módulo
→ nivel lógico
→ digitalRead
→ significado
```

Separa nivel eléctrico de interpretación.

# 3. Antes de conectar

Identifica:
- modelo exacto;
- tensión de alimentación;
- tensión/naturaleza de salida;
- pinout;
- salida push-pull/open collector/open drain si aplica;
- pull-up necesario;
- lógica activa.

No asumas que VCC compatible implica que la salida también sea segura para tu GPIO.

# 4. Código mínimo

```cpp
const int SENSOR = 2;

void setup() {
  pinMode(SENSOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int nivel = digitalRead(SENSOR);
  Serial.println(nivel);
}
```

Primero observa. Después controla actuadores.

# 5. INPUT o INPUT_PULLUP

Depende de la salida del sensor/módulo.

No actives pull-up interno automáticamente si el módulo ya conduce/eleva la señal de otra forma.

Consulta documentación.

# 6. Activo en LOW

Traduce una vez:

```cpp
bool detectado =
  digitalRead(SENSOR) == LOW;
```

El resto del programa trabaja con `detectado`, no con detalles eléctricos.

# 7. Eventos

Un sensor puede permanecer activo durante segundos.

Si quieres contar detecciones, necesitas detectar transición, no sumar en cada loop.

# 8. Ruido/rebote

Sensores mecánicos o módulos cerca del umbral pueden oscilar.

Opciones:
- debounce;
- histéresis en módulo/algoritmo;
- filtro temporal;
según fenómeno.

No apliques la misma solución a todo.

# 9. Seguridad de nivel

Una señal de 5 V puede ser peligrosa para una entrada de 3.3 V en placas que no sean tolerantes.

Arduino es un ecosistema de placas; verifica límites del modelo real.

# 10. Recursos

Realiza [PRACTICA.md](PRACTICA.md) y [ejercicios/README.md](ejercicios/README.md).

# 11. Práctica guiada

Con un sensor disponible:
1. identifica datasheet/pinout;
2. mide alimentación;
3. observa salida por Serial;
4. determina activo HIGH/LOW;
5. traduce a bool semántico;
6. añade LED;
7. elimina delay de la lógica principal.

# 12. Errores frecuentes
- pinout por apariencia;
- VCC = nivel de salida seguro;
- activo HIGH asumido;
- INPUT_PULLUP indiscriminado;
- contar nivel como evento;
- actuar antes de observar.

# 13. Reto
Alarma no bloqueante que cuente eventos válidos y documente nivel eléctrico/estado lógico.

# 14. Autoevaluación
1. ¿HIGH siempre significa detectado?
2. ¿Qué verificar antes de conectar?
3. ¿VCC y output level son lo mismo?
4. ¿Nivel vs evento?
5. ¿Cuándo pull-up?
6. ¿5 V siempre seguro?

# 15. Checklist
- [ ] Modelo/pinout.
- [ ] Alimentación/niveles.
- [ ] Lógica traducida.
- [ ] Eventos correctos.
- [ ] Serial antes de acción.

Continúa con sensores analógicos.


---


## Laboratorio completo de referencia

Esta unidad incluye [montaje, programas y práctica paso a paso](LABORATORIO.md), [soluciones razonadas](SOLUCIONES.md) y [registro de evidencias](../docs/EVIDENCIAS.md).

**Práctica:** Sensor digital de contacto.

**Alcance:** No conectes salida de un módulo activo sin comprobar niveles; esta referencia es contacto seco.

## Continuar el curso

- **Unidad anterior:** [Unidad 09 — millis(), tareas cooperativas y máquinas de estados](../unidad09-tiempo-estados/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 11 — Sensores analógicos, calibración y filtrado](../unidad11-sensores-analogicos/README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2010%20%E2%80%94%20Sensores%20digitales%20del%20curso%20Arduino%20desde%20cero%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-Arduino%2Ftree%2Fmain%2Funidad10-sensores-digitales%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
