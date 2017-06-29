#include <msp430.h>

int main(){
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= BIT0;                            // Set P1.0 to output direction

  while (true){
      volatile unsigned int i;

      P1OUT ^= BIT0;

      i=50000;
      do i--;
      while(i!=0);
  }
}

