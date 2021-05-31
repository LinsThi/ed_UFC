#include "cell.h"

cell::cell(int col, int row) {
    this->col = col;
    this->row = row;
    for (int k=0; k<4; k++)
    walls[k] = true;
    visited = false;
}

void cell::drop (char d) {
   walls[d] = false;
}

bool cell::isDroped (char d){
    return walls[d]==false;
}

bool& cell::visit() {
    visited = true;
    return visited;
}

bool cell::isVisited() {
    return visited;
}

int cell::getLinha(){
    return row;
}

int cell::getColuna(){
    return col;
}