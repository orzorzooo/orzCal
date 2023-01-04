#include <Keypad.h>

// const byte ROWS = 4; // four rows
// const byte COLS = 4; // four columns
// char keys[ROWS][COLS] = {
//     {'1', '2', '3', 'A'},
//     {'4', '5', '6', 'B'},
//     {'7', '8', '9', 'C'},
//     {'*', '0', '#', 'D'},
// };
const byte COLS = 4; // four columns
const byte ROWS = 6; // four rows
char keys[ROWS][COLS] = {
    {'A', 'B', 'C', 'D'},
    {'E', '*', '/', '-'},
    {'7', '8', '9', '+'},
    {'4', '5', '6', '+'},
    {'1', '2', '3', '+'},
    {'0', '0', '.', '='}

};

// byte colPins[ROWS] = {33, 25};        // connect to the column pinouts of the keypad
// byte rowPins[COLS] = {18, 5, 17, 16}; // connect to the row pinouts of the keypad

// WORK

byte colPins[COLS] = {18, 5, 17, 16};          // connect to the column pinouts of the keypad
byte rowPins[ROWS] = {33, 25, 26, 27, 14, 12}; // connect to the row pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);