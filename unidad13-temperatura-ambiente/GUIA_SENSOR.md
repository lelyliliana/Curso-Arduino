# Guía — Integrar un sensor ambiental sin copiar a ciegas

## 1. Identifica el modelo
No escribas solamente "sensor de temperatura". Registra fabricante/modelo.

## 2. Consulta
- tensión;
- protocolo;
- precisión;
- rango;
- tiempo entre lecturas;
- biblioteca recomendada.

## 3. Prueba mínima
Ejecuta primero el ejemplo oficial/de la biblioteca y observa valores.

## 4. Valida
¿La lectura es físicamente plausible?

## 5. Integra
Solo después añade pantalla, alertas o comunicación.

## 6. Maneja fallo
Define qué hará el sistema ante una lectura inválida. No conviertas un error en 0 °C sin distinguirlo.

## Reto
Crea una ficha del sensor utilizado y registra 20 lecturas con intervalo compatible con su documentación.
