#pragma once
#include "Object.h"

class PillarRoom : public Object {
public:
  PillarRoom() {
  }

  void SetPortal(Object& portal) const {
    portal.pos = LocalToWorld().MulPoint(Vector3(0.f, 1.5f, -10.f));
    portal.context = context;
    portal.euler = euler;
    portal.euler.y -= GH_PI / 2;
    portal.scale = Vector3(10.f, 1.5f, 1.f) * scale;
  }
  virtual ~PillarRoom() {}
};