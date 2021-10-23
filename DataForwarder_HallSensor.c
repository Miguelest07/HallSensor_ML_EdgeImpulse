//ESP32-Arduino IDE// Code written by Jose Miguel Estrada
#define FREQUENCY_HZ 50
#define INTERVAL_MS (1000 / (FREQUENCY_HZ + 1))
#define OFFSET      1900

static const int potPin = 36;
static int x[1024] = {0};
static int onn = 0;
static int st = 0;
static int n = 0;
static int ii = 0;

void SendData(void);

void setup() 
{
    Serial.begin(115200);
    delay(1000);
}

void loop() 
{
    filter();
    SendData();
}

void SendData(void)
{
    static unsigned long last_interval_ms = 0;
    if (millis() > last_interval_ms + INTERVAL_MS) 
    {
        last_interval_ms = millis();
        Serial.println(x[ii]);
        ii++;
        if(ii >= 1024);
        {
          ii = 0;
          onn = 0;
        }
    }
}

void filter(void)
{
  if(onn == 0)
    {
        x[ii] = analogRead(potPin) - OFFSET;//Obtain data and apply offset
        if(x[ii] <150)//noise in data offset filter
        x[ii] = 0;//noise = 0
        ii++;
        if(ii >= 1024)//1024 samples
        {
          onn = 1;
          ii = 0;
        }
    }
}
