#include <Arduino_GigaDisplay_GFX.h>
#include <Arduino_GigaDisplay.h>
GigaDisplay_GFX display; // create the object
GigaDisplayRGB rgb; //create rgb object
#define BLACK		0x0000
#define MAROON		0x8000
#define GREEN		0x0400
#define OLIVE		0x8400
#define NAVY		0x0010
#define PURPLE		0x8010
#define TEAL		0x0410
#define SILVER		0xC618
#define GRAY		0x8410
#define RED			0xF800
#define LIME		0x07E0
#define YELLOW		0xFFE0
#define BLUE		0x001F
#define MAGENTA		0xF81F
#define CYAN		0x07FF
#define WHITE		0xFFFF
int Player_x = 0;
int Player_y = 0;
int current_frame = 1;
void Frame_1(){
  display.fillScreen(OLIVE);
  display.fillRect(0,0,100,100,BLUE);
  if (Player_x >= 800) {
    current_frame =+ 1;
  }
}
void Frame_2(){
  display.fillScreen(RED);
  display.fillRect(0,0,100,100,BLUE);
  if (Player_x >= 800) {
  }
}
void Frame_3(){
  display.fillScreen(CYAN);
  display.fillRect(0,0,100,100,BLUE);
}
void check_Frame() {
  Serial.println(current_frame);
}

void setup() {
  Serial.begin(9600);// Initialize serial communication at 9600 baud rate
  display.begin();//start display
  rgb.begin(); //init the library
  rgb.on(0, 255, 0);
  Frame_1();
  pinMode(22, INPUT); // Set digital pin 22 as an input
  pinMode(23, INPUT);// Set digital pin 23 as an input
  pinMode(12, INPUT);   // Set digital pin 24 as an input
  pinMode(13, INPUT);   // Set digital pin 25 as an input
  display.fillScreen(CYAN);
  delay(500);
  display.fillRect(0,0,100,100,BLUE);
  }

void loop() {
  int old_Player_x = Player_x; // Store the current X position
  int old_Player_y = Player_y; // Store the current Y position
  // Read the valupine from  22 and check if it is HIGH
  

  if (digitalRead(22) == HIGH) {
    Serial.println("down");
    Player_y -= 100; // keep your horizontal style
    display.fillRect(Player_y,Player_x,100,100,BLUE);
    display.fillRect(old_Player_y,old_Player_x,100,100,CYAN);
  }
  if (digitalRead(23) == HIGH) {
    Serial.println("Jump");
    Player_y += 100;
    display.fillRect(old_Player_y,old_Player_x,100,100,CYAN);
    display.fillRect(Player_y,Player_x,100,100,BLUE);
    delay(100); // Print message if the pin is HIGH
  }
  if (digitalRead(12) == HIGH) {
  Serial.println("Backwards");
  Player_x -= 100; // keep your horizontal style
  display.fillRect(old_Player_y,old_Player_x, 100, 100, CYAN); // erase old
  display.fillRect(Player_y,Player_x, 100, 100, BLUE);         // draw new
  delay(100);
  }
  if (digitalRead(13) == HIGH) {
    Serial.println("Forwards");//say forwards
    Player_x += 100;
    display.fillRect(Player_y,Player_x,100,100,BLUE);
    display.fillRect(old_Player_y,old_Player_x,100,100,CYAN);
    delay(100);
  }
}