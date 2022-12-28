#ifndef VESSEL_FACTORY_H
#define VESSEL_FACTORY_H

#include "scene.h"

#define nullptr 0

class VesselFactory {
private:
    static VesselFactory* factory_;
    VesselFactory() {};
    ~VesselFactory();

public:
    VesselFactory(const VesselFactory& obj) = delete;

    Scene *new_scene(const char* name, float width, float height, int r, int g, int b);
    static VesselFactory *GetInstance();
};



#endif // VESSEL_FACTORY_H