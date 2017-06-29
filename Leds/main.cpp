#include <msp430.h>

int main(){
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= BIT0;                            // Set P1.0 to output direction

  const auto toggle = [](auto& p, const auto bit){
      p ^= (BIT0 << bit);
  };

  while (true){

      toggle(P1OUT, !BIT0);

      for (volatile unsigned int i=25000;i!=0;i++){}
  }
}

