#pragma once
#include <GL/glew.h>

class Texture {
public:
  Texture(const char* fname);

  void Use();

private:
  GLuint texId;
};
