# CJsMB_SDL2
[WIP] C++ SDL2 implementation of JsMB API

## namespace JsMB
"[!]" - doesn't work

### Hooks

- int Main() => 0
- bool Loop() => true

### SDL

- bool createWindow(const char \*title, uint16 width, uint16 height) => true
- void delay(int32 ms)

### Get

- uint16 screenWidth()
- uint16 screenHeight()

### Math

**Using math.h**

- double ctg(double x)
- [!] float random(float min, float max)

### Graphics

- bool setColor(uint8 red, uint8 green, uint8 blue) => true
- [!] bool setBgColor(uint8 red, uint8 green, uint8 blue) => **false**
- bool cls() => true
- bool repaint() => true

### Draw

- bool drawRect(int16 x, int16 y, int16 width, int16 height) => true
- bool fillRect(int16 x, int16 y, int16 width, int16 height) => true
- bool fillScreen(uint8 red, uint8 green, uint8 blue) => true
