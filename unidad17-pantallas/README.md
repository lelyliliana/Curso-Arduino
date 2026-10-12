# Unidad 17 — Pantallas y visualización local

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Identificar controlador/interfaz, actualizar una pantalla sin bloquear y diseñar información legible en recursos limitados.

# 1. “Pantalla” no identifica el dispositivo

Dos módulos visualmente parecidos pueden usar:
- controladores distintos;
- I²C;
- SPI;
- paralelo;
- tensiones diferentes.

Identifica referencia/controlador antes de instalar una biblioteca.

# 2. Proceso

```text
modelo
→ controlador
→ alimentación/niveles
→ interfaz
→ dirección/pines
→ biblioteca
→ ejemplo mínimo
→ integración
```

# 3. Biblioteca

Elige una biblioteca compatible con:
- controlador;
- resolución;
- interfaz;
- core/placa.

Una librería para SSD1306 no es universal para cualquier OLED.

# 4. Memoria

Algunas bibliotecas mantienen framebuffer en RAM.

En microcontroladores pequeños, una pantalla puede consumir una fracción importante de memoria.

Revisa requisitos.

# 5. Actualización

No redibujes todo miles de veces por segundo si los datos cambian una vez por segundo.

Actualiza:
- cuando cambia información;
- o a una frecuencia de interfaz razonable.

Esto reduce tráfico y trabajo.

# 6. Separar dato/presentación

```text
leer sensor
→ estado
→ formatear
→ mostrar
```

La pantalla no debería convertirse en la fuente de verdad del sistema.

# 7. Unidades

Muestra:

```text
Temp: 24.3 °C
Hum: 61 %
Estado: NORMAL
```

Un número sin unidad/contexto obliga a adivinar.

# 8. Valores inválidos

Si sensor falla, no mantengas silenciosamente el último valor como si fuera actual.

Puedes mostrar:
```text
Temp: --.- °C
SENSOR ERROR
```

según diseño.

# 9. Parpadeo

Redibujar/borrar continuamente puede producir flicker en algunas pantallas/librerías.

Actualiza regiones o buffer según API y necesidad.

# 10. I²C/SPI

La pantalla puede compartir bus con sensores.

Direcciones, chip select, velocidad y compatibilidad importan; se profundizan en Unidad 19.

# 11. Práctica guiada

1. ejemplo mínimo;
2. texto fijo;
3. dos variables;
4. estado;
5. lectura inválida;
6. actualización cada intervalo con millis.

# 12. Errores frecuentes
- biblioteca por apariencia;
- controlador equivocado;
- redibujar en cada loop;
- olvidar RAM;
- dato sin unidad;
- conservar valor viejo tras fallo;
- pantalla como estado.

# 13. Reto
Panel no bloqueante de dos sensores con estado de error y actualización solo cuando corresponda.

# 14. Autoevaluación
1. ¿Pantallas iguales usan mismo driver?
2. ¿Por qué revisar RAM?
3. ¿Actualizar cada loop?
4. ¿Qué mostrar ante dato inválido?
5. ¿Pantalla es fuente de verdad?
6. ¿Por qué unidades?

# 15. Checklist
- [ ] Controlador identificado.
- [ ] Biblioteca compatible.
- [ ] Memoria considerada.
- [ ] Actualización razonable.
- [ ] Errores visibles.

Continúa con comunicación serial.


---

## Continuar el curso

- **Unidad anterior:** [Unidad 16 — Motores DC, drivers y etapa de potencia](../unidad16-motores-dc/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 18 — Comunicación serial entre dispositivos](../unidad18-comunicacion-serial/README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2017%20%E2%80%94%20Pantallas%20y%20visualizaci%C3%B3n%20del%20curso%20Arduino%20desde%20cero%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-Arduino%2Ftree%2Fmain%2Funidad17-pantallas%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
