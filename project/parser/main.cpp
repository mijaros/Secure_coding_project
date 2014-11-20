#include <iostream>
#include "jparser.h"
#include "mediamanager.h"
using namespace std;

int main()
{
        cout << "Hello World!" << endl;
        cout << "New Hello World!" << endl;
        JParser j;
        std::cin >> j;
        MediaManager m(j.getParsed());
        m.process();
        return 0;
}

