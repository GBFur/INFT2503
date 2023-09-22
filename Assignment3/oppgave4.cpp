#include <iostream>
#include <string>

using namespace std;

int main()
{

  string word1, word2, word3;
  cout << "Write 3 words: ";
  cin >> word1 >> word2 >> word3;

  string sentence = word1 + " " + word2 + " " + word3 + ".";
  cout << "Here's what you wrote in a sentence: " << endl
       << sentence << endl;

  cout << "Here's the length of each word you wrote:" << endl;
  cout << "Word 1 length: " << word1.length() << endl;
  cout << "Word 2 length: " << word2.length() << endl;
  cout << "Word 3 length: " << word3.length() << endl;

  cout << "Length of the sentence:" << endl;
  cout << sentence.length() << endl;

  string sentence2 = sentence;

  if (sentence2.length() >= 12)
  {
    sentence2[10] = 'x';
    sentence2[11] = 'x';
    sentence2[12] = 'x';
  }

  cout << "Old sentence: " << sentence << endl;
  cout << "New sentence: " << sentence2 << endl;

  if (sentence.length() >= 5)
  {
    string sentence_start = sentence.substr(0, 5);
    cout << "sentence: " << sentence << endl;
    cout << "sentence_start: " << sentence_start << endl;
  }

  if (sentence.find("hallo") != string::npos)
  {
    cout << "sentence contains 'hallo'" << endl;
  }

  size_t pos = sentence.find("er");
  while (pos != string::npos)
  {
    cout << "'er' found at: " << pos << " and " << pos + 1 << endl;
    pos = sentence.find("er", pos + 1);
  }

  return 0;
}