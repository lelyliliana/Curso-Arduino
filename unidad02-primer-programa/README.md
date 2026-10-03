# Unidad 02 — Conoce Arduino y tu primer programa

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Reconocer la placa, comprender setup/loop y distinguir compilación, carga y ejecución.

# 1. Arduino no es solo la placa

El entorno incluye:
- hardware;
- bootloader/firmware de soporte según placa;
- toolchain que compila;
- IDE;
- cable/USB;
- tu sketch.

Un fallo puede pertenecer a capas distintas.

# 2. Reconoce tu placa

En un Arduino Uno clásico identifica:
- microcontrolador;
- USB/interfaz;
- alimentación;
- GND;
- 5 V/3.3 V disponibles según placa;
- pines digitales;
- entradas analógicas;
- LED integrado;
- reset.

No asumas que otra placa tiene el mismo pinout o niveles.

# 3. Sketch

```cpp
void setup() {
}

void loop() {
}
```

`setup()` se ejecuta una vez después del arranque/reset.

`loop()` se repite mientras el programa funciona.

# 4. Primer programa

```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);

  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
```

# 5. Línea por línea

`LED_BUILTIN` identifica el pin del LED integrado según definición de la placa.

`pinMode(..., OUTPUT)` configura el GPIO como salida.

`digitalWrite(..., HIGH/LOW)` establece un nivel lógico.

`delay(500)` bloquea aproximadamente 500 ms.

# 6. HIGH y LOW

Son niveles lógicos, no conceptos universales de “5 V y 0 V” para cualquier placa.

En un Uno clásico HIGH se relaciona con su lógica de alimentación; otras familias pueden trabajar a 3.3 V u otros niveles.

Consulta especificaciones antes de conectar señales entre placas.

# 7. Compilar

El compilador transforma/verifica el código para producir el programa de la plataforma.

Un error de compilación puede deberse a:
- sintaxis;
- nombre inexistente;
- librería;
- placa/toolchain.

Todavía no significa que haya un problema eléctrico.

# 8. Cargar

Después de compilar, el programa debe transferirse.

Un fallo de carga puede involucrar:
- cable;
- puerto;
- placa seleccionada;
- permisos/driver;
- puerto ocupado;
- bootloader/interfaz.

Usa [DIAGNOSTICO.md](DIAGNOSTICO.md).

# 9. Ejecutar

Que compile y cargue no garantiza que el comportamiento sea correcto.

Si el LED no responde:
1. confirma LED_BUILTIN/placa;
2. confirma que el sketch cargó;
3. prueba ejemplo conocido;
4. separa software de hardware externo.

# 10. Reset

Reset reinicia la ejecución desde el comienzo.

No borra el sketch almacenado.

# 11. delay

Es perfecto para aprender Blink.

Más adelante veremos por qué bloquea la capacidad de atender otras tareas y lo reemplazaremos cuando el sistema lo requiera.

# 12. Práctica guiada

1. carga Blink;
2. cambia 500→100;
3. crea patrón corto-corto-largo;
4. provoca un error de compilación;
5. corrígelo;
6. selecciona temporalmente un puerto/placa incorrecta solo si puedes hacerlo sin riesgo y observa la diferencia del error.

# 13. Errores frecuentes
- placa/puerto incorrectos;
- cable solo carga;
- confundir compilación con upload;
- pensar HIGH siempre =5 V;
- modificar circuito para arreglar sintaxis;
- creer reset borra programa.

# 14. Reto
Crea un patrón luminoso identificable y explica el recorrido completo código→compilación→carga→ejecución.

# 15. Autoevaluación
1. ¿setup cuántas veces?
2. ¿loop?
3. ¿HIGH siempre 5 V?
4. ¿Compilar/cargar?
5. ¿Reset borra sketch?
6. ¿delay bloquea?

# 16. Checklist
- [ ] Identifico placa.
- [ ] Comprendo sketch.
- [ ] Distingo errores.
- [ ] Cargo Blink.
- [ ] Sé volver a estado conocido.

Continúa con salidas digitales.


---

## Continuar el curso

- **Unidad anterior:** [Unidad 01 — Electricidad y electrónica básica](../unidad01-electronica-basica/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 03 — Salidas digitales y LED](../unidad03-salidas-digitales/README.md)
