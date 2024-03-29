// *****************************
// Example file name : main.cpp
// Description:
// Test file SSD1306_OLED lib, showing hello world for a 128by32 screen
// URL: https://github.com/gavinlyonsrepo/SSD1306_OLED_RPI
// *****************************

// #include <bcm2835.h>
#include <time.h>
#include <stdio.h>
#include "SSD1306_OLED.hpp"

#define myOLEDwidth  128
#define myOLEDheight 32
const uint16_t I2C_Speed = 626; //  bcm2835I2CClockDivider 
const uint8_t I2C_Address = 0x3C;
SSD1306 myOLED(myOLEDwidth ,myOLEDheight) ; // instantiate  an object 

// =============== Function prototype ================
void SetupTest(void);
void TestLoop(void);
void EndTest(void);

// ======================= Main ===================
int main(int argc, char **argv) 
{
	// if(!bcm2835_init())
	// {
	// 	printf("Error 1201: init bcm2835 library\r\n");
	// 	return -1;
	// }
	
	SetupTest();
	TestLoop();
	EndTest();
	
	return 0;
}
// ======================= End of main  ===================

// ===================== Function Space =====================
void SetupTest() 
{
	delay(500);
	printf("OLED Begin\r\n");
	myOLED.OLEDbegin(I2C_Speed, I2C_Address); // initialize the OLED
	myOLED.OLEDFillScreen(0xF0, 0); // splash screen bars
	delay(1000);
}

void EndTest()
{
	myOLED.OLEDPowerDown(); //Switch off display
	// bcm2835_close(); // Close the library
	printf("OLED End\r\n");
}

void TestLoop() 
{

	// Define a buffer to cover whole screen 
	uint8_t  screenBuffer[myOLEDwidth * (myOLEDheight/8)+1]; 
 	myOLED.buffer = (uint8_t*) &screenBuffer;  // set that to library buffer pointer

	myOLED.OLEDclearBuffer();  
	myOLED.setTextColor(WHITE);
	myOLED.setCursor(0, 0);
	myOLED.print("Hello world");
	myOLED.setCursor(0, 7);
	myOLED.print("Page 1");
	myOLED.setCursor(0, 16);
	myOLED.print("12345678912345678");
	myOLED.setCursor(0, 24);
	myOLED.print("Page 3");
	myOLED.OLEDupdate();  //write  buffer
	delay(5000);

}

// ============== EOF =========
