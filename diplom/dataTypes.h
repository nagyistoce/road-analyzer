#ifndef DATATYPES_H
#define DATATYPES_H

namespace DATA{

enum TYPE { UNKNOWN, FRAME, VIDEO, XML};

struct Info {
    TYPE type;
    bool isProcessed;
};

}
#endif // DATATYPES_H
