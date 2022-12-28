#ifndef SCENES_H
#define SCENES_H

#define NUM_OF_SCENES 1
 struct SCN {
    int id;
    const char *addr;
} SCN[] {
    { .id = 0, .addr="./src/scenes/scene0.xml"}
};

#endif // SCENES_H