#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



bool contains(const string& source, char key)
{
    for (int i = 0; i < source.size(); i++) {
        if (source[i] == key) return true;   
    }
    return false;
}


int main()
{
    int W, H, N; // width of the building.
    std::cin >> W >> H; std::cin.ignore();
    std::cin >> N; std::cin.ignore();
    
    int x, y;
    std::cin >> x >> y; std::cin.ignore();
    
    std::vector<std::vector<bool> > table(W, std::vector<bool>(H, false));

        int x0 = 0;
        int x1 = W;

        int y0 = 0;
        int y1 = H;
    
    while (1) {
        std::string bombDir; 
        std::cin >> bombDir; cin.ignore();

        std::cerr << x  << ' '  << y   << std::endl;
        std::cerr << x0 << ' ' << x1 << std::endl;
        std::cerr << y0 << ' ' << y1 << std::endl;

        if (contains(bombDir, 'U')) 
            y1 = y;

        if (contains(bombDir, 'D')) 
            y0 = y;
            
        if (contains(bombDir, 'L')) 
            x1 = x;

        if (contains(bombDir, 'R')) 
            x0 = x;
            
        x = x0 + (x1 - x0) / 2;
        y = y0 + (y1 - y0) / 2;

        std::cout << x << ' ' << y << std::endl;
    }
}