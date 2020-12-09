#include <SDL.h>

#include "utils/logger.h"
#include "app.h"

int main(int argc, char *argv[])  {

    utils::logger::getInstance().toggleDebugMessages(true);
    app{}.run();

    return 0;
}
