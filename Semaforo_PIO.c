#include <stdio.h> //Usada para entrada/saída padrão, como printf()
#include "pico/stdlib.h"   // Biblioteca padrão para GPIO, temporização e comunicação serial.
#include "hardware/timer.h" // Biblioteca para gerenciamento de temporizadores de hardware.

#define LED_PIN_RED 13 //Pino do Led Vermelho
#define LED_PIN_BLUE 12 //Pino do Led Azul - Amarelo no Wokwi e Azul na placa
#define LED_PIN_GREEN 11 //Pino do Led Verde

int estado = 1; // Começa em 1 para alternar para azul primeiro - Pois ja começa no RED
int contador = 0; // Contador de segundos

// Função de callback para alternar o semáforo a cada 3 segundos
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de ativar o próximo estado
    gpio_put(LED_PIN_RED, 0); //Desligando Led vermelho
    gpio_put(LED_PIN_BLUE, 0); //Desligando Led Azul
    gpio_put(LED_PIN_GREEN, 0); //Desligando Led Verde

    // Alterna entre os estados do semáforo
    switch (estado) {
        case 0:
            gpio_put(LED_PIN_RED, 1); // Sinal vermelho - Já está iniciado
            break;
        case 1:
            gpio_put(LED_PIN_BLUE, 1); // Sinal azul - Começa aqui
            break;
        case 2:
            gpio_put(LED_PIN_GREEN, 1); // Sinal verde
            break;
    }
    
    estado = (estado + 1) % 3; // Alterna entre 0, 1 e 2 - %3 para manter nesse intervalor - Estado do Led
    contador = 0; // Reinicia o contador - Reiniciar o contador para 0, afim de manter em 3s - Sempre que altera estado
    printf("Alteração de cor\n"); //Mostra a mensagem da alteração da cor no terminal
    return true; // Mantém o temporizador ativo
}

// Função de callback para contar segundos continuamente
bool second_timer_callback(struct repeating_timer *t) {
    contador++; //Acrescenta o contador
    printf("%d segundos se passaram\n", contador); //Mostra quantos segundos se passaram
    return true; // Mantém o temporizador ativo
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial
    
    // Inicializa os pinos dos LEDs
    gpio_init(LED_PIN_RED); //inicializando red vermelho
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_BLUE); //inicializando red azul
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
    gpio_init(LED_PIN_GREEN); //inicializando red verde
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    // Garante que o LED vermelho inicie ligado - desde o inicio pra não ficar 3 segundos para executar o processo
    gpio_put(LED_PIN_RED, 1);

    struct repeating_timer semaforo_timer; //Controla a mudança de cores a cada 3 segundos
    struct repeating_timer contador_timer; //Conta os segundos continuamente

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &semaforo_timer); //Inicia o temporizador do semáforo
    add_repeating_timer_ms(1000, second_timer_callback, NULL, &contador_timer); //Inicia o temporizador do contador

    while (true) {

    //Livre pra ser feliz kk

    }
    return 0;
}