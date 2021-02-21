#include "soccer.h"
#include "voleyball.h"
#include "template.h"

int main(int argc, char const *argv[])
{
    Concrete soccer = {
        .base.initialize = Soccer_initialize,
        .base.start = Soccer_startPlay,
        .base.end = Soccer_endPlay
    };

    Concrete voleyball = {
        .base.initialize = Voleyball_initialize,
        .base.start = Voleyball_startPlay,
        .base.end = Voleyball_endPlay
    };

    
    concreteOpen(&soccer);
    run();

    concreteOpen(&voleyball);
    run();

    return 0;
}
