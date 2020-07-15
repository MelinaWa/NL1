void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length){ // Übergabewerte für Funktion

  int f1 = 0; // global
  int f2 = 0;
  int f3 = 0;

  if(type == WStype_TEXT){
    if(payload[0] == 'b'){ 
                          

        for(int i = 0; i < length; i++){  
         // An welcher Stelle im Stringt liegt die Begrenzung, zB. b1023t354e // Wo stehen b t und e? 
           if(payload[i] == 'b'){ 
              f1 = i;}
           else if(payload[i] == 't'){
              f2 = i;}
           else if(payload[i] == 'e'){
              f3 = i;}
        }

        int b_length = f2 - f1 - 1;      // Aus wie vielen Zahlen besteht der Helligkeits-& Temp. wert? 
        int t_length = f3 - f2 - 1;  
            
                    // 5-0-1 = 4 // b Wert hat 4 Stellen
                    // 9 - 5 - 1 = 3 // t Wert hat 3 Stellen 
  

        char teststring[f3];              //convert payload data in char array
        for(int i = 0; i < f3; i++){     
          teststring[i] = payload[i];
        }
        char s_brightness[b_length];             //divide data-char-array in two char-arrays
        for(int i = f1+1; i < f2; i++){
          s_brightness[i-1] = teststring[i];    // Helligkeitswert aus Payload Beispiel 1023 wird in s_brightness (string) geschrieben
        }
        char s_temperature[t_length];
        for(int i = f2+1; i < f3; i++){
          s_temperature[i-(f2+1)] = teststring[i]; //  Temp.wert aus Payload Beispiel 354 wird in s_temperature (string) geschrieben
        }

        String st_brightness = String(s_brightness);     //convert char array in string
        String st_temperature = String(s_temperature);     
       
        
        st_brightness.remove(b_length);                   
        st_temperature.remove(t_length);                  // String wird abgeschnitten ab dem Zeichen b_length (um Nullen zu vermeiden)
        

        brightness  = st_brightness.toInt();        
        temperature = st_temperature.toInt();         // konvertiere in Zahlenwerte
        
        Serial.println(st_brightness);
        Serial.println(brightness);
        Serial.println("______________");
        Serial.println(st_temperature);
        Serial.println(temperature);
        Serial.println("_____________________________________________");
        LEDcontrol(brightness,temperature);       

    }
    else if(payload[0] == 't'){   //Schalter ON 
      bool up = true;
      LEDdim(up); // Funktion wird aufgerufen, Übergabewert Up, hochdimmen
      Serial.println("t");      
    }
    else if(payload[0] == 'f'){   //Schalter OFF
      bool up = false;
      LEDdim(up); // runterdimmen
      Serial.println("f");
    }

  }

  
}
