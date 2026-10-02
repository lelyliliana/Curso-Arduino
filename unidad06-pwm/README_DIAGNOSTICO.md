# Diagnóstico — PWM

## El LED solo enciende/apaga
Comprueba que el pin utilizado soporte PWM en tu placa.

## El rango parece extraño
Imprime lectura ADC y valor PWM por Serial.

## Quiero controlar un motor
No conectes el motor directamente al pin PWM. El pin proporciona la **señal de control**; la potencia debe manejarse con una etapa adecuada.

## Concepto
PWM no significa que el pin entregue cualquier voltaje analógico estable. La salida conmuta y el promedio percibido por ciertas cargas cambia.
