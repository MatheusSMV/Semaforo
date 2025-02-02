# Semáforo com LEDs utilizando a Raspberry Pi Pico

Este projeto simula o funcionamento de um semáforo utilizando três LEDs (vermelho, verde e azul) conectados aos pinos GPIO da BitDogLab. O semáforo alterna entre as cores vermelha, azul e verde a cada 3 segundos, com a contagem de tempo sendo exibida a cada segundo no terminal.

## Funcionalidades

- **LEDs de cores (Vermelho, Azul e Verde)**: Representam as cores do semáforo.
- **Temporizador de mudança de estado**: Cada cor do semáforo é alternada a cada 3 segundos.
- **Contador de tempo**: O tempo em segundos é exibido no terminal a cada segundo.

## Componentes Necessários

- Placa BitDogLab - Fornecida pelo EmbarcaTech

## Conexões

- **LED Vermelho**: Conectado ao pino 13 da Placa BitDogLab.
- **LED Azul**: Conectado ao pino 12 da Placa BitDogLab.
- **LED Verde**: Conectado ao pino 11 da Placa BitDogLab.
- **Resistores**: Resistor de 330 Ohms conetados em série, para simulação no Wokwi integrado ao VSCode.

## Funcionamento

### Início:
- O código inicia com o LED vermelho aceso.

### Temporizador de Mudança de Estado:
- A cada 3 segundos, o estado do semáforo é alterado:
  - **Estado 0**: O LED vermelho é aceso, e os LEDs azul e verde são apagados.
  - **Estado 1**: O LED azul é aceso, e os LEDs vermelho e verde são apagados.
  - **Estado 2**: O LED verde é aceso, e os LEDs vermelho e azul são apagados.

- A cada mudança de cor, a mensagem "Alteração de cor" é exibida no terminal.

### Temporizador de Contagem de Tempo:
- O contador incrementa a cada segundo, e a quantidade de segundos passados é exibida no terminal a cada 1 segundo.

## Como Compilar e Carregar o Código

1. **Instale as dependências**:
   Para compilar e carregar o código, você precisará do ambiente de desenvolvimento adequado para a Raspberry Pi Pico. Isso inclui o **Pico SDK**.

2. **Compile o código**:
   Use CMake para compilar o código, como mostrado nos tutoriais do SDK.

3. **Carregue no dispositivo**:
   Após compilar, carregue o código na Raspberry Pi Pico utilizando o método de upload adequado (com o dispositivo em modo de bootloader).

## Autor

Matheus Santos Souza

## Código Base

Professor Ricardo Menezes Prates

## Código Base Obtenção
Código obtido do GitHub disponibilizado pelo própio docente: [GitHubProfessorRicardo](https://github.com/rmprates84/timer_callback.git)
