# Unidad 03 — Salidas digitales y LED

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Controlar un GPIO como salida, calcular un circuito LED básico y diagnosticar software y conexión por separado.

# 1. Salida digital

Un GPIO configurado como OUTPUT puede establecer niveles lógicos HIGH/LOW dentro de las especificaciones eléctricas de la placa.

No es una fuente de potencia general.

# 2. Circuito

```text
GPIO → resistencia → LED → GND
```

Consulta [CONEXIONES.md](CONEXIONES.md).

La resistencia y el LED están en serie; su orden físico dentro de ese mismo camino puede variar.

# 3. Polaridad

LED típico:
- ánodo;
- cátodo.

La forma/pata larga puede ayudar a identificar, pero verifica el componente real; no dependas de una única pista física si fue cortado/montado.

# 4. Resistencia

Elige el valor mediante:
- tensión de salida aproximada;
- caída del LED;
- corriente objetivo segura;
- límites del GPIO/LED.

```text
R ≈ (Vsalida - Vf_LED) / I
```

Los 220–330 Ω del curso son valores educativos comunes para ciertos LED/Uno, no una ley universal.

# 5. Código

```cpp
const int LED = 8;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);

  digitalWrite(LED, LOW);
  delay(1000);
}
```

# 6. Constante del pin

Nombrar el pin evita números mágicos dispersos.

En proyectos más grandes, el tipo/convención puede refinarse; aquí priorizamos legibilidad.

# 7. Estado inicial

Tras reset, los pines no deben asumirse como salidas activas antes de configurarlos.

Si una carga necesita un estado seguro al arranque, diseña hardware/software considerando ese periodo.

# 8. Diagnóstico

Si no enciende:

**Primero:** ¿el sketch correcto está cargado?  
**Después:** ¿pin del código coincide?  
**Después:** ¿LED orientado?  
**Después:** ¿resistencia/conexiones?  
**Después:** mide nivel del pin respecto a GND si sabes usar el multímetro.

No cambies cinco cosas a la vez.

# 9. LED integrado vs externo

LED_BUILTIN permite comprobar software/placa sin tu circuito externo.

Si integrado funciona y externo no, has reducido el problema hacia cableado/componente/pin.

# 10. Varios LED

Antes de conectar varios, considera corriente total y límites de placa.

No extrapoles “uno funcionó” a docenas de cargas desde GPIO.

# 11. Ejemplo

Revisa [ejemplos/semaforo.ino](ejemplos/semaforo.ino).

# 12. Práctica guiada

1. LED externo;
2. 1 Hz;
3. mide nivel HIGH/LOW;
4. invierte LED con alimentación desconectada y predice;
5. corrige;
6. añade segundo LED.

# 13. Errores frecuentes
- LED sin resistencia;
- polaridad;
- pin diferente;
- GPIO como fuente de potencia;
- asumir HIGH universal;
- depurar software/hardware simultáneamente.

# 14. Reto
Semáforo de tres LED con tabla de estados por fase y cálculo/justificación de resistencias.

# 15. Autoevaluación
1. ¿Qué hace OUTPUT?
2. ¿Por qué resistencia?
3. ¿Cómo calcularla?
4. ¿GPIO alimenta motores?
5. ¿Cómo aislar fallo externo?
6. ¿Qué es estado seguro de arranque?

# 16. Checklist
- [ ] Cableo desenergizado.
- [ ] Resistencia calculada.
- [ ] Pin/código coinciden.
- [ ] Diagnostico por capas.
- [ ] Respeto límites.

Continúa con entradas digitales.


---

## Continuar el curso

- **Unidad anterior:** [Unidad 02 — Conoce Arduino y tu primer programa](../unidad02-primer-programa/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 04 — Entradas digitales y pulsadores](../unidad04-entradas-digitales/README.md)
