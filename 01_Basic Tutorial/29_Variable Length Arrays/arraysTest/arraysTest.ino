
void setup() 
{
  Serial.begin(115200);
  int arrayLength = random(98,100);
  Serial.print("Heap before variable size array: ");
  Serial.println(ESP.getFreeHeap());
  int stackArray[arrayLength];
  Serial.print("Heap after variable size array: ");
  Serial.println(ESP.getFreeHeap());
  Serial.print("Heap before malloc: ");
  Serial.println(ESP.getFreeHeap());

  int * heapArray =(int *) malloc(arrayLength*sizeof(int));
  Serial.print("Heap after malloc: ");
  Serial.println(ESP.getFreeHeap());
  for(int i= 0; i<arrayLength; i++)
  {
    heapArray[i] = i;
    stackArray[i]=i;
    Serial.print(heapArray[i]);
    Serial.print(stackArray[i]);
  }
}

void loop() 
{
  
}
