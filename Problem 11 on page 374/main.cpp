#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int number1, number2, number3, number4;
    ofstream file;
    file.open("rectline.svg");
    cout << "Please enter 4 numbers : ";
    cin>> number1 >> number2 >> number3 >> number4;
    file << "<?xml version=\"1.0\" standalone=\"no\"?>\n"
         << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n"
         << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n"
         << "<svg width=\"500\" height=\"500\"\n"
         << "xmlns=\"http://www.w3.org/2000/svg\">\n";
    // This creates the bars.
    file << "<rect x=\"" << 0 <<"\" y=\"" << 400-number1 << "\" width=\"" << 25
         << "\" height=\"" << number1 << "\" style=\"fill:blue;\"/>\n"
         << "<rect x=\"" << 50 << "\" y=\"" << 400-number2 << "\" width=\"" << 25
         << "\" height=\"" << number2 << "\" style=\"fill:rgb(0,255,0);\"/>\n"
         << "<rect x=\"" << 100 <<"\" y=\"" << 400-number3 << "\" width=\"" << 25
         << "\" height=\"" << number3 << "\" style=\"fill:blue;\"/>\n"
         << "<rect x=\"" << 150 << "\" y=\"" << 400-number4 << "\" width=\"" << 25
         << "\" height=\"" << number4 << "\" style=\"fill:rgb(0,255,0);\"/>\n";
    // This creates the lines.
    file << "<line x1=\"" << 0 << "\" y1=\"" << 0 << "\" x2=\"" << 0 << "\" y2=\"" << 400
         << "\" style=\"stroke:purple;stroke-width:2\"/>" << endl
         << "<line x1=\"" << 0 << "\" y1=\"" << 400 << "\" x2=\"" << 400 << "\" y2=\"" << 400
         << "\" style=\"stroke:purple;stroke-width:2\"/>" << endl;
    file<< "</svg>" << endl;
    file.close();
    return 0;
}
