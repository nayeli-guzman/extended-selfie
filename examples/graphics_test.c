// graphics_test.c

uint64_t FB_START = 2147483648; // 0x80000000
uint64_t DRAW_REGISTER = 2147487744; // FB_START + 4096
uint64_t FB_WIDTH = 64;

void draw_pixel(uint64_t x, uint64_t y, uint64_t color) {
  uint64_t* pixel_addr;
  uint64_t offset;

  offset = (y * FB_WIDTH + x) * 4;
  
  // We need to write to this address.
  // In C*, we can cast integer to pointer.
  pixel_addr = (uint64_t*) (FB_START + offset);
  *pixel_addr = color;
}

void refresh_screen() {
  uint64_t* draw_reg;
  draw_reg = (uint64_t*) DRAW_REGISTER;
  *draw_reg = 1;
}

int main(int argc, char** argv) {
  uint64_t x;
  uint64_t y;
  
  x = 0;
  while (x < 64) {
    y = 0;
    while (y < 64) {
      // Draw a gradient
      // R = x * 4, G = y * 4, B = 0
      // Color = A R G B (or R G B A depending on endianness/format)
      // SDL ARGB8888: A=MSB, B=LSB (on Little Endian?)
      // Let's try simple colors first.
      
      // 0xFFFF0000 = Red (ARGB)
      // 0xFF00FF00 = Green
      // 0xFF0000FF = Blue
      
      if (x < 20)
        draw_pixel(x, y, 4294901760); // Red: FF FF 00 00 (ARGB) -> 4294901760
      else if (x < 40)
        draw_pixel(x, y, 4278255360); // Green: FF 00 FF 00 -> 4278255360
      else
        draw_pixel(x, y, 4278190335); // Blue: FF 00 00 FF -> 4278190335
        
      y = y + 1;
    }
    x = x + 1;
  }
  
  refresh_screen();
  
  return 0;
}
