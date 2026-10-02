# I2C vs SPI

| Aspecto | I2C | SPI |
|---|---|---|
| Señales principales | SDA, SCL | reloj, datos y selección |
| Varios dispositivos | mediante direcciones | mediante selección |
| Cableado | menor | mayor |
| Velocidad típica | depende del modo/dispositivo | puede ser mayor |
| Complejidad | direccionamiento | más líneas/señales |

## No elijas por tabla solamente
La decisión depende de:
- periférico disponible;
- distancia;
- velocidad;
- número de dispositivos;
- pines;
- bibliotecas;
- niveles eléctricos.

## Reto
Compara dos módulos reales, uno I2C y otro SPI, usando sus hojas de datos.
