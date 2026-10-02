# Unidad 11 — Sensores analógicos, calibración y filtrado

## Qué aprenderás
Convertir una lectura ADC en información útil sin inventar unidades físicas ni ocultar ruido con filtros arbitrarios.

# 1. Cadena de medición

```text
magnitud física
→ transductor
→ señal eléctrica
→ acondicionamiento
→ ADC
→ counts
→ calibración/modelo
→ unidad o decisión
```

Cada etapa puede introducir error.

# 2. Counts no son unidades

```cpp
int lectura = analogRead(A0);
```

Una lectura 612 no significa automáticamente 612 °C, 61.2% o 612 lux.

Necesitas la relación del sensor y del circuito.

# 3. Datasheet

Busca:
- rango;
- función de transferencia;
- tolerancia;
- alimentación;
- tiempo de respuesta;
- condiciones de operación.

Un módulo puede añadir electrónica respecto al sensor desnudo.

# 4. Calibración

Con referencias conocidas puedes relacionar entrada real y lectura observada.

Dos puntos permiten una aproximación lineal, pero muchos sensores no son lineales en todo su rango.

# 5. Modelo lineal

```text
y = m·x + b
```

b representa offset y m escala.

No fuerces este modelo si la física o datasheet define otra relación.

# 6. Promedio

```cpp
long suma = 0;

for (int i = 0; i < N; i++) {
  suma += analogRead(A0);
}

float promedio =
  suma / (float)N;
```

Puede reducir parte del ruido aleatorio, pero añade latencia, suaviza cambios y no corrige sesgo.

# 7. Otros filtros

Una mediana puede ser útil ante valores atípicos impulsivos.

No existe un filtro universal: elige según la señal y el problema.

# 8. Histéresis

Una alarma puede encender por encima de 650 y apagar solo por debajo de 600.

Así evita conmutar repetidamente cerca de un único umbral cuando existe ruido.

# 9. Saturación

Si siempre lees cerca de 0 o del máximo ADC, investiga:
- rango;
- cableado;
- saturación;
- referencia.

No calibres una señal saturada como si fuera válida.

# 10. Incertidumbre

Considera resolución, tolerancia, referencia, ruido y calibración.

Mostrar muchos decimales no aumenta exactitud.

# 11. Recursos

Realiza [PRACTICA.md](PRACTICA.md) y [ejercicios/README.md](ejercicios/README.md).

# 12. Práctica guiada

Toma 20 muestras y calcula promedio, mínimo, máximo y rango pico a pico.

Aplica después un filtro y compara su respuesta ante un cambio rápido.

# 13. Errores frecuentes
- counts = unidad;
- promedio corrige calibración;
- filtro sin observar;
- demasiados decimales;
- ignorar saturación;
- umbral único con ruido.

# 14. Reto
Sistema de medición con calibración documentada, filtro justificado e histéresis.

# 15. Autoevaluación
1. ¿ADC count es unidad física?
2. ¿Qué aporta calibración?
3. ¿Promedio corrige sesgo?
4. ¿Qué es histéresis?
5. ¿Qué indica saturación?
6. ¿Decimales = precisión?

# 16. Checklist
- [ ] Cadena de medición.
- [ ] Datasheet.
- [ ] Calibración.
- [ ] Filtro justificado.
- [ ] Incertidumbre reconocida.

Continúa con ultrasonido.
