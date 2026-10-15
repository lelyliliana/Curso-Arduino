# Soluciones desarrolladas de la Unidad 21

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Secuencia desde alerta apagada

29 produce OFF; 30 activa ON; volver a 29 conserva ON; 28 libera OFF. Sin recordar el estado, 29 no podría tener dos respuestas distintas según el recorrido.

## 2. Alcance de simulación

Una entrada controlada comprueba fronteras e histéresis. No demuestra precisión de TMP36, alimentación ni ADC. La prueba física aporta evidencia distinta.

## 3. Mostrar fallo en LCD

Usa un texto explícito como DATO INVALIDO y evita presentar un número anterior como actual. Revisa el mapa de pines antes de integrar. El proyecto base todavía utiliza Serial y LED, no un LCD instalado.

## Caso adicional

Después de una muestra inválida la referencia pone alerta=false y LED HIGH por diagnóstico. Si llega después una muestra válida de 29, la alerta permanece apagada y el LED se apaga. El estado posterior al fallo es una política implementada, no la conservación automática del estado de alerta anterior.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
