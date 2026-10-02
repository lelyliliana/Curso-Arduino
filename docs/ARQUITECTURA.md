# Arquitectura pedagógica

## Enfoque

El curso combina programación y electrónica. Cada práctica debe evitar presentar el código aislado del circuito físico.

## Plantilla de unidad

- Qué aprenderás.
- Componentes.
- Conceptos.
- Conexiones.
- Verificación previa.
- Programa.
- Explicación.
- Prueba.
- Diagnóstico.
- Reto.

## Reglas técnicas

- No alimentar cargas de potencia desde pines GPIO.
- Documentar polaridad cuando exista.
- Indicar resistencias limitadoras en LED.
- Usar etapa de potencia y protección apropiada para motores.
- No trabajar directamente con tensión de red.
- Separar claramente alimentación lógica y de potencia cuando corresponda.
- Explicar masas comunes cuando sean necesarias.
- Evitar enseñar delay() como única estrategia de temporización.
- Favorecer código modular y estados en proyectos que crezcan.

## Progresión

Seguridad → electricidad → placa → E/S digital → analógico/PWM → diagnóstico → programación no bloqueante → sensores → actuadores → buses → integración → proyectos.
