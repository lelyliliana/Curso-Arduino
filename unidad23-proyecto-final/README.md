# Unidad 23 — Proyecto final: sistema embebido reproducible

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Propósito
Diseñar, construir, probar y documentar un prototipo propio aplicando electrónica, programación, medición e integración.

El objetivo no es demostrar cuántos módulos puedes conectar, sino que cada decisión eléctrica, lógica y mecánica tenga sentido.

# Etapa 1 — Problema

Define:
- usuario/contexto;
- necesidad;
- entrada;
- salida;
- criterio de éxito;
- qué queda fuera del alcance.

Evita comenzar por “quiero usar un servo”.

# Etapa 2 — Requisitos

Separa:
- funcionales;
- eléctricos;
- temporales;
- mecánicos;
- seguridad;
- interfaz/diagnóstico.

Hazlos verificables.

# Etapa 3 — Arquitectura

Dibuja bloques:

```text
entradas
  ↓
adquisición/validación
  ↓
estado/decisión
  ↓
salidas
  ↓
mundo físico
```

Añade alimentación y comunicaciones.

# Etapa 4 — Componentes

Para cada elemento registra:
- referencia;
- función;
- tensión;
- niveles lógicos;
- consumo/picos;
- interfaz;
- datasheet/fuente;
- razón de elección.

# Etapa 5 — Presupuesto eléctrico

Calcula:
- reposo;
- operación;
- peor caso razonable.

Incluye motores/servos con arranque o stall cuando corresponda.

Dimensiona fuente, driver, reguladores, cables y conectores.

# Etapa 6 — Tabla de pines

Ejemplo de columnas:
- pin Arduino;
- dispositivo;
- dirección;
- nivel;
- función;
- observaciones.

Detecta conflictos de timers/buses antes de montar.

# Etapa 7 — Estado seguro

Define comportamiento:
- al encender;
- durante reset;
- ante sensor inválido;
- pérdida de comunicación;
- timeout;
- alimentación insuficiente;
- fallo de actuador cuando pueda detectarse.

# Etapa 8 — Prototipos unitarios

Prueba por separado:
1. cada sensor;
2. cada actuador;
3. pantalla;
4. comunicación;
5. fuente/driver.

Conserva sketches mínimos de diagnóstico cuando aporten.

# Etapa 9 — Código

Organiza por responsabilidades:
- lectura;
- validación;
- lógica/estado;
- salida;
- comunicación;
- diagnóstico.

Usa millis cuando haya tareas concurrentes.

# Etapa 10 — Integración incremental

Integra un componente por vez y ejecuta pruebas de regresión básicas después de cada cambio.

Si deja de funcionar, sabrás qué incorporación investigar primero.

# Etapa 11 — Medición

No afirmes:
> la fuente aguanta.

Mide o justifica con especificaciones.

Registra cuando corresponda:
- tensiones;
- corriente;
- temperatura;
- tiempos;
- error de sensores;
- comportamiento bajo carga.

# Etapa 12 — Pruebas

Crea tabla:

```text
caso | condición | esperado | obtenido | resultado
```

Incluye:
- nominal;
- límites;
- repetición;
- arranque/reset;
- entrada inválida;
- fallo seguro.

No provoques fallas eléctricas peligrosas.

# Etapa 13 — Diagnóstico

El sistema debe permitir entender:
- qué leyó;
- qué decidió;
- qué estado tiene;
- qué ordenó;
- qué error detectó.

Serial/pantalla/LED pueden formar parte del diagnóstico.

# Etapa 14 — Reproducibilidad

Otra persona debe poder reconstruir el prototipo sin preguntarte:
- qué pin;
- qué biblioteca;
- qué versión;
- qué fuente;
- qué resistencia;
- qué orientación.

# Etapa 15 — README

Incluye:
1. título/objetivo;
2. foto/diagrama cuando exista;
3. arquitectura;
4. BOM;
5. conexiones;
6. alimentación;
7. software/librerías;
8. funcionamiento;
9. pruebas;
10. fallos/correcciones;
11. limitaciones;
12. mejoras.

# Etapa 16 — Evidencia

Entrega:
- código;
- documentación;
- esquema o tabla de conexiones;
- datasheets/referencias;
- presupuesto;
- resultados de pruebas;
- video/demostración si corresponde.

# Ideas

- estación ambiental;
- sistema de acceso didáctico;
- robot sencillo;
- riego de baja tensión;
- monitor de distancia;
- dispositivo interactivo;
- maqueta automatizada.

# Criterios de calidad

Un proyecto fuerte:
- no conecta cargas fuera de especificación;
- no bloquea sin necesidad;
- distingue dato inválido;
- tiene estados seguros;
- puede diagnosticarse;
- está documentado;
- puede reproducirse.

# Autoevaluación final

1. ¿Puedo explicar cada cable?
2. ¿Sé cuánto consume el peor caso?
3. ¿Sé qué ocurre durante reset?
4. ¿Qué pasa si falla el sensor?
5. ¿Mi código separa responsabilidades?
6. ¿Tengo evidencia de pruebas?
7. ¿Otra persona puede reconstruirlo?
8. ¿Puedo defender por qué elegí cada componente?

# Cierre

> Un prototipo no es una colección de módulos conectados: es un sistema cuyas decisiones eléctricas, lógicas, temporales y mecánicas deben funcionar juntas y poder justificarse.


---

## Continuar el curso

- **Unidad anterior:** [Unidad 22 — Proyecto: sistema automatizado](../unidad22-proyecto-automatizacion/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)

Llegaste a la última unidad. Revisa tu proyecto y la lista de comprobación antes de dar por terminado el curso.
