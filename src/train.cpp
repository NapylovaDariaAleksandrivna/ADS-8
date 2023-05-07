// Copyright 2021 NNTU-CS
#include "train.h"

void Train::addCage(bool light) {
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

int Train::getLength() {
    Cage* Wagon = first;
    if (Wagon->light == false) {
        Wagon->light = true;
    }
    
    int rez = 0;
    int countWagon = 0;
    
    while (true) {
        Wagon = Wagon->next;
        countOp += 1;
        countWagon += 1;
        while (Wagon->light == false) {
            Wagon = Wagon->next;
            countOp += 1;
            countWagon += 1;
        }
        Wagon->light = false;
        rez = countWagon;
        while (countWagon != 0) {
            countOp += 1;
            countWagon -= 1;
            Wagon = Wagon->prev;
        }
        if (Wagon->light == false) {
            return rez;
        }
    }
}


int Train::getOpCount() {
    return countOp;
}
