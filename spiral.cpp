//
// Facebook's Practice Interview Question #1
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<int> > matrix;

void allocate(matrix& m, int size)
{
    m.resize(size);
    for (int i=0; i<size; i++)
        m[i].resize(size);
}

void top(matrix& m, int x, int y, int& v, int size)
{
    if (size==1) {
        m[x][y] = v++;
    } else {
        for (int i=0; i<size; i++) {
            m[x+i][y] = v++;
        }
    }
}

void right(matrix& m, int x, int y, int& v, int size)
{
    if (size >= 2) {
        for (int i=1; i<size; i++) {
            m[x+size-1][y+i] = v++;
        }
    }
}

void bottom(matrix& m, int x, int y, int& v, int size)
{
    if (size >= 2) {
        for (int i=1; i<size; i++) {
            m[x+size-i-1][y+size-1] = v++;
        }
    }
}

void left(matrix& m, int x, int y, int& v, int size)
{
    if (size >= 3) {
        for (int i=1; i<(size-1); i++) {
            m[x][y+size-i-1] = v++;
        }
    }
}

void spiral(matrix&m, int x, int y, int& v, int size)
{
    top(m, x, y, v, size);
    right(m, x, y, v, size);
    bottom(m, x, y, v, size);
    left(m, x, y, v, size);
    if (size > 0)
        spiral(m, x+1, y+1, v, size-2);
}

void spiral(matrix& m)
{
    int size = m.size();
    int v = 1;
    spiral(m, 0,0, v, size);
}

void display(matrix& m)
{
    std::cout << "input: " << m.size() << std::endl;
    int width = log10(m.size()*m.size())+1;
    for (int x=0; x<m.size(); x++) {
        std::vector<int> c = m[x];
        for (int y=0; y<c.size(); y++) {
            std::cout << std::setw(width) << m[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    matrix m;
    allocate(m, 10);
    spiral(m);
    display(m);
}
