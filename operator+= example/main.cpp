#include "geek.hpp"
#include "nerd.hpp"

int main(int argc, char const *argv[]) {
        myspace::geek myGeek("le geek", 3);
        myspace::nerd leNerd("le nerd", 4, 3);
        myspace::nerd lautreNerd("ultime nerd", 2, 2);
        cout << myGeek;
        lautreNerd += leNerd;
        cout << lautreNerd;
        return 0;
}
