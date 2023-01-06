#ifndef display_h
#define display_h
#include <U8g2lib.h>
// U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/22, /* data=*/21); // ESP32 Thing, HW I2C with pin remapping
// U8G2_SSD1309_128X64_NONAME2_1_HW_I2C u8g2(U8G2_R0); // ESP32 Thing, HW I2C with pin remapping
U8G2_SSD1309_128X64_NONAME2_1_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 22, 21);
// U8G2_SSD1309_128X64_NONAME2_1_4W_SW_SPI(U8G2_R0, clock, data, cs, dc [, reset]) [page buffer, size = 128 bytes]
void displayInit()
{
	// 顯示
	u8g2.begin();
	u8g2.enableUTF8Print(); // enable UTF8 support for the Arduino print() function
	// u8g2.setFont(u8g2_font_unifont_t_chinese2); // use chinese2
	// u8g2.setFont(u8g2_font_callite24_tr); // use chinese2
	u8g2.setFont(u8g2_font_helvB12_tf); // 定義要顯示什麼字型
}

int setCursorY()
{
	int h = u8g2.getMaxCharHeight();
	return h;
}

void showTest()
{
	u8g2.firstPage();
	do
	{
		u8g2.setCursor(0, setCursorY());
		u8g2.println("test");

	} while (u8g2.nextPage());
}

void showNum(String s, int line)
{
	u8g2.setCursor(0, setCursorY() * line);
	u8g2.println(s);
	// u8g2.firstPage();
	// do
	// {
	// 	u8g2.setCursor(0, setCursorY() * line);
	// 	u8g2.println(s);
	// } while (u8g2.nextPage());
}
#endif