#pragma once
#include "Object.h"

class Tunnel : public Object {
public:
  enum Type {
    NORMAL = 0,
    SLOPE = 2,
  };

  Tunnel(Type type) : type(type) {
    if (type == SLOPE) {
      mesh = AquireMesh("tunnel_slope.obj");
    } else {
      mesh = AquireMesh("tunnel.obj");
    }
    shader = AquireShader("texture");
    texture = AquireTexture("checker_gray.bmp");
  }
  virtual ~Tunnel() {}

  void SetDoor1(Object& portal) const {
    portal.pos = LocalToWorld().MulPoint(Vector3(0, 1, 1));
    portal.context = context;
    portal.euler = euler;
    portal.scale = Vector3(0.6f, 0.999f, 1) * scale.x;
  }
  void SetDoor2(Object& portal) const {
    portal.euler = euler;
    portal.context = context;
    if (type == SLOPE) {
      portal.pos = LocalToWorld().MulPoint(Vector3(0, -1, -1));
      portal.scale = Vector3(0.6f, 0.999f, 1) * scale.x;
    } else {
      portal.pos = LocalToWorld().MulPoint(Vector3(0, 1, -1));
      portal.scale = Vector3(0.6f, 0.999f, 1) * scale.x;
    }
  }

private:
  Type type;
};
