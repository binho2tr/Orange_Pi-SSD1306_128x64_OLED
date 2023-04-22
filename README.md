# Orange Pi  - SSD1306 128x64 OLED Display - C++
<p align="justify"> Foi desenvolvida utilizando o código da biblioteca https://github.com/vansatchen/OPiZero2Plus-ssd1306-i2c com alguma coisa desta outra https://github.com/vadzimyatskevich/SSD1306 .<br> 
A função:<br>
int SSD1306::bcm2835_i2c_write(char* data, int bytes)
<br>
Está com o endereço do i2c mocado no código, assim que tiver tempo faço a correção.
	char *deviceName = (char*)"/dev/i2c-3";
</p>

Para compilar utilizar:
    g++ -Wall -I/include/ -I  -o textGraph  main.cpp SSD1306_OLED.cpp SSD1306_OLED_Print.cpp SSD1306_OLED_graphics.cpp SSD1306_OLED_font.cpp   -L/usr/lib  -l wiringPi
