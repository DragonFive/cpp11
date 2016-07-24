/*************************************************************************
	> File Name: cpp11_10_uDefineLite.cpp
	> Author: DragonFive
	> Mail: dragonfive2013@163.com
	> Created Time: 2016年07月24日 星期日 16时02分04秒
 ************************************************************************/

#include <iostream>

using namespace std;

std::size_t operator"" _len(char const *,std::size_t size)
{
    return size;
}

class Inch {
  public:
    Inch() : Inch(0) { }
    Inch(double value_) : value(value_) { }
    double toCentimeter()const
    {
        return value*2.54;
    }

  private:
    double value = 0;
};

Inch operator "" _inch(long double arg) {
  return Inch(arg);
}

int main() {
    cout << (1.0_inch).toCentimeter() << " centimeter" << endl;
    cout<<"hehe"s<<endl;
    cout<<"haha"_len<<endl;
    return 0;
}
