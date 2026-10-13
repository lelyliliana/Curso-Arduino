# Soluciones razonadas del laboratorio 16

[Volver al laboratorio](LABORATORIO.md)

1. No: depende de carga, motor y pérdidas.
2. Mantiene deshabilitación durante reset antes de setup.
3. Tensión, corriente continua, arranque/bloqueo y térmica, según ficha.

## Criterio para avanzar

Arranque deshabilitado; f/r activan PWM 128; timeout 5 s apaga driver. El programa rechaza nueva dirección mientras activo.

El resultado esperado debe compararse con tu evidencia. Una solución escrita no sustituye la observación del montaje; las pruebas de escritorio validan reglas de software y los resultados eléctricos requieren placa/componentes.

## Entrega mínima

Incluye montaje y referencias, versión de core/bibliotecas, cambio exacto, entrada, esperado, observado y explicación. Para señales periódicas mide al menos varios eventos; para sensores indica fuente, unidad y condiciones de medición. Si utilizaste un pulsador para representar un sensor, decláralo.

## Límite que debes explicar

No conectar red doméstica. El ejemplo no implementa realimentación ni freno certificado.
