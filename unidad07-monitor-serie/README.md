# Unidad 07 — Monitor serie y diagnóstico

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
