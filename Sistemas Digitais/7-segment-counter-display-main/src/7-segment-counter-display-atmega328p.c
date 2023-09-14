#include <util/delay.h>

unsigned const int A = 8; // B
unsigned const int B = 7; // D
unsigned const int C = 4; // D
unsigned const int D = 5; // D
unsigned const int E = 6; // D
unsigned const int F = 9; // B
unsigned const int G = 10;// B
unsigned const int H = 3; // D

unsigned const int PIN_BUTTON = 2;

unsigned int STATE_BUTTON = 0;
unsigned int counter = 0;

void zero(){
  PORTB = 0x03; // 0000 0011 => B;
  PORTD = 0xF4; // 1111 0100 => D;
}

void one(){
  PORTB = 0x00; // 0000 0000  => B;
  PORTD = 0x94; // 01001 0100 => D;
}

void two(){
  PORTB = 0x05; // 0000 0101 => B;
  PORTD = 0xE4; // 1110 0100 => D;
}

void three(){
  PORTB = 0x05; // 0000 0101 => B;
  PORTD = 0xB4; // 1011 0100 => D;
}

void four(){
  PORTB = 0x06; // 0000 0110 => B;
  PORTD = 0x94; // 1001 0100 => D;
}

void five(){  
  PORTB = 0x07; // 0000 0111 => B;
  PORTD = 0x34; // 0011 0100 => D;
}

void six(){
  PORTB = 0x07; // 0000 0111 => B;
  PORTD = 0x74; // 0111 0100 => D;
}

void seven(){
  PORTB = 0x01; // 0000 0111 => B;
  PORTD = 0x94; // 1001 0100 => D;
}

int main(void){
  DDRD = 0xF8;
  DDRB = 0x07;
  
  zero(); // start display with zero;
  
  void (*display_num[8])() = {zero, one, two, three, four, five, six, seven};

  while(1){
    if(PIND & 0x04){ continue; } // the button was not pressed
    
    counter++;
    
    if (counter <= 7) {
      display_num[counter]();
    } else {
      zero();
      counter = 0;
    }
    
    _delay_ms(1000);
  }
  
  return 0;
}