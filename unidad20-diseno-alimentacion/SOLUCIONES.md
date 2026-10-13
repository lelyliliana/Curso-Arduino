# Soluciones razonadas del laboratorio 20

[Volver al laboratorio](LABORATORIO.md)

1. La referencia cambia con el mismo riel; existe circularidad.
2. En peor caso de alimentación/driver, no solo corriente sin carga.
3. Potencia de motor/servo y lógica, con referencia común cuando requiera diseño.

## Criterio para avanzar

Estimación queda cerca de 5 V porque referencia ADC es ese mismo riel: no permite verificar caída de fuente de forma independiente.

El resultado esperado debe compararse con tu evidencia. Una solución escrita no sustituye la observación del montaje; las pruebas de escritorio validan reglas de software y los resultados eléctricos requieren placa/componentes.

## Entrega mínima

Incluye montaje y referencias, versión de core/bibliotecas, cambio exacto, entrada, esperado, observado y explicación. Para señales periódicas mide al menos varios eventos; para sensores indica fuente, unidad y condiciones de medición. Si utilizaste un pulsador para representar un sensor, decláralo.

## Límite que debes explicar

No es un voltímetro de batería. No energices montajes de potencia sin diseño y protecciones apropiados.
