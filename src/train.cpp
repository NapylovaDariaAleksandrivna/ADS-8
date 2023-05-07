// Copyright 2021 NNTU-CS
#include "train.h"

void Train::addCage(bool light) { // добавить вагон с начальным состоянием лампочки
  Cage* wagon = new Cage;
  wagon->next = nullptr;
  wagon->prev = nullptr;
  wagon->light = light;
  
  if (first == nullptr) {
    first = wagon;
  } else {
    if (first->next == nullptr) {
      first->next = wagon;
      first->prev = wagon;
      wagon->prev = first;
      wagon->next = first;
    } else {
      Cage* copy = first;
      while (copy->next != first) {
        copy = copy->next;
      }
      copy->next = wagon;
      wagon->prev = copy;
      
      wagon->next = first;
      first->prev  = wagon;
    }
  }
  countOp = 0;
}

Train::Train(): first(nullptr), countOp(0) {}

int Train::getLength() {// вычислить длину поезда
    Cage* Wagon = first;
    if (Wagon->light == false) {
        Wagon->light = true;
    }
    Wagon = Wagon->next;
    int rez = 0;
    int countWagon=2;
    countOp += 1;
    while (true) {
        while (Wagon->light == false) {
            Wagon = Wagon->next;
            countOp += 1;
            countWagon += 1;
        }
        Wagon->light = false;
        rez = countWagon;
        while (countWagon != 1) {
            countOp += 1;
            countWagon -= 1;
            Wagon = Wagon->prev;
        }
        if (Wagon->light == false) {
            return rez;
        }
    }
}


int Train::getOpCount() { // вернуть число переходов (из вагона в вагон)
    return countOp;
}
#endif  // INCLUDE_TRAIN_H_
