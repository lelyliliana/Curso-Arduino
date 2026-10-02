# Práctica — Medición ultrasónica

## Objetivo
Medir distancia mediante tiempo de vuelo.

El ejemplo conceptual supone un módulo compatible con señales utilizadas por Arduino Uno. **Verifica el pinout del módulo real.**

## Secuencia
```text
TRIG: pulso
        ↓
onda ultrasónica → objeto → eco
                         ↓
                     duración
```

## Cálculo conceptual
```text
distancia = duración × velocidad_del_sonido / 2
```

El divisor 2 corresponde al viaje de ida y regreso.

## Pruebas
Mide a distancias conocidas y registra:
| distancia real | medida | error |
|---:|---:|---:|
| | | |

## Limitaciones
Superficies inclinadas, blandas, pequeñas o fuera del rango pueden producir mediciones deficientes.

## Reto
Aplica un filtro sencillo y genera tres zonas: lejos, cerca y alerta.
