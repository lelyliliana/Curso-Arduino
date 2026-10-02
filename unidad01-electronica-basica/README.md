# Unidad 01 — Electricidad y electrónica básica

## Qué aprenderás
Razonar sobre voltaje, corriente, resistencia y potencia antes de conectar componentes.

# 1. Circuito

Para que circule corriente debe existir un camino cerrado y una diferencia de potencial.

Un circuito abierto interrumpe el camino.

Un cortocircuito crea un camino de resistencia muy baja donde no debería existir, pudiendo producir corriente peligrosa para los componentes/fuente.

# 2. Voltaje

Diferencia de potencial eléctrico entre dos puntos.

Se mide en voltios (V).

No digas simplemente que “un punto tiene voltaje” sin referencia; la medición compara puntos.

# 3. Corriente

Flujo de carga.

Se mide en amperios (A), frecuentemente mA en nuestros circuitos.

La carga **demanda** corriente según el circuito; una fuente debe poder suministrarla dentro de sus especificaciones.

# 4. Resistencia

Oposición al paso de corriente.

Se mide en ohmios (Ω).

Las resistencias también tienen tolerancia y potencia nominal.

# 5. Ley de Ohm

```text
V = I × R
I = V / R
R = V / I
```

Aplica al elemento/modelo resistivo bajo las condiciones correspondientes; no todos los componentes se comportan como una resistencia lineal.

# 6. LED + resistencia

Modelo aproximado educativo:

```text
5 V ─ resistencia ─ LED ─ GND
```

Si el LED cae aproximadamente 2 V, quedan cerca de 3 V sobre la resistencia.

Con 330 Ω:

```text
I ≈ 3 V / 330 Ω
I ≈ 0.0091 A
I ≈ 9.1 mA
```

Es una aproximación. La caída real depende del LED/corriente/temperatura.

# 7. Por qué no LED directo

Sin una limitación adecuada, la corriente puede superar valores seguros para LED o pin.

La resistencia limita corriente; no está “para bajar brillo” únicamente.

# 8. Potencia

```text
P = V × I
```

Para una resistencia también puedes derivar relaciones como `P=I²R` o `P=V²/R` cuando aplica.

Comprueba que el componente tenga margen de potencia.

# 9. Serie

En un camino en serie circula la misma corriente por los elementos.

Las caídas de tensión se distribuyen según el circuito.

# 10. Paralelo

Ramas comparten nodos/tensión entre sus extremos.

Las corrientes de ramas contribuyen a la corriente total.

No extrapoles reglas de serie a paralelo.

# 11. Protoboard

Antes de energizar:
- identifica filas conectadas;
- identifica rieles;
- comprueba si están partidos;
- usa continuidad si tienes dudas.

# 12. Multímetro

**Voltaje:** normalmente en paralelo y circuito energizado.  
**Resistencia/continuidad:** circuito desenergizado.  
**Corriente:** instrumento en serie, borne/rango correcto.

Nunca midas resistencia de un circuito energizado.

# 13. Tierra/GND

GND es una referencia eléctrica del circuito, no necesariamente “la Tierra física”.

Cuando dos sistemas intercambian señales suelen necesitar referencia común, salvo diseños con aislamiento.

# 14. Práctica guiada

Calcula corriente LED para 220 Ω, 330 Ω y 1 kΩ usando una caída aproximada dada.

Después mide:
- resistencia;
- tensión de alimentación;
- caída sobre LED/resistencia.

Compara modelo y realidad.

# 15. Ejercicios

Continúa con [ejercicios/README.md](ejercicios/README.md).

# 16. Errores frecuentes
- medir voltaje en serie;
- continuidad con energía;
- LED sin resistencia;
- tratar todo componente con V=IR directamente;
- confundir GND con ausencia absoluta de voltaje;
- ignorar potencia/tolerancia.

# 17. Reto
Diseña en papel un circuito LED, calcula corriente/potencia y justifica la resistencia antes de montarlo.

# 18. Autoevaluación
1. ¿Voltaje se mide entre qué?
2. ¿Qué necesita corriente para circular?
3. ¿Por qué resistencia con LED?
4. ¿Qué cambia serie/paralelo?
5. ¿Cuándo medir continuidad?
6. ¿GND siempre es tierra física?

# 19. Checklist
- [ ] Aplico Ohm.
- [ ] Calculo potencia básica.
- [ ] Distingo serie/paralelo.
- [ ] Uso multímetro con criterio.
- [ ] Reviso antes de energizar.

Continúa con la placa y primer sketch.
