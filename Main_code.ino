String apikey ="QF0QD6JZ6WKNRFQY";
const char* server = "api.thingspeak.com";

const char* ssid="arunmukkamla";
const char* password="1234567890";
char res[130];

int led = 13;
int led1 = 12;
char check(char* ex,int timeout)
{
  int i=0;
  int j = 0,k=0;
                                            while (1)
                                            {
                                              sl:
                                                            if(Serial.available() > 0)
                                                            {
                                                              res[i] = Serial.read();
                                                                            if(res[i] == 0x0a || res[i]=='>' || i == 100)
                                                                            {
                                                                              i++;
                                                                              res[i] = 0;break;
                                                                            }
                                                              i++;
                                                            }
                                              j++;
                                              if(j == 30000)
                                              {
                                                k++;
                                                //Serial.println("kk");
                                                j = 0;
                                              }
                                              if(k > timeout)
                                              {
                                               // Serial.println("timeout");
                                                return 1;
                                               }
                                            }//while 1
  if(!strncmp(ex,res,strlen(ex)))
  {
    //Serial.println("ok..");
    return 0;
   }
  else
  {
   // Serial.print("Wrong  ");
   // Serial.println(res);
    i=0;
    goto sl;
   }
}
void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
}

char buff[200];
 int sen1=0,sen2=0,sen3=0;
void setup() {

  char ret;

   pinMode(led, OUTPUT);
   pinMode(led1, OUTPUT);
   digitalWrite(led, LOW);
   digitalWrite(led1, LOW);
   Serial.begin(115200);

   sen1 = analogRead(A0);
  sen2 = analogRead(A1);
  sen3 = analogRead(A2);



   delay(3000);
   serialFlush();

   st:
   digitalWrite(led,LOW);
   Serial.println("ATE0");
   ret = check((char*)"OK",50);
   Serial.println("AT");
   ret = check((char*)"OK",50);

   if(ret != 0){
    delay(100);
    digitalWrite(led,HIGH);
    delay(100);
    //digitalWrite(led1, HIGH);delay(500);digitalWrite(led1, LOW);
    goto st;
   }

    digitalWrite(led, HIGH);delay(500);digitalWrite(led, LOW);
    Serial.println("AT+CWMODE = 1");
    ret  = check((char*)"OK",50);

    connectagain:
    digitalWrite(led, HIGH);delay(500);digitalWrite(led, LOW);
    serialFlush();
    Serial.print("AT+CWJAP=\"");
    Serial.print(ssid);
    Serial.print("\",\"");
    Serial.print(password);
    Serial.println("\"");

    if(check((char*)"OK",300)){
      goto connectagain;
    }
    digitalWrite(led, HIGH);delay(500);digitalWrite(led, LOW);
    Serial.println("AT+CIPMUX=1");
    digitalWrite(led, HIGH);delay(500);digitalWrite(led, LOW);
    digitalWrite(led1, HIGH);//delay(500);digitalWrite(led1, LOW);
}

void loop() {
  serialFlush();
  Serial.println("AT+CIPSTART=4,\"TCP\",\"184.106.153.149\",80");

  if(!check((char*)"Linked",200))
  {
      digitalWrite(led, HIGH);delay(500);digitalWrite(led, LOW);
      serialFlush();
      Serial.println("AT+CIPSEND=4,76");
      if(!check((char*)">",50))
      {
          digitalWrite(led, HIGH);delay(500);digitalWrite(led, LOW);
          sen2 = analogRead(A1)/2;


          serialFlush();
          Serial.print("GET /update?api_key=QF0QD6JZ6WKNRFQY");
          sprintf(buff,"field1=%04u",sen2);
          Serial.print(buff);
          Serial.println("");
          if(!check((char*)"OK",200))
          {
              digitalWrite(led1, HIGH);delay(500);digitalWrite(led1, LOW);

              Serial.println("AT+CIPCLOSE");
          }

      }

    }



}
