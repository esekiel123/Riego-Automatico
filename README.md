# Proyecto de Riego Automático

Este proyecto utiliza un ESP32 para controlar un sistema de riego automático. El ESP32 está programado para encender una bomba de agua en intervalos regulares, asegurando que tus plantas reciban la cantidad adecuada de agua.

## Requisitos

- [ESP32](https://www.espressif.com/en/products/hardware/esp32/overview) (u otro microcontrolador compatible)
- Relé de 5V
- Bomba de agua
- Fuente de alimentación para la bomba de agua
- Memoria EEPROM (opcional)
- Conexiones eléctricas y cables adecuados
- Plataforma de desarrollo Arduino IDE

## Esquema de Conexiones

![Esquema de Conexiones](conexion_esp32_bomba.png)

- **ESP32 (GPIO 4)** -> **Entrada del relé (IN)**
- **ESP32 (GND)** -> **GND del relé**
- **Relé (OUT)** -> **Alimentación de la bomba (positivo rojo)**
- **Relé (GND)** -> **GND de la bomba (negativo negro)**
- **Fuente de Alimentación de la bomba** -> **Alimentación de la bomba (positivo rojo y negativo negro)**
- **Tierra Común (GND)** -> **Conexión entre GND de ESP32, relé y fuente de alimentación de la bomba**

> Asegúrate de proporcionar la fuente de alimentación adecuada para la bomba de agua, ya que las bombas suelen requerir una fuente de alimentación más potente que la que puede proporcionar directamente el ESP32.

## Uso

1. Carga el código en el ESP32 utilizando la plataforma de desarrollo Arduino IDE.
2. Asegúrate de que la memoria EEPROM (si se usa) esté configurada correctamente.
3. Conecta todas las conexiones según el esquema anterior.
4. Enciende el ESP32.

El ESP32 controlará automáticamente la bomba de agua, asegurando que se encienda cada 12 horas, contando desde la primera vez que se enciende o la última vez que se encendió.

## Consideraciones de Seguridad

- Ten en cuenta las consideraciones de seguridad al trabajar con dispositivos de alto voltaje como bombas de agua.
- Proporciona la fuente de alimentación adecuada para la bomba y asegúrate de que el sistema esté correctamente aislado y protegido.

## Contribuciones

¡Las contribuciones son bienvenidas! Si tienes ideas para mejorar este proyecto, siéntete libre de abrir un issue o enviar una solicitud de extracción.

## Licencia

Este proyecto se encuentra bajo la licencia MIT. Consulta el archivo [LICENSE](LICENSE) para obtener más detalles.
