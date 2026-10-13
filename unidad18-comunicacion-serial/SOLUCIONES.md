# Soluciones razonadas del laboratorio 18

[Volver al laboratorio](LABORATORIO.md)

1. No: solo dígitos y 0..1023.
2. Solo recepción/validación del ejemplo.
3. Cada enlace debe tener velocidades compatibles; USB 115200 y software 9600 son distintos.

## Criterio para avanzar

VAL0..1023 aceptado y ACK; formato/rango/longitud inválidos rechazados.

El resultado esperado debe compararse con tu evidencia. Una solución escrita no sustituye la observación del montaje; las pruebas de escritorio validan reglas de software y los resultados eléctricos requieren placa/componentes.

## Entrega mínima

Incluye montaje y referencias, versión de core/bibliotecas, cambio exacto, entrada, esperado, observado y explicación. Para señales periódicas mide al menos varios eventos; para sensores indica fuente, unidad y condiciones de medición. Si utilizaste un pulsador para representar un sensor, decláralo.

## Límite que debes explicar

SoftwareSerial tiene límites de simultaneidad y temporización; no es RS232 ±voltios ni compatible directo 3.3 V.
