#include "libpgm.h"
#include "cell.h"
#include "matriz.h"
#include "maze.h"

int main() {
    maze x(50,50);
    x.generate();
    x.saveAsImage(50, "mymze.pgm");

    cell* a = x.takecell(0,0);
    cell* b = x.takecell(25,30);
    x.getway(a,b);
 }

