
// Example file name : main.cpp
// Description:
// Test file for SSD1306_OLED library, showing use of various function
//
//  (1) Enable and disable Screen (Sleep mode)
//  (2) Invert screen color
//  (3) Contrast screen
//  (4) Scroll Screen
//  (5) Rotate 
//
// URL: https://github.com/gavinlyonsrepo/SSD1306_OLED_RPI

// #include <bcm2835.h>
#include <time.h>
#include <stdio.h>
#include "SSD1306_OLED.hpp"

#define myOLEDwidth  128
#define myOLEDheight 64
const uint16_t I2C_Speed = 626; //  bcm2835I2CClockDivider 
const uint8_t I2C_Address = 0x3C;
SSD1306 myOLED(myOLEDwidth ,myOLEDheight);

// =============== Function prototypes ================
void setup(void);
void myLoop(void);

// ======================= Main ===================
int main(int argc, char **argv)
{
	// if(!bcm2835_init())
	// {
	// 	printf("Error 1201 : Failure to init bcm2835 library\r\n");
	// 	return -1;
	// }
	delay(50);
	printf("OLED Begin\r\n");
	setup();
	myOLED.setRotation(0);
	myLoop();
	myOLED.OLEDPowerDown();
	// bcm2835_close(); // Close the library,
	printf("OLED End\r\n");
	return 0;
}
// ======================= End of main  =====

// =============== Functions ================
void setup()
{
	myOLED.OLEDbegin(I2C_Speed, I2C_Address); // initialize the OLED
	myOLED.OLEDFillScreen(0x11, 0); // splash screen
	myOLED.setTextColor(WHITE);
	delay(1000);
}

void myLoop()
{
	// Define a full screen buffer and struct
	uint8_t  screenBuffer[myOLEDwidth * (myOLEDheight / 8) ];
	myOLED.buffer = (uint8_t*) &screenBuffer;  // set that to library buffer pointer
	myOLED.OLEDclearBuffer(); // clear the buffer

	// Set text parameters
	myOLED.setTextColor(WHITE);
	myOLED.setTextSize(1);


	//  ** Test1 OLED display enable and disable **
	myOLED.setCursor(0, 30);
	myOLED.print("OLED Disable test 1");
	myOLED.OLEDupdate();

	delay(2000); 
	myOLED.OLEDEnable(0); 
	delay(2000); 
	myOLED.OLEDEnable(1); 
	delay(2000); 
	myOLED.OLEDclearBuffer();

	// ** Test 2 inverse **
	myOLED.setCursor(0, 10);
	myOLED.print("OLED Inverse test 2");
	myOLED.OLEDupdate();
	delay(1500);
	myOLED.OLEDInvert(1); // Inverted
	delay(1500);
	myOLED.OLEDInvert(0);
	delay(1500);

	// ** Test 3 contrast **
	myOLED.OLEDclearBuffer();
	myOLED.setCursor(0, 0);
	myOLED.print("Contrast test 3");
	myOLED.OLEDupdate();
	delay(1500);
	myOLED.OLEDFillScreen(0x77, 0); 
	myOLED.OLEDContrast(0x00);
	delay(1000);
	myOLED.OLEDContrast(0x80);
	delay(1000);
	myOLED.OLEDContrast(0xFF);
	delay(1000);
	myOLED.OLEDContrast(0x81);
	delay(1000);
	myOLED.OLEDclearBuffer();

	// ***** Test 4 Scroll **
	myOLED.setCursor(20,20 );
	myOLED.print("scroll test 4");
	myOLED.OLEDupdate();
	delay(2500);

	myOLED.OLED_StartScrollRight(0, 0x0F);
	delay(3000);
	myOLED.OLED_StopScroll();
	
	myOLED.OLED_StartScrollLeft(0, 0x0F);
	delay(3000);
	myOLED.OLED_StopScroll();

	myOLED.OLED_StartScrollDiagRight(0, 0x07);
	delay(3000);
	myOLED.OLED_StopScroll();
 	
	myOLED.OLED_StartScrollDiagLeft(0, 0x07);
	delay(3000);
	myOLED.OLED_StopScroll();
 	
 	
 	// ** Test 5 rotate test **
 	
 	myOLED.OLEDclearBuffer();
 	
	myOLED.setRotation(1);
	myOLED.OLEDclearBuffer();
	myOLED.print(" rotate 1");
	myOLED.setCursor(5,5 );
	myOLED.OLEDupdate();
	delay(3000);
	
	myOLED.setRotation(2);
	myOLED.OLEDclearBuffer();
	myOLED.print("rotate 2");
	myOLED.setCursor(5,5 );
	myOLED.OLEDupdate();
	delay(3000);
	
	
	myOLED.setRotation(3);
	myOLED.OLEDclearBuffer();
	myOLED.setCursor(5,5 );
	myOLED.print("rotate 3");
	myOLED.OLEDupdate();
	delay(3000);
	
	myOLED.setRotation(0); //default normal 
	myOLED.OLEDclearBuffer();
	myOLED.setCursor(5,5 );
	myOLED.print("rotate 0");
	myOLED.OLEDupdate();
	delay(3000);
	
	// ** end of tests **
	myOLED.OLEDclearBuffer();
	myOLED.setCursor(5, 5);
	myOLED.print("End of tests");
	myOLED.OLEDupdate();
	delay(3000);
}

// =============== EOF ================
