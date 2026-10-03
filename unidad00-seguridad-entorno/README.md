# Unidad 00 — Seguridad, materiales y entorno

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Preparar un banco de trabajo, reconocer riesgos de baja tensión, instalar Arduino IDE y distinguir fallos de software, USB y circuito.

# 1. Principio del curso

```text
comprender → revisar → energizar → medir → programar → integrar
```

Nunca uses “conectar hasta que funcione” como método de diagnóstico.

# 2. Material inicial

- Arduino Uno o compatible;
- cable USB **de datos**;
- protoboard;
- jumpers;
- LED;
- resistencias 220–330 Ω;
- pulsadores;
- potenciómetro cercano a 10 kΩ;
- multímetro recomendado.

Antes de usar un módulo nuevo, busca su documentación/pinout.

# 3. Baja tensión no significa riesgo cero

Un cortocircuito puede:
- calentar conductores/componentes;
- dañar reguladores o USB;
- destruir un GPIO;
- deteriorar una batería/fuente.

Este curso no trabaja directamente con red eléctrica doméstica.

# 4. Regla de energía

Antes de cambiar conexiones:
1. desconecta alimentación;
2. modifica;
3. inspecciona;
4. energiza.

Si algo se calienta, huele extraño o se comporta de forma inesperada, desconecta inmediatamente.

# 5. GPIO no es fuente de potencia

Un pin está diseñado principalmente para señales/cargas pequeñas dentro de las especificaciones del microcontrolador.

No conectes directamente:
- motores;
- relés sin etapa apropiada;
- tiras LED;
- cargas de corriente desconocida.

Los límites exactos dependen de placa/microcontrolador. Consulta documentación/datasheet; no diseñes al límite absoluto.

# 6. Protoboard

No todas tienen rieles continuos de extremo a extremo.

Usa continuidad del multímetro con el circuito **sin alimentación** para conocer conexiones internas.

# 7. Multímetro

Antes de medir pregunta:
> ¿quiero voltaje, resistencia/continuidad o corriente?

Voltaje se mide normalmente en paralelo.

Corriente exige insertar el instrumento en el camino y usar borne/rango correctos; una conexión incorrecta puede crear un cortocircuito.

Si todavía no sabes medir corriente con seguridad, no improvises: comienza con voltaje/continuidad.

# 8. Arduino IDE

1. instala Arduino IDE;
2. conecta la placa;
3. selecciona modelo;
4. selecciona puerto;
5. abre un ejemplo;
6. verifica/compila;
7. carga.

# 9. Cable USB

Algunos cables solo cargan.

Si la placa recibe energía pero no aparece como puerto, prueba primero un cable de datos conocido antes de modificar drivers/circuito.

# 10. Tres capas de diagnóstico

**Código:** ¿compila?  
**Comunicación:** ¿placa/puerto/cable permiten cargar?  
**Hardware:** ¿el circuito está conectado correctamente?

No cambies resistencias para resolver un error de sintaxis.

# 11. Primera comprobación

Con la placa sola:
- identifica LED de alimentación;
- identifica LED integrado;
- compila/carga Blink;
- confirma que puedes recuperar la placa a un estado conocido.

# 12. Checklist obligatorio

Antes de energizar una práctica usa [CHECKLIST.md](CHECKLIST.md).

# 13. Práctica guiada

Documenta tu kit:
- componente;
- cantidad;
- tensión nominal si aplica;
- función;
- pinout/fuente de documentación.

# 14. Errores frecuentes
- cable solo carga;
- cambiar circuito energizado;
- motor en GPIO;
- medir corriente como voltaje;
- asumir rieles de protoboard;
- diseñar con límites máximos sin margen.

# 15. Reto
Prepara tu banco y explica qué harías ante: placa no detectada, LED que se calienta y motor que quieres controlar.

# 16. Autoevaluación
1. ¿Baja tensión = imposible dañar?
2. ¿GPIO es fuente de potencia?
3. ¿Cómo comprobar riel?
4. ¿Voltaje se mide cómo?
5. ¿Placa energizada pero sin puerto?
6. ¿Qué tres capas diagnosticar?

# 17. Checklist de dominio
- [ ] Trabajo desenergizado al cablear.
- [ ] Identifico alimentación/GND.
- [ ] Sé usar continuidad/voltaje.
- [ ] Distingo compilación/carga/hardware.
- [ ] Consulto especificaciones.

Continúa con electrónica básica.


---

## Continuar el curso

- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 01 — Electricidad y electrónica básica](../unidad01-electronica-basica/README.md)
