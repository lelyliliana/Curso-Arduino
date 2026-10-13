# Unidad 22 — Proyecto: sistema automatizado

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Propósito
Tomar decisiones a partir de entradas reales y controlar un actuador con estados, temporización y comportamiento seguro ante fallos.

# 1. Automatizar no es solo un if

Un sistema completo:
- adquiere;
- valida;
- interpreta;
- decide;
- actúa;
- observa/diagnostica.

También debe saber qué hacer cuando la entrada falla.

# 2. Define el proceso

Antes del circuito escribe:
- qué observa;
- qué controla;
- estados;
- eventos;
- transiciones;
- estado seguro.

Una barrera podría tener estados CERRADA, ABRIENDO, ABIERTA, CERRANDO y ERROR.

No copies esos estados si tu problema necesita otros.

# 3. Tabla de estados

Para cada estado documenta:
- entrada esperada;
- salida;
- temporización;
- transición permitida;
- fallo posible.

Esto guía código y pruebas.

# 4. Sensor aislado

Valida primero la entrada sin actuador.

No dejes que un motor o servo complique el diagnóstico inicial.

# 5. Actuador aislado

Prueba:
- alimentación;
- límites;
- driver;
- dirección;
- rango mecánico;
- estado al arrancar.

Todavía sin depender del sensor.

# 6. Alimentación

Si existe motor o servo registra:
- corriente normal;
- pico o stall;
- driver;
- fuente;
- cables;
- referencia de señal;
- disipación.

Observa si aparecen resets al accionar.

# 7. Integración

Une sensor y actuador solo después de validar ambos.

La lógica debe actuar únicamente con una entrada considerada válida.

# 8. Temporización

Usa millis para tiempos de apertura, espera, alarmas y muestreo.

El sistema debe poder atender un botón o detectar un fallo mientras temporiza.

# 9. Estado seguro

Define qué ocurre si:
- sensor inválido;
- timeout;
- comunicación perdida;
- reset;
- límite mecánico;
- dato imposible.

Actuar con información inválida puede ser peor que detenerse.

# 10. Manual y recuperación

Cuando el proyecto lo justifique, incluye una forma segura de detener, resetear o volver a un estado conocido.

No conviertas un override en bypass permanente de protecciones.

# 11. Diagnóstico

El registro debe permitir reconstruir:
- tiempo;
- sensor;
- estado;
- salida;
- error.

No imprimas miles de líneas sin propósito.

# 12. Pruebas normales

Ejecuta:
- ciclo completo;
- varias repeticiones;
- límites;
- cambios rápidos.

# 13. Pruebas de fallo

Provoca de forma segura:
- sensor desconectado;
- lectura inválida;
- condición que no desaparece;
- comando fuera de rango;
- reset.

Nunca provoques un cortocircuito o un bloqueo peligroso como prueba.

# 14. Evidencia

Documenta:
- máquina de estados;
- diagrama eléctrico;
- presupuesto;
- código modular;
- casos de prueba;
- fallos;
- correcciones.

# 15. Ideas

- barrera con servo;
- ventilación simulada;
- iluminación automática;
- alarma de proximidad;
- clasificador didáctico seguro.

# 16. Reto
Implementa al menos tres estados funcionales y un estado de error real, demostrando cómo se recupera.

# 17. Autoevaluación
1. ¿Automatización es solo if?
2. ¿Qué es estado seguro?
3. ¿Sensor y actuador se integran desde el inicio?
4. ¿Por qué millis?
5. ¿Qué probar ante fallo?
6. ¿Override elimina protecciones?

# 18. Checklist
- [ ] Proceso definido.
- [ ] Máquina de estados.
- [ ] Entrada validada.
- [ ] Actuador seguro.
- [ ] Alimentación.
- [ ] Fallos.
- [ ] Recuperación.
- [ ] Evidencia.

Continúa con el proyecto final.


---


## Laboratorio completo de referencia

Esta unidad incluye [montaje, programas y práctica paso a paso](LABORATORIO.md), [soluciones razonadas](SOLUCIONES.md) y [registro de evidencias](../docs/EVIDENCIAS.md).

**Práctica:** Proyecto de iluminación automática local.

**Alcance:** Umbrales requieren caracterización de tuLDR. No usa relé ni detecta todos los fallos eléctricos.

## Continuar el curso

- **Unidad anterior:** [Unidad 21 — Proyecto: sistema de monitoreo](../unidad21-proyecto-monitoreo/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 23 — Proyecto final: sistema embebido reproducible](../unidad23-proyecto-final/README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2022%20%E2%80%94%20Proyecto%3A%20sistema%20automatizado%20del%20curso%20Arduino%20desde%20cero%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-Arduino%2Ftree%2Fmain%2Funidad22-proyecto-automatizacion%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
