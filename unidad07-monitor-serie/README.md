# Unidad 07 — Monitor serie y diagnóstico

**[Desarrollo paso a paso: Construir un diálogo de comandos por Serial](DESARROLLO.md)**. Sigue el recorrido del código, las tablas y los experimentos antes de resolver la práctica.

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Usar comunicación serial como instrumento de observación, formular hipótesis y registrar datos sin alterar innecesariamente el sistema.

# 1. Qué es Serial

La comunicación serial permite intercambiar datos entre la placa y otro sistema, normalmente el computador mediante USB o puerto serie virtual según placa.

```cpp
void setup() {
  Serial.begin(9600);
}
```

El monitor debe usar una configuración de velocidad compatible.

# 2. print y println

```cpp
Serial.print("A0 = ");
Serial.println(valor);
```

println añade final de línea.

Combina etiquetas y valores para que el dato tenga contexto.

# 3. Diagnóstico por pregunta

No imprimas todo. Si preguntas por qué una alarma se activa, registra sensor, umbral y decisión.

Un buen log permite reconstruir la decisión del programa.

# 4. Separar capas

Si un LED no responde a un sensor:

1. imprime sensor;
2. imprime condición calculada;
3. imprime estado deseado;
4. después inspecciona salida física.

Así sabes dónde diverge el sistema.

# 5. Frecuencia de impresión

Serial consume tiempo y utiliza buffers.

Imprimir en cada iteración a gran velocidad puede saturar la salida, hacer ilegible el diagnóstico y alterar temporalmente el comportamiento observado.

Registra a una frecuencia útil.

# 6. Formato y precisión

Puedes imprimir distintos tipos y controlar formato.

Mostrar más decimales de un float no aumenta la precisión real del sensor o ADC.

# 7. Serial Plotter

Permite observar señales numéricas a lo largo del tiempo.

Produce líneas consistentes según el formato esperado por la herramienta que uses.

# 8. Ruido

Si un potenciómetro quieto oscila algunos counts, antes de filtrar pregunta:
- ¿cuánto varía?
- ¿afecta la decisión?
- ¿la entrada está estable?
- ¿es resolución/ruido del sistema?

# 9. Tiempo

Añade millis cuando necesitas saber cuándo ocurrió una lectura:

```cpp
Serial.print(millis());
Serial.print(",");
Serial.println(valor);
```

Esto facilita exportar y analizar.

# 10. Datos sensibles

En proyectos conectados posteriores evita registrar credenciales o tokens.

Es una buena práctica desde ahora.

# 11. Recursos

Usa [GUIA_DIAGNOSTICO.md](GUIA_DIAGNOSTICO.md) y [diagnostico_sensor.ino](ejemplos/diagnostico_sensor.ino).

# 12. Práctica guiada

Potenciómetro:
1. lectura cruda;
2. timestamp;
3. mínimo/máximo;
4. valor calculado;
5. Plotter;
6. quieto vs movimiento.

# 13. Errores frecuentes
- baud incompatible;
- mensajes sin contexto;
- imprimir en cada loop sin criterio;
- más decimales = más precisión;
- cambiar hardware antes de observar;
- filtrar antes de medir ruido.

# 14. Reto
Diseña un formato serial para diagnosticar sensor→decisión→actuador y elimina después los campos que no aporten.

# 15. Autoevaluación
1. ¿Para qué Serial.begin?
2. ¿print/println?
3. ¿Qué registrar?
4. ¿Serial puede afectar timing?
5. ¿Más decimales aumenta precisión?
6. ¿Para qué timestamp?

# 16. Checklist
- [ ] Registro con propósito.
- [ ] Datos contextualizados.
- [ ] Frecuencia razonable.
- [ ] Diagnóstico por capas.
- [ ] Puedo graficar señales.

Continúa con funciones.


---


## Laboratorio completo de referencia

Esta unidad incluye [montaje, programas y práctica paso a paso](LABORATORIO.md), [soluciones razonadas](SOLUCIONES.md) y [registro de evidencias](../docs/EVIDENCIAS.md).

**Práctica:** Comandos y diagnóstico serial.

**Alcance:** Interfaz local de caracteres, no protocolo autenticado ni parser de números.

## Continuar el curso

- **Unidad anterior:** [Unidad 06 — PWM: brillo y control proporcional](../unidad06-pwm/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 08 — Funciones y organización del código](../unidad08-funciones/README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2007%20%E2%80%94%20Monitor%20serie%20y%20diagn%C3%B3stico%20del%20curso%20Arduino%20desde%20cero%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-Arduino%2Ftree%2Fmain%2Funidad07-monitor-serie%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
