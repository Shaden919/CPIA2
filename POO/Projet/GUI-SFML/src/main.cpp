#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

const int cellSize = 10;
const int gridWidth = 80;
const int gridHeight = 80;

std::vector<std::vector<int>> grid(gridWidth, std::vector<int>(gridHeight));
std::vector<std::vector<int>> nextGrid(gridWidth,std::vector<int> (gridHeight));

void initializeGrid() {
    std::srand(std::time(0));
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            grid[x][y] = std::rand() % 2;  // Randomly initialize cells as alive or dead
        }
    }
}

void renderGrid(sf::RenderWindow &window) {
    int x, y;
    
    window.clear(sf::Color::Red);
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            if (grid[x][y] == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
                cell.setFillColor(sf::Color::White);
                window.draw(cell);
            } else {
                cell.setPosition(x * cellSize, y * cellSize);
                cell.setFillColor(sf::Color::Black);
                window.draw(cell);
            }
        }
    }
    window.display();
}

int countNeighbour(int x , int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++)
        {
            if(i == 0 && j == 0) continue;
            int xNeighbour = (x + i + gridWidth) % gridWidth;
            int yNeighbour = (y + j + gridHeight) % gridHeight;

            count += grid[xNeighbour][yNeighbour];
        }
    }
    return count;
}

void updateGrid() {
    for (int x = 0; x < gridWidth; x++)
    {
        for (int y = 0; y < gridHeight; y++)
        {
            int alive = grid[x][y];
            int neighboor = countNeighbour(x,y);

            if ( alive == 0  && (neighboor == 3))
            {
                nextGrid[x][y] = 1;
            }
            else if (alive == 1 && (neighboor < 2 || neighboor > 3))
            {
                nextGrid[x][y] = 0;
            }
            else {
                nextGrid[x][y] = alive;
            }
        }
    }
    grid = nextGrid;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");

    bool pause = false;

    int speed = 100;
    
    initializeGrid();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    if(speed == 10) break;
                    speed -= 10;
                    break;
                
                case sf::Keyboard::Down :
                    if(speed == 1000) break;
                    speed += 10;
                    break;
                
                case sf::Keyboard::Space :
                    pause = !pause;
                    break;
                }
            }
        }

        
        updateGrid();
        renderGrid(window);
        sf::sleep(sf::milliseconds(speed));
    }

    return 0;
}
