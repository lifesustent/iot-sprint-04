# SPRINT 04 - ESR1

Apresentação do projeto disponível no [Youtube](https://youtu.be/YmSNocPrCAw?si=PkUVS1eDT4AWCnlK).

## Alunos

- Deivison Pertel – **RM 550803**
- Eduardo Akira Murata – **RM 98713**
- Guilherme Jacob Soares da Costa – **RM 84581**
- Fabrizio El Ajouri Romano – **RM 550410**
- Wesley Souza de Oliveira – **RM 97874**

# Resumo

Este projeto LifeSustent utiliza o Arduino, sensores DHT22, e a comunicação via MQTT para criar um sistema de monitoramento ambiental inteligente. O sistema mede temperatura e umidade em tempo real, exibindo as leituras em um display LCD e transmitindo os dados de maneira eficiente para o Node-RED através do protocolo MQTT.

## Componentes Necessários
- Arduino (qualquer modelo compatível)
- Sensor DHT22 (ou DHT11)
- Display LCD 16x2
- Módulo Wi-Fi (se aplicável)
- Node-RED (ou outro servidor MQTT)

## Bibliotecas Utilizadas

- [ArduinoJson](https://arduinojson.org/): Biblioteca para facilitar a manipulação de dados JSON no Arduino.
  
- [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library): Permite a comunicação com sensores de temperatura e umidade DHT.
  
- [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal): Fornece uma interface para controlar displays LCD.
  
- [PubSubClient](https://pubsubclient.knolleary.net/): Facilita a comunicação MQTT no Arduino, essencial para enviar dados ao Node-RED.


## Configuração de Pinos
**O código faz uso dos seguintes pinos do Arduino:**

- **DHTPIN (Pino do Sensor DHT):** Definido como 5. Conecte o pino de dados do sensor DHT22 a este pino.

- **Pinos do Display LCD (RS, E, D4, D5, D6, D7):** Definidos como 12, 11, 10, 9, 8, 7. Conecte os pinos do display LCD conforme especificado.

- **AlertaTempBaixa e AlertaTempAlta (Pinos de Alerta de Temperatura):** Definidos como 8 e 13, respectivamente. Conecte LEDs ou dispositivos de sinalização a esses pinos.

- **Pinos de Comunicação Serial (TX, RX):** Utilizados para comunicação serial com uma taxa de 9600 bps. Certifique-se de que esses pinos não estejam conectados a nenhum dispositivo durante a programação.

- **Pinos de Comunicação Wi-Fi (se aplicável):** Caso esteja utilizando um módulo Wi-Fi, configure os pinos conforme as especificações do módulo.


## Configuração do Software
1. Defina os valores de `TempBaixa` e `TempAlta` de acordo com os limites desejados para alerta de temperatura.
2. Configure as credenciais Wi-Fi, se aplicável.
3. Certifique-se de ajustar as configurações MQTT para corresponder às do seu servidor.

## Funcionamento
O código realiza as seguintes operações:
1. Inicializa o sensor DHT22, o display LCD e a comunicação MQTT.
2. No loop principal:
   - Lê a temperatura e umidade do sensor DHT22.
   - Serializa esses dados em formato JSON.
   - Envia os dados para o Node-RED (ou servidor MQTT) via Wi-Fi.
   - Exibe as leituras no display LCD e na Serial Monitor.
   - Atualiza os alertas luminosos com base nos limites de temperatura definidos.

## Como Executar o Código

**Antes de começar:**

1. Certifique-se de ter todas as bibliotecas necessárias instaladas conforme a seção "Bibliotecas Utilizadas".

2. Faça as conexões de hardware conforme descrito na seção "Configuração do Hardware".

**Para executar o código:**

1. Abra o arquivo Arduino (.ino) em sua IDE Arduino.

2. Verifique se o tipo de placa e a porta estão configurados corretamente na IDE Arduino.

3. Compile o código para garantir que não haja erros.

4. Faça o upload do código para o seu Arduino.

5. Abra a Serial Monitor da IDE Arduino para monitorar a execução do código. Certifique-se de que a taxa de comunicação serial esteja configurada para 9600 bps.

6. Se estiver utilizando um módulo Wi-Fi, certifique-se de configurar corretamente as credenciais Wi-Fi e as configurações MQTT no código.

7. Alimente o Arduino e observe as leituras de temperatura e umidade sendo exibidas no LCD, na Serial Monitor e enviadas para o Node-RED (ou outro servidor MQTT).

**Observação:** Ajuste os parâmetros do código, como os limites de temperatura (`TempBaixa` e `TempAlta`), de acordo com as necessidades do seu ambiente.

## Personalização
**Você pode personalizar este código alterando os seguintes parâmetros:**

- ***DHTPIN*** e ***DHTTYPE*** para adaptar ao seu sensor DHT específico.
- ***empBaixa*** e ***TempAlta*** para definir os limites de temperatura para os alertas.
- Os textos exibidos no display LCD na função ***setup()***.

## SimulIDE

<img src="/assets/img/SimullDE.jpeg">

## MQTT

<img src="/assets/img/MQTT.jpg">

## NODE-RED

<img src="/assets/img/NODE-RED.jpg">

## *Observação*
*Para mais informações acesse nosso [github](https://github.com/lifesustent/iot-sprint-04.git)
