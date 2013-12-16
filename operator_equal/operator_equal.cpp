#include <string>
using namespace std;

struct Css {
  int left;
  int top;
  int right;
  int bottom;
  int width;
  int height;
};

class Icon {
 public:
  std::string small_icon;
  std::string large_icon;
  Css css_info;
};

int main()
{
  Css css1, css2;
  if (css1 == css2) {
    int i = 0;
    i++;
  }
	return 0;
}

