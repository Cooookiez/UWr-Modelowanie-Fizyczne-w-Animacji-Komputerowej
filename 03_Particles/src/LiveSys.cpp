#include "LiveSys.h"

LiveSys::LiveSys() {
    this->width = 50;
    this->height = 50;
}

LiveSys::LiveSys(double width, double height) {
    this->width = width;
    this->height = height;
}

void LiveSys::update(double dt) {
    // remove dead particles
    for (unsigned i = 0; i < this->particles.size(); i++) {
        if ( this->particles.at(i).lifeLived >= this->particles.at(i).lifeSpan ) {
            // vec.erase(vec.begin() + 1);
            this->particles.erase(this->particles.begin() + i);
            i--;
        }
    }
    for (unsigned i = 0; i < this->particles.size(); i++) {
        this->particles.at(i).update(dt);
    }

    // std::cout << dt << "\t" << this->particles.size() << "\t" << cos(0) << std::endl;
    for (unsigned i = 0; i < this->emiters.size(); i++) {
        this->emiters.at(i).update(dt);
        double particle2add = this->emiters.at(i).particlesPerSecond * dt;
        // add particles
        for (unsigned j = 0; j < particle2add; j++) {
            this->particles.push_back(this->emiters.at(i).addParticle());
        }
    }
}

void LiveSys::draw() {
    // Emiters
    for (unsigned i = 0; i < this->emiters.size(); i++) {
        this->emiters.at(i).draw();
    }
    // Particles
    for (unsigned i = 0; i < this->particles.size(); i++) {
        this->particles.at(i).draw();
    }
}

void LiveSys::addEmiter(double x, double y, double width, double height) {

    this->emiters.push_back(Emiter(x, y, width, height));

}