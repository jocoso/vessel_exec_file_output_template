#include "vessel_factory.h"


Scene *VesselFactory::new_scene(const char* name, float width, float height, int r, int g, int b) {
    Scene *scene = new Scene(name);
    scene->setSize(sf::Vector2f(width, height));
    scene->setFillColor(sf::Color(r, g, b));
    return scene;
}

VesselFactory *VesselFactory::GetInstance() {
    if(factory_ == nullptr) {
        factory_ = new VesselFactory();
    }

    return factory_;
}

VesselFactory::~VesselFactory() {
    if(factory_ != nullptr)
        free(factory_);
}

VesselFactory *VesselFactory::factory_ = nullptr;
