# Unidad 19 — I²C y SPI: buses compartidos

## Qué aprenderás
Elegir entre I²C/SPI a nivel conceptual, verificar niveles y diagnosticar dirección, cableado y selección de dispositivos.

# 1. Por qué un bus

En vez de dedicar muchos pines a cada periférico, varios dispositivos pueden compartir líneas bajo un protocolo.

Compartir líneas no significa conectar cualquier módulo sin analizar compatibilidad eléctrica/protocolo.

# 2. I²C

Usa típicamente:
- SDA: datos;
- SCL: reloj.

Varios dispositivos pueden compartir ambas líneas y se identifican mediante direcciones.

# 3. Pull-ups

I²C usa líneas tipo open-drain/open-collector conceptualmente y necesita resistencias pull-up.

Muchos módulos ya incorporan pull-ups.

Demasiadas resistencias en paralelo pueden producir un valor equivalente demasiado bajo; ninguna puede impedir funcionamiento.

No añadas 4.7 kΩ por costumbre sin revisar el bus.

# 4. Nivel lógico

Las pull-ups determinan hacia qué tensión suben las líneas.

Al mezclar placas/periféricos de 3.3 V y 5 V, comprueba tolerancia y necesidad de level shifting.

Que el módulo se alimente a 5 V no demuestra que SDA/SCL sean seguros a 5 V o 3.3 V: revisa esquema/datasheet.

# 5. Dirección

Dos dispositivos con la misma dirección fija pueden entrar en conflicto.

Soluciones dependen del hardware:
- pin de selección de dirección;
- multiplexor;
- bus adicional;
- otro dispositivo.

No existe una solución solo de software si ambos responden igual en el mismo bus.

# 6. Scanner

Un scanner I²C puede ayudar a detectar direcciones.

Si no encuentra nada, revisa:
- alimentación;
- GND/referencia;
- SDA/SCL;
- pinout;
- pull-ups;
- niveles;
- dirección/bus correcto.

Un scanner no certifica que el sensor funcione correctamente.

# 7. SPI

Usa típicamente:
- SCK;
- MOSI;
- MISO;
- CS/SS por dispositivo.

Los nombres modernos pueden variar (COPI/CIPO, etc.).

# 8. Selección

Varios periféricos pueden compartir reloj/datos y tener líneas CS independientes.

Solo el dispositivo seleccionado debe conducir la línea compartida según protocolo.

# 9. Velocidad/modo

SPI tiene parámetros como:
- frecuencia;
- polaridad/fase (mode);
- orden de bits según dispositivo.

No uses la máxima velocidad de la placa si el periférico/cableado no la soporta.

# 10. I²C vs SPI

**I²C:** menos líneas, direccionamiento, cómodo para varios sensores cercanos.  
**SPI:** más líneas/CS, normalmente mayor rendimiento/control temporal.

La elección depende del periférico y requisitos; a menudo ya viene impuesta por el módulo.

# 11. Cableado físico

Buses rápidos o cables largos pueden degradar señales.

Protoboard/jumpers funcionan para aprendizaje, pero no representan automáticamente un diseño robusto para distancia/ruido industrial.

# 12. Práctica guiada

Con un módulo disponible:
1. identifica interfaz;
2. datasheet;
3. tensión lógica;
4. pines;
5. dirección o CS;
6. ejemplo mínimo;
7. diagnóstico.

# 13. Errores frecuentes
- pull-up añadida automáticamente;
- niveles ignorados;
- dos direcciones fijas iguales;
- scanner = sensor validado;
- SPI a máxima frecuencia por defecto;
- intercambiar SDA/SCL o MOSI/MISO;
- bus largo sin analizar.

# 14. Reto
Diseña un sistema con dos sensores I²C y una pantalla SPI justificando niveles, direcciones, CS y alimentación.

# 15. Autoevaluación
1. ¿Por qué I²C necesita pull-ups?
2. ¿Módulos pueden traerlas?
3. ¿Dos direcciones iguales?
4. ¿Scanner prueba funcionalidad completa?
5. ¿Qué es CS?
6. ¿SPI siempre a máxima velocidad?

# 16. Checklist
- [ ] Interfaz identificada.
- [ ] Niveles compatibles.
- [ ] Pull-ups/direcciones revisadas.
- [ ] SPI mode/frecuencia.
- [ ] Cableado razonable.

Continúa con diseño y alimentación.
