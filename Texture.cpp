#include "Texture.h"
#include <fstream>

Texture::Texture(const char* fname) {
  //Open the bitmap
  std::ifstream fin(std::string("Textures/") + fname, std::ios::in | std::ios::binary);
  if (!fin) {
    texId = 0;
    return;
  }

  //Read the bitmap
  char input[54];
  fin.read(input, 54);
  const GLsizei width = *reinterpret_cast<int32_t*>(&input[18]);
  const GLsizei height = *reinterpret_cast<int32_t*>(&input[22]);
  const int block_w = width;
  const int block_h = height;
  uint8_t* img = new uint8_t[width * height * 3];
  for (int y = height; y--> 0;) {
    const int row = y / block_h;
    const int ty = y % block_h;
    for (int x = 0; x < width; x++) {
      const int col = x / block_w;
      const int tx = x % block_w;
      uint8_t* ptr = img + ((row + col)*(block_w * block_h) + ty*block_w + tx)*3;
      fin.read(reinterpret_cast<char*>(ptr), 3);
    }
    const int padding = (width * 3) % 4;
    if (padding) {
      char junk[3];
      fin.read(junk, 4 - padding);
    }
  }

  //Load texture into video memory
  glGenTextures(1, &texId);
  glBindTexture(GL_TEXTURE_2D, texId);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, img);

  //Clenup
  delete[] img;
}

void Texture::Use() {
  glBindTexture(GL_TEXTURE_2D, texId);
}
