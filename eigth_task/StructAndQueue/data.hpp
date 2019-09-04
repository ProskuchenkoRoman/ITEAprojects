#pragma once

struct stackcell {
  long variable = 0;
  stackcell* PrevPtr = nullptr;
};