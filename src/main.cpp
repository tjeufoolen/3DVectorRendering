#include <SDL.h>

#include "logger.h"
#include "app.h"

//
//  ,--.   ,--.,--.  ,--.  ,---.  ,--.
//  |  |   |  ||  ,'.|  | /  O  \ |  |
//  |  |   |  ||  |' '  ||  .-.  ||  |
//  |  '--.|  ||  | `   ||  | |  ||  '--.
//  `-----'`--'`--'  `--'`--' `--'`-----'
//
// This code is written for the linear algebra course which is part of
// the software architecture minor.
//
// Authors: Stan Geitel & Tjeu Foolen
//

int main(int argc, char *argv[])  {

    utils::logger::getInstance().toggleDebugMessages(true);
    app{}.run();

    return 0;
}
