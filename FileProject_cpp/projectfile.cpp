#include <iostream>
#include <fstream>
#include <string.h>
#define ll long long
using namespace std;

class Student_Teacher
{
public:
  ll id, age;
  char name[10];
  int phone_number;
  int level;
};
class Book
{
public:
  int id;
  char subject[20];
  char name[20];
};
class Student_Book{
	public:
	char Borrower_Name[15];
	char Book_Name[15];
	
};
void writeStudent_Teacher()
{
  fstream outFile("Student_Teacher.txt", ios::out | ios::app);
  Student_Teacher s1;
  char c;
  do
  {
    cout << "Welcome In Our Libarary System !\n";
    cout << "Enter Name: ";
    cin >> s1.name;
    cout << "Enter ID: ";
    cin >> s1.id;
    cout << "Enter Age: ";
    cin >> s1.age;
    cout << "Enter Your Level If You A Student: ";
    cin >> s1.level;
    cout << "Enter Your Phone Number: ";
    cin >> s1.phone_number;
    outFile.write((char *)&s1, sizeof(s1));
    cout << "Enter records again? (Y/N) ";
    cin >> c;
  } while (c == 'y');
  outFile.close();
}
void readRecord()
{
  Student_Teacher s2;
  ifstream in;
  in.open("Student_Teacher.txt", ios::in);
  if (in.is_open())
  {
    in.read((char *)&s2, sizeof(s2));
    cout << "Id\tName\tAge\tLevel\tPhone\n";
    while (!in.eof())
    {
      cout << s2.id << "\t" << s2.name << "\t" << s2.age << "\t" << s2.level << "\t" << s2.phone_number << "\n";
      in.read((char *)&s2, sizeof(s2));
    }
    in.close();
  }
  else
  {
    cout << "can not open the specified file"
        << "\n";
  }
}
void search_byID()
{
  int ide;
  cout << "Enter Your ID To Search For ";
  cin >> ide;
  bool found = false;
  Student_Teacher s1;
  ifstream in;
  in.open("Student_Teacher.txt", ios::in);
  if (in.is_open())
  {
    in.read((char *)&s1, sizeof(s1));
    while (!in.eof())
    {
      if (s1.id == ide)
      {
        cout << "Id\tName\tAge\tLevel\tPhone\t"
            << "\n\n";
        cout << s1.id << "\t" << s1.name << "\t" << s1.age << "\t" << s1.level << "\t" << s1.phone_number << "\n";
        found = true;
      }
      in.read((char *)&s1, sizeof(s1));
    }
    if (!found)
      cout << "Name not found"
          << "\n";
    in.close();
  }
}
void update()
{
  char str[10];
  cout << "Enter A Name To Search For ";
  cin >> str;
  bool found = false;
  Student_Teacher s1;
  fstream in;
  in.open("Student_Teacher.txt", ios::in | ios::out);
  if (in.is_open())
  {
    in.read((char *)&s1, sizeof(s1));
    while (!in.eof())
    {
      if (strcmp(str, s1.name) == 0)
      {
        cout << "Enter New Age For " << str << " ";
        cin >> s1.age;
        cout << "Enter New Level For " << str << " ";
        cin >> s1.level;
        cout << "Enter New Phone Number For " << str << " ";
        cin >> s1.phone_number;
        int curpos = in.tellg();
        int stusize = sizeof(s1);
        in.seekp(curpos - stusize, ios::beg);
        in.write((char *)&s1, sizeof(s1));
        in.seekg(curpos - stusize, ios::beg);
        in.read((char *)&s1, sizeof(s1));
        cout << "Id\tName\tAge\tLevel\tPhone\n";
        cout << s1.id << "\t" << s1.name << "\t" << s1.age << "\t" << s1.level << "\t" << s1.phone_number << "\n";
        found = true;
      }
      in.read((char *)&s1, sizeof(s1));
    }
    if (!found)
      cout << "Name not found"
          << "\n";
    in.close();
  }
}
void delete_Name()
{
  char str[10];
  cout << "Enter A Name To Delete ";
  cin >> str;
  bool found = false;
  Student_Teacher s1;
  ifstream in;
  ofstream out;
  in.open("Student_Teacher.txt", ios::in);
  out.open("Temp.txt", ios::out);
  if (in.is_open())
  {
    in.read((char *)&s1, sizeof(s1));
    while (!in.eof())
    {
      if (strcmp(str, s1.name) != 0)
      {
        out.write((char *)&s1, sizeof(s1));
        found = true;
      }
      in.read((char *)&s1, sizeof(s1));
    }
    if (!found)
      cout << "Name not found"
          << "\n";
    in.close();
    out.close();
    remove("Student_Teacher.txt");
    rename("Temp.txt", "Student_Teacher.txt");
  }
}
void writebook()
{
  fstream f;
  f.open("BOOKS.txt", ios::out);
  Book b;
  char c;
  do
  {
    cout << "Enter Book Name: ";
    cin >> b.name;
    cout << "Enter Book ID: ";
    cin >> b.id;
    cout << "Enter Book subject: ";
    cin >> b.subject;
    f.write((char *)&b, sizeof(b));
    cout << "Enter record again? (Y / N): ";
    cin >> c;
  } while (c == 'y');
  f.close();
}
void searchbook()
{
  char str[10];
  cout << "Enter Book Name to Search ";
  cin >> str;
  Book b;
  bool found = false;
  ifstream in;
  in.open("BOOKS.txt", ios::in);
  if (in.is_open())
  {
    in.read((char *)&b, sizeof(b));
    while (!in.eof())
    {
      if (strcmp(str, b.name) == 0)
      {
        cout << "Name\tID\tSubject\n";
        cout << b.name << "\t" << b.id << "\t" << b.subject << "\n";
        found = true;
      }
      in.read((char *)&b, sizeof(b));
    }
    if (!found)
      cout << "Book not found\n";
  }
  else
    cout << "Can not open this file";
}
void readbook()
{
  Book b;
  ifstream in;
  in.open("BOOKS.txt", ios::in);
  if (in.is_open())
  {
    in.read((char *)&b, sizeof(b));
    cout << "Book Name\t ID\tSubject\n";
    while (!in.eof())
    {
      cout << b.name << "\t" << b.id << "\t" << b.subject << "\n";
      in.read((char *)&b, sizeof(b));
    }
    in.close();
  }
  else
    cout << "Can not open this file";
}
void editbook()
{
  char str[10];
  cout << "Enter Book Name to Search ";
  cin >> str;
  Book b;
  fstream in;
  in.open("BOOKS.txt", ios::in | ios::out);
  if (in.is_open())
  {
    in.read((char *)&b, sizeof(b));
    while (!in.eof())
    {
      if (strcmp(str, b.name) == 0)
      {
        cout << "Enter new ID for Book " << str << " ";
        cin >> b.id;
        int curpos = in.tellg();
        int stusize = sizeof(b);
        in.seekp(curpos - stusize, ios::beg);
        in.write((char *)&b, sizeof(b));
        in.seekp(curpos - stusize, ios::beg);
        in.read((char *)&b, sizeof(b));
        cout << "Name\tID\tSubject\n";
        cout << b.name << "\t" << b.id << "\t" << b.subject << "\n";
        break;
      }
      in.read((char *)&b, sizeof(b));
    }
    in.close();
  }
  else
  {
    cout << "Can not open this file";
  }
}
void deletebook()
{
  char str[10];
  bool found = false;
  cout << "Enter Book Name to  Delete: ";
  cin >> str;
  Book b;
  ifstream in;
  in.open("BOOKS.txt", ios::in);
  ofstream out("BOOKS2.txt", ios::out);
  if (in.is_open())
  {
    in.read((char *)&b, sizeof(b));
    while (!in.eof())
    {
      if (strcmp(str, b.name) != 0)
      {
        out.write((char *)&b, sizeof(b));
        found = true;
      }
      in.read((char *)&b, sizeof(b));
    }
    if (!found)
      cout << "Name not found\n";
    in.read((char *)&b, sizeof(b));
    in.close();
    out.close();
    remove("BOOKS.txt");
    rename("BOOKS2.txt", "BOOKS.txt");
  }
}

void write_Student_Book()
{
  fstream f;
  f.open("StudentBook.txt", ios::out);
  Student_Book sb;
  char c;
  do
  {
  	cout << "Enter Borrower Name: ";
    cin >> sb.Borrower_Name;
    cout << "Enter Book Name: ";
    cin >> sb.Book_Name;
    
    f.write((char *)&sb, sizeof(sb));
    cout << "Enter record again? (Y / N): ";
    cin >> c;
  } while (c == 'y'||c=='Y');
  f.close();
}
void read_Student_Book()
{
  Student_Book sb;
  ifstream in;
  in.open("StudentBook.txt", ios::in);
  if (in.is_open())
  {
    in.read((char *)&sb, sizeof(sb));
    cout << "Borrower\tBook\t\n";
    while (!in.eof())
    {
      cout << sb.Borrower_Name << "\t\t" << sb.Book_Name << "\t\n";
      in.read((char *)&sb, sizeof(sb));
    }
    in.close();
  }
  else
    cout << "Can not open this file";
}
int main()
{
  char c;
  do
  {
    cout << "0 - Write A New Student Or Teacher "<< "\n";
    cout << "1 - Read All Records "<< "\n";
    cout << "2 - Search For A Student By Id "<< "\n";
    cout << "3 - Update Student Record By Enter His Name "<< "\n";
    cout << "4 - Delete Student Record By Enter His Name "<< "\n";
    cout << "5 - Write a New Books\n";
    cout << "6 - Search for Books\n";
    cout << "7 - Read All Record\n";
    cout << "8 - Update Books ID\n";
    cout << "9 - Delete Book By ID\n";
    cout << "10 - To Exit"<< "\n";
    cin >> c;
    switch (c)
    {
    case '0':
      writeStudent_Teacher();
      break;
    case '1':
      readRecord();
      break;
    case '2':
      search_byID();
      break;
    case '3':
      update();
      break;
    case '4':
      delete_Name();
      break;
    case '5':
      writebook();
      break;
    case '6':
      searchbook();
      break;
    case '7':
      readbook();
      break;
    case '8':
      editbook();
      break;
    case '9':
      deletebook();
      break;
    }

  } while (c != '10');
  write_Student_Book();
  read_Student_Book();
  return 0;
}
