#include "clist.hpp"
#include <string>

int main()
{
  Clist<string> playlist;

  playlist.insert("Song X");
  playlist.insert("Song G");
  playlist.insert("Song A");
  cout << "Now playing " << playlist.back() << endl;

  playlist.advance();
  cout << "Now playing " << playlist.back() << endl;
  playlist.advance();
  cout << "Now playing " << playlist.back() << endl;
  playlist.remove();
  playlist.insert("Song J");

  return 0;
}
