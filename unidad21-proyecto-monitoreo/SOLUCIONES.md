# Soluciones razonadas del laboratorio 21

[Volver al laboratorio](LABORATORIO.md)

1. OFF, ON, ON, OFF.
2. La lógica y límites, no el sensor físico.
3. Mensaje ERROR y estado explícito; no conservar valor viejo comoactual.

## Criterio para avanzar

Alerta activa≥30°C y libera≤28°C. Valores fuera de rango dan diagnóstico distinto, nunca temperatura 0 inventada.

El resultado esperado debe compararse con tu evidencia. Una solución escrita no sustituye la observación del montaje; las pruebas de escritorio validan reglas de software y los resultados eléctricos requieren placa/componentes.

## Entrega mínima

Incluye montaje y referencias, versión de core/bibliotecas, cambio exacto, entrada, esperado, observado y explicación. Para señales periódicas mide al menos varios eventos; para sensores indica fuente, unidad y condiciones de medición. Si utilizaste un pulsador para representar un sensor, decláralo.

## Límite que debes explicar

Base ejecutable de monitoreo; gráficos, CSV y humedad se incorporan solo cuando se implementan.
