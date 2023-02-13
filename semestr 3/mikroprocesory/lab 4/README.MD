# Co musicie ustawić w cube MX
### diodę (PA5) ustawić jako GPIO_output i nazwać jako "LD2"
### USART2 tak jak zwykle z włączonymi przerwaniami
### TIMERY
-TIM2 jako timer do delaya<br>
-TIM3 jako timer do reszty zastosowań<br>
-w obydwóch ustawić źródła zegarów (Clock Source) jako zegar węwnetrzny (Internal Clock)<br>
-ustawić prescalery (PSC) zgodnie z zegarem (u mnie przy 84 MHz zegara ustawiłem 8399) tak aby timer zwiększał się z częstotliwością 10KHz<br>
-włączyć przerwania w obydwu timerach
