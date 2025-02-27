import processing.serial.*;  
Serial myPort;  
String data;
PFont  myFont;  
int distance;
int check=0;
int[] gdistance={0,0,0,0,0,0,0,0,0,0};
int avedistance=0;
int sumdistance=0;
int removal=0;

void setup()
{
size(1366,900); // size of processing window
background(0);// setting background color to black
myPort = new Serial(this, "COM3", 9600);
myPort.bufferUntil('\n');

}


void draw(){
  if ((distance==0)&&(check>10)){
    check=check-10;
  }
  if ((distance>=30)&&(check>0)){
    check=check-1;
  }
  if ((distance>0)&&(distance<30)){
    check=check+1;
  }
    background(0);
    gdistance=splice(gdistance, distance, 0);
    gdistance=shorten(gdistance);
    avedistance=(gdistance[0]+gdistance[1]+gdistance[2]+gdistance[3]+gdistance[4]+gdistance[5]+gdistance[6]+gdistance[7]+gdistance[8]+gdistance[9])/10;

  // Scale the mouseX value from 0 to 640 to a range between 0 and 175
//    float c = map(avedistance*3, 0, width, 0, 400);
  // Scale the mouseX value from 0 to 640 to a range between 40 and 300
//    float d = map(avedistance*3, 0, width, 40,500);
    float d = avedistance*8;
    if (avedistance>=40){
      fill(255, d, 0);
      ellipse(width/2, height/2, 200, 200); 
    }
    else{
      fill(255, d, 0);
      ellipse(width/2, height/2, 800-d, 800-d);
    }
//    fill(255);
//    textSize(100);
//    text(check,820,400);
    
    
    if (check>=500){
      check = 200;
      launch("C:/Users/Simplexity/Desktop/alarm.wav");
      delay(10000);
    }
    
  //  background(0);
//  textAlign(CENTER);
//  fill(255);
//  text(data,820,400);
//  text(distance, 820, 200);
//  textSize(100);
//  fill(#4B5DCE);
//  text("              Distance :        cm",450,400);
//  noFill();
//  stroke(#4B5DCE);
}


void serialEvent(Serial myPort)
{
 
  data=myPort.readStringUntil('\n');
  if (data != null) {  // Make sure data isn't null
    distance = int(trim(data));  // Convert the string to an integer
}
}
