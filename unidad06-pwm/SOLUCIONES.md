# Soluciones razonadas del laboratorio 06

[Volver al laboratorio](LABORATORIO.md)

1.127 por truncamiento.
2. Uno R3 no ofrece PWM hardware en D8.
3. La percepción y el LED no garantizan linealidad.

## Criterio para avanzar

Duty 0..255; brillo cambia. Reducción a 128 limita ciclo de trabajo máximo.

El resultado esperado debe compararse con tu evidencia. Una solución escrita no sustituye la observación del montaje; las pruebas de escritorio validan reglas de software y los resultados eléctricos requieren placa/componentes.

## Entrega mínima

Incluye montaje y referencias, versión de core/bibliotecas, cambio exacto, entrada, esperado, observado y explicación. Para señales periódicas mide al menos varios eventos; para sensores indica fuente, unidad y condiciones de medición. Si utilizaste un pulsador para representar un sensor, decláralo.

## Límite que debes explicar

No alimentes motor desde este pin; necesita driver de Unidad 16.
