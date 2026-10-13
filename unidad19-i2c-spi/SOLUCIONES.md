# Soluciones razonadas del laboratorio 19

[Volver al laboratorio](LABORATORIO.md)

1. No: varios dispositivos pueden usar misma dirección.
2. Mantiene controlador AVR en modo master.
3. CS, modo, frecuencia, comandos y niveles según datasheet.

## Criterio para avanzar

I2C encuentra direcciones que ACK; SPI devuelve A5 con puente. Sin puente, MISO flota y respuesta no está definida.

El resultado esperado debe compararse con tu evidencia. Una solución escrita no sustituye la observación del montaje; las pruebas de escritorio validan reglas de software y los resultados eléctricos requieren placa/componentes.

## Entrega mínima

Incluye montaje y referencias, versión de core/bibliotecas, cambio exacto, entrada, esperado, observado y explicación. Para señales periódicas mide al menos varios eventos; para sensores indica fuente, unidad y condiciones de medición. Si utilizaste un pulsador para representar un sensor, decláralo.

## Límite que debes explicar

No son dos protocolos intercambiables; identificar dirección I2C no reemplaza leer ficha.
