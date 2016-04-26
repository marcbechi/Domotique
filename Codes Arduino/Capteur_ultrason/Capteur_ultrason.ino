#define trigPin 8  
	#define echoPin 9  
	  
	int dist = 0;  
	void setup ()  
	{  
	Serial.begin (9600);  
	  
	pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	}  
	void loop()  
	{  
	long duration, distance;  
	digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10); //Trig déclenché 10ms sur HIGH  
	digitalWrite(trigPin, LOW);  
	  
	  
	// Calcul de l'écho  
	duration = pulseIn(echoPin, HIGH);  
	// Distance proportionnelle à la durée de sortie  
	distance = duration*340/(2*10000); //Vitesse du son théorique  
	  
	dist = distance;  
	  
	Serial.print("distance: ");  
	Serial.print(dist);  
	Serial.println(" cm");  
	delay(1000);  
}  
