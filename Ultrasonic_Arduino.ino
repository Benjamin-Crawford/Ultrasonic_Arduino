//define all pins
#define numSensors 2
int trigPins[numSensors] = {13,6};
int echoPins[numSensors] = {12,5};

void setup() {
    Serial.begin (9600);
    for(int i = 0; i < numSensors; i++){
        pinMode(trigPins[i], OUTPUT);
        pinMode(echoPins[i], INPUT);
    }
}

void loop() {
    long duration1, distance1, duration2, distance2;
    long durations[numSensors];
    long distances[numSensors];

    for(int i = 0; i < numSensors; i++){
        digitalWrite(trigPins[i], LOW);
    }
    delayMicroseconds(2);

    for(int i = 0; i < numSensors; i++){
        digitalWrite(trigPins[i], HIGH);
    }
    delayMicroseconds(10); // Added this line

    for(int i = 0; i < numSensors; i++){
        digitalWrite(trigPins[i], LOW);
        durations[i] = pulseIn(echoPins[i], HIGH);
        distances[i] = (durations[i]/2) / 29.1;
    }

    for(int i = 0; i < numSensors; i++){
        if (distances[i] >= 300 || distances[i] <= 0){
            Serial.print("Sensor ");
            Serial.print(i);
            Serial.print(" Is Out Of Range!\n");
        }
        else {
            Serial.print("Sensor ");
            Serial.print(i);
            Serial.print(": ");
            Serial.print(distances[i]);
            Serial.println(" cm");
        }
    }
    delay(500);
}
