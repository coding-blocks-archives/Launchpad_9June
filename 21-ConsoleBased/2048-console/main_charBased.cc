#include "main_charBased.h"
#include "core/game.h"

int mainForCharBased(){
    Game G;
    while(G.IsOver() == false){
        G.move();
    }
    return 0;
}
