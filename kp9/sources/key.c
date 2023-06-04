#include "headers/key.h"

int keycmp(key k1, key k2) {
    if (k1.num == k2.num) {
        if (k1.letter < k2.letter) {
            return -1;
        } else if (k1.letter > k2.letter) {
            return 1;
        }
        return 0;
    } else if (k1.num < k2.num) {
        return -1;
    } else {
        return 1;
    }
}
