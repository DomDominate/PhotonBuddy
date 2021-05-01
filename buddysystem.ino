const pin_t LED = A5;

void setup()
{
	pinMode(LED, OUTPUT);
	Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", handler);
}


void handler(const char *event, const char *data)
{
    if (strcmp(data,"wave") == 0)
    {
        blink(3, 1000);
    }
    else if (strcmp(data,"pat") == 0)
    {
        blink(5, 300);
    }
}

void blink(int blinks, int delayTime)
{
    for(int i = 0; i < blinks; i++)
    {
        digitalWrite(LED, HIGH);
        delay(delayTime);
        digitalWrite(LED, LOW);
        delay(delayTime);
    }
}