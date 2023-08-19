// define the pins that will be used for the inputs and outputs
//Input
const int inputPin1 = 4;
const int inputPin2 = 9;
//Output
const int outputPin1 = 12;
const int outputPin2 = 11;
//Variables
int block = 0;
int left = 1;
int right = 1; 
int left_delay = 1;
int right_delay = 1;

void setup() {
  // initialize the input and output pins as inputs and outputs
  pinMode(inputPin1, INPUT);
  pinMode(inputPin2, INPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // read the values of the inputs
  int input1Value = digitalRead(inputPin1);
  int input2Value = digitalRead(inputPin2);
  
  if(input1Value){Serial.print("Input Left \n");}
  if(input2Value){Serial.print("Input Right \n");}

  if(block == 0){
    if(input1Value == HIGH && input2Value == LOW) {
      Serial.print("Output Left \n");
      left = LOW;
      block = 1;
    } else if (input2Value == HIGH && input1Value == LOW) {
        Serial.print("Output Right \n");
        right = LOW;
        block = 1;
    }
  }

  digitalWrite(outputPin1, left);
  digitalWrite(outputPin2, right);
}