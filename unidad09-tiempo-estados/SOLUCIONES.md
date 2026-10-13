# Soluciones razonadas del laboratorio 09

[Volver al laboratorio](LABORATORIO.md)

1. Evita reiniciar el periodo de la otra.
2. No: un loop cooperativo.
3. Registra timestamps y compara diferencia real con periodo nominal.

## Criterio para avanzar

LED alterna cada 500 ms; muestras cada 200 ms aproximadamente. Con delay largo se retrasan ambas.

El resultado esperado debe compararse con tu evidencia. Una solución escrita no sustituye la observación del montaje; las pruebas de escritorio validan reglas de software y los resultados eléctricos requieren placa/componentes.

## Entrega mínima

Incluye montaje y referencias, versión de core/bibliotecas, cambio exacto, entrada, esperado, observado y explicación. Para señales periódicas mide al menos varios eventos; para sensores indica fuente, unidad y condiciones de medición. Si utilizaste un pulsador para representar un sensor, decláralo.

## Límite que debes explicar

No garantiza tiempo real estricto; Serial también consume tiempo.
