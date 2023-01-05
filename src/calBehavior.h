#include <Arduino.h>
#include "display.h"

boolean presentValue = false;
boolean next = false;
boolean final = false;
String num1, num2;
int answer;
char op;
void cal(char key)
{

	if (key && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0'))
	{
		if (presentValue != true)
		{
			num1 = num1 + key;
			int numLength = num1.length();
			u8g2.firstPage();
			do
			{
				u8g2.setCursor(0, 24);
				u8g2.println(num1);

			} while (u8g2.nextPage());

			Serial.println(num1);
		}
		else
		{
			num2 = num2 + key;
			int numLength = num2.length();
			u8g2.firstPage();
			do
			{
				u8g2.setCursor(0, 24);
				u8g2.println(num2);
				final = true;

			} while (u8g2.nextPage());
			Serial.println(num2);
		}
	}

	else if (presentValue == false && key && (key == '/' || key == '*' || key == '-' || key == '+'))
	{
		if (presentValue == false)
		{
			presentValue = true;
			op = key;
			do
			{
				u8g2.setCursor(0, 24);
				u8g2.println(op);

			} while (u8g2.nextPage());
		}
		Serial.println(op);
	}

	else if (final == true && key && key == '=')
	{
		if (op == '+')
		{
			answer = num1.toInt() + num2.toInt();
		}
		else if (op == '-')
		{
			answer = num1.toInt() - num2.toInt();
		}
		else if (op == '*')
		{
			answer = num1.toInt() * num2.toInt();
		}
		else if (op == '/')
		{
			answer = num1.toInt() / num2.toInt();
		}
		Serial.println(answer);
		num1 = "";
		num2 = "";
		// lcd.clear();
		// lcd.setCursor(15,0);
		// lcd.autoscroll();
		// lcd.print(answer);
		// lcd.noAutoscroll();
	}

	else if (key && key == 'C')
	{
		presentValue = false;
		final = false;
		num1 = "";
		num2 = "";
		answer = 0;
		op = ' ';

		u8g2.firstPage();
		do
		{
			u8g2.setCursor(0, 24);
			u8g2.println('0');
			u8g2.setCursor(0, 24);
			u8g2.println("clear");

		} while (u8g2.nextPage());
	}
}