//
// Created by Yoko on 03/01/2025.
//

#include <stdio.h>
#include "tuple.h"

#include <stdlib.h>

Tuple* creeTuple(Chevalet lettre, int nbChevalet) {
    Tuple tu;
    tu.lettre = lettre;
    tu.nbChevalet = nbChevalet;
    Tuple* t;
    t = (Tuple*)malloc(sizeof(Tuple));
    *t = tu;
    return t;
}
