#include <bits/stdc++.h>
using namespace std;

//unscoped enumeration named color
enum Color // this enum is defined in the global namespace
{
	red, // so red is put into the global namespace
	green,
	blue,
};

// compiler will give an error
// enum Feeling
// {
//     happy,
//     tired,
//     blue, // error: naming collision with the above blue
// };

//using enumerator with namespace
namespace Feeling
{
	enum Feeling
	{
		happy,
		sad,
		blue,
	};
}

int main(){

	Color apple{red};
	Color shirt{green};
	Color captain_america{blue};
	cout<<apple<<" "<<shirt<<" "<<captain_america<<"\n";

	Feeling::Feeling me{Feeling::blue};
	cout<<me<<"\n";
	return 0;
}