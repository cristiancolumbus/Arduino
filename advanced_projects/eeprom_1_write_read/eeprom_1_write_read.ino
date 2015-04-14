/*
  EEPROM 
 
 Storaggio di un valore e sucessiva lettura.
 */

#include <EEPROM.h>

// the current address in the EEPROM (i.e. which byte
// we're going to write to next)
int addr = 12;

void setup()
{ 
  Serial.begin(9600);
  Serial.println("Storaggio valore");
  // EEPROM.write(addr, 124); 
  // Eseguire una volta sola, caricare lo sketch
  // e immediatamente commetare e ripetere l'upload.
}

void loop()
{
  Serial.print("Lettura Valore: ");
  Serial.println(EEPROM.read(12)); 
  Serial.flush();
  exit(0) ;
  // need to divide by 4 because analog inputs range from
  // 0 to 1023 and each byte of the EEPROM can only hold a
  // value from 0 to 255.
  int val = analogRead(0) / 4;

  // write the value to the appropriate byte of the EEPROM.
  // these values will remain there when the board is
  // turned off.
  EEPROM.write(addr, val);

  // advance to the next address.  there are 512 bytes in 
  // the EEPROM, so go back to 0 when we hit 512.
  addr = addr + 1;
  if (addr == 512)
    addr = 0;

  delay(100);
}

