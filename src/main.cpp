#include <iostream>
#include <sstream>
#include <vector>

#include <mrpt/gui/CDisplayWindow.h>

using namespace mrpt;
using namespace mrpt::gui;
using namespace mrpt::img;
using namespace std;

string Annc =
"                       Announce \n"
"This is the first open source project of the OrdBot organization, \n"
"which aims to develop ordinary and most vibrant robots. Empowering \n"
"robots with ordinary vitality, for which we hope more people will join. \n"
"                                                         OrdBot.Calm \n"
"                                                         2025.05.11 \n";

vector<string> splitLines(const string& str)
{
    vector<string> lines;
    istringstream iss(str);
    string line;

    while (getline(iss, line))
    {
        lines.push_back(line);
    }

    return lines;
}

// ------------------------------------------------------
//                   TestFonts
// ------------------------------------------------------
void TestFonts()
{
    CImage img(800, 300);

    img.filledRectangle(0, 0, 800, 300, TColor(0x50, 0x50, 0x50));

    img.selectTextFont("10x20");

    const int fontHeight = 20;
    int y = 0;

    for (const auto& line : splitLines(Annc))
    {
        img.textOut(10, y, line, TColor::white());
        y += fontHeight;
    }

    CDisplayWindow win1("OrdBot Announce");
    win1.setPos(10, 10);
    win1.showImage(img);

    cout << "Push a key in the console or in the window to continue...";
    win1.waitForKey();
    cout << "Done" << endl;
}

// ------------------------------------------------------
//                      MAIN
// ------------------------------------------------------
int main()
{
    try
    {
        TestFonts();
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "MRPT error: " << mrpt::exception_to_str(e) << std::endl;
        return -1;
    }
}
