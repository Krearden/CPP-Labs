#include <stdio.h>
#include <cstdlib>
#include "Graph.h"

int main() {
    system("chcp 65001");
    char do_again;
    do
    {
        GraphSin g_sin;
        GraphTg g_tg;
        GraphExp g_exp;
        g_sin.printgraph();
        g_tg.printgraph();
        g_exp.printgraph();
        //ask if wank to continue
        printf("\n\nПродолжить работу? (y/n): ");
        scanf(" %c", &do_again);
    } while (do_again == 'y');
    return 0;
}
