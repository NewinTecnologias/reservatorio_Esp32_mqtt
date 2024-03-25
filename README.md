# Sistema de Monitoramento de Reservatório de Água com ESP32

Este projeto implementa um sistema de monitoramento de nível de água em um reservatório utilizando um ESP32 e um sensor ultrassônico. O sistema é capaz de medir o nível de água no reservatório e enviar as informações para um servidor MQTT para monitoramento remoto.

## Descrição do Projeto

O sistema de monitoramento de reservatório de água consiste em:
- ESP32: responsável pela leitura do sensor ultrassônico e comunicação MQTT.
- Sensor Ultrassônico: utilizado para medir o nível de água no reservatório.
- Servidor MQTT: recebe as informações de nível de água para monitoramento remoto.
- Aplicativo cliente (opcional): aplicativo móvel ou web para visualização dos dados de nível de água em tempo real.

## Funcionalidades

- Medição contínua do nível de água no reservatório.
- Comunicação com um servidor MQTT para envio dos dados de nível de água.
- Possibilidade de visualização remota dos dados de nível de água através de um aplicativo cliente.

## Pré-requisitos

- Placa ESP32 com suporte a Arduino IDE.
- Sensor ultrassônico compatível com Arduino.
- Servidor MQTT (público ou privado) para receber os dados de nível de água.
- Conexão com a internet para comunicação MQTT (opcional).

## Instalação e Configuração

1. Clone o repositório para o seu ambiente de desenvolvimento.
2. Abra o código-fonte do projeto em sua IDE preferida.
3. Conecte os componentes do hardware conforme especificado no esquemático.
4. Configure as credenciais de rede Wi-Fi e do servidor MQTT no código.
5. Compile e faça o upload do código para a placa ESP32.
6. Inicie o sistema de monitoramento e verifique os dados de nível de água sendo enviados para o servidor MQTT.

## Contribuição

Contribuições são sempre bem-vindas! Se você deseja contribuir para este projeto, por favor, siga estas etapas:
1. Fork este repositório.
2. Crie um branch para sua nova funcionalidade (`git checkout -b feature/nova-funcionalidade`).
3. Commit suas alterações (`git commit -am 'Adiciona nova funcionalidade'`).
4. Faça o push para o branch (`git push origin feature/nova-funcionalidade`).
5. Crie um novo Pull Request.

## Autor 
 Elismar Silva 
