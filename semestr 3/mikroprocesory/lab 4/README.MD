# Co musicie ustawić w cube MX
### diodę (PA5) ustawić jako GPIO_output i nazwać jako "LD2"
### USART2 tak jak zwykle z włączonymi przerwaniami
### TIMERY
-TIM2 jako timer do delaya
-TIM3 jako timer do reszty zastosowań
-ustawić prescalery (PSC) zgodnie z zegarem (u mnie 84 MHz ustawiłem 8399) tak aby timer zwiększał się z częstotliwością 10KHz
-włączyć przerwania w obydwu timerach