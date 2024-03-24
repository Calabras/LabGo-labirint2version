#include "Cell.h"
class Wall : public Cell {
public:
    Cell* operator+(Hero& hero) {
        // Стена не позволяет герою проходить, возвращает себя
        return this;
    }

    Cell* operator-(Hero& hero) {
        // Удаление героя из стены не предусмотрено, возвращает себя
        return this;
    }

    void print(ostream& out) const override {
        out << "#"; // Предположим, что # - это стена
    }
};
